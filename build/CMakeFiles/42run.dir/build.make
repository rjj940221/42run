# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /nfs/zfs-student-6/users/rojones/.brew/Cellar/cmake/3.7.0/bin/cmake

# The command to remove a file.
RM = /nfs/zfs-student-6/users/rojones/.brew/Cellar/cmake/3.7.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /nfs/zfs-student-6/users/rojones/Documents/42run

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nfs/zfs-student-6/users/rojones/Documents/42run/build

# Include any dependencies generated for this target.
include CMakeFiles/42run.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/42run.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/42run.dir/flags.make

CMakeFiles/42run.dir/src/main.cpp.o: CMakeFiles/42run.dir/flags.make
CMakeFiles/42run.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/Documents/42run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/42run.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/42run.dir/src/main.cpp.o -c /nfs/zfs-student-6/users/rojones/Documents/42run/src/main.cpp

CMakeFiles/42run.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/42run.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/zfs-student-6/users/rojones/Documents/42run/src/main.cpp > CMakeFiles/42run.dir/src/main.cpp.i

CMakeFiles/42run.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/42run.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/zfs-student-6/users/rojones/Documents/42run/src/main.cpp -o CMakeFiles/42run.dir/src/main.cpp.s

CMakeFiles/42run.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/42run.dir/src/main.cpp.o.requires

CMakeFiles/42run.dir/src/main.cpp.o.provides: CMakeFiles/42run.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/42run.dir/src/main.cpp.o.provides

CMakeFiles/42run.dir/src/main.cpp.o.provides.build: CMakeFiles/42run.dir/src/main.cpp.o


CMakeFiles/42run.dir/src/load_shader.cpp.o: CMakeFiles/42run.dir/flags.make
CMakeFiles/42run.dir/src/load_shader.cpp.o: ../src/load_shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/Documents/42run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/42run.dir/src/load_shader.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/42run.dir/src/load_shader.cpp.o -c /nfs/zfs-student-6/users/rojones/Documents/42run/src/load_shader.cpp

CMakeFiles/42run.dir/src/load_shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/42run.dir/src/load_shader.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/zfs-student-6/users/rojones/Documents/42run/src/load_shader.cpp > CMakeFiles/42run.dir/src/load_shader.cpp.i

CMakeFiles/42run.dir/src/load_shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/42run.dir/src/load_shader.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/zfs-student-6/users/rojones/Documents/42run/src/load_shader.cpp -o CMakeFiles/42run.dir/src/load_shader.cpp.s

CMakeFiles/42run.dir/src/load_shader.cpp.o.requires:

.PHONY : CMakeFiles/42run.dir/src/load_shader.cpp.o.requires

CMakeFiles/42run.dir/src/load_shader.cpp.o.provides: CMakeFiles/42run.dir/src/load_shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/src/load_shader.cpp.o.provides.build
.PHONY : CMakeFiles/42run.dir/src/load_shader.cpp.o.provides

CMakeFiles/42run.dir/src/load_shader.cpp.o.provides.build: CMakeFiles/42run.dir/src/load_shader.cpp.o


CMakeFiles/42run.dir/src/support.cpp.o: CMakeFiles/42run.dir/flags.make
CMakeFiles/42run.dir/src/support.cpp.o: ../src/support.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/Documents/42run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/42run.dir/src/support.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/42run.dir/src/support.cpp.o -c /nfs/zfs-student-6/users/rojones/Documents/42run/src/support.cpp

CMakeFiles/42run.dir/src/support.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/42run.dir/src/support.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/zfs-student-6/users/rojones/Documents/42run/src/support.cpp > CMakeFiles/42run.dir/src/support.cpp.i

CMakeFiles/42run.dir/src/support.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/42run.dir/src/support.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/zfs-student-6/users/rojones/Documents/42run/src/support.cpp -o CMakeFiles/42run.dir/src/support.cpp.s

CMakeFiles/42run.dir/src/support.cpp.o.requires:

.PHONY : CMakeFiles/42run.dir/src/support.cpp.o.requires

CMakeFiles/42run.dir/src/support.cpp.o.provides: CMakeFiles/42run.dir/src/support.cpp.o.requires
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/src/support.cpp.o.provides.build
.PHONY : CMakeFiles/42run.dir/src/support.cpp.o.provides

