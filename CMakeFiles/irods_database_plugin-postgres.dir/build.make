# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/derek.d/irods/db_template_test/database

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/derek.d/irods/db_template_test/database

# Include any dependencies generated for this target.
include CMakeFiles/irods_database_plugin-postgres.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/irods_database_plugin-postgres.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/irods_database_plugin-postgres.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/irods_database_plugin-postgres.dir/flags.make

CMakeFiles/irods_database_plugin-postgres.dir/src/db_plugin.o: CMakeFiles/irods_database_plugin-postgres.dir/flags.make
CMakeFiles/irods_database_plugin-postgres.dir/src/db_plugin.o: src/db_plugin.cpp
CMakeFiles/irods_database_plugin-postgres.dir/src/db_plugin.o: CMakeFiles/irods_database_plugin-postgres.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/derek.d/irods/db_template_test/database/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/irods_database_plugin-postgres.dir/src/db_plugin.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/irods_database_plugin-postgres.dir/src/db_plugin.o -MF CMakeFiles/irods_database_plugin-postgres.dir/src/db_plugin.o.d -o CMakeFiles/irods_database_plugin-postgres.dir/src/db_plugin.o -c /home/derek.d/irods/db_template_test/database/src/db_plugin.cpp

CMakeFiles/irods_database_plugin-postgres.dir/src/db_plugin.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/irods_database_plugin-postgres.dir/src/db_plugin.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/derek.d/irods/db_template_test/database/src/db_plugin.cpp > CMakeFiles/irods_database_plugin-postgres.dir/src/db_plugin.i

CMakeFiles/irods_database_plugin-postgres.dir/src/db_plugin.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/irods_database_plugin-postgres.dir/src/db_plugin.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/derek.d/irods/db_template_test/database/src/db_plugin.cpp -o CMakeFiles/irods_database_plugin-postgres.dir/src/db_plugin.s

CMakeFiles/irods_database_plugin-postgres.dir/src/general_query.o: CMakeFiles/irods_database_plugin-postgres.dir/flags.make
CMakeFiles/irods_database_plugin-postgres.dir/src/general_query.o: src/general_query.cpp
CMakeFiles/irods_database_plugin-postgres.dir/src/general_query.o: CMakeFiles/irods_database_plugin-postgres.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/derek.d/irods/db_template_test/database/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/irods_database_plugin-postgres.dir/src/general_query.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/irods_database_plugin-postgres.dir/src/general_query.o -MF CMakeFiles/irods_database_plugin-postgres.dir/src/general_query.o.d -o CMakeFiles/irods_database_plugin-postgres.dir/src/general_query.o -c /home/derek.d/irods/db_template_test/database/src/general_query.cpp

CMakeFiles/irods_database_plugin-postgres.dir/src/general_query.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/irods_database_plugin-postgres.dir/src/general_query.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/derek.d/irods/db_template_test/database/src/general_query.cpp > CMakeFiles/irods_database_plugin-postgres.dir/src/general_query.i

CMakeFiles/irods_database_plugin-postgres.dir/src/general_query.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/irods_database_plugin-postgres.dir/src/general_query.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/derek.d/irods/db_template_test/database/src/general_query.cpp -o CMakeFiles/irods_database_plugin-postgres.dir/src/general_query.s

CMakeFiles/irods_database_plugin-postgres.dir/src/general_query_setup.o: CMakeFiles/irods_database_plugin-postgres.dir/flags.make
CMakeFiles/irods_database_plugin-postgres.dir/src/general_query_setup.o: src/general_query_setup.cpp
CMakeFiles/irods_database_plugin-postgres.dir/src/general_query_setup.o: CMakeFiles/irods_database_plugin-postgres.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/derek.d/irods/db_template_test/database/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/irods_database_plugin-postgres.dir/src/general_query_setup.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/irods_database_plugin-postgres.dir/src/general_query_setup.o -MF CMakeFiles/irods_database_plugin-postgres.dir/src/general_query_setup.o.d -o CMakeFiles/irods_database_plugin-postgres.dir/src/general_query_setup.o -c /home/derek.d/irods/db_template_test/database/src/general_query_setup.cpp

