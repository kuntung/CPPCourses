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
include LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/depend.make

# Include the progress variables for this target.
include LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/progress.make

# Include the compile flags for this target's objects.
include LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/flags.make

LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/msgGet.cpp.o: LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/flags.make
LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/msgGet.cpp.o: ../../LinuxNetworkCoding/src/IPC/msgGet.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/msgGet.cpp.o"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/IPC && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/msgGet.dir/msgGet.cpp.o -c /home/xiaotang/GitHub/CPPCourses/LinuxNetworkCoding/src/IPC/msgGet.cpp

LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/msgGet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/msgGet.dir/msgGet.cpp.i"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/IPC && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/xiaotang/GitHub/CPPCourses/LinuxNetworkCoding/src/IPC/msgGet.cpp > CMakeFiles/msgGet.dir/msgGet.cpp.i

LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/msgGet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/msgGet.dir/msgGet.cpp.s"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/IPC && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/xiaotang/GitHub/CPPCourses/LinuxNetworkCoding/src/IPC/msgGet.cpp -o CMakeFiles/msgGet.dir/msgGet.cpp.s

LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/msgGet.cpp.o.requires:
.PHONY : LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/msgGet.cpp.o.requires

LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/msgGet.cpp.o.provides: LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/msgGet.cpp.o.requires
	$(MAKE) -f LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/build.make LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/msgGet.cpp.o.provides.build
.PHONY : LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/msgGet.cpp.o.provides

LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/msgGet.cpp.o.provides.build: LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/msgGet.cpp.o

# Object files for target msgGet
msgGet_OBJECTS = \
"CMakeFiles/msgGet.dir/msgGet.cpp.o"

# External object files for target msgGet
msgGet_EXTERNAL_OBJECTS =

bin/msgGet: LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/msgGet.cpp.o
bin/msgGet: LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/build.make
bin/msgGet: LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../../bin/msgGet"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/IPC && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/msgGet.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/build: bin/msgGet
.PHONY : LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/build

LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/requires: LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/msgGet.cpp.o.requires
.PHONY : LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/requires

LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/clean:
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/IPC && $(CMAKE_COMMAND) -P CMakeFiles/msgGet.dir/cmake_clean.cmake
.PHONY : LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/clean

LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/depend:
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xiaotang/GitHub/CPPCourses /home/xiaotang/GitHub/CPPCourses/LinuxNetworkCoding/src/IPC /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11 /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/IPC /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : LinuxNetworkCoding/src/IPC/CMakeFiles/msgGet.dir/depend
