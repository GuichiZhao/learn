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

# Utility rule file for wasm-c-api-trap-copy-to-bin.

# Include any custom commands dependencies for this target.
include CMakeFiles/wasm-c-api-trap-copy-to-bin.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/wasm-c-api-trap-copy-to-bin.dir/progress.make

CMakeFiles/wasm-c-api-trap-copy-to-bin: wasm-c-api-trap
	/usr/bin/cmake -E make_directory /home/plusai/wabt/bin
	/usr/bin/cmake -E copy /home/plusai/wabt/build/wasm-c-api-trap /home/plusai/wabt/bin/
	/usr/bin/cmake -E copy /home/plusai/wabt/third_party/wasm-c-api/example/trap.wasm /home/plusai/wabt/build/
	/usr/bin/cmake -E copy /home/plusai/wabt/third_party/wasm-c-api/example/trap.wasm /home/plusai/wabt/bin/

wasm-c-api-trap-copy-to-bin: CMakeFiles/wasm-c-api-trap-copy-to-bin
wasm-c-api-trap-copy-to-bin: CMakeFiles/wasm-c-api-trap-copy-to-bin.dir/build.make
.PHONY : wasm-c-api-trap-copy-to-bin

# Rule to build all files generated by this target.
CMakeFiles/wasm-c-api-trap-copy-to-bin.dir/build: wasm-c-api-trap-copy-to-bin
.PHONY : CMakeFiles/wasm-c-api-trap-copy-to-bin.dir/build

CMakeFiles/wasm-c-api-trap-copy-to-bin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wasm-c-api-trap-copy-to-bin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wasm-c-api-trap-copy-to-bin.dir/clean

CMakeFiles/wasm-c-api-trap-copy-to-bin.dir/depend:
	cd /home/plusai/wabt/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/plusai/wabt /home/plusai/wabt /home/plusai/wabt/build /home/plusai/wabt/build /home/plusai/wabt/build/CMakeFiles/wasm-c-api-trap-copy-to-bin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wasm-c-api-trap-copy-to-bin.dir/depend

