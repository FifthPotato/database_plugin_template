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

# Utility rule file for all-plugins-database.

# Include any custom commands dependencies for this target.
include CMakeFiles/all-plugins-database.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/all-plugins-database.dir/progress.make

all-plugins-database: CMakeFiles/all-plugins-database.dir/build.make
.PHONY : all-plugins-database

# Rule to build all files generated by this target.
CMakeFiles/all-plugins-database.dir/build: all-plugins-database
.PHONY : CMakeFiles/all-plugins-database.dir/build

CMakeFiles/all-plugins-database.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/all-plugins-database.dir/cmake_clean.cmake
.PHONY : CMakeFiles/all-plugins-database.dir/clean

CMakeFiles/all-plugins-database.dir/depend:
	cd /home/derek.d/irods/db_template_test/database && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/derek.d/irods/db_template_test/database /home/derek.d/irods/db_template_test/database /home/derek.d/irods/db_template_test/database /home/derek.d/irods/db_template_test/database /home/derek.d/irods/db_template_test/database/CMakeFiles/all-plugins-database.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/all-plugins-database.dir/depend

