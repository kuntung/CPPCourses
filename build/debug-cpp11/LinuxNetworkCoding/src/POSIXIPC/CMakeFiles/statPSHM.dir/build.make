# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xiaotang/GitHub/CPPCourses

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11

# Include any dependencies generated for this target.
include LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/depend.make

# Include the progress variables for this target.
include LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/progress.make

# Include the compile flags for this target's objects.
include LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/flags.make

LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/statPSHM.cpp.o: LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/flags.make
LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/statPSHM.cpp.o: ../../LinuxNetworkCoding/src/POSIXIPC/statPSHM.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/statPSHM.cpp.o"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/POSIXIPC && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/statPSHM.dir/statPSHM.cpp.o -c /home/xiaotang/GitHub/CPPCourses/LinuxNetworkCoding/src/POSIXIPC/statPSHM.cpp

LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/statPSHM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/statPSHM.dir/statPSHM.cpp.i"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/POSIXIPC && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/xiaotang/GitHub/CPPCourses/LinuxNetworkCoding/src/POSIXIPC/statPSHM.cpp > CMakeFiles/statPSHM.dir/statPSHM.cpp.i

LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/statPSHM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/statPSHM.dir/statPSHM.cpp.s"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/POSIXIPC && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/xiaotang/GitHub/CPPCourses/LinuxNetworkCoding/src/POSIXIPC/statPSHM.cpp -o CMakeFiles/statPSHM.dir/statPSHM.cpp.s

LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/statPSHM.cpp.o.requires:
.PHONY : LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/statPSHM.cpp.o.requires

LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/statPSHM.cpp.o.provides: LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/statPSHM.cpp.o.requires
	$(MAKE) -f LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/build.make LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/statPSHM.cpp.o.provides.build
.PHONY : LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/statPSHM.cpp.o.provides

LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/statPSHM.cpp.o.provides.build: LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/statPSHM.cpp.o

# Object files for target statPSHM
statPSHM_OBJECTS = \
"CMakeFiles/statPSHM.dir/statPSHM.cpp.o"

# External object files for target statPSHM
statPSHM_EXTERNAL_OBJECTS =

bin/statPSHM: LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/statPSHM.cpp.o
bin/statPSHM: LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/build.make
bin/statPSHM: LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../../bin/statPSHM"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/POSIXIPC && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/statPSHM.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/build: bin/statPSHM
.PHONY : LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/build

LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/requires: LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/statPSHM.cpp.o.requires
.PHONY : LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/requires

LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/clean:
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/POSIXIPC && $(CMAKE_COMMAND) -P CMakeFiles/statPSHM.dir/cmake_clean.cmake
.PHONY : LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/clean

LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/depend:
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xiaotang/GitHub/CPPCourses /home/xiaotang/GitHub/CPPCourses/LinuxNetworkCoding/src/POSIXIPC /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11 /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/POSIXIPC /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/statPSHM.dir/depend

