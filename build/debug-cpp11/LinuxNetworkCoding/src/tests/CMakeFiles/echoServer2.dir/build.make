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
include LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/depend.make

# Include the progress variables for this target.
include LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/progress.make

# Include the compile flags for this target's objects.
include LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/flags.make

LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/echoServer2.cc.o: LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/flags.make
LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/echoServer2.cc.o: ../../LinuxNetworkCoding/src/tests/echoServer2.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/echoServer2.cc.o"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/tests && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/echoServer2.dir/echoServer2.cc.o -c /home/xiaotang/GitHub/CPPCourses/LinuxNetworkCoding/src/tests/echoServer2.cc

LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/echoServer2.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/echoServer2.dir/echoServer2.cc.i"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/tests && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/xiaotang/GitHub/CPPCourses/LinuxNetworkCoding/src/tests/echoServer2.cc > CMakeFiles/echoServer2.dir/echoServer2.cc.i

LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/echoServer2.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/echoServer2.dir/echoServer2.cc.s"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/tests && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/xiaotang/GitHub/CPPCourses/LinuxNetworkCoding/src/tests/echoServer2.cc -o CMakeFiles/echoServer2.dir/echoServer2.cc.s

LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/echoServer2.cc.o.requires:
.PHONY : LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/echoServer2.cc.o.requires

LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/echoServer2.cc.o.provides: LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/echoServer2.cc.o.requires
	$(MAKE) -f LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/build.make LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/echoServer2.cc.o.provides.build
.PHONY : LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/echoServer2.cc.o.provides

LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/echoServer2.cc.o.provides.build: LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/echoServer2.cc.o

# Object files for target echoServer2
echoServer2_OBJECTS = \
"CMakeFiles/echoServer2.dir/echoServer2.cc.o"

# External object files for target echoServer2
echoServer2_EXTERNAL_OBJECTS =

bin/echoServer2: LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/echoServer2.cc.o
bin/echoServer2: LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/build.make
bin/echoServer2: LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../../bin/echoServer2"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/echoServer2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/build: bin/echoServer2
.PHONY : LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/build

LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/requires: LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/echoServer2.cc.o.requires
.PHONY : LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/requires

LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/clean:
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/tests && $(CMAKE_COMMAND) -P CMakeFiles/echoServer2.dir/cmake_clean.cmake
.PHONY : LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/clean

LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/depend:
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xiaotang/GitHub/CPPCourses /home/xiaotang/GitHub/CPPCourses/LinuxNetworkCoding/src/tests /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11 /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/tests /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : LinuxNetworkCoding/src/tests/CMakeFiles/echoServer2.dir/depend

