# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.9.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.9.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Rmbp_Nathan/Documents/Github/var/n-Algorithm/Chapter2/MergeSort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Rmbp_Nathan/Documents/Github/var/n-Algorithm/Chapter2/MergeSort/build

# Include any dependencies generated for this target.
include CMakeFiles/merge_sort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/merge_sort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/merge_sort.dir/flags.make

CMakeFiles/merge_sort.dir/merge_sort.cpp.o: CMakeFiles/merge_sort.dir/flags.make
CMakeFiles/merge_sort.dir/merge_sort.cpp.o: ../merge_sort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Rmbp_Nathan/Documents/Github/var/n-Algorithm/Chapter2/MergeSort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/merge_sort.dir/merge_sort.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/merge_sort.dir/merge_sort.cpp.o -c /Users/Rmbp_Nathan/Documents/Github/var/n-Algorithm/Chapter2/MergeSort/merge_sort.cpp

CMakeFiles/merge_sort.dir/merge_sort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/merge_sort.dir/merge_sort.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Rmbp_Nathan/Documents/Github/var/n-Algorithm/Chapter2/MergeSort/merge_sort.cpp > CMakeFiles/merge_sort.dir/merge_sort.cpp.i

CMakeFiles/merge_sort.dir/merge_sort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/merge_sort.dir/merge_sort.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Rmbp_Nathan/Documents/Github/var/n-Algorithm/Chapter2/MergeSort/merge_sort.cpp -o CMakeFiles/merge_sort.dir/merge_sort.cpp.s

CMakeFiles/merge_sort.dir/merge_sort.cpp.o.requires:

.PHONY : CMakeFiles/merge_sort.dir/merge_sort.cpp.o.requires

CMakeFiles/merge_sort.dir/merge_sort.cpp.o.provides: CMakeFiles/merge_sort.dir/merge_sort.cpp.o.requires
	$(MAKE) -f CMakeFiles/merge_sort.dir/build.make CMakeFiles/merge_sort.dir/merge_sort.cpp.o.provides.build
.PHONY : CMakeFiles/merge_sort.dir/merge_sort.cpp.o.provides

CMakeFiles/merge_sort.dir/merge_sort.cpp.o.provides.build: CMakeFiles/merge_sort.dir/merge_sort.cpp.o


# Object files for target merge_sort
merge_sort_OBJECTS = \
"CMakeFiles/merge_sort.dir/merge_sort.cpp.o"

# External object files for target merge_sort
merge_sort_EXTERNAL_OBJECTS =

../bin/merge_sort: CMakeFiles/merge_sort.dir/merge_sort.cpp.o
../bin/merge_sort: CMakeFiles/merge_sort.dir/build.make
../bin/merge_sort: CMakeFiles/merge_sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Rmbp_Nathan/Documents/Github/var/n-Algorithm/Chapter2/MergeSort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/merge_sort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/merge_sort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/merge_sort.dir/build: ../bin/merge_sort

.PHONY : CMakeFiles/merge_sort.dir/build

CMakeFiles/merge_sort.dir/requires: CMakeFiles/merge_sort.dir/merge_sort.cpp.o.requires

.PHONY : CMakeFiles/merge_sort.dir/requires

CMakeFiles/merge_sort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/merge_sort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/merge_sort.dir/clean

CMakeFiles/merge_sort.dir/depend:
	cd /Users/Rmbp_Nathan/Documents/Github/var/n-Algorithm/Chapter2/MergeSort/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Rmbp_Nathan/Documents/Github/var/n-Algorithm/Chapter2/MergeSort /Users/Rmbp_Nathan/Documents/Github/var/n-Algorithm/Chapter2/MergeSort /Users/Rmbp_Nathan/Documents/Github/var/n-Algorithm/Chapter2/MergeSort/build /Users/Rmbp_Nathan/Documents/Github/var/n-Algorithm/Chapter2/MergeSort/build /Users/Rmbp_Nathan/Documents/Github/var/n-Algorithm/Chapter2/MergeSort/build/CMakeFiles/merge_sort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/merge_sort.dir/depend

