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
include LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/depend.make

# Include the progress variables for this target.
include LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/progress.make

# Include the compile flags for this target's objects.
include LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/flags.make

LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/shmfifoSend.cpp.o: LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/flags.make
LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/shmfifoSend.cpp.o: ../../LinuxNetworkCoding/shmfifo/tests/shmfifoSend.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/shmfifoSend.cpp.o"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/shmfifo/tests && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/shmfifoSend.dir/shmfifoSend.cpp.o -c /home/xiaotang/GitHub/CPPCourses/LinuxNetworkCoding/shmfifo/tests/shmfifoSend.cpp

LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/shmfifoSend.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shmfifoSend.dir/shmfifoSend.cpp.i"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/shmfifo/tests && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/xiaotang/GitHub/CPPCourses/LinuxNetworkCoding/shmfifo/tests/shmfifoSend.cpp > CMakeFiles/shmfifoSend.dir/shmfifoSend.cpp.i

LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/shmfifoSend.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shmfifoSend.dir/shmfifoSend.cpp.s"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/shmfifo/tests && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/xiaotang/GitHub/CPPCourses/LinuxNetworkCoding/shmfifo/tests/shmfifoSend.cpp -o CMakeFiles/shmfifoSend.dir/shmfifoSend.cpp.s

LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/shmfifoSend.cpp.o.requires:
.PHONY : LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/shmfifoSend.cpp.o.requires

LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/shmfifoSend.cpp.o.provides: LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/shmfifoSend.cpp.o.requires
	$(MAKE) -f LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/build.make LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/shmfifoSend.cpp.o.provides.build
.PHONY : LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/shmfifoSend.cpp.o.provides

LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/shmfifoSend.cpp.o.provides.build: LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/shmfifoSend.cpp.o

# Object files for target shmfifoSend
shmfifoSend_OBJECTS = \
"CMakeFiles/shmfifoSend.dir/shmfifoSend.cpp.o"

# External object files for target shmfifoSend
shmfifoSend_EXTERNAL_OBJECTS =

bin/shmfifoSend: LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/shmfifoSend.cpp.o
bin/shmfifoSend: LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/build.make
bin/shmfifoSend: lib/libSHMFIFO.a
bin/shmfifoSend: LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../../bin/shmfifoSend"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/shmfifo/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shmfifoSend.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/build: bin/shmfifoSend
.PHONY : LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/build

LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/requires: LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/shmfifoSend.cpp.o.requires
.PHONY : LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/requires

LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/clean:
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/shmfifo/tests && $(CMAKE_COMMAND) -P CMakeFiles/shmfifoSend.dir/cmake_clean.cmake
.PHONY : LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/clean

LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/depend:
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xiaotang/GitHub/CPPCourses /home/xiaotang/GitHub/CPPCourses/LinuxNetworkCoding/shmfifo/tests /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11 /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/shmfifo/tests /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : LinuxNetworkCoding/shmfifo/tests/CMakeFiles/shmfifoSend.dir/depend
