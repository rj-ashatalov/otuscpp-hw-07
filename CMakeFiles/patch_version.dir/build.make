# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/local/cmake-3.12.4/bin/cmake

# The command to remove a file.
RM = /usr/local/cmake-3.12.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/travis/build/rj-ashatalov/otuscpp-hw-07

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/travis/build/rj-ashatalov/otuscpp-hw-07

# Include any dependencies generated for this target.
include CMakeFiles/patch_version.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/patch_version.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/patch_version.dir/flags.make

CMakeFiles/patch_version.dir/lib.cpp.o: CMakeFiles/patch_version.dir/flags.make
CMakeFiles/patch_version.dir/lib.cpp.o: lib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/travis/build/rj-ashatalov/otuscpp-hw-07/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/patch_version.dir/lib.cpp.o"
	/usr/local/clang-7.0.0/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/patch_version.dir/lib.cpp.o -c /home/travis/build/rj-ashatalov/otuscpp-hw-07/lib.cpp

CMakeFiles/patch_version.dir/lib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/patch_version.dir/lib.cpp.i"
	/usr/local/clang-7.0.0/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/travis/build/rj-ashatalov/otuscpp-hw-07/lib.cpp > CMakeFiles/patch_version.dir/lib.cpp.i

CMakeFiles/patch_version.dir/lib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/patch_version.dir/lib.cpp.s"
	/usr/local/clang-7.0.0/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/travis/build/rj-ashatalov/otuscpp-hw-07/lib.cpp -o CMakeFiles/patch_version.dir/lib.cpp.s

# Object files for target patch_version
patch_version_OBJECTS = \
"CMakeFiles/patch_version.dir/lib.cpp.o"

# External object files for target patch_version
patch_version_EXTERNAL_OBJECTS =

libpatch_version.a: CMakeFiles/patch_version.dir/lib.cpp.o
libpatch_version.a: CMakeFiles/patch_version.dir/build.make
libpatch_version.a: CMakeFiles/patch_version.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/travis/build/rj-ashatalov/otuscpp-hw-07/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libpatch_version.a"
	$(CMAKE_COMMAND) -P CMakeFiles/patch_version.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/patch_version.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/patch_version.dir/build: libpatch_version.a

.PHONY : CMakeFiles/patch_version.dir/build

CMakeFiles/patch_version.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/patch_version.dir/cmake_clean.cmake
.PHONY : CMakeFiles/patch_version.dir/clean

CMakeFiles/patch_version.dir/depend:
	cd /home/travis/build/rj-ashatalov/otuscpp-hw-07 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/travis/build/rj-ashatalov/otuscpp-hw-07 /home/travis/build/rj-ashatalov/otuscpp-hw-07 /home/travis/build/rj-ashatalov/otuscpp-hw-07 /home/travis/build/rj-ashatalov/otuscpp-hw-07 /home/travis/build/rj-ashatalov/otuscpp-hw-07/CMakeFiles/patch_version.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/patch_version.dir/depend