CMakeFiles/irods_database_plugin-postgres.dir/src/general_query_setup.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/irods_database_plugin-postgres.dir/src/general_query_setup.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/derek.d/irods/db_template_test/database/src/general_query_setup.cpp > CMakeFiles/irods_database_plugin-postgres.dir/src/general_query_setup.i

CMakeFiles/irods_database_plugin-postgres.dir/src/general_query_setup.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/irods_database_plugin-postgres.dir/src/general_query_setup.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/derek.d/irods/db_template_test/database/src/general_query_setup.cpp -o CMakeFiles/irods_database_plugin-postgres.dir/src/general_query_setup.s

CMakeFiles/irods_database_plugin-postgres.dir/src/general_update.o: CMakeFiles/irods_database_plugin-postgres.dir/flags.make
CMakeFiles/irods_database_plugin-postgres.dir/src/general_update.o: src/general_update.cpp
CMakeFiles/irods_database_plugin-postgres.dir/src/general_update.o: CMakeFiles/irods_database_plugin-postgres.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/derek.d/irods/db_template_test/database/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/irods_database_plugin-postgres.dir/src/general_update.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/irods_database_plugin-postgres.dir/src/general_update.o -MF CMakeFiles/irods_database_plugin-postgres.dir/src/general_update.o.d -o CMakeFiles/irods_database_plugin-postgres.dir/src/general_update.o -c /home/derek.d/irods/db_template_test/database/src/general_update.cpp

CMakeFiles/irods_database_plugin-postgres.dir/src/general_update.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/irods_database_plugin-postgres.dir/src/general_update.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/derek.d/irods/db_template_test/database/src/general_update.cpp > CMakeFiles/irods_database_plugin-postgres.dir/src/general_update.i

CMakeFiles/irods_database_plugin-postgres.dir/src/general_update.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/irods_database_plugin-postgres.dir/src/general_update.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/derek.d/irods/db_template_test/database/src/general_update.cpp -o CMakeFiles/irods_database_plugin-postgres.dir/src/general_update.s

CMakeFiles/irods_database_plugin-postgres.dir/src/irods_catalog_properties.o: CMakeFiles/irods_database_plugin-postgres.dir/flags.make
CMakeFiles/irods_database_plugin-postgres.dir/src/irods_catalog_properties.o: src/irods_catalog_properties.cpp
CMakeFiles/irods_database_plugin-postgres.dir/src/irods_catalog_properties.o: CMakeFiles/irods_database_plugin-postgres.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/derek.d/irods/db_template_test/database/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/irods_database_plugin-postgres.dir/src/irods_catalog_properties.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/irods_database_plugin-postgres.dir/src/irods_catalog_properties.o -MF CMakeFiles/irods_database_plugin-postgres.dir/src/irods_catalog_properties.o.d -o CMakeFiles/irods_database_plugin-postgres.dir/src/irods_catalog_properties.o -c /home/derek.d/irods/db_template_test/database/src/irods_catalog_properties.cpp

CMakeFiles/irods_database_plugin-postgres.dir/src/irods_catalog_properties.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/irods_database_plugin-postgres.dir/src/irods_catalog_properties.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/derek.d/irods/db_template_test/database/src/irods_catalog_properties.cpp > CMakeFiles/irods_database_plugin-postgres.dir/src/irods_catalog_properties.i

CMakeFiles/irods_database_plugin-postgres.dir/src/irods_catalog_properties.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/irods_database_plugin-postgres.dir/src/irods_catalog_properties.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/derek.d/irods/db_template_test/database/src/irods_catalog_properties.cpp -o CMakeFiles/irods_database_plugin-postgres.dir/src/irods_catalog_properties.s

