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
include LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/depend.make

# Include the progress variables for this target.
include LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/progress.make

# Include the compile flags for this target's objects.
include LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/flags.make

LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/shutdownCliTest.cpp.o: LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/flags.make
LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/shutdownCliTest.cpp.o: ../../LinuxNetworkCoding/src/socket/shutdownCliTest.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/shutdownCliTest.cpp.o"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/socket && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/shutdownCliTest.dir/shutdownCliTest.cpp.o -c /home/xiaotang/GitHub/CPPCourses/LinuxNetworkCoding/src/socket/shutdownCliTest.cpp

LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/shutdownCliTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shutdownCliTest.dir/shutdownCliTest.cpp.i"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/socket && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/xiaotang/GitHub/CPPCourses/LinuxNetworkCoding/src/socket/shutdownCliTest.cpp > CMakeFiles/shutdownCliTest.dir/shutdownCliTest.cpp.i

LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/shutdownCliTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shutdownCliTest.dir/shutdownCliTest.cpp.s"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/socket && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/xiaotang/GitHub/CPPCourses/LinuxNetworkCoding/src/socket/shutdownCliTest.cpp -o CMakeFiles/shutdownCliTest.dir/shutdownCliTest.cpp.s

LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/shutdownCliTest.cpp.o.requires:
.PHONY : LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/shutdownCliTest.cpp.o.requires

LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/shutdownCliTest.cpp.o.provides: LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/shutdownCliTest.cpp.o.requires
	$(MAKE) -f LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/build.make LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/shutdownCliTest.cpp.o.provides.build
.PHONY : LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/shutdownCliTest.cpp.o.provides

LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/shutdownCliTest.cpp.o.provides.build: LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/shutdownCliTest.cpp.o

# Object files for target shutdownCliTest
shutdownCliTest_OBJECTS = \
"CMakeFiles/shutdownCliTest.dir/shutdownCliTest.cpp.o"

# External object files for target shutdownCliTest
shutdownCliTest_EXTERNAL_OBJECTS =

bin/shutdownCliTest: LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/shutdownCliTest.cpp.o
bin/shutdownCliTest: LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/build.make
bin/shutdownCliTest: LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../../bin/shutdownCliTest"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/socket && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shutdownCliTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/build: bin/shutdownCliTest
.PHONY : LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/build

LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/requires: LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/shutdownCliTest.cpp.o.requires
.PHONY : LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/requires

LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/clean:
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/socket && $(CMAKE_COMMAND) -P CMakeFiles/shutdownCliTest.dir/cmake_clean.cmake
.PHONY : LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/clean

LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/depend:
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xiaotang/GitHub/CPPCourses /home/xiaotang/GitHub/CPPCourses/LinuxNetworkCoding/src/socket /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11 /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/socket /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : LinuxNetworkCoding/src/socket/CMakeFiles/shutdownCliTest.dir/depend