CMakeFiles/42run.dir/src/support.cpp.o.provides.build: CMakeFiles/42run.dir/src/support.cpp.o


CMakeFiles/42run.dir/src/obj_loader.cpp.o: CMakeFiles/42run.dir/flags.make
CMakeFiles/42run.dir/src/obj_loader.cpp.o: ../src/obj_loader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/Documents/42run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/42run.dir/src/obj_loader.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/42run.dir/src/obj_loader.cpp.o -c /nfs/zfs-student-6/users/rojones/Documents/42run/src/obj_loader.cpp

CMakeFiles/42run.dir/src/obj_loader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/42run.dir/src/obj_loader.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/zfs-student-6/users/rojones/Documents/42run/src/obj_loader.cpp > CMakeFiles/42run.dir/src/obj_loader.cpp.i

CMakeFiles/42run.dir/src/obj_loader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/42run.dir/src/obj_loader.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/zfs-student-6/users/rojones/Documents/42run/src/obj_loader.cpp -o CMakeFiles/42run.dir/src/obj_loader.cpp.s

CMakeFiles/42run.dir/src/obj_loader.cpp.o.requires:

.PHONY : CMakeFiles/42run.dir/src/obj_loader.cpp.o.requires

CMakeFiles/42run.dir/src/obj_loader.cpp.o.provides: CMakeFiles/42run.dir/src/obj_loader.cpp.o.requires
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/src/obj_loader.cpp.o.provides.build
.PHONY : CMakeFiles/42run.dir/src/obj_loader.cpp.o.provides

CMakeFiles/42run.dir/src/obj_loader.cpp.o.provides.build: CMakeFiles/42run.dir/src/obj_loader.cpp.o


CMakeFiles/42run.dir/src/player.cpp.o: CMakeFiles/42run.dir/flags.make
CMakeFiles/42run.dir/src/player.cpp.o: ../src/player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/Documents/42run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/42run.dir/src/player.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/42run.dir/src/player.cpp.o -c /nfs/zfs-student-6/users/rojones/Documents/42run/src/player.cpp

CMakeFiles/42run.dir/src/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/42run.dir/src/player.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/zfs-student-6/users/rojones/Documents/42run/src/player.cpp > CMakeFiles/42run.dir/src/player.cpp.i

CMakeFiles/42run.dir/src/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/42run.dir/src/player.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/zfs-student-6/users/rojones/Documents/42run/src/player.cpp -o CMakeFiles/42run.dir/src/player.cpp.s

CMakeFiles/42run.dir/src/player.cpp.o.requires:

.PHONY : CMakeFiles/42run.dir/src/player.cpp.o.requires

CMakeFiles/42run.dir/src/player.cpp.o.provides: CMakeFiles/42run.dir/src/player.cpp.o.requires
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/src/player.cpp.o.provides.build
.PHONY : CMakeFiles/42run.dir/src/player.cpp.o.provides

CMakeFiles/42run.dir/src/player.cpp.o.provides.build: CMakeFiles/42run.dir/src/player.cpp.o


CMakeFiles/42run.dir/src/obstical.cpp.o: CMakeFiles/42run.dir/flags.make
CMakeFiles/42run.dir/src/obstical.cpp.o: ../src/obstical.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/Documents/42run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/42run.dir/src/obstical.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/42run.dir/src/obstical.cpp.o -c /nfs/zfs-student-6/users/rojones/Documents/42run/src/obstical.cpp

CMakeFiles/42run.dir/src/obstical.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/42run.dir/src/obstical.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/zfs-student-6/users/rojones/Documents/42run/src/obstical.cpp > CMakeFiles/42run.dir/src/obstical.cpp.i

CMakeFiles/42run.dir/src/obstical.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/42run.dir/src/obstical.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/zfs-student-6/users/rojones/Documents/42run/src/obstical.cpp -o CMakeFiles/42run.dir/src/obstical.cpp.s

CMakeFiles/42run.dir/src/obstical.cpp.o.requires:

.PHONY : CMakeFiles/42run.dir/src/obstical.cpp.o.requires

CMakeFiles/42run.dir/src/obstical.cpp.o.provides: CMakeFiles/42run.dir/src/obstical.cpp.o.requires
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/src/obstical.cpp.o.provides.build
.PHONY : CMakeFiles/42run.dir/src/obstical.cpp.o.provides

