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
CMAKE_SOURCE_DIR = /home/yongpu/NetCode/lst_timer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yongpu/NetCode/lst_timer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lst_timer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lst_timer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lst_timer.dir/flags.make

CMakeFiles/lst_timer.dir/main.cpp.o: CMakeFiles/lst_timer.dir/flags.make
CMakeFiles/lst_timer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yongpu/NetCode/lst_timer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lst_timer.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lst_timer.dir/main.cpp.o -c /home/yongpu/NetCode/lst_timer/main.cpp

CMakeFiles/lst_timer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lst_timer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yongpu/NetCode/lst_timer/main.cpp > CMakeFiles/lst_timer.dir/main.cpp.i

CMakeFiles/lst_timer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lst_timer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yongpu/NetCode/lst_timer/main.cpp -o CMakeFiles/lst_timer.dir/main.cpp.s

CMakeFiles/lst_timer.dir/sort_timer_lst.cpp.o: CMakeFiles/lst_timer.dir/flags.make
CMakeFiles/lst_timer.dir/sort_timer_lst.cpp.o: ../sort_timer_lst.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yongpu/NetCode/lst_timer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lst_timer.dir/sort_timer_lst.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lst_timer.dir/sort_timer_lst.cpp.o -c /home/yongpu/NetCode/lst_timer/sort_timer_lst.cpp

CMakeFiles/lst_timer.dir/sort_timer_lst.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lst_timer.dir/sort_timer_lst.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yongpu/NetCode/lst_timer/sort_timer_lst.cpp > CMakeFiles/lst_timer.dir/sort_timer_lst.cpp.i

CMakeFiles/lst_timer.dir/sort_timer_lst.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lst_timer.dir/sort_timer_lst.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yongpu/NetCode/lst_timer/sort_timer_lst.cpp -o CMakeFiles/lst_timer.dir/sort_timer_lst.cpp.s

CMakeFiles/lst_timer.dir/util_timer.cpp.o: CMakeFiles/lst_timer.dir/flags.make
CMakeFiles/lst_timer.dir/util_timer.cpp.o: ../util_timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yongpu/NetCode/lst_timer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lst_timer.dir/util_timer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lst_timer.dir/util_timer.cpp.o -c /home/yongpu/NetCode/lst_timer/util_timer.cpp

CMakeFiles/lst_timer.dir/util_timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lst_timer.dir/util_timer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yongpu/NetCode/lst_timer/util_timer.cpp > CMakeFiles/lst_timer.dir/util_timer.cpp.i

CMakeFiles/lst_timer.dir/util_timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lst_timer.dir/util_timer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yongpu/NetCode/lst_timer/util_timer.cpp -o CMakeFiles/lst_timer.dir/util_timer.cpp.s

CMakeFiles/lst_timer.dir/main2.cpp.o: CMakeFiles/lst_timer.dir/flags.make
CMakeFiles/lst_timer.dir/main2.cpp.o: ../main2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yongpu/NetCode/lst_timer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/lst_timer.dir/main2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lst_timer.dir/main2.cpp.o -c /home/yongpu/NetCode/lst_timer/main2.cpp

CMakeFiles/lst_timer.dir/main2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lst_timer.dir/main2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yongpu/NetCode/lst_timer/main2.cpp > CMakeFiles/lst_timer.dir/main2.cpp.i

CMakeFiles/lst_timer.dir/main2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lst_timer.dir/main2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yongpu/NetCode/lst_timer/main2.cpp -o CMakeFiles/lst_timer.dir/main2.cpp.s

# Object files for target lst_timer
lst_timer_OBJECTS = \
"CMakeFiles/lst_timer.dir/main.cpp.o" \
"CMakeFiles/lst_timer.dir/sort_timer_lst.cpp.o" \
"CMakeFiles/lst_timer.dir/util_timer.cpp.o" \
"CMakeFiles/lst_timer.dir/main2.cpp.o"

# External object files for target lst_timer
lst_timer_EXTERNAL_OBJECTS =

lst_timer: CMakeFiles/lst_timer.dir/main.cpp.o
lst_timer: CMakeFiles/lst_timer.dir/sort_timer_lst.cpp.o
lst_timer: CMakeFiles/lst_timer.dir/util_timer.cpp.o
lst_timer: CMakeFiles/lst_timer.dir/main2.cpp.o
lst_timer: CMakeFiles/lst_timer.dir/build.make
lst_timer: CMakeFiles/lst_timer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yongpu/NetCode/lst_timer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable lst_timer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lst_timer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lst_timer.dir/build: lst_timer

.PHONY : CMakeFiles/lst_timer.dir/build

CMakeFiles/lst_timer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lst_timer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lst_timer.dir/clean

CMakeFiles/lst_timer.dir/depend:
	cd /home/yongpu/NetCode/lst_timer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yongpu/NetCode/lst_timer /home/yongpu/NetCode/lst_timer /home/yongpu/NetCode/lst_timer/cmake-build-debug /home/yongpu/NetCode/lst_timer/cmake-build-debug /home/yongpu/NetCode/lst_timer/cmake-build-debug/CMakeFiles/lst_timer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lst_timer.dir/depend

