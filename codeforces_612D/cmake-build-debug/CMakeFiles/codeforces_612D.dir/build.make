# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /home/mental/下载/clion-2017.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/mental/下载/clion-2017.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mental/ACM/codeforces_612D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mental/ACM/codeforces_612D/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/codeforces_612D.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/codeforces_612D.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/codeforces_612D.dir/flags.make

CMakeFiles/codeforces_612D.dir/main.cpp.o: CMakeFiles/codeforces_612D.dir/flags.make
CMakeFiles/codeforces_612D.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mental/ACM/codeforces_612D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/codeforces_612D.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/codeforces_612D.dir/main.cpp.o -c /home/mental/ACM/codeforces_612D/main.cpp

CMakeFiles/codeforces_612D.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/codeforces_612D.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mental/ACM/codeforces_612D/main.cpp > CMakeFiles/codeforces_612D.dir/main.cpp.i

CMakeFiles/codeforces_612D.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/codeforces_612D.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mental/ACM/codeforces_612D/main.cpp -o CMakeFiles/codeforces_612D.dir/main.cpp.s

CMakeFiles/codeforces_612D.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/codeforces_612D.dir/main.cpp.o.requires

CMakeFiles/codeforces_612D.dir/main.cpp.o.provides: CMakeFiles/codeforces_612D.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/codeforces_612D.dir/build.make CMakeFiles/codeforces_612D.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/codeforces_612D.dir/main.cpp.o.provides

CMakeFiles/codeforces_612D.dir/main.cpp.o.provides.build: CMakeFiles/codeforces_612D.dir/main.cpp.o


# Object files for target codeforces_612D
codeforces_612D_OBJECTS = \
"CMakeFiles/codeforces_612D.dir/main.cpp.o"

# External object files for target codeforces_612D
codeforces_612D_EXTERNAL_OBJECTS =

codeforces_612D: CMakeFiles/codeforces_612D.dir/main.cpp.o
codeforces_612D: CMakeFiles/codeforces_612D.dir/build.make
codeforces_612D: CMakeFiles/codeforces_612D.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mental/ACM/codeforces_612D/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable codeforces_612D"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/codeforces_612D.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/codeforces_612D.dir/build: codeforces_612D

.PHONY : CMakeFiles/codeforces_612D.dir/build

CMakeFiles/codeforces_612D.dir/requires: CMakeFiles/codeforces_612D.dir/main.cpp.o.requires

.PHONY : CMakeFiles/codeforces_612D.dir/requires

CMakeFiles/codeforces_612D.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/codeforces_612D.dir/cmake_clean.cmake
.PHONY : CMakeFiles/codeforces_612D.dir/clean

CMakeFiles/codeforces_612D.dir/depend:
	cd /home/mental/ACM/codeforces_612D/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mental/ACM/codeforces_612D /home/mental/ACM/codeforces_612D /home/mental/ACM/codeforces_612D/cmake-build-debug /home/mental/ACM/codeforces_612D/cmake-build-debug /home/mental/ACM/codeforces_612D/cmake-build-debug/CMakeFiles/codeforces_612D.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/codeforces_612D.dir/depend

