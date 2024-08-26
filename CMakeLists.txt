cmake_minimum_required(VERSION 3.7.0 FATAL_ERROR)

add_custom_target(all-plugins-database)

find_package(IRODS REQUIRED)
set(IRODS_PLUGIN_REVISION "0")
set(IRODS_PLUGIN_VERSION "${IRODS_VERSION}.${IRODS_PLUGIN_REVISION}")

set(IRODS_PACKAGE_REVISION "1")

include(IrodsCXXCompiler)
set(CMAKE_CXX_STANDARD ${IRODS_CXX_STANDARD})
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_MODULE_LINKER_FLAGS_INIT "-Wl,--enable-new-dtags -Wl,--as-needed -Wl,-z,defs")
set(CMAKE_MODULE_LINKER_FLAGS_RELEASE_INIT "-Wl,--gc-sections -Wl,-z,combreloc")

project(irods_database_plugin VERSION "${IRODS_PLUGIN_VERSION}" LANGUAGES CXX)

set(IRODS_PACKAGE_COMPONENT_POSTGRES_NAME "irods-database-plugin-postgres")
set(IRODS_PACKAGE_COMPONENT_MYSQL_NAME "irods-database-plugin-mysql")
set(IRODS_PACKAGE_COMPONENT_ORACLE_NAME "irods-database-plugin-oracle")

# Include this module to inherit iRODS's defaults for RPATH/RUNPATH handling
include(IrodsRunpathDefaults)

include("${IRODS_TARGETS_PATH}")
include(GNUInstallDirs)
include(UseLibCXX)

find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED COMPONENTS Crypto SSL)
find_package(nlohmann_json "3.6.1" REQUIRED)

if (NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build {Debug, Release}." FORCE)
    message(STATUS "Setting unspecified CMAKE_BUILD_TYPE to '${CMAKE_BUILD_TYPE}'")
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-fpermissive>)
endif()

set(IRODS_BUILD_WITH_WERROR OFF CACHE BOOL "Choose whether to compile with -Werror.")

if (IRODS_BUILD_WITH_WERROR)
  add_compile_options(-Werror)
endif()

if (NOT ODBC_LIBRARY)
  find_library(ODBC_LIBRARY odbc)
  if (ODBC_LIBRARY)
    message(STATUS "Found odbc: ${ODBC_LIBRARY}")
  else()
    message(FATAL_ERROR "odbc library not found")
  endif()
endif()

set(
  IRODS_DATABASE_PLUGINS
  postgres
  mysql
  oracle
)


string(TOUPPER ${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME} IRODS_PACKAGE_COMPONENT_POSTGRES_NAME_UPPERCASE)
string(TOUPPER ${IRODS_PACKAGE_COMPONENT_MYSQL_NAME} IRODS_PACKAGE_COMPONENT_MYSQL_NAME_UPPERCASE)
string(TOUPPER ${IRODS_PACKAGE_COMPONENT_ORACLE_NAME} IRODS_PACKAGE_COMPONENT_ORACLE_NAME_UPPERCASE)
include(IrodsCPackCommon)

configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/src/icatSysTables.sql.pp.in"
  "${CMAKE_CURRENT_BINARY_DIR}/src/icatSysTables.sql.pp"
  @ONLY
)
configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/src/mysql_functions.sql.in"
  "${CMAKE_CURRENT_BINARY_DIR}/src/mysql_functions.sql"
  @ONLY
)

