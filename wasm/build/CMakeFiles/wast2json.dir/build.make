# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/plusai/wabt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/plusai/wabt/build

# Include any dependencies generated for this target.
include CMakeFiles/wast2json.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/wast2json.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/wast2json.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wast2json.dir/flags.make

CMakeFiles/wast2json.dir/src/tools/wast2json.cc.o: CMakeFiles/wast2json.dir/flags.make
CMakeFiles/wast2json.dir/src/tools/wast2json.cc.o: ../src/tools/wast2json.cc
CMakeFiles/wast2json.dir/src/tools/wast2json.cc.o: CMakeFiles/wast2json.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/plusai/wabt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/wast2json.dir/src/tools/wast2json.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/wast2json.dir/src/tools/wast2json.cc.o -MF CMakeFiles/wast2json.dir/src/tools/wast2json.cc.o.d -o CMakeFiles/wast2json.dir/src/tools/wast2json.cc.o -c /home/plusai/wabt/src/tools/wast2json.cc

CMakeFiles/wast2json.dir/src/tools/wast2json.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wast2json.dir/src/tools/wast2json.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/plusai/wabt/src/tools/wast2json.cc > CMakeFiles/wast2json.dir/src/tools/wast2json.cc.i

CMakeFiles/wast2json.dir/src/tools/wast2json.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wast2json.dir/src/tools/wast2json.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/plusai/wabt/src/tools/wast2json.cc -o CMakeFiles/wast2json.dir/src/tools/wast2json.cc.s

# Object files for target wast2json
wast2json_OBJECTS = \
"CMakeFiles/wast2json.dir/src/tools/wast2json.cc.o"

# External object files for target wast2json
wast2json_EXTERNAL_OBJECTS =

wast2json: CMakeFiles/wast2json.dir/src/tools/wast2json.cc.o
wast2json: CMakeFiles/wast2json.dir/build.make
wast2json: libwabt.a
wast2json: CMakeFiles/wast2json.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/plusai/wabt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable wast2json"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wast2json.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wast2json.dir/build: wast2json
.PHONY : CMakeFiles/wast2json.dir/build

CMakeFiles/wast2json.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wast2json.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wast2json.dir/clean

CMakeFiles/wast2json.dir/depend:
	cd /home/plusai/wabt/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/plusai/wabt /home/plusai/wabt /home/plusai/wabt/build /home/plusai/wabt/build /home/plusai/wabt/build/CMakeFiles/wast2json.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wast2json.dir/depend

