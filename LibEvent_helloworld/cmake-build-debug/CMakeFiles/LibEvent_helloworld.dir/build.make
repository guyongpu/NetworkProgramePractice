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
CMAKE_COMMAND = /home/yongpu/Software/clion-2019.3.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/yongpu/Software/clion-2019.3.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yongpu/NetCode/LibEvent_helloworld

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yongpu/NetCode/LibEvent_helloworld/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LibEvent_helloworld.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LibEvent_helloworld.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LibEvent_helloworld.dir/flags.make

CMakeFiles/LibEvent_helloworld.dir/main.cpp.o: CMakeFiles/LibEvent_helloworld.dir/flags.make
CMakeFiles/LibEvent_helloworld.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yongpu/NetCode/LibEvent_helloworld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LibEvent_helloworld.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LibEvent_helloworld.dir/main.cpp.o -c /home/yongpu/NetCode/LibEvent_helloworld/main.cpp

CMakeFiles/LibEvent_helloworld.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LibEvent_helloworld.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yongpu/NetCode/LibEvent_helloworld/main.cpp > CMakeFiles/LibEvent_helloworld.dir/main.cpp.i

CMakeFiles/LibEvent_helloworld.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LibEvent_helloworld.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yongpu/NetCode/LibEvent_helloworld/main.cpp -o CMakeFiles/LibEvent_helloworld.dir/main.cpp.s

# Object files for target LibEvent_helloworld
LibEvent_helloworld_OBJECTS = \
"CMakeFiles/LibEvent_helloworld.dir/main.cpp.o"

# External object files for target LibEvent_helloworld
LibEvent_helloworld_EXTERNAL_OBJECTS =

LibEvent_helloworld: CMakeFiles/LibEvent_helloworld.dir/main.cpp.o
LibEvent_helloworld: CMakeFiles/LibEvent_helloworld.dir/build.make
LibEvent_helloworld: CMakeFiles/LibEvent_helloworld.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yongpu/NetCode/LibEvent_helloworld/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LibEvent_helloworld"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LibEvent_helloworld.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LibEvent_helloworld.dir/build: LibEvent_helloworld

.PHONY : CMakeFiles/LibEvent_helloworld.dir/build

CMakeFiles/LibEvent_helloworld.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LibEvent_helloworld.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LibEvent_helloworld.dir/clean

CMakeFiles/LibEvent_helloworld.dir/depend:
	cd /home/yongpu/NetCode/LibEvent_helloworld/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yongpu/NetCode/LibEvent_helloworld /home/yongpu/NetCode/LibEvent_helloworld /home/yongpu/NetCode/LibEvent_helloworld/cmake-build-debug /home/yongpu/NetCode/LibEvent_helloworld/cmake-build-debug /home/yongpu/NetCode/LibEvent_helloworld/cmake-build-debug/CMakeFiles/LibEvent_helloworld.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LibEvent_helloworld.dir/depend
