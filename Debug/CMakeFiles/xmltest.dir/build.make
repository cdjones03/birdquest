# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Jin Park\Desktop\Bird Quest\birdquest"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Jin Park\Desktop\Bird Quest\birdquest\Debug"

# Include any dependencies generated for this target.
include CMakeFiles/xmltest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/xmltest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/xmltest.dir/flags.make

CMakeFiles/xmltest.dir/bin/xmltest.cpp.obj: CMakeFiles/xmltest.dir/flags.make
CMakeFiles/xmltest.dir/bin/xmltest.cpp.obj: CMakeFiles/xmltest.dir/includes_CXX.rsp
CMakeFiles/xmltest.dir/bin/xmltest.cpp.obj: ../bin/xmltest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Jin Park\Desktop\Bird Quest\birdquest\Debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/xmltest.dir/bin/xmltest.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\xmltest.dir\bin\xmltest.cpp.obj -c "C:\Users\Jin Park\Desktop\Bird Quest\birdquest\bin\xmltest.cpp"

CMakeFiles/xmltest.dir/bin/xmltest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xmltest.dir/bin/xmltest.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Jin Park\Desktop\Bird Quest\birdquest\bin\xmltest.cpp" > CMakeFiles\xmltest.dir\bin\xmltest.cpp.i

CMakeFiles/xmltest.dir/bin/xmltest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xmltest.dir/bin/xmltest.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Jin Park\Desktop\Bird Quest\birdquest\bin\xmltest.cpp" -o CMakeFiles\xmltest.dir\bin\xmltest.cpp.s

# Object files for target xmltest
xmltest_OBJECTS = \
"CMakeFiles/xmltest.dir/bin/xmltest.cpp.obj"

# External object files for target xmltest
xmltest_EXTERNAL_OBJECTS =

xmltest.exe: CMakeFiles/xmltest.dir/bin/xmltest.cpp.obj
xmltest.exe: CMakeFiles/xmltest.dir/build.make
xmltest.exe: C:/SFML-2.4.2/lib/libsfml-graphics-d.a
xmltest.exe: C:/SFML-2.4.2/lib/libsfml-window-d.a
xmltest.exe: C:/SFML-2.4.2/lib/libsfml-system-d.a
xmltest.exe: C:/SFML-2.4.2/lib/libsfml-audio-d.a
xmltest.exe: C:/SFML-2.4.2/lib/libsfml-network-d.a
xmltest.exe: libbirdquest_core.a
xmltest.exe: C:/SFML-2.4.2/lib/libsfml-graphics-d.a
xmltest.exe: C:/SFML-2.4.2/lib/libsfml-window-d.a
xmltest.exe: C:/SFML-2.4.2/lib/libsfml-system-d.a
xmltest.exe: C:/SFML-2.4.2/lib/libsfml-audio-d.a
xmltest.exe: C:/SFML-2.4.2/lib/libsfml-network-d.a
xmltest.exe: CMakeFiles/xmltest.dir/linklibs.rsp
xmltest.exe: CMakeFiles/xmltest.dir/objects1.rsp
xmltest.exe: CMakeFiles/xmltest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Jin Park\Desktop\Bird Quest\birdquest\Debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable xmltest.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\xmltest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/xmltest.dir/build: xmltest.exe

.PHONY : CMakeFiles/xmltest.dir/build

CMakeFiles/xmltest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\xmltest.dir\cmake_clean.cmake
.PHONY : CMakeFiles/xmltest.dir/clean

CMakeFiles/xmltest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Jin Park\Desktop\Bird Quest\birdquest" "C:\Users\Jin Park\Desktop\Bird Quest\birdquest" "C:\Users\Jin Park\Desktop\Bird Quest\birdquest\Debug" "C:\Users\Jin Park\Desktop\Bird Quest\birdquest\Debug" "C:\Users\Jin Park\Desktop\Bird Quest\birdquest\Debug\CMakeFiles\xmltest.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/xmltest.dir/depend

