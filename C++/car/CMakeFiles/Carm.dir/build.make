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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/DSchana/Documents/GitHub/Misc/C++/car

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/DSchana/Documents/GitHub/Misc/C++/car

# Include any dependencies generated for this target.
include CMakeFiles/Carm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Carm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Carm.dir/flags.make

CMakeFiles/Carm.dir/source/car.cpp.o: CMakeFiles/Carm.dir/flags.make
CMakeFiles/Carm.dir/source/car.cpp.o: source/car.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/DSchana/Documents/GitHub/Misc/C++/car/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Carm.dir/source/car.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Carm.dir/source/car.cpp.o -c /Users/DSchana/Documents/GitHub/Misc/C++/car/source/car.cpp

CMakeFiles/Carm.dir/source/car.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Carm.dir/source/car.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/DSchana/Documents/GitHub/Misc/C++/car/source/car.cpp > CMakeFiles/Carm.dir/source/car.cpp.i

CMakeFiles/Carm.dir/source/car.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Carm.dir/source/car.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/DSchana/Documents/GitHub/Misc/C++/car/source/car.cpp -o CMakeFiles/Carm.dir/source/car.cpp.s

CMakeFiles/Carm.dir/source/car.cpp.o.requires:

.PHONY : CMakeFiles/Carm.dir/source/car.cpp.o.requires

CMakeFiles/Carm.dir/source/car.cpp.o.provides: CMakeFiles/Carm.dir/source/car.cpp.o.requires
	$(MAKE) -f CMakeFiles/Carm.dir/build.make CMakeFiles/Carm.dir/source/car.cpp.o.provides.build
.PHONY : CMakeFiles/Carm.dir/source/car.cpp.o.provides

CMakeFiles/Carm.dir/source/car.cpp.o.provides.build: CMakeFiles/Carm.dir/source/car.cpp.o


CMakeFiles/Carm.dir/source/test.cpp.o: CMakeFiles/Carm.dir/flags.make
CMakeFiles/Carm.dir/source/test.cpp.o: source/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/DSchana/Documents/GitHub/Misc/C++/car/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Carm.dir/source/test.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Carm.dir/source/test.cpp.o -c /Users/DSchana/Documents/GitHub/Misc/C++/car/source/test.cpp

CMakeFiles/Carm.dir/source/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Carm.dir/source/test.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/DSchana/Documents/GitHub/Misc/C++/car/source/test.cpp > CMakeFiles/Carm.dir/source/test.cpp.i

CMakeFiles/Carm.dir/source/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Carm.dir/source/test.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/DSchana/Documents/GitHub/Misc/C++/car/source/test.cpp -o CMakeFiles/Carm.dir/source/test.cpp.s

CMakeFiles/Carm.dir/source/test.cpp.o.requires:

.PHONY : CMakeFiles/Carm.dir/source/test.cpp.o.requires

CMakeFiles/Carm.dir/source/test.cpp.o.provides: CMakeFiles/Carm.dir/source/test.cpp.o.requires
	$(MAKE) -f CMakeFiles/Carm.dir/build.make CMakeFiles/Carm.dir/source/test.cpp.o.provides.build
.PHONY : CMakeFiles/Carm.dir/source/test.cpp.o.provides

CMakeFiles/Carm.dir/source/test.cpp.o.provides.build: CMakeFiles/Carm.dir/source/test.cpp.o


# Object files for target Carm
Carm_OBJECTS = \
"CMakeFiles/Carm.dir/source/car.cpp.o" \
"CMakeFiles/Carm.dir/source/test.cpp.o"

# External object files for target Carm
Carm_EXTERNAL_OBJECTS =

Carm: CMakeFiles/Carm.dir/source/car.cpp.o
Carm: CMakeFiles/Carm.dir/source/test.cpp.o
Carm: CMakeFiles/Carm.dir/build.make
Carm: CMakeFiles/Carm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/DSchana/Documents/GitHub/Misc/C++/car/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Carm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Carm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Carm.dir/build: Carm

.PHONY : CMakeFiles/Carm.dir/build

CMakeFiles/Carm.dir/requires: CMakeFiles/Carm.dir/source/car.cpp.o.requires
CMakeFiles/Carm.dir/requires: CMakeFiles/Carm.dir/source/test.cpp.o.requires

.PHONY : CMakeFiles/Carm.dir/requires

CMakeFiles/Carm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Carm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Carm.dir/clean

CMakeFiles/Carm.dir/depend:
	cd /Users/DSchana/Documents/GitHub/Misc/C++/car && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/DSchana/Documents/GitHub/Misc/C++/car /Users/DSchana/Documents/GitHub/Misc/C++/car /Users/DSchana/Documents/GitHub/Misc/C++/car /Users/DSchana/Documents/GitHub/Misc/C++/car /Users/DSchana/Documents/GitHub/Misc/C++/car/CMakeFiles/Carm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Carm.dir/depend

