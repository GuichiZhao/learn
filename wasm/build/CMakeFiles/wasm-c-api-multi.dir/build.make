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
include CMakeFiles/wasm-c-api-multi.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/wasm-c-api-multi.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/wasm-c-api-multi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wasm-c-api-multi.dir/flags.make

CMakeFiles/wasm-c-api-multi.dir/third_party/wasm-c-api/example/multi.c.o: CMakeFiles/wasm-c-api-multi.dir/flags.make
CMakeFiles/wasm-c-api-multi.dir/third_party/wasm-c-api/example/multi.c.o: ../third_party/wasm-c-api/example/multi.c
CMakeFiles/wasm-c-api-multi.dir/third_party/wasm-c-api/example/multi.c.o: CMakeFiles/wasm-c-api-multi.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/plusai/wabt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/wasm-c-api-multi.dir/third_party/wasm-c-api/example/multi.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/wasm-c-api-multi.dir/third_party/wasm-c-api/example/multi.c.o -MF CMakeFiles/wasm-c-api-multi.dir/third_party/wasm-c-api/example/multi.c.o.d -o CMakeFiles/wasm-c-api-multi.dir/third_party/wasm-c-api/example/multi.c.o -c /home/plusai/wabt/third_party/wasm-c-api/example/multi.c

CMakeFiles/wasm-c-api-multi.dir/third_party/wasm-c-api/example/multi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wasm-c-api-multi.dir/third_party/wasm-c-api/example/multi.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/plusai/wabt/third_party/wasm-c-api/example/multi.c > CMakeFiles/wasm-c-api-multi.dir/third_party/wasm-c-api/example/multi.c.i

CMakeFiles/wasm-c-api-multi.dir/third_party/wasm-c-api/example/multi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wasm-c-api-multi.dir/third_party/wasm-c-api/example/multi.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/plusai/wabt/third_party/wasm-c-api/example/multi.c -o CMakeFiles/wasm-c-api-multi.dir/third_party/wasm-c-api/example/multi.c.s

# Object files for target wasm-c-api-multi
wasm__c__api__multi_OBJECTS = \
"CMakeFiles/wasm-c-api-multi.dir/third_party/wasm-c-api/example/multi.c.o"

# External object files for target wasm-c-api-multi
wasm__c__api__multi_EXTERNAL_OBJECTS =

wasm-c-api-multi: CMakeFiles/wasm-c-api-multi.dir/third_party/wasm-c-api/example/multi.c.o
wasm-c-api-multi: CMakeFiles/wasm-c-api-multi.dir/build.make
wasm-c-api-multi: libwasm.so
wasm-c-api-multi: libwabt.a
wasm-c-api-multi: CMakeFiles/wasm-c-api-multi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/plusai/wabt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable wasm-c-api-multi"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wasm-c-api-multi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wasm-c-api-multi.dir/build: wasm-c-api-multi
.PHONY : CMakeFiles/wasm-c-api-multi.dir/build

CMakeFiles/wasm-c-api-multi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wasm-c-api-multi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wasm-c-api-multi.dir/clean

CMakeFiles/wasm-c-api-multi.dir/depend:
	cd /home/plusai/wabt/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/plusai/wabt /home/plusai/wabt /home/plusai/wabt/build /home/plusai/wabt/build /home/plusai/wabt/build/CMakeFiles/wasm-c-api-multi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wasm-c-api-multi.dir/depend

