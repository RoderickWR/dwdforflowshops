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
CMAKE_SOURCE_DIR = /home/roderich/Documents/BAP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/roderich/Documents/BAP/build-debug

# Utility rule file for ContinuousTest.

# Include any custom commands dependencies for this target.
include check/CMakeFiles/ContinuousTest.dir/compiler_depend.make

# Include the progress variables for this target.
include check/CMakeFiles/ContinuousTest.dir/progress.make

check/CMakeFiles/ContinuousTest:
	cd /home/roderich/Documents/BAP/build-debug/check && /usr/bin/ctest -D ContinuousTest

ContinuousTest: check/CMakeFiles/ContinuousTest
ContinuousTest: check/CMakeFiles/ContinuousTest.dir/build.make
.PHONY : ContinuousTest

# Rule to build all files generated by this target.
check/CMakeFiles/ContinuousTest.dir/build: ContinuousTest
.PHONY : check/CMakeFiles/ContinuousTest.dir/build

check/CMakeFiles/ContinuousTest.dir/clean:
	cd /home/roderich/Documents/BAP/build-debug/check && $(CMAKE_COMMAND) -P CMakeFiles/ContinuousTest.dir/cmake_clean.cmake
.PHONY : check/CMakeFiles/ContinuousTest.dir/clean

check/CMakeFiles/ContinuousTest.dir/depend:
	cd /home/roderich/Documents/BAP/build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/roderich/Documents/BAP /home/roderich/Documents/BAP/check /home/roderich/Documents/BAP/build-debug /home/roderich/Documents/BAP/build-debug/check /home/roderich/Documents/BAP/build-debug/check/CMakeFiles/ContinuousTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : check/CMakeFiles/ContinuousTest.dir/depend

