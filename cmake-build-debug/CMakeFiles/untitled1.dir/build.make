# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\uni\untitled1\project-fsadatl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\uni\untitled1\project-fsadatl\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled1.dir/flags.make

CMakeFiles/untitled1.dir/src/main.c.obj: CMakeFiles/untitled1.dir/flags.make
CMakeFiles/untitled1.dir/src/main.c.obj: CMakeFiles/untitled1.dir/includes_C.rsp
CMakeFiles/untitled1.dir/src/main.c.obj: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\uni\untitled1\project-fsadatl\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/untitled1.dir/src/main.c.obj"
	C:\PROGRA~1\X86_64~1.0-W\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\untitled1.dir\src\main.c.obj -c D:\uni\untitled1\project-fsadatl\src\main.c

CMakeFiles/untitled1.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/untitled1.dir/src/main.c.i"
	C:\PROGRA~1\X86_64~1.0-W\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\uni\untitled1\project-fsadatl\src\main.c > CMakeFiles\untitled1.dir\src\main.c.i

CMakeFiles/untitled1.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/untitled1.dir/src/main.c.s"
	C:\PROGRA~1\X86_64~1.0-W\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\uni\untitled1\project-fsadatl\src\main.c -o CMakeFiles\untitled1.dir\src\main.c.s

# Object files for target untitled1
untitled1_OBJECTS = \
"CMakeFiles/untitled1.dir/src/main.c.obj"

# External object files for target untitled1
untitled1_EXTERNAL_OBJECTS =

untitled1.exe: CMakeFiles/untitled1.dir/src/main.c.obj
untitled1.exe: CMakeFiles/untitled1.dir/build.make
untitled1.exe: ../sdl2/sdl2-lib/libSDL2.a
untitled1.exe: ../sdl2/sdl2-lib/libSDL2main.a
untitled1.exe: ../sdl2/sdl2-gfx-lib/libsdl-gfx.a
untitled1.exe: CMakeFiles/untitled1.dir/linklibs.rsp
untitled1.exe: CMakeFiles/untitled1.dir/objects1.rsp
untitled1.exe: CMakeFiles/untitled1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\uni\untitled1\project-fsadatl\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable untitled1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\untitled1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled1.dir/build: untitled1.exe

.PHONY : CMakeFiles/untitled1.dir/build

CMakeFiles/untitled1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\untitled1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/untitled1.dir/clean

CMakeFiles/untitled1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\uni\untitled1\project-fsadatl D:\uni\untitled1\project-fsadatl D:\uni\untitled1\project-fsadatl\cmake-build-debug D:\uni\untitled1\project-fsadatl\cmake-build-debug D:\uni\untitled1\project-fsadatl\cmake-build-debug\CMakeFiles\untitled1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled1.dir/depend