CMakeFiles/irods_database_plugin-postgres.dir/src/irods_sql_logger.o: CMakeFiles/irods_database_plugin-postgres.dir/flags.make
CMakeFiles/irods_database_plugin-postgres.dir/src/irods_sql_logger.o: src/irods_sql_logger.cpp
CMakeFiles/irods_database_plugin-postgres.dir/src/irods_sql_logger.o: CMakeFiles/irods_database_plugin-postgres.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/derek.d/irods/db_template_test/database/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/irods_database_plugin-postgres.dir/src/irods_sql_logger.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/irods_database_plugin-postgres.dir/src/irods_sql_logger.o -MF CMakeFiles/irods_database_plugin-postgres.dir/src/irods_sql_logger.o.d -o CMakeFiles/irods_database_plugin-postgres.dir/src/irods_sql_logger.o -c /home/derek.d/irods/db_template_test/database/src/irods_sql_logger.cpp

CMakeFiles/irods_database_plugin-postgres.dir/src/irods_sql_logger.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/irods_database_plugin-postgres.dir/src/irods_sql_logger.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/derek.d/irods/db_template_test/database/src/irods_sql_logger.cpp > CMakeFiles/irods_database_plugin-postgres.dir/src/irods_sql_logger.i

CMakeFiles/irods_database_plugin-postgres.dir/src/irods_sql_logger.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/irods_database_plugin-postgres.dir/src/irods_sql_logger.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/derek.d/irods/db_template_test/database/src/irods_sql_logger.cpp -o CMakeFiles/irods_database_plugin-postgres.dir/src/irods_sql_logger.s

CMakeFiles/irods_database_plugin-postgres.dir/src/low_level_odbc.o: CMakeFiles/irods_database_plugin-postgres.dir/flags.make
CMakeFiles/irods_database_plugin-postgres.dir/src/low_level_odbc.o: src/low_level_odbc.cpp
CMakeFiles/irods_database_plugin-postgres.dir/src/low_level_odbc.o: CMakeFiles/irods_database_plugin-postgres.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/derek.d/irods/db_template_test/database/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/irods_database_plugin-postgres.dir/src/low_level_odbc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/irods_database_plugin-postgres.dir/src/low_level_odbc.o -MF CMakeFiles/irods_database_plugin-postgres.dir/src/low_level_odbc.o.d -o CMakeFiles/irods_database_plugin-postgres.dir/src/low_level_odbc.o -c /home/derek.d/irods/db_template_test/database/src/low_level_odbc.cpp

CMakeFiles/irods_database_plugin-postgres.dir/src/low_level_odbc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/irods_database_plugin-postgres.dir/src/low_level_odbc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/derek.d/irods/db_template_test/database/src/low_level_odbc.cpp > CMakeFiles/irods_database_plugin-postgres.dir/src/low_level_odbc.i

CMakeFiles/irods_database_plugin-postgres.dir/src/low_level_odbc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/irods_database_plugin-postgres.dir/src/low_level_odbc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/derek.d/irods/db_template_test/database/src/low_level_odbc.cpp -o CMakeFiles/irods_database_plugin-postgres.dir/src/low_level_odbc.s

CMakeFiles/irods_database_plugin-postgres.dir/src/mid_level_routines.o: CMakeFiles/irods_database_plugin-postgres.dir/flags.make
CMakeFiles/irods_database_plugin-postgres.dir/src/mid_level_routines.o: src/mid_level_routines.cpp
CMakeFiles/irods_database_plugin-postgres.dir/src/mid_level_routines.o: CMakeFiles/irods_database_plugin-postgres.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/derek.d/irods/db_template_test/database/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/irods_database_plugin-postgres.dir/src/mid_level_routines.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/irods_database_plugin-postgres.dir/src/mid_level_routines.o -MF CMakeFiles/irods_database_plugin-postgres.dir/src/mid_level_routines.o.d -o CMakeFiles/irods_database_plugin-postgres.dir/src/mid_level_routines.o -c /home/derek.d/irods/db_template_test/database/src/mid_level_routines.cpp

CMakeFiles/irods_database_plugin-postgres.dir/src/mid_level_routines.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/irods_database_plugin-postgres.dir/src/mid_level_routines.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/derek.d/irods/db_template_test/database/src/mid_level_routines.cpp > CMakeFiles/irods_database_plugin-postgres.dir/src/mid_level_routines.i