foreach(plugin IN LISTS IRODS_DATABASE_PLUGINS)
  string(TOUPPER ${plugin} PLUGIN_UPPERCASE)
  set(plugin_target "irods_database_plugin-${plugin}")
  set(plugin_name "${plugin}")

  add_library(
    ${plugin_target}
    MODULE
    "${CMAKE_CURRENT_SOURCE_DIR}/src/db_plugin.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/general_query.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/general_query_setup.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/general_update.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/irods_catalog_properties.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/irods_sql_logger.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/low_level_odbc.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/mid_level_routines.cpp"
  )
  set_property(TARGET ${plugin_target} PROPERTY LIBRARY_OUTPUT_NAME ${plugin_name})
  target_link_libraries(
    ${plugin_target}
    PRIVATE
    irods_common
    irods_server
    irods_plugin_dependencies
    "${IRODS_EXTERNALS_FULLPATH_BOOST}/lib/libboost_filesystem.so"
    "${IRODS_EXTERNALS_FULLPATH_BOOST}/lib/libboost_system.so"
    "${IRODS_EXTERNALS_FULLPATH_BOOST}/lib/libboost_regex.so"
    "${IRODS_EXTERNALS_FULLPATH_NANODBC}/lib/libnanodbc.so"
    fmt::fmt
    nlohmann_json::nlohmann_json
    ${ODBC_LIBRARY}
  )
  target_include_directories(
    ${plugin_target}
    PRIVATE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "${IRODS_EXTERNALS_FULLPATH_BOOST}/include"
    "${IRODS_EXTERNALS_FULLPATH_NANODBC}/include"
  )
  target_compile_definitions(
    ${plugin_target}
    PRIVATE
    ${IRODS_COMPILE_DEFINITIONS_PRIVATE}
    ENABLE_RE
    IRODS_ENABLE_SYSLOG
  )

  # TODO(#6213): don't run `cpp` like this
  add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/icatSysTables_${plugin}.sql"
    COMMAND cpp -E -P -D${plugin} "${CMAKE_CURRENT_BINARY_DIR}/src/icatSysTables.sql.pp" "${CMAKE_CURRENT_BINARY_DIR}/icatSysTables_${plugin}.sql"
    MAIN_DEPENDENCY "${CMAKE_CURRENT_BINARY_DIR}/src/icatSysTables.sql.pp"
  )
  add_custom_target(IRODS_PHONY_TARGET_icatSysTables_${plugin}.sql ALL DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/icatSysTables_${plugin}.sql")
  add_dependencies(${plugin_target} IRODS_PHONY_TARGET_icatSysTables_${plugin}.sql)

  install(
    TARGETS
    ${plugin_target}
    LIBRARY
    DESTINATION "${IRODS_PLUGINS_DIRECTORY}/database"
    COMPONENT ${IRODS_PACKAGE_COMPONENT_${PLUGIN_UPPERCASE}_NAME}
  )

  install(
    FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/${plugin}/upgrade-3.3.xto4.0.0.sql"
    DESTINATION "${IRODS_HOME_DIRECTORY}/packaging"
    COMPONENT ${IRODS_PACKAGE_COMPONENT_${PLUGIN_UPPERCASE}_NAME}
  )

  install(
    FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/packaging/localhost_setup_${plugin}.input"
    DESTINATION "${IRODS_HOME_DIRECTORY}/packaging"
    COMPONENT ${IRODS_PACKAGE_COMPONENT_${PLUGIN_UPPERCASE}_NAME}
    PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
  )

  install(
    FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/icatDropSysTables.sql"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/icatSysInserts.sql"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/icatPurgeRecycleBin.sql"
    DESTINATION "${IRODS_HOME_DIRECTORY}/packaging/sql"
    COMPONENT ${IRODS_PACKAGE_COMPONENT_${PLUGIN_UPPERCASE}_NAME}
    PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
  )

  install(
    FILES
    "${CMAKE_CURRENT_BINARY_DIR}/icatSysTables_${plugin}.sql"
    DESTINATION "${IRODS_HOME_DIRECTORY}/packaging/sql"
    COMPONENT ${IRODS_PACKAGE_COMPONENT_${PLUGIN_UPPERCASE}_NAME}
    RENAME icatSysTables.sql
    PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
  )
endforeach()

#target_compile_options(${IRODS_MICROSERVICE_NAME} PRIVATE -Wall -Wextra)

list(APPEND CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION "${CPACK_PACKAGING_INSTALL_PREFIX}${IRODS_HOME_DIRECTORY}")
list(APPEND CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION "${CPACK_PACKAGING_INSTALL_PREFIX}${IRODS_HOME_DIRECTORY}/scripts")
list(APPEND CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION "${CPACK_PACKAGING_INSTALL_PREFIX}${IRODS_HOME_DIRECTORY}/scripts/irods")
list(APPEND CPACK_RPM_EXCLUDE_FROM_AUTO_FILELIST_ADDITION "${CPACK_PACKAGING_INSTALL_PREFIX}${IRODS_HOME_DIRECTORY}/scripts/irods/test")

set(CPACK_PACKAGE_VERSION ${IRODS_PLUGIN_VERSION})
set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
set(CPACK_COMPONENT_INCLUDE_TOPLEVEL_DIRECTORY OFF)
set(CPACK_COMPONENTS_GROUPING IGNORE)
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "The integrated Rule-Oriented Data System")

