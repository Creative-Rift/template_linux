# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/maxime/Repo_Tek/CreativeRift/template_linux

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maxime/Repo_Tek/CreativeRift/template_linux/Build

# Include any dependencies generated for this target.
include CMakeFiles/project.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/project.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project.dir/flags.make

CMakeFiles/project.dir/Project/sources/main.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/Project/sources/main.cpp.o: ../Project/sources/main.cpp
CMakeFiles/project.dir/Project/sources/main.cpp.o: CMakeFiles/project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maxime/Repo_Tek/CreativeRift/template_linux/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project.dir/Project/sources/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project.dir/Project/sources/main.cpp.o -MF CMakeFiles/project.dir/Project/sources/main.cpp.o.d -o CMakeFiles/project.dir/Project/sources/main.cpp.o -c /home/maxime/Repo_Tek/CreativeRift/template_linux/Project/sources/main.cpp

CMakeFiles/project.dir/Project/sources/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/Project/sources/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maxime/Repo_Tek/CreativeRift/template_linux/Project/sources/main.cpp > CMakeFiles/project.dir/Project/sources/main.cpp.i

CMakeFiles/project.dir/Project/sources/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/Project/sources/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maxime/Repo_Tek/CreativeRift/template_linux/Project/sources/main.cpp -o CMakeFiles/project.dir/Project/sources/main.cpp.s

CMakeFiles/project.dir/Project/sources/scenes/Main.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/Project/sources/scenes/Main.cpp.o: ../Project/sources/scenes/Main.cpp
CMakeFiles/project.dir/Project/sources/scenes/Main.cpp.o: CMakeFiles/project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maxime/Repo_Tek/CreativeRift/template_linux/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project.dir/Project/sources/scenes/Main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project.dir/Project/sources/scenes/Main.cpp.o -MF CMakeFiles/project.dir/Project/sources/scenes/Main.cpp.o.d -o CMakeFiles/project.dir/Project/sources/scenes/Main.cpp.o -c /home/maxime/Repo_Tek/CreativeRift/template_linux/Project/sources/scenes/Main.cpp

CMakeFiles/project.dir/Project/sources/scenes/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/Project/sources/scenes/Main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maxime/Repo_Tek/CreativeRift/template_linux/Project/sources/scenes/Main.cpp > CMakeFiles/project.dir/Project/sources/scenes/Main.cpp.i

CMakeFiles/project.dir/Project/sources/scenes/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/Project/sources/scenes/Main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maxime/Repo_Tek/CreativeRift/template_linux/Project/sources/scenes/Main.cpp -o CMakeFiles/project.dir/Project/sources/scenes/Main.cpp.s

# Object files for target project
project_OBJECTS = \
"CMakeFiles/project.dir/Project/sources/main.cpp.o" \
"CMakeFiles/project.dir/Project/sources/scenes/Main.cpp.o"

# External object files for target project
project_EXTERNAL_OBJECTS =

out/project: CMakeFiles/project.dir/Project/sources/main.cpp.o
out/project: CMakeFiles/project.dir/Project/sources/scenes/Main.cpp.o
out/project: CMakeFiles/project.dir/build.make
out/project: ../Engine/libJsnp.so
out/project: ../Engine/libSWEngine-Core.so
out/project: ../Engine/libyaml-cpp.so
out/project: ../Engine/libSWEngine-SfmlModule.so
out/project: ../Engine/libsfml-audio.so
out/project: ../Engine/libsfml-graphics.so
out/project: ../Engine/libsfml-system.so
out/project: ../Engine/libsfml-window.so
out/project: CMakeFiles/project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maxime/Repo_Tek/CreativeRift/template_linux/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable out/project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project.dir/build: out/project
.PHONY : CMakeFiles/project.dir/build

CMakeFiles/project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project.dir/clean

CMakeFiles/project.dir/depend:
	cd /home/maxime/Repo_Tek/CreativeRift/template_linux/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maxime/Repo_Tek/CreativeRift/template_linux /home/maxime/Repo_Tek/CreativeRift/template_linux /home/maxime/Repo_Tek/CreativeRift/template_linux/Build /home/maxime/Repo_Tek/CreativeRift/template_linux/Build /home/maxime/Repo_Tek/CreativeRift/template_linux/Build/CMakeFiles/project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project.dir/depend