CMakeFiles/42run.dir/src/obstical.cpp.o.provides.build: CMakeFiles/42run.dir/src/obstical.cpp.o


CMakeFiles/42run.dir/src/flaw.cpp.o: CMakeFiles/42run.dir/flags.make
CMakeFiles/42run.dir/src/flaw.cpp.o: ../src/flaw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/Documents/42run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/42run.dir/src/flaw.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/42run.dir/src/flaw.cpp.o -c /nfs/zfs-student-6/users/rojones/Documents/42run/src/flaw.cpp

CMakeFiles/42run.dir/src/flaw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/42run.dir/src/flaw.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/zfs-student-6/users/rojones/Documents/42run/src/flaw.cpp > CMakeFiles/42run.dir/src/flaw.cpp.i

CMakeFiles/42run.dir/src/flaw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/42run.dir/src/flaw.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/zfs-student-6/users/rojones/Documents/42run/src/flaw.cpp -o CMakeFiles/42run.dir/src/flaw.cpp.s

CMakeFiles/42run.dir/src/flaw.cpp.o.requires:

.PHONY : CMakeFiles/42run.dir/src/flaw.cpp.o.requires

CMakeFiles/42run.dir/src/flaw.cpp.o.provides: CMakeFiles/42run.dir/src/flaw.cpp.o.requires
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/src/flaw.cpp.o.provides.build
.PHONY : CMakeFiles/42run.dir/src/flaw.cpp.o.provides

CMakeFiles/42run.dir/src/flaw.cpp.o.provides.build: CMakeFiles/42run.dir/src/flaw.cpp.o


CMakeFiles/42run.dir/src/object.cpp.o: CMakeFiles/42run.dir/flags.make
CMakeFiles/42run.dir/src/object.cpp.o: ../src/object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/Documents/42run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/42run.dir/src/object.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/42run.dir/src/object.cpp.o -c /nfs/zfs-student-6/users/rojones/Documents/42run/src/object.cpp

CMakeFiles/42run.dir/src/object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/42run.dir/src/object.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/zfs-student-6/users/rojones/Documents/42run/src/object.cpp > CMakeFiles/42run.dir/src/object.cpp.i

CMakeFiles/42run.dir/src/object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/42run.dir/src/object.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/zfs-student-6/users/rojones/Documents/42run/src/object.cpp -o CMakeFiles/42run.dir/src/object.cpp.s

CMakeFiles/42run.dir/src/object.cpp.o.requires:

.PHONY : CMakeFiles/42run.dir/src/object.cpp.o.requires

CMakeFiles/42run.dir/src/object.cpp.o.provides: CMakeFiles/42run.dir/src/object.cpp.o.requires
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/src/object.cpp.o.provides.build
.PHONY : CMakeFiles/42run.dir/src/object.cpp.o.provides

CMakeFiles/42run.dir/src/object.cpp.o.provides.build: CMakeFiles/42run.dir/src/object.cpp.o


CMakeFiles/42run.dir/src/wall.cpp.o: CMakeFiles/42run.dir/flags.make
CMakeFiles/42run.dir/src/wall.cpp.o: ../src/wall.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/Documents/42run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/42run.dir/src/wall.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/42run.dir/src/wall.cpp.o -c /nfs/zfs-student-6/users/rojones/Documents/42run/src/wall.cpp

CMakeFiles/42run.dir/src/wall.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/42run.dir/src/wall.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/zfs-student-6/users/rojones/Documents/42run/src/wall.cpp > CMakeFiles/42run.dir/src/wall.cpp.i

CMakeFiles/42run.dir/src/wall.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/42run.dir/src/wall.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/zfs-student-6/users/rojones/Documents/42run/src/wall.cpp -o CMakeFiles/42run.dir/src/wall.cpp.s

CMakeFiles/42run.dir/src/wall.cpp.o.requires:

.PHONY : CMakeFiles/42run.dir/src/wall.cpp.o.requires

CMakeFiles/42run.dir/src/wall.cpp.o.provides: CMakeFiles/42run.dir/src/wall.cpp.o.requires
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/src/wall.cpp.o.provides.build
.PHONY : CMakeFiles/42run.dir/src/wall.cpp.o.provides

CMakeFiles/42run.dir/src/wall.cpp.o.provides.build: CMakeFiles/42run.dir/src/wall.cpp.o