set(CPACK_DEB_COMPONENT_INSTALL ON)
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS OFF)
set(CPACK_DEBIAN_PACKAGE_CONTROL_STRICT_PERMISSION ON)
set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/packaging/postinst;")
set(CPACK_DEBIAN_PACKAGE_BREAKS ${PLUGIN_PACKAGE_NAME})
set(CPACK_DEBIAN_PACKAGE_REPLACES ${PLUGIN_PACKAGE_NAME})
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)

set(CPACK_RPM_COMPONENT_INSTALL OFF)
set(CPACK_RPM_PACKAGE_LICENSE "BSD-3-Clause")
set(CPACK_RPM_PACKAGE_AUTOREQ 0)
set(CPACK_RPM_PACKAGE_AUTOPROV 0)
set(CPACK_RPM_PACKAGE_OBSOLETES ${PLUGIN_PACKAGE_NAME})
set(CPACK_RPM_POST_INSTALL_SCRIPT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/packaging/postinst")
set(CPACK_RPM_FILE_NAME RPM-DEFAULT)

set(CPACK_ARCHIVE_COMPONENT_INSTALL OFF)

set(CPACK_DEBIAN_PACKAGE_NAME ${PLUGIN_PACKAGE_NAME})
set(CPACK_DEBIAN_PACKAGE_DEPENDS "${IRODS_PACKAGE_DEPENDENCIES_STRING}, irods-server (= ${IRODS_VERSION}), irods-runtime (= ${IRODS_VERSION}), libc6")

set(CPACK_RPM_PACKAGE_REQUIRES "${IRODS_PACKAGE_DEPENDENCIES_STRING}, irods-server = ${IRODS_VERSION}, irods-runtime = ${IRODS_VERSION}")

if (NOT CPACK_GENERATOR)
    set(CPACK_GENERATOR ${IRODS_CPACK_GENERATOR} CACHE STRING "CPack generator to use, e.g. {DEB, RPM, TGZ}." FORCE)
    message(STATUS "Setting unspecified CPACK_GENERATOR to ${CPACK_GENERATOR}. This is the correct setting for normal builds.")
endif()

#steal some db plugin stuff...
#######################################
## Postgres database plugin package
#######################################
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME_UPPERCASE}_PACKAGE_NAME "irods-database-plugin-postgres")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME_UPPERCASE}_PACKAGE_DEPENDS "${IRODS_PACKAGE_DEPENDENCIES_STRING}, irods-server (= ${CPACK_DEBIAN_PACKAGE_VERSION}-${CPACK_DEBIAN_PACKAGE_RELEASE}), unixodbc, ${CPACK_DEBIAN_PACKAGE_DEPENDS_LIBODBC}, odbcinst, odbc-postgresql, postgresql-client, libc6, libgcc-s1, libstdc++6")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME_UPPERCASE}_PACKAGE_PROVIDES "irods-database-plugin-postgres (= ${CPACK_DEBIAN_PACKAGE_VERSION})")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME_UPPERCASE}_PACKAGE_CONFLICTS "irods-database-plugin-mysql, irods-database-plugin-oracle")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME_UPPERCASE}_PACKAGE_CONTROL_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/packaging/preinst;${CMAKE_CURRENT_SOURCE_DIR}/packaging/postinst;${CMAKE_CURRENT_SOURCE_DIR}/packaging/postrm;")

set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME}_PACKAGE_NAME "irods-database-plugin-postgres")
if (IRODS_LINUX_DISTRIBUTION_NAME STREQUAL "opensuse")
  set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME}_PACKAGE_REQUIRES "${IRODS_PACKAGE_DEPENDENCIES_STRING}, irods-server = ${CPACK_RPM_PACKAGE_VERSION}-${CPACK_RPM_PACKAGE_RELEASE}, unixODBC, postgresql, psqlODBC")
