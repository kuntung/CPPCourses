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
include LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/depend.make

# Include the progress variables for this target.
include LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/progress.make

# Include the compile flags for this target's objects.
include LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/flags.make

LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/recvMSG.cpp.o: LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/flags.make
LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/recvMSG.cpp.o: ../../LinuxNetworkCoding/src/POSIXIPC/recvMSG.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/recvMSG.cpp.o"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/POSIXIPC && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/recvMSGPMQ.dir/recvMSG.cpp.o -c /home/xiaotang/GitHub/CPPCourses/LinuxNetworkCoding/src/POSIXIPC/recvMSG.cpp

LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/recvMSG.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/recvMSGPMQ.dir/recvMSG.cpp.i"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/POSIXIPC && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/xiaotang/GitHub/CPPCourses/LinuxNetworkCoding/src/POSIXIPC/recvMSG.cpp > CMakeFiles/recvMSGPMQ.dir/recvMSG.cpp.i

LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/recvMSG.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/recvMSGPMQ.dir/recvMSG.cpp.s"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/POSIXIPC && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/xiaotang/GitHub/CPPCourses/LinuxNetworkCoding/src/POSIXIPC/recvMSG.cpp -o CMakeFiles/recvMSGPMQ.dir/recvMSG.cpp.s

LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/recvMSG.cpp.o.requires:
.PHONY : LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/recvMSG.cpp.o.requires

LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/recvMSG.cpp.o.provides: LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/recvMSG.cpp.o.requires
	$(MAKE) -f LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/build.make LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/recvMSG.cpp.o.provides.build
.PHONY : LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/recvMSG.cpp.o.provides

LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/recvMSG.cpp.o.provides.build: LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/recvMSG.cpp.o

# Object files for target recvMSGPMQ
recvMSGPMQ_OBJECTS = \
"CMakeFiles/recvMSGPMQ.dir/recvMSG.cpp.o"

# External object files for target recvMSGPMQ
recvMSGPMQ_EXTERNAL_OBJECTS =

bin/recvMSGPMQ: LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/recvMSG.cpp.o
bin/recvMSGPMQ: LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/build.make
bin/recvMSGPMQ: LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../../bin/recvMSGPMQ"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/POSIXIPC && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/recvMSGPMQ.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/build: bin/recvMSGPMQ
.PHONY : LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/build

LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/requires: LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/recvMSG.cpp.o.requires
.PHONY : LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/requires

LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/clean:
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/POSIXIPC && $(CMAKE_COMMAND) -P CMakeFiles/recvMSGPMQ.dir/cmake_clean.cmake
.PHONY : LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/clean

LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/depend:
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xiaotang/GitHub/CPPCourses /home/xiaotang/GitHub/CPPCourses/LinuxNetworkCoding/src/POSIXIPC /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11 /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/POSIXIPC /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : LinuxNetworkCoding/src/POSIXIPC/CMakeFiles/recvMSGPMQ.dir/depend