CMakeFiles/42run.dir/src/ceiling.cpp.o: CMakeFiles/42run.dir/flags.make
CMakeFiles/42run.dir/src/ceiling.cpp.o: ../src/ceiling.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/Documents/42run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/42run.dir/src/ceiling.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/42run.dir/src/ceiling.cpp.o -c /nfs/zfs-student-6/users/rojones/Documents/42run/src/ceiling.cpp

CMakeFiles/42run.dir/src/ceiling.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/42run.dir/src/ceiling.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/zfs-student-6/users/rojones/Documents/42run/src/ceiling.cpp > CMakeFiles/42run.dir/src/ceiling.cpp.i

CMakeFiles/42run.dir/src/ceiling.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/42run.dir/src/ceiling.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/zfs-student-6/users/rojones/Documents/42run/src/ceiling.cpp -o CMakeFiles/42run.dir/src/ceiling.cpp.s

CMakeFiles/42run.dir/src/ceiling.cpp.o.requires:

.PHONY : CMakeFiles/42run.dir/src/ceiling.cpp.o.requires

CMakeFiles/42run.dir/src/ceiling.cpp.o.provides: CMakeFiles/42run.dir/src/ceiling.cpp.o.requires
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/src/ceiling.cpp.o.provides.build
.PHONY : CMakeFiles/42run.dir/src/ceiling.cpp.o.provides

CMakeFiles/42run.dir/src/ceiling.cpp.o.provides.build: CMakeFiles/42run.dir/src/ceiling.cpp.o


CMakeFiles/42run.dir/src/room.cpp.o: CMakeFiles/42run.dir/flags.make
CMakeFiles/42run.dir/src/room.cpp.o: ../src/room.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/Documents/42run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/42run.dir/src/room.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/42run.dir/src/room.cpp.o -c /nfs/zfs-student-6/users/rojones/Documents/42run/src/room.cpp

CMakeFiles/42run.dir/src/room.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/42run.dir/src/room.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/zfs-student-6/users/rojones/Documents/42run/src/room.cpp > CMakeFiles/42run.dir/src/room.cpp.i

CMakeFiles/42run.dir/src/room.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/42run.dir/src/room.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/zfs-student-6/users/rojones/Documents/42run/src/room.cpp -o CMakeFiles/42run.dir/src/room.cpp.s

CMakeFiles/42run.dir/src/room.cpp.o.requires:

.PHONY : CMakeFiles/42run.dir/src/room.cpp.o.requires

CMakeFiles/42run.dir/src/room.cpp.o.provides: CMakeFiles/42run.dir/src/room.cpp.o.requires
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/src/room.cpp.o.provides.build
.PHONY : CMakeFiles/42run.dir/src/room.cpp.o.provides

CMakeFiles/42run.dir/src/room.cpp.o.provides.build: CMakeFiles/42run.dir/src/room.cpp.o


CMakeFiles/42run.dir/src/mesh.cpp.o: CMakeFiles/42run.dir/flags.make
CMakeFiles/42run.dir/src/mesh.cpp.o: ../src/mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-6/users/rojones/Documents/42run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/42run.dir/src/mesh.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/42run.dir/src/mesh.cpp.o -c /nfs/zfs-student-6/users/rojones/Documents/42run/src/mesh.cpp

CMakeFiles/42run.dir/src/mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/42run.dir/src/mesh.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/zfs-student-6/users/rojones/Documents/42run/src/mesh.cpp > CMakeFiles/42run.dir/src/mesh.cpp.i

CMakeFiles/42run.dir/src/mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/42run.dir/src/mesh.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/zfs-student-6/users/rojones/Documents/42run/src/mesh.cpp -o CMakeFiles/42run.dir/src/mesh.cpp.s

CMakeFiles/42run.dir/src/mesh.cpp.o.requires:

.PHONY : CMakeFiles/42run.dir/src/mesh.cpp.o.requires

CMakeFiles/42run.dir/src/mesh.cpp.o.provides: CMakeFiles/42run.dir/src/mesh.cpp.o.requires
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/src/mesh.cpp.o.provides.build
.PHONY : CMakeFiles/42run.dir/src/mesh.cpp.o.provides

CMakeFiles/42run.dir/src/mesh.cpp.o.provides.build: CMakeFiles/42run.dir/src/mesh.cpp.o


