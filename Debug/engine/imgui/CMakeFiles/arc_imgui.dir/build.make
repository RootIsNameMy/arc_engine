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
include engine/imgui/CMakeFiles/arc_imgui.dir/depend.make

# Include the progress variables for this target.
include engine/imgui/CMakeFiles/arc_imgui.dir/progress.make

# Include the compile flags for this target's objects.
include engine/imgui/CMakeFiles/arc_imgui.dir/flags.make

engine/imgui/CMakeFiles/arc_imgui.dir/src/imgui_layer.cpp.o: engine/imgui/CMakeFiles/arc_imgui.dir/flags.make
engine/imgui/CMakeFiles/arc_imgui.dir/src/imgui_layer.cpp.o: ../engine/imgui/src/imgui_layer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object engine/imgui/CMakeFiles/arc_imgui.dir/src/imgui_layer.cpp.o"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arc_imgui.dir/src/imgui_layer.cpp.o -c /home/tilen/Projects/feri/URG/vaja01/arc_engine/engine/imgui/src/imgui_layer.cpp

engine/imgui/CMakeFiles/arc_imgui.dir/src/imgui_layer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arc_imgui.dir/src/imgui_layer.cpp.i"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tilen/Projects/feri/URG/vaja01/arc_engine/engine/imgui/src/imgui_layer.cpp > CMakeFiles/arc_imgui.dir/src/imgui_layer.cpp.i

engine/imgui/CMakeFiles/arc_imgui.dir/src/imgui_layer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arc_imgui.dir/src/imgui_layer.cpp.s"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tilen/Projects/feri/URG/vaja01/arc_engine/engine/imgui/src/imgui_layer.cpp -o CMakeFiles/arc_imgui.dir/src/imgui_layer.cpp.s

engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/backends/imgui_impl_glfw.cpp.o: engine/imgui/CMakeFiles/arc_imgui.dir/flags.make
engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/backends/imgui_impl_glfw.cpp.o: ../external/imgui/imgui/backends/imgui_impl_glfw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/backends/imgui_impl_glfw.cpp.o"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/backends/imgui_impl_glfw.cpp.o -c /home/tilen/Projects/feri/URG/vaja01/arc_engine/external/imgui/imgui/backends/imgui_impl_glfw.cpp

engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/backends/imgui_impl_glfw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/backends/imgui_impl_glfw.cpp.i"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tilen/Projects/feri/URG/vaja01/arc_engine/external/imgui/imgui/backends/imgui_impl_glfw.cpp > CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/backends/imgui_impl_glfw.cpp.i

engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/backends/imgui_impl_glfw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/backends/imgui_impl_glfw.cpp.s"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tilen/Projects/feri/URG/vaja01/arc_engine/external/imgui/imgui/backends/imgui_impl_glfw.cpp -o CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/backends/imgui_impl_glfw.cpp.s

engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/backends/imgui_impl_opengl3.cpp.o: engine/imgui/CMakeFiles/arc_imgui.dir/flags.make
engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/backends/imgui_impl_opengl3.cpp.o: ../external/imgui/imgui/backends/imgui_impl_opengl3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/backends/imgui_impl_opengl3.cpp.o"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/backends/imgui_impl_opengl3.cpp.o -c /home/tilen/Projects/feri/URG/vaja01/arc_engine/external/imgui/imgui/backends/imgui_impl_opengl3.cpp

engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/backends/imgui_impl_opengl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/backends/imgui_impl_opengl3.cpp.i"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tilen/Projects/feri/URG/vaja01/arc_engine/external/imgui/imgui/backends/imgui_impl_opengl3.cpp > CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/backends/imgui_impl_opengl3.cpp.i

engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/backends/imgui_impl_opengl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/backends/imgui_impl_opengl3.cpp.s"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tilen/Projects/feri/URG/vaja01/arc_engine/external/imgui/imgui/backends/imgui_impl_opengl3.cpp -o CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/backends/imgui_impl_opengl3.cpp.s

engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_draw.cpp.o: engine/imgui/CMakeFiles/arc_imgui.dir/flags.make
engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_draw.cpp.o: ../external/imgui/imgui/imgui_draw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_draw.cpp.o"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_draw.cpp.o -c /home/tilen/Projects/feri/URG/vaja01/arc_engine/external/imgui/imgui/imgui_draw.cpp

engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_draw.cpp.i"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tilen/Projects/feri/URG/vaja01/arc_engine/external/imgui/imgui/imgui_draw.cpp > CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_draw.cpp.i

engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_draw.cpp.s"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tilen/Projects/feri/URG/vaja01/arc_engine/external/imgui/imgui/imgui_draw.cpp -o CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_draw.cpp.s

engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_widgets.cpp.o: engine/imgui/CMakeFiles/arc_imgui.dir/flags.make
engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_widgets.cpp.o: ../external/imgui/imgui/imgui_widgets.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_widgets.cpp.o"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_widgets.cpp.o -c /home/tilen/Projects/feri/URG/vaja01/arc_engine/external/imgui/imgui/imgui_widgets.cpp

engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_widgets.cpp.i"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tilen/Projects/feri/URG/vaja01/arc_engine/external/imgui/imgui/imgui_widgets.cpp > CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_widgets.cpp.i

engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_widgets.cpp.s"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tilen/Projects/feri/URG/vaja01/arc_engine/external/imgui/imgui/imgui_widgets.cpp -o CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_widgets.cpp.s

engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_tables.cpp.o: engine/imgui/CMakeFiles/arc_imgui.dir/flags.make
engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_tables.cpp.o: ../external/imgui/imgui/imgui_tables.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_tables.cpp.o"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_tables.cpp.o -c /home/tilen/Projects/feri/URG/vaja01/arc_engine/external/imgui/imgui/imgui_tables.cpp

engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_tables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_tables.cpp.i"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tilen/Projects/feri/URG/vaja01/arc_engine/external/imgui/imgui/imgui_tables.cpp > CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_tables.cpp.i

engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_tables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_tables.cpp.s"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tilen/Projects/feri/URG/vaja01/arc_engine/external/imgui/imgui/imgui_tables.cpp -o CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_tables.cpp.s

engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui.cpp.o: engine/imgui/CMakeFiles/arc_imgui.dir/flags.make
engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui.cpp.o: ../external/imgui/imgui/imgui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui.cpp.o"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui.cpp.o -c /home/tilen/Projects/feri/URG/vaja01/arc_engine/external/imgui/imgui/imgui.cpp

engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui.cpp.i"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tilen/Projects/feri/URG/vaja01/arc_engine/external/imgui/imgui/imgui.cpp > CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui.cpp.i

engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui.cpp.s"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tilen/Projects/feri/URG/vaja01/arc_engine/external/imgui/imgui/imgui.cpp -o CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui.cpp.s

engine/imgui/CMakeFiles/arc_imgui.dir/__/log/src/log.cpp.o: engine/imgui/CMakeFiles/arc_imgui.dir/flags.make
engine/imgui/CMakeFiles/arc_imgui.dir/__/log/src/log.cpp.o: ../engine/log/src/log.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object engine/imgui/CMakeFiles/arc_imgui.dir/__/log/src/log.cpp.o"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arc_imgui.dir/__/log/src/log.cpp.o -c /home/tilen/Projects/feri/URG/vaja01/arc_engine/engine/log/src/log.cpp

engine/imgui/CMakeFiles/arc_imgui.dir/__/log/src/log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arc_imgui.dir/__/log/src/log.cpp.i"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tilen/Projects/feri/URG/vaja01/arc_engine/engine/log/src/log.cpp > CMakeFiles/arc_imgui.dir/__/log/src/log.cpp.i

engine/imgui/CMakeFiles/arc_imgui.dir/__/log/src/log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arc_imgui.dir/__/log/src/log.cpp.s"
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tilen/Projects/feri/URG/vaja01/arc_engine/engine/log/src/log.cpp -o CMakeFiles/arc_imgui.dir/__/log/src/log.cpp.s

arc_imgui: engine/imgui/CMakeFiles/arc_imgui.dir/src/imgui_layer.cpp.o
arc_imgui: engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/backends/imgui_impl_glfw.cpp.o
arc_imgui: engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/backends/imgui_impl_opengl3.cpp.o
arc_imgui: engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_draw.cpp.o
arc_imgui: engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_widgets.cpp.o
arc_imgui: engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui_tables.cpp.o
arc_imgui: engine/imgui/CMakeFiles/arc_imgui.dir/__/__/external/imgui/imgui/imgui.cpp.o
arc_imgui: engine/imgui/CMakeFiles/arc_imgui.dir/__/log/src/log.cpp.o
arc_imgui: engine/imgui/CMakeFiles/arc_imgui.dir/build.make

.PHONY : arc_imgui

# Rule to build all files generated by this target.
engine/imgui/CMakeFiles/arc_imgui.dir/build: arc_imgui

.PHONY : engine/imgui/CMakeFiles/arc_imgui.dir/build

engine/imgui/CMakeFiles/arc_imgui.dir/clean:
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui && $(CMAKE_COMMAND) -P CMakeFiles/arc_imgui.dir/cmake_clean.cmake
.PHONY : engine/imgui/CMakeFiles/arc_imgui.dir/clean

engine/imgui/CMakeFiles/arc_imgui.dir/depend:
	cd /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tilen/Projects/feri/URG/vaja01/arc_engine /home/tilen/Projects/feri/URG/vaja01/arc_engine/engine/imgui /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui /home/tilen/Projects/feri/URG/vaja01/arc_engine/Debug/engine/imgui/CMakeFiles/arc_imgui.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : engine/imgui/CMakeFiles/arc_imgui.dir/depend

