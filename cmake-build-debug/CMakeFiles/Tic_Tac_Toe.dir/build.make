# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/superkuo/CLionProjects/Tic Tac Toe"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/superkuo/CLionProjects/Tic Tac Toe/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Tic_Tac_Toe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tic_Tac_Toe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tic_Tac_Toe.dir/flags.make

CMakeFiles/Tic_Tac_Toe.dir/main.c.o: CMakeFiles/Tic_Tac_Toe.dir/flags.make
CMakeFiles/Tic_Tac_Toe.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/superkuo/CLionProjects/Tic Tac Toe/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Tic_Tac_Toe.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tic_Tac_Toe.dir/main.c.o   -c "/Users/superkuo/CLionProjects/Tic Tac Toe/main.c"

CMakeFiles/Tic_Tac_Toe.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tic_Tac_Toe.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/superkuo/CLionProjects/Tic Tac Toe/main.c" > CMakeFiles/Tic_Tac_Toe.dir/main.c.i

CMakeFiles/Tic_Tac_Toe.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tic_Tac_Toe.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/superkuo/CLionProjects/Tic Tac Toe/main.c" -o CMakeFiles/Tic_Tac_Toe.dir/main.c.s

CMakeFiles/Tic_Tac_Toe.dir/main.c.o.requires:

.PHONY : CMakeFiles/Tic_Tac_Toe.dir/main.c.o.requires

CMakeFiles/Tic_Tac_Toe.dir/main.c.o.provides: CMakeFiles/Tic_Tac_Toe.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Tic_Tac_Toe.dir/build.make CMakeFiles/Tic_Tac_Toe.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Tic_Tac_Toe.dir/main.c.o.provides

CMakeFiles/Tic_Tac_Toe.dir/main.c.o.provides.build: CMakeFiles/Tic_Tac_Toe.dir/main.c.o


CMakeFiles/Tic_Tac_Toe.dir/TTTFunctions.c.o: CMakeFiles/Tic_Tac_Toe.dir/flags.make
CMakeFiles/Tic_Tac_Toe.dir/TTTFunctions.c.o: ../TTTFunctions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/superkuo/CLionProjects/Tic Tac Toe/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Tic_Tac_Toe.dir/TTTFunctions.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Tic_Tac_Toe.dir/TTTFunctions.c.o   -c "/Users/superkuo/CLionProjects/Tic Tac Toe/TTTFunctions.c"

CMakeFiles/Tic_Tac_Toe.dir/TTTFunctions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Tic_Tac_Toe.dir/TTTFunctions.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/superkuo/CLionProjects/Tic Tac Toe/TTTFunctions.c" > CMakeFiles/Tic_Tac_Toe.dir/TTTFunctions.c.i

CMakeFiles/Tic_Tac_Toe.dir/TTTFunctions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Tic_Tac_Toe.dir/TTTFunctions.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/superkuo/CLionProjects/Tic Tac Toe/TTTFunctions.c" -o CMakeFiles/Tic_Tac_Toe.dir/TTTFunctions.c.s

CMakeFiles/Tic_Tac_Toe.dir/TTTFunctions.c.o.requires:

.PHONY : CMakeFiles/Tic_Tac_Toe.dir/TTTFunctions.c.o.requires

CMakeFiles/Tic_Tac_Toe.dir/TTTFunctions.c.o.provides: CMakeFiles/Tic_Tac_Toe.dir/TTTFunctions.c.o.requires
	$(MAKE) -f CMakeFiles/Tic_Tac_Toe.dir/build.make CMakeFiles/Tic_Tac_Toe.dir/TTTFunctions.c.o.provides.build
.PHONY : CMakeFiles/Tic_Tac_Toe.dir/TTTFunctions.c.o.provides

CMakeFiles/Tic_Tac_Toe.dir/TTTFunctions.c.o.provides.build: CMakeFiles/Tic_Tac_Toe.dir/TTTFunctions.c.o


# Object files for target Tic_Tac_Toe
Tic_Tac_Toe_OBJECTS = \
"CMakeFiles/Tic_Tac_Toe.dir/main.c.o" \
"CMakeFiles/Tic_Tac_Toe.dir/TTTFunctions.c.o"

# External object files for target Tic_Tac_Toe
Tic_Tac_Toe_EXTERNAL_OBJECTS =

Tic_Tac_Toe: CMakeFiles/Tic_Tac_Toe.dir/main.c.o
Tic_Tac_Toe: CMakeFiles/Tic_Tac_Toe.dir/TTTFunctions.c.o
Tic_Tac_Toe: CMakeFiles/Tic_Tac_Toe.dir/build.make
Tic_Tac_Toe: CMakeFiles/Tic_Tac_Toe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/superkuo/CLionProjects/Tic Tac Toe/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Tic_Tac_Toe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tic_Tac_Toe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tic_Tac_Toe.dir/build: Tic_Tac_Toe

.PHONY : CMakeFiles/Tic_Tac_Toe.dir/build

CMakeFiles/Tic_Tac_Toe.dir/requires: CMakeFiles/Tic_Tac_Toe.dir/main.c.o.requires
CMakeFiles/Tic_Tac_Toe.dir/requires: CMakeFiles/Tic_Tac_Toe.dir/TTTFunctions.c.o.requires

.PHONY : CMakeFiles/Tic_Tac_Toe.dir/requires

CMakeFiles/Tic_Tac_Toe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tic_Tac_Toe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tic_Tac_Toe.dir/clean

CMakeFiles/Tic_Tac_Toe.dir/depend:
	cd "/Users/superkuo/CLionProjects/Tic Tac Toe/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/superkuo/CLionProjects/Tic Tac Toe" "/Users/superkuo/CLionProjects/Tic Tac Toe" "/Users/superkuo/CLionProjects/Tic Tac Toe/cmake-build-debug" "/Users/superkuo/CLionProjects/Tic Tac Toe/cmake-build-debug" "/Users/superkuo/CLionProjects/Tic Tac Toe/cmake-build-debug/CMakeFiles/Tic_Tac_Toe.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Tic_Tac_Toe.dir/depend

