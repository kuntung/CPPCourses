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
include StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/depend.make

# Include the progress variables for this target.
include StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/progress.make

# Include the compile flags for this target's objects.
include StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/flags.make

StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/testSingleton.cpp.o: StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/flags.make
StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/testSingleton.cpp.o: ../../StudyCPPWithMe/testSrc/tests/testSingleton.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/testSingleton.cpp.o"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc/tests && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/testSingleton.dir/testSingleton.cpp.o -c /home/xiaotang/GitHub/CPPCourses/StudyCPPWithMe/testSrc/tests/testSingleton.cpp

StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/testSingleton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testSingleton.dir/testSingleton.cpp.i"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc/tests && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/xiaotang/GitHub/CPPCourses/StudyCPPWithMe/testSrc/tests/testSingleton.cpp > CMakeFiles/testSingleton.dir/testSingleton.cpp.i

StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/testSingleton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testSingleton.dir/testSingleton.cpp.s"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc/tests && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/xiaotang/GitHub/CPPCourses/StudyCPPWithMe/testSrc/tests/testSingleton.cpp -o CMakeFiles/testSingleton.dir/testSingleton.cpp.s

StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/testSingleton.cpp.o.requires:
.PHONY : StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/testSingleton.cpp.o.requires

StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/testSingleton.cpp.o.provides: StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/testSingleton.cpp.o.requires
	$(MAKE) -f StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/build.make StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/testSingleton.cpp.o.provides.build
.PHONY : StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/testSingleton.cpp.o.provides

StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/testSingleton.cpp.o.provides.build: StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/testSingleton.cpp.o

# Object files for target testSingleton
testSingleton_OBJECTS = \
"CMakeFiles/testSingleton.dir/testSingleton.cpp.o"

# External object files for target testSingleton
testSingleton_EXTERNAL_OBJECTS =

bin/testSingleton: StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/testSingleton.cpp.o
bin/testSingleton: StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/build.make
bin/testSingleton: lib/libStudyCPPWithMe.a
bin/testSingleton: StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../../bin/testSingleton"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testSingleton.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/build: bin/testSingleton
.PHONY : StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/build

StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/requires: StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/testSingleton.cpp.o.requires
.PHONY : StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/requires

StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/clean:
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc/tests && $(CMAKE_COMMAND) -P CMakeFiles/testSingleton.dir/cmake_clean.cmake
.PHONY : StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/clean

StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/depend:
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xiaotang/GitHub/CPPCourses /home/xiaotang/GitHub/CPPCourses/StudyCPPWithMe/testSrc/tests /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11 /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc/tests /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : StudyCPPWithMe/testSrc/tests/CMakeFiles/testSingleton.dir/depend

