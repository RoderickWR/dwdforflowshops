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
CMAKE_SOURCE_DIR = /home/roderich/Documents/BAP/gitdir01/dwdforflowshops

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/roderich/Documents/BAP/gitdir01/dwdforflowshops/build

# Utility rule file for NightlyUpdate.

# Include any custom commands dependencies for this target.
include check/CMakeFiles/NightlyUpdate.dir/compiler_depend.make

# Include the progress variables for this target.
include check/CMakeFiles/NightlyUpdate.dir/progress.make

check/CMakeFiles/NightlyUpdate:
	cd /home/roderich/Documents/BAP/gitdir01/dwdforflowshops/build/check && /usr/bin/ctest -D NightlyUpdate

NightlyUpdate: check/CMakeFiles/NightlyUpdate
NightlyUpdate: check/CMakeFiles/NightlyUpdate.dir/build.make
.PHONY : NightlyUpdate

# Rule to build all files generated by this target.
check/CMakeFiles/NightlyUpdate.dir/build: NightlyUpdate
.PHONY : check/CMakeFiles/NightlyUpdate.dir/build

check/CMakeFiles/NightlyUpdate.dir/clean:
	cd /home/roderich/Documents/BAP/gitdir01/dwdforflowshops/build/check && $(CMAKE_COMMAND) -P CMakeFiles/NightlyUpdate.dir/cmake_clean.cmake
.PHONY : check/CMakeFiles/NightlyUpdate.dir/clean

check/CMakeFiles/NightlyUpdate.dir/depend:
	cd /home/roderich/Documents/BAP/gitdir01/dwdforflowshops/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/roderich/Documents/BAP/gitdir01/dwdforflowshops /home/roderich/Documents/BAP/gitdir01/dwdforflowshops/check /home/roderich/Documents/BAP/gitdir01/dwdforflowshops/build /home/roderich/Documents/BAP/gitdir01/dwdforflowshops/build/check /home/roderich/Documents/BAP/gitdir01/dwdforflowshops/build/check/CMakeFiles/NightlyUpdate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : check/CMakeFiles/NightlyUpdate.dir/depend

