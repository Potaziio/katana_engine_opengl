# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_SOURCE_DIR = /home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test

# Include any dependencies generated for this target.
include CMakeFiles/Katana_Engine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Katana_Engine.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Katana_Engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Katana_Engine.dir/flags.make

CMakeFiles/Katana_Engine.dir/src/input.cpp.o: CMakeFiles/Katana_Engine.dir/flags.make
CMakeFiles/Katana_Engine.dir/src/input.cpp.o: src/input.cpp
CMakeFiles/Katana_Engine.dir/src/input.cpp.o: CMakeFiles/Katana_Engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Katana_Engine.dir/src/input.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Katana_Engine.dir/src/input.cpp.o -MF CMakeFiles/Katana_Engine.dir/src/input.cpp.o.d -o CMakeFiles/Katana_Engine.dir/src/input.cpp.o -c /home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test/src/input.cpp

CMakeFiles/Katana_Engine.dir/src/input.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Katana_Engine.dir/src/input.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test/src/input.cpp > CMakeFiles/Katana_Engine.dir/src/input.cpp.i

CMakeFiles/Katana_Engine.dir/src/input.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Katana_Engine.dir/src/input.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test/src/input.cpp -o CMakeFiles/Katana_Engine.dir/src/input.cpp.s

CMakeFiles/Katana_Engine.dir/src/loadshaders.cpp.o: CMakeFiles/Katana_Engine.dir/flags.make
CMakeFiles/Katana_Engine.dir/src/loadshaders.cpp.o: src/loadshaders.cpp
CMakeFiles/Katana_Engine.dir/src/loadshaders.cpp.o: CMakeFiles/Katana_Engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Katana_Engine.dir/src/loadshaders.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Katana_Engine.dir/src/loadshaders.cpp.o -MF CMakeFiles/Katana_Engine.dir/src/loadshaders.cpp.o.d -o CMakeFiles/Katana_Engine.dir/src/loadshaders.cpp.o -c /home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test/src/loadshaders.cpp

CMakeFiles/Katana_Engine.dir/src/loadshaders.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Katana_Engine.dir/src/loadshaders.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test/src/loadshaders.cpp > CMakeFiles/Katana_Engine.dir/src/loadshaders.cpp.i

CMakeFiles/Katana_Engine.dir/src/loadshaders.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Katana_Engine.dir/src/loadshaders.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test/src/loadshaders.cpp -o CMakeFiles/Katana_Engine.dir/src/loadshaders.cpp.s

CMakeFiles/Katana_Engine.dir/src/main.cpp.o: CMakeFiles/Katana_Engine.dir/flags.make
CMakeFiles/Katana_Engine.dir/src/main.cpp.o: src/main.cpp
CMakeFiles/Katana_Engine.dir/src/main.cpp.o: CMakeFiles/Katana_Engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Katana_Engine.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Katana_Engine.dir/src/main.cpp.o -MF CMakeFiles/Katana_Engine.dir/src/main.cpp.o.d -o CMakeFiles/Katana_Engine.dir/src/main.cpp.o -c /home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test/src/main.cpp

CMakeFiles/Katana_Engine.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Katana_Engine.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test/src/main.cpp > CMakeFiles/Katana_Engine.dir/src/main.cpp.i

CMakeFiles/Katana_Engine.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Katana_Engine.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test/src/main.cpp -o CMakeFiles/Katana_Engine.dir/src/main.cpp.s

CMakeFiles/Katana_Engine.dir/src/renderwindow.cpp.o: CMakeFiles/Katana_Engine.dir/flags.make
CMakeFiles/Katana_Engine.dir/src/renderwindow.cpp.o: src/renderwindow.cpp
CMakeFiles/Katana_Engine.dir/src/renderwindow.cpp.o: CMakeFiles/Katana_Engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Katana_Engine.dir/src/renderwindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Katana_Engine.dir/src/renderwindow.cpp.o -MF CMakeFiles/Katana_Engine.dir/src/renderwindow.cpp.o.d -o CMakeFiles/Katana_Engine.dir/src/renderwindow.cpp.o -c /home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test/src/renderwindow.cpp

CMakeFiles/Katana_Engine.dir/src/renderwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Katana_Engine.dir/src/renderwindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test/src/renderwindow.cpp > CMakeFiles/Katana_Engine.dir/src/renderwindow.cpp.i

CMakeFiles/Katana_Engine.dir/src/renderwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Katana_Engine.dir/src/renderwindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test/src/renderwindow.cpp -o CMakeFiles/Katana_Engine.dir/src/renderwindow.cpp.s

CMakeFiles/Katana_Engine.dir/src/shape.cpp.o: CMakeFiles/Katana_Engine.dir/flags.make
CMakeFiles/Katana_Engine.dir/src/shape.cpp.o: src/shape.cpp
CMakeFiles/Katana_Engine.dir/src/shape.cpp.o: CMakeFiles/Katana_Engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Katana_Engine.dir/src/shape.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Katana_Engine.dir/src/shape.cpp.o -MF CMakeFiles/Katana_Engine.dir/src/shape.cpp.o.d -o CMakeFiles/Katana_Engine.dir/src/shape.cpp.o -c /home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test/src/shape.cpp

CMakeFiles/Katana_Engine.dir/src/shape.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Katana_Engine.dir/src/shape.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test/src/shape.cpp > CMakeFiles/Katana_Engine.dir/src/shape.cpp.i

CMakeFiles/Katana_Engine.dir/src/shape.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Katana_Engine.dir/src/shape.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test/src/shape.cpp -o CMakeFiles/Katana_Engine.dir/src/shape.cpp.s

# Object files for target Katana_Engine
Katana_Engine_OBJECTS = \
"CMakeFiles/Katana_Engine.dir/src/input.cpp.o" \
"CMakeFiles/Katana_Engine.dir/src/loadshaders.cpp.o" \
"CMakeFiles/Katana_Engine.dir/src/main.cpp.o" \
"CMakeFiles/Katana_Engine.dir/src/renderwindow.cpp.o" \
"CMakeFiles/Katana_Engine.dir/src/shape.cpp.o"

# External object files for target Katana_Engine
Katana_Engine_EXTERNAL_OBJECTS =

Katana_Engine: CMakeFiles/Katana_Engine.dir/src/input.cpp.o
Katana_Engine: CMakeFiles/Katana_Engine.dir/src/loadshaders.cpp.o
Katana_Engine: CMakeFiles/Katana_Engine.dir/src/main.cpp.o
Katana_Engine: CMakeFiles/Katana_Engine.dir/src/renderwindow.cpp.o
Katana_Engine: CMakeFiles/Katana_Engine.dir/src/shape.cpp.o
Katana_Engine: CMakeFiles/Katana_Engine.dir/build.make
Katana_Engine: libimgui.a
Katana_Engine: /usr/lib/libglfw.so.3.3
Katana_Engine: CMakeFiles/Katana_Engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Katana_Engine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Katana_Engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Katana_Engine.dir/build: Katana_Engine
.PHONY : CMakeFiles/Katana_Engine.dir/build

CMakeFiles/Katana_Engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Katana_Engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Katana_Engine.dir/clean

CMakeFiles/Katana_Engine.dir/depend:
	cd /home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test /home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test /home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test /home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test /home/potaziio-i3/Desktop/Coding/cpp-coding/opengl-sdl2-projects/first-test/CMakeFiles/Katana_Engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Katana_Engine.dir/depend
