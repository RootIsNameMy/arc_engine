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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tilen/Projects/feri/URG/vaja01/arc_engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug

# Include any dependencies generated for this target.
include engine/log/CMakeFiles/arc_log.dir/depend.make

# Include the progress variables for this target.
include engine/log/CMakeFiles/arc_log.dir/progress.make

# Include the compile flags for this target's objects.
include engine/log/CMakeFiles/arc_log.dir/flags.make

engine/log/CMakeFiles/arc_log.dir/src/log.cpp.o: engine/log/CMakeFiles/arc_log.dir/flags.make
engine/log/CMakeFiles/arc_log.dir/src/log.cpp.o: ../engine/log/src/log.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object engine/log/CMakeFiles/arc_log.dir/src/log.cpp.o"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/log && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arc_log.dir/src/log.cpp.o -c /home/tilen/Projects/feri/URG/vaja01/arc_engine/engine/log/src/log.cpp

engine/log/CMakeFiles/arc_log.dir/src/log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arc_log.dir/src/log.cpp.i"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/log && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tilen/Projects/feri/URG/vaja01/arc_engine/engine/log/src/log.cpp > CMakeFiles/arc_log.dir/src/log.cpp.i

engine/log/CMakeFiles/arc_log.dir/src/log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arc_log.dir/src/log.cpp.s"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/log && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tilen/Projects/feri/URG/vaja01/arc_engine/engine/log/src/log.cpp -o CMakeFiles/arc_log.dir/src/log.cpp.s

# Object files for target arc_log
arc_log_OBJECTS = \
"CMakeFiles/arc_log.dir/src/log.cpp.o"

# External object files for target arc_log
arc_log_EXTERNAL_OBJECTS =

engine/log/libarc_log.a: engine/log/CMakeFiles/arc_log.dir/src/log.cpp.o
engine/log/libarc_log.a: engine/log/CMakeFiles/arc_log.dir/build.make
engine/log/libarc_log.a: engine/log/CMakeFiles/arc_log.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libarc_log.a"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/log && $(CMAKE_COMMAND) -P CMakeFiles/arc_log.dir/cmake_clean_target.cmake
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/log && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arc_log.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
engine/log/CMakeFiles/arc_log.dir/build: engine/log/libarc_log.a

.PHONY : engine/log/CMakeFiles/arc_log.dir/build

engine/log/CMakeFiles/arc_log.dir/clean:
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/log && $(CMAKE_COMMAND) -P CMakeFiles/arc_log.dir/cmake_clean.cmake
.PHONY : engine/log/CMakeFiles/arc_log.dir/clean

engine/log/CMakeFiles/arc_log.dir/depend:
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tilen/Projects/feri/URG/vaja01/arc_engine /home/tilen/Projects/feri/URG/vaja01/arc_engine/engine/log /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/log /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/log/CMakeFiles/arc_log.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : engine/log/CMakeFiles/arc_log.dir/depend
