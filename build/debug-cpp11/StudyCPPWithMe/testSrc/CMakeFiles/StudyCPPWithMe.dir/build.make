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
include StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/depend.make

# Include the progress variables for this target.
include StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/progress.make

# Include the compile flags for this target's objects.
include StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/flags.make

StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Complex.cpp.o: StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/flags.make
StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Complex.cpp.o: ../../StudyCPPWithMe/testSrc/Complex.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Complex.cpp.o"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/StudyCPPWithMe.dir/Complex.cpp.o -c /home/xiaotang/GitHub/CPPCourses/StudyCPPWithMe/testSrc/Complex.cpp

StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Complex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StudyCPPWithMe.dir/Complex.cpp.i"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/xiaotang/GitHub/CPPCourses/StudyCPPWithMe/testSrc/Complex.cpp > CMakeFiles/StudyCPPWithMe.dir/Complex.cpp.i

StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Complex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StudyCPPWithMe.dir/Complex.cpp.s"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/xiaotang/GitHub/CPPCourses/StudyCPPWithMe/testSrc/Complex.cpp -o CMakeFiles/StudyCPPWithMe.dir/Complex.cpp.s

StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Complex.cpp.o.requires:
.PHONY : StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Complex.cpp.o.requires

StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Complex.cpp.o.provides: StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Complex.cpp.o.requires
	$(MAKE) -f StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/build.make StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Complex.cpp.o.provides.build
.PHONY : StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Complex.cpp.o.provides

StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Complex.cpp.o.provides.build: StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Complex.cpp.o

StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Shape.cpp.o: StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/flags.make
StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Shape.cpp.o: ../../StudyCPPWithMe/testSrc/Shape.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Shape.cpp.o"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/StudyCPPWithMe.dir/Shape.cpp.o -c /home/xiaotang/GitHub/CPPCourses/StudyCPPWithMe/testSrc/Shape.cpp

StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Shape.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StudyCPPWithMe.dir/Shape.cpp.i"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/xiaotang/GitHub/CPPCourses/StudyCPPWithMe/testSrc/Shape.cpp > CMakeFiles/StudyCPPWithMe.dir/Shape.cpp.i

StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Shape.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StudyCPPWithMe.dir/Shape.cpp.s"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/xiaotang/GitHub/CPPCourses/StudyCPPWithMe/testSrc/Shape.cpp -o CMakeFiles/StudyCPPWithMe.dir/Shape.cpp.s

StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Shape.cpp.o.requires:
.PHONY : StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Shape.cpp.o.requires

StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Shape.cpp.o.provides: StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Shape.cpp.o.requires
	$(MAKE) -f StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/build.make StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Shape.cpp.o.provides.build
.PHONY : StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Shape.cpp.o.provides

StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Shape.cpp.o.provides.build: StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Shape.cpp.o

# Object files for target StudyCPPWithMe
StudyCPPWithMe_OBJECTS = \
"CMakeFiles/StudyCPPWithMe.dir/Complex.cpp.o" \
"CMakeFiles/StudyCPPWithMe.dir/Shape.cpp.o"

# External object files for target StudyCPPWithMe
StudyCPPWithMe_EXTERNAL_OBJECTS =

lib/libStudyCPPWithMe.a: StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Complex.cpp.o
lib/libStudyCPPWithMe.a: StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Shape.cpp.o
lib/libStudyCPPWithMe.a: StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/build.make
lib/libStudyCPPWithMe.a: StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library ../../lib/libStudyCPPWithMe.a"
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc && $(CMAKE_COMMAND) -P CMakeFiles/StudyCPPWithMe.dir/cmake_clean_target.cmake
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StudyCPPWithMe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/build: lib/libStudyCPPWithMe.a
.PHONY : StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/build

StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/requires: StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Complex.cpp.o.requires
StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/requires: StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/Shape.cpp.o.requires
.PHONY : StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/requires

StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/clean:
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc && $(CMAKE_COMMAND) -P CMakeFiles/StudyCPPWithMe.dir/cmake_clean.cmake
.PHONY : StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/clean

StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/depend:
	cd /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xiaotang/GitHub/CPPCourses /home/xiaotang/GitHub/CPPCourses/StudyCPPWithMe/testSrc /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11 /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc /home/xiaotang/GitHub/CPPCourses/build/debug-cpp11/StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : StudyCPPWithMe/testSrc/CMakeFiles/StudyCPPWithMe.dir/depend