elseif (IRODS_LINUX_DISTRIBUTION_NAME STREQUAL "centos" AND IRODS_LINUX_DISTRIBUTION_VERSION_MAJOR EQUAL 7)
  set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME}_PACKAGE_REQUIRES "${IRODS_PACKAGE_DEPENDENCIES_STRING}, irods-server = ${CPACK_RPM_PACKAGE_VERSION}-${CPACK_RPM_PACKAGE_RELEASE}, unixODBC, postgresql, authd, postgresql-odbc, glibc, libgcc, libstdc++")
else()
  set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME}_PACKAGE_REQUIRES "${IRODS_PACKAGE_DEPENDENCIES_STRING}, irods-server = ${CPACK_RPM_PACKAGE_VERSION}-${CPACK_RPM_PACKAGE_RELEASE}, unixODBC, postgresql, postgresql-odbc, glibc, libgcc, libstdc++")
endif()
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME}_PACKAGE_CONFLICTS "irods-database-plugin-mysql, irods-database-plugin-oracle")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME}_PRE_INSTALL_SCRIPT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/packaging/preinst")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME}_POST_INSTALL_SCRIPT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/packaging/postinst")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME}_POST_UNINSTALL_SCRIPT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/packaging/postrm")

#if (CPACK_GENERATOR STREQUAL DEB)
#  install(
#    FILES
#    "${CMAKE_IRODS_SOURCE_DIR}/LICENSE"
#    DESTINATION "${CMAKE_INSTALL_DOCDIR}/${CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME_UPPERCASE}_PACKAGE_NAME}"
#    COMPONENT ${IRODS_PACKAGE_COMPONENT_POSTGRES_NAME}
#    RENAME copyright
#  )
#endif()

#######################################
## MySQL database plugin package
#######################################
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME_UPPERCASE}_PACKAGE_NAME "irods-database-plugin-mysql")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME_UPPERCASE}_PACKAGE_DEPENDS "${IRODS_PACKAGE_DEPENDENCIES_STRING}, irods-server (= ${CPACK_DEBIAN_PACKAGE_VERSION}-${CPACK_DEBIAN_PACKAGE_RELEASE}), unixodbc, ${CPACK_DEBIAN_PACKAGE_DEPENDS_LIBODBC}, odbcinst, virtual-mysql-client, libc6, libgcc-s1, libstdc++6")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME_UPPERCASE}_PACKAGE_RECOMMENDS "odbc-mariadb | mariadb-connector-odbc | mysql-connector-odbc | mysql-connector-odbc-commercial | libmyodbc")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME_UPPERCASE}_PACKAGE_PROVIDES "irods-database-plugin-mysql (= ${CPACK_DEBIAN_PACKAGE_VERSION})")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME_UPPERCASE}_PACKAGE_CONFLICTS "irods-database-plugin-postgres, irods-database-plugin-oracle")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME_UPPERCASE}_PACKAGE_CONTROL_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/packaging/preinst;${CMAKE_CURRENT_SOURCE_DIR}/packaging/postinst;${CMAKE_CURRENT_SOURCE_DIR}/packaging/postrm;")

set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME}_PACKAGE_NAME "irods-database-plugin-mysql")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME}_PACKAGE_REQUIRES "${IRODS_PACKAGE_DEPENDENCIES_STRING}, irods-server = ${CPACK_RPM_PACKAGE_VERSION}-${CPACK_RPM_PACKAGE_RELEASE}, unixODBC")
if (IRODS_LINUX_DISTRIBUTION_NAME STREQUAL "opensuse")
  set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME}_PACKAGE_REQUIRES "${CPACK_RPM_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME}_PACKAGE_REQUIRES}, (mariadb-client or mysql-client or MariaDB-client or MySQL-client), (mariadb-connector-odbc or mysql-connector-odbc)")
elseif (IRODS_LINUX_DISTRIBUTION_VERSION_MAJOR EQUAL 7)
  # boolean dependencies added in RPM 4.13, EL7 has 4.11
  set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME}_PACKAGE_REQUIRES "${CPACK_RPM_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME}_PACKAGE_REQUIRES}, mysql, mysql-connector-odbc, glibc, libgcc, libstdc++")
else()
  set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME}_PACKAGE_REQUIRES "${CPACK_RPM_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME}_PACKAGE_REQUIRES}, (mariadb or mysql or mariadb-client or mysql-client or MariaDB-client or MySQL-client or mysql-compat-client), (mariadb-connector-odbc or mysql-connector-odbc), glibc, libgcc, libstdc++")