CMakeFiles/irods_database_plugin-postgres.dir/src/mid_level_routines.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/irods_database_plugin-postgres.dir/src/mid_level_routines.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/derek.d/irods/db_template_test/database/src/mid_level_routines.cpp -o CMakeFiles/irods_database_plugin-postgres.dir/src/mid_level_routines.s

# Object files for target irods_database_plugin-postgres
irods_database_plugin__postgres_OBJECTS = \
"CMakeFiles/irods_database_plugin-postgres.dir/src/db_plugin.o" \
"CMakeFiles/irods_database_plugin-postgres.dir/src/general_query.o" \
"CMakeFiles/irods_database_plugin-postgres.dir/src/general_query_setup.o" \
"CMakeFiles/irods_database_plugin-postgres.dir/src/general_update.o" \
"CMakeFiles/irods_database_plugin-postgres.dir/src/irods_catalog_properties.o" \
"CMakeFiles/irods_database_plugin-postgres.dir/src/irods_sql_logger.o" \
"CMakeFiles/irods_database_plugin-postgres.dir/src/low_level_odbc.o" \
"CMakeFiles/irods_database_plugin-postgres.dir/src/mid_level_routines.o"

# External object files for target irods_database_plugin-postgres
irods_database_plugin__postgres_EXTERNAL_OBJECTS =

libpostgres.so: CMakeFiles/irods_database_plugin-postgres.dir/src/db_plugin.o
libpostgres.so: CMakeFiles/irods_database_plugin-postgres.dir/src/general_query.o
libpostgres.so: CMakeFiles/irods_database_plugin-postgres.dir/src/general_query_setup.o
libpostgres.so: CMakeFiles/irods_database_plugin-postgres.dir/src/general_update.o
libpostgres.so: CMakeFiles/irods_database_plugin-postgres.dir/src/irods_catalog_properties.o
libpostgres.so: CMakeFiles/irods_database_plugin-postgres.dir/src/irods_sql_logger.o
libpostgres.so: CMakeFiles/irods_database_plugin-postgres.dir/src/low_level_odbc.o
libpostgres.so: CMakeFiles/irods_database_plugin-postgres.dir/src/mid_level_routines.o
libpostgres.so: CMakeFiles/irods_database_plugin-postgres.dir/build.make
libpostgres.so: /opt/irods-externals/boost-libcxx1.81.0-1/lib/libboost_filesystem.so
libpostgres.so: /opt/irods-externals/boost-libcxx1.81.0-1/lib/libboost_system.so
libpostgres.so: /opt/irods-externals/boost-libcxx1.81.0-1/lib/libboost_regex.so
libpostgres.so: /opt/irods-externals/nanodbc-libcxx2.13.0-2/lib/libnanodbc.so
libpostgres.so: /opt/irods-externals/fmt-libcxx8.1.1-1/lib/libfmt.so.8.1.1
libpostgres.so: /usr/lib/x86_64-linux-gnu/libodbc.so
libpostgres.so: CMakeFiles/irods_database_plugin-postgres.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/derek.d/irods/db_template_test/database/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX shared module libpostgres.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/irods_database_plugin-postgres.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/irods_database_plugin-postgres.dir/build: libpostgres.so
.PHONY : CMakeFiles/irods_database_plugin-postgres.dir/build

CMakeFiles/irods_database_plugin-postgres.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/irods_database_plugin-postgres.dir/cmake_clean.cmake
.PHONY : CMakeFiles/irods_database_plugin-postgres.dir/clean

CMakeFiles/irods_database_plugin-postgres.dir/depend:
	cd /home/derek.d/irods/db_template_test/database && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/derek.d/irods/db_template_test/database /home/derek.d/irods/db_template_test/database /home/derek.d/irods/db_template_test/database /home/derek.d/irods/db_template_test/database /home/derek.d/irods/db_template_test/database/CMakeFiles/irods_database_plugin-postgres.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/irods_database_plugin-postgres.dir/depend

