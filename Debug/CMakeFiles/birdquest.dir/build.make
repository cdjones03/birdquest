# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/chasejones/birdquest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chasejones/birdquest/Debug

# Include any dependencies generated for this target.
include CMakeFiles/birdquest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/birdquest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/birdquest.dir/flags.make

CMakeFiles/birdquest.dir/bin/birdquest.cpp.o: CMakeFiles/birdquest.dir/flags.make
CMakeFiles/birdquest.dir/bin/birdquest.cpp.o: ../bin/birdquest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chasejones/birdquest/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/birdquest.dir/bin/birdquest.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/birdquest.dir/bin/birdquest.cpp.o -c /Users/chasejones/birdquest/bin/birdquest.cpp

CMakeFiles/birdquest.dir/bin/birdquest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/birdquest.dir/bin/birdquest.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chasejones/birdquest/bin/birdquest.cpp > CMakeFiles/birdquest.dir/bin/birdquest.cpp.i

CMakeFiles/birdquest.dir/bin/birdquest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/birdquest.dir/bin/birdquest.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chasejones/birdquest/bin/birdquest.cpp -o CMakeFiles/birdquest.dir/bin/birdquest.cpp.s

# Object files for target birdquest
birdquest_OBJECTS = \
"CMakeFiles/birdquest.dir/bin/birdquest.cpp.o"

# External object files for target birdquest
birdquest_EXTERNAL_OBJECTS =

birdquest: CMakeFiles/birdquest.dir/bin/birdquest.cpp.o
birdquest: CMakeFiles/birdquest.dir/build.make
birdquest: libbirdquest_core.a
birdquest: CMakeFiles/birdquest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/chasejones/birdquest/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable birdquest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/birdquest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/birdquest.dir/build: birdquest

.PHONY : CMakeFiles/birdquest.dir/build

CMakeFiles/birdquest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/birdquest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/birdquest.dir/clean

CMakeFiles/birdquest.dir/depend:
	cd /Users/chasejones/birdquest/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chasejones/birdquest /Users/chasejones/birdquest /Users/chasejones/birdquest/Debug /Users/chasejones/birdquest/Debug /Users/chasejones/birdquest/Debug/CMakeFiles/birdquest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/birdquest.dir/depend