endif()
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME}_PACKAGE_CONFLICTS "irods-database-plugin-postgres, irods-database-plugin-oracle")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME}_PRE_INSTALL_SCRIPT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/packaging/preinst")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME}_POST_INSTALL_SCRIPT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/packaging/postinst")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME}_POST_UNINSTALL_SCRIPT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/packaging/postrm")

#if (CPACK_GENERATOR STREQUAL DEB)
#  install(
#    FILES
#    "${CMAKE_IRODS_SOURCE_DIR}/LICENSE"
#    DESTINATION "${CMAKE_INSTALL_DOCDIR}/${CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_MYSQL_NAME_UPPERCASE}_PACKAGE_NAME}"
#    COMPONENT ${IRODS_PACKAGE_COMPONENT_MYSQL_NAME}
#    RENAME copyright
#  )
#endif()

#######################################
## Oracle database plugin package
#######################################
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_ORACLE_NAME_UPPERCASE}_PACKAGE_NAME "irods-database-plugin-oracle")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_ORACLE_NAME_UPPERCASE}_PACKAGE_DEPENDS "${IRODS_PACKAGE_DEPENDENCIES_STRING}, irods-server (= ${CPACK_DEBIAN_PACKAGE_VERSION}-${CPACK_DEBIAN_PACKAGE_RELEASE}), unixodbc, ${CPACK_DEBIAN_PACKAGE_DEPENDS_LIBODBC}, odbcinst, libc6, libgcc-s1, libstdc++6")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_ORACLE_NAME_UPPERCASE}_PACKAGE_PROVIDES "irods-database-plugin-oracle (= ${CPACK_DEBIAN_PACKAGE_VERSION})")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_ORACLE_NAME_UPPERCASE}_PACKAGE_CONFLICTS "irods-database-plugin-mysql, irods-database-plugin-postgres")
set(CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_ORACLE_NAME_UPPERCASE}_PACKAGE_CONTROL_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/packaging/preinst;${CMAKE_CURRENT_SOURCE_DIR}/packaging/postinst;${CMAKE_CURRENT_SOURCE_DIR}/packaging/postrm;")

set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_ORACLE_NAME}_PACKAGE_NAME "irods-database-plugin-oracle")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_ORACLE_NAME}_PACKAGE_REQUIRES "${IRODS_PACKAGE_DEPENDENCIES_STRING}, irods-server = ${CPACK_RPM_PACKAGE_VERSION}-${CPACK_RPM_PACKAGE_RELEASE}, unixODBC, glibc, libgcc, libstdc++")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_ORACLE_NAME}_PACKAGE_CONFLICTS "irods-database-plugin-mysql, irods-database-plugin-postgres")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_ORACLE_NAME}_PRE_INSTALL_SCRIPT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/packaging/preinst")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_ORACLE_NAME}_POST_INSTALL_SCRIPT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/packaging/postinst")
set(CPACK_RPM_${IRODS_PACKAGE_COMPONENT_ORACLE_NAME}_POST_UNINSTALL_SCRIPT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/packaging/postrm")

#if (CPACK_GENERATOR STREQUAL DEB)
#  install(
#    FILES
#    "${CMAKE_IRODS_SOURCE_DIR}/LICENSE"
#    DESTINATION "${CMAKE_INSTALL_DOCDIR}/${CPACK_DEBIAN_${IRODS_PACKAGE_COMPONENT_ORACLE_NAME_UPPERCASE}_PACKAGE_NAME}"
#    COMPONENT ${IRODS_PACKAGE_COMPONENT_ORACLE_NAME}
#    RENAME copyright
#  )
#endif()

include(CPack)

target_compile_definitions(irods_database_plugin-mysql PRIVATE MY_ICAT)
target_compile_definitions(irods_database_plugin-oracle PRIVATE ORA_ICAT)

install(
  FILES
  "${CMAKE_CURRENT_BINARY_DIR}/src/mysql_functions.sql"
  DESTINATION "${IRODS_HOME_DIRECTORY}/packaging/sql"
  COMPONENT ${IRODS_PACKAGE_COMPONENT_MYSQL_NAME}
)
