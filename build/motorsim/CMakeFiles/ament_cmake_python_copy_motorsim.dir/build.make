# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tanakon/RoboticsDev2024/src/motorsim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tanakon/RoboticsDev2024/build/motorsim

# Utility rule file for ament_cmake_python_copy_motorsim.

# Include any custom commands dependencies for this target.
include CMakeFiles/ament_cmake_python_copy_motorsim.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ament_cmake_python_copy_motorsim.dir/progress.make

CMakeFiles/ament_cmake_python_copy_motorsim:
	/usr/local/bin/cmake -E copy_directory /home/tanakon/RoboticsDev2024/src/motorsim/motorsim /home/tanakon/RoboticsDev2024/build/motorsim/ament_cmake_python/motorsim/motorsim

ament_cmake_python_copy_motorsim: CMakeFiles/ament_cmake_python_copy_motorsim
ament_cmake_python_copy_motorsim: CMakeFiles/ament_cmake_python_copy_motorsim.dir/build.make
.PHONY : ament_cmake_python_copy_motorsim

# Rule to build all files generated by this target.
CMakeFiles/ament_cmake_python_copy_motorsim.dir/build: ament_cmake_python_copy_motorsim
.PHONY : CMakeFiles/ament_cmake_python_copy_motorsim.dir/build

CMakeFiles/ament_cmake_python_copy_motorsim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ament_cmake_python_copy_motorsim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ament_cmake_python_copy_motorsim.dir/clean

CMakeFiles/ament_cmake_python_copy_motorsim.dir/depend:
	cd /home/tanakon/RoboticsDev2024/build/motorsim && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tanakon/RoboticsDev2024/src/motorsim /home/tanakon/RoboticsDev2024/src/motorsim /home/tanakon/RoboticsDev2024/build/motorsim /home/tanakon/RoboticsDev2024/build/motorsim /home/tanakon/RoboticsDev2024/build/motorsim/CMakeFiles/ament_cmake_python_copy_motorsim.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ament_cmake_python_copy_motorsim.dir/depend

