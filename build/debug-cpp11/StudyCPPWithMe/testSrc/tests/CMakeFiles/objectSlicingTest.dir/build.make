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
include StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/depend.make

# Include the progress variables for this target.
include StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/progress.make

# Include the compile flags for this target's objects.
include StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/flags.make

StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/objectSlicing.cpp.o: StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/flags.make
StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/objectSlicing.cpp.o: ../../StudyCPPWithMe/testSrc/tests/objectSlicing.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/objectSlicing.cpp.o"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc/tests && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/objectSlicingTest.dir/objectSlicing.cpp.o -c /home/xiaotang/GitHub/CPPCourses/StudyCPPWithMe/testSrc/tests/objectSlicing.cpp

StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/objectSlicing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/objectSlicingTest.dir/objectSlicing.cpp.i"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc/tests && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/xiaotang/GitHub/CPPCourses/StudyCPPWithMe/testSrc/tests/objectSlicing.cpp > CMakeFiles/objectSlicingTest.dir/objectSlicing.cpp.i

StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/objectSlicing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/objectSlicingTest.dir/objectSlicing.cpp.s"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc/tests && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/xiaotang/GitHub/CPPCourses/StudyCPPWithMe/testSrc/tests/objectSlicing.cpp -o CMakeFiles/objectSlicingTest.dir/objectSlicing.cpp.s

StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/objectSlicing.cpp.o.requires:
.PHONY : StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/objectSlicing.cpp.o.requires

StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/objectSlicing.cpp.o.provides: StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/objectSlicing.cpp.o.requires
	$(MAKE) -f StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/build.make StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/objectSlicing.cpp.o.provides.build
.PHONY : StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/objectSlicing.cpp.o.provides

StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/objectSlicing.cpp.o.provides.build: StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/objectSlicing.cpp.o

# Object files for target objectSlicingTest
objectSlicingTest_OBJECTS = \
"CMakeFiles/objectSlicingTest.dir/objectSlicing.cpp.o"

# External object files for target objectSlicingTest
objectSlicingTest_EXTERNAL_OBJECTS =

bin/objectSlicingTest: StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/objectSlicing.cpp.o
bin/objectSlicingTest: StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/build.make
bin/objectSlicingTest: StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../../bin/objectSlicingTest"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/objectSlicingTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/build: bin/objectSlicingTest
.PHONY : StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/build

StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/requires: StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/objectSlicing.cpp.o.requires
.PHONY : StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/requires

StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/clean:
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc/tests && $(CMAKE_COMMAND) -P CMakeFiles/objectSlicingTest.dir/cmake_clean.cmake
.PHONY : StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/clean

StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/depend:
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xiaotang/GitHub/CPPCourses /home/xiaotang/GitHub/CPPCourses/StudyCPPWithMe/testSrc/tests /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11 /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc/tests /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : StudyCPPWithMe/testSrc/tests/CMakeFiles/objectSlicingTest.dir/depend