# Object files for target 42run
42run_OBJECTS = \
"CMakeFiles/42run.dir/src/main.cpp.o" \
"CMakeFiles/42run.dir/src/load_shader.cpp.o" \
"CMakeFiles/42run.dir/src/support.cpp.o" \
"CMakeFiles/42run.dir/src/obj_loader.cpp.o" \
"CMakeFiles/42run.dir/src/player.cpp.o" \
"CMakeFiles/42run.dir/src/obstical.cpp.o" \
"CMakeFiles/42run.dir/src/flaw.cpp.o" \
"CMakeFiles/42run.dir/src/object.cpp.o" \
"CMakeFiles/42run.dir/src/wall.cpp.o" \
"CMakeFiles/42run.dir/src/ceiling.cpp.o" \
"CMakeFiles/42run.dir/src/room.cpp.o" \
"CMakeFiles/42run.dir/src/mesh.cpp.o"

# External object files for target 42run
42run_EXTERNAL_OBJECTS =

42run: CMakeFiles/42run.dir/src/main.cpp.o
42run: CMakeFiles/42run.dir/src/load_shader.cpp.o
42run: CMakeFiles/42run.dir/src/support.cpp.o
42run: CMakeFiles/42run.dir/src/obj_loader.cpp.o
42run: CMakeFiles/42run.dir/src/player.cpp.o
42run: CMakeFiles/42run.dir/src/obstical.cpp.o
42run: CMakeFiles/42run.dir/src/flaw.cpp.o
42run: CMakeFiles/42run.dir/src/object.cpp.o
42run: CMakeFiles/42run.dir/src/wall.cpp.o
42run: CMakeFiles/42run.dir/src/ceiling.cpp.o
42run: CMakeFiles/42run.dir/src/room.cpp.o
42run: CMakeFiles/42run.dir/src/mesh.cpp.o
42run: CMakeFiles/42run.dir/build.make
42run: ../Framework/Glfw/lib/libglfw3.a
42run: ../Framework/Glew/lib/libGLEW.a
42run: ../Framework/Soil/lib/libSOIL.a
42run: ../Framework/FreeType/lib/libfreetype.a
42run: ../Framework/assimp/lib/libassimp.3.3.1.dylib
42run: CMakeFiles/42run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nfs/zfs-student-6/users/rojones/Documents/42run/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable 42run"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/42run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/42run.dir/build: 42run

.PHONY : CMakeFiles/42run.dir/build

CMakeFiles/42run.dir/requires: CMakeFiles/42run.dir/src/main.cpp.o.requires
CMakeFiles/42run.dir/requires: CMakeFiles/42run.dir/src/load_shader.cpp.o.requires
CMakeFiles/42run.dir/requires: CMakeFiles/42run.dir/src/support.cpp.o.requires
CMakeFiles/42run.dir/requires: CMakeFiles/42run.dir/src/obj_loader.cpp.o.requires
CMakeFiles/42run.dir/requires: CMakeFiles/42run.dir/src/player.cpp.o.requires
CMakeFiles/42run.dir/requires: CMakeFiles/42run.dir/src/obstical.cpp.o.requires
CMakeFiles/42run.dir/requires: CMakeFiles/42run.dir/src/flaw.cpp.o.requires
CMakeFiles/42run.dir/requires: CMakeFiles/42run.dir/src/object.cpp.o.requires
CMakeFiles/42run.dir/requires: CMakeFiles/42run.dir/src/wall.cpp.o.requires
CMakeFiles/42run.dir/requires: CMakeFiles/42run.dir/src/ceiling.cpp.o.requires
CMakeFiles/42run.dir/requires: CMakeFiles/42run.dir/src/room.cpp.o.requires
CMakeFiles/42run.dir/requires: CMakeFiles/42run.dir/src/mesh.cpp.o.requires

.PHONY : CMakeFiles/42run.dir/requires

CMakeFiles/42run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/42run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/42run.dir/clean

CMakeFiles/42run.dir/depend:
	cd /nfs/zfs-student-6/users/rojones/Documents/42run/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/zfs-student-6/users/rojones/Documents/42run /nfs/zfs-student-6/users/rojones/Documents/42run /nfs/zfs-student-6/users/rojones/Documents/42run/build /nfs/zfs-student-6/users/rojones/Documents/42run/build /nfs/zfs-student-6/users/rojones/Documents/42run/build/CMakeFiles/42run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/42run.dir/depend

