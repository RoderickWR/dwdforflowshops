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
CMAKE_BINARY_DIR = /home/roderich/Documents/BAP/build

# Utility rule file for ContinuousMemCheck.

# Include any custom commands dependencies for this target.
include check/CMakeFiles/ContinuousMemCheck.dir/compiler_depend.make

# Include the progress variables for this target.
include check/CMakeFiles/ContinuousMemCheck.dir/progress.make

check/CMakeFiles/ContinuousMemCheck:
	cd /home/roderich/Documents/BAP/build/check && /usr/bin/ctest -D ContinuousMemCheck

ContinuousMemCheck: check/CMakeFiles/ContinuousMemCheck
ContinuousMemCheck: check/CMakeFiles/ContinuousMemCheck.dir/build.make
.PHONY : ContinuousMemCheck

# Rule to build all files generated by this target.
check/CMakeFiles/ContinuousMemCheck.dir/build: ContinuousMemCheck
.PHONY : check/CMakeFiles/ContinuousMemCheck.dir/build

check/CMakeFiles/ContinuousMemCheck.dir/clean:
	cd /home/roderich/Documents/BAP/build/check && $(CMAKE_COMMAND) -P CMakeFiles/ContinuousMemCheck.dir/cmake_clean.cmake
.PHONY : check/CMakeFiles/ContinuousMemCheck.dir/clean

check/CMakeFiles/ContinuousMemCheck.dir/depend:
	cd /home/roderich/Documents/BAP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/roderich/Documents/BAP /home/roderich/Documents/BAP/check /home/roderich/Documents/BAP/build /home/roderich/Documents/BAP/build/check /home/roderich/Documents/BAP/build/check/CMakeFiles/ContinuousMemCheck.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : check/CMakeFiles/ContinuousMemCheck.dir/depend

