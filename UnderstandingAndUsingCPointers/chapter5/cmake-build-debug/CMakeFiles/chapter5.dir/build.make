# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/JetBrains/clion-2021.1.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /usr/JetBrains/clion-2021.1.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lilin/CLionProjects/UnderstandingAndUsingCPointers/chapter5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lilin/CLionProjects/UnderstandingAndUsingCPointers/chapter5/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/chapter5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/chapter5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chapter5.dir/flags.make

CMakeFiles/chapter5.dir/main.c.o: CMakeFiles/chapter5.dir/flags.make
CMakeFiles/chapter5.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lilin/CLionProjects/UnderstandingAndUsingCPointers/chapter5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/chapter5.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/chapter5.dir/main.c.o -c /home/lilin/CLionProjects/UnderstandingAndUsingCPointers/chapter5/main.c

CMakeFiles/chapter5.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/chapter5.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lilin/CLionProjects/UnderstandingAndUsingCPointers/chapter5/main.c > CMakeFiles/chapter5.dir/main.c.i

CMakeFiles/chapter5.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/chapter5.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lilin/CLionProjects/UnderstandingAndUsingCPointers/chapter5/main.c -o CMakeFiles/chapter5.dir/main.c.s

# Object files for target chapter5
chapter5_OBJECTS = \
"CMakeFiles/chapter5.dir/main.c.o"

# External object files for target chapter5
chapter5_EXTERNAL_OBJECTS =

chapter5: CMakeFiles/chapter5.dir/main.c.o
chapter5: CMakeFiles/chapter5.dir/build.make
chapter5: CMakeFiles/chapter5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lilin/CLionProjects/UnderstandingAndUsingCPointers/chapter5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable chapter5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chapter5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chapter5.dir/build: chapter5

.PHONY : CMakeFiles/chapter5.dir/build

CMakeFiles/chapter5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chapter5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chapter5.dir/clean

CMakeFiles/chapter5.dir/depend:
	cd /home/lilin/CLionProjects/UnderstandingAndUsingCPointers/chapter5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lilin/CLionProjects/UnderstandingAndUsingCPointers/chapter5 /home/lilin/CLionProjects/UnderstandingAndUsingCPointers/chapter5 /home/lilin/CLionProjects/UnderstandingAndUsingCPointers/chapter5/cmake-build-debug /home/lilin/CLionProjects/UnderstandingAndUsingCPointers/chapter5/cmake-build-debug /home/lilin/CLionProjects/UnderstandingAndUsingCPointers/chapter5/cmake-build-debug/CMakeFiles/chapter5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chapter5.dir/depend
