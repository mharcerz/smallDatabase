# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/mharc/Desktop/smallDatabase

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/mharc/Desktop/smallDatabase

# Include any dependencies generated for this target.
include CMakeFiles/smallDatabase.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/smallDatabase.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/smallDatabase.dir/flags.make

CMakeFiles/smallDatabase.dir/main.cpp.o: CMakeFiles/smallDatabase.dir/flags.make
CMakeFiles/smallDatabase.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/mharc/Desktop/smallDatabase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/smallDatabase.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smallDatabase.dir/main.cpp.o -c /mnt/c/Users/mharc/Desktop/smallDatabase/main.cpp

CMakeFiles/smallDatabase.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smallDatabase.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/mharc/Desktop/smallDatabase/main.cpp > CMakeFiles/smallDatabase.dir/main.cpp.i

CMakeFiles/smallDatabase.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smallDatabase.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/mharc/Desktop/smallDatabase/main.cpp -o CMakeFiles/smallDatabase.dir/main.cpp.s

CMakeFiles/smallDatabase.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/smallDatabase.dir/main.cpp.o.requires

CMakeFiles/smallDatabase.dir/main.cpp.o.provides: CMakeFiles/smallDatabase.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/smallDatabase.dir/build.make CMakeFiles/smallDatabase.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/smallDatabase.dir/main.cpp.o.provides

CMakeFiles/smallDatabase.dir/main.cpp.o.provides.build: CMakeFiles/smallDatabase.dir/main.cpp.o


CMakeFiles/smallDatabase.dir/Person.cpp.o: CMakeFiles/smallDatabase.dir/flags.make
CMakeFiles/smallDatabase.dir/Person.cpp.o: Person.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/mharc/Desktop/smallDatabase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/smallDatabase.dir/Person.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smallDatabase.dir/Person.cpp.o -c /mnt/c/Users/mharc/Desktop/smallDatabase/Person.cpp

CMakeFiles/smallDatabase.dir/Person.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smallDatabase.dir/Person.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/mharc/Desktop/smallDatabase/Person.cpp > CMakeFiles/smallDatabase.dir/Person.cpp.i

CMakeFiles/smallDatabase.dir/Person.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smallDatabase.dir/Person.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/mharc/Desktop/smallDatabase/Person.cpp -o CMakeFiles/smallDatabase.dir/Person.cpp.s

CMakeFiles/smallDatabase.dir/Person.cpp.o.requires:

.PHONY : CMakeFiles/smallDatabase.dir/Person.cpp.o.requires

CMakeFiles/smallDatabase.dir/Person.cpp.o.provides: CMakeFiles/smallDatabase.dir/Person.cpp.o.requires
	$(MAKE) -f CMakeFiles/smallDatabase.dir/build.make CMakeFiles/smallDatabase.dir/Person.cpp.o.provides.build
.PHONY : CMakeFiles/smallDatabase.dir/Person.cpp.o.provides

CMakeFiles/smallDatabase.dir/Person.cpp.o.provides.build: CMakeFiles/smallDatabase.dir/Person.cpp.o


# Object files for target smallDatabase
smallDatabase_OBJECTS = \
"CMakeFiles/smallDatabase.dir/main.cpp.o" \
"CMakeFiles/smallDatabase.dir/Person.cpp.o"

# External object files for target smallDatabase
smallDatabase_EXTERNAL_OBJECTS =

smallDatabase: CMakeFiles/smallDatabase.dir/main.cpp.o
smallDatabase: CMakeFiles/smallDatabase.dir/Person.cpp.o
smallDatabase: CMakeFiles/smallDatabase.dir/build.make
smallDatabase: CMakeFiles/smallDatabase.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/mharc/Desktop/smallDatabase/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable smallDatabase"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/smallDatabase.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/smallDatabase.dir/build: smallDatabase

.PHONY : CMakeFiles/smallDatabase.dir/build

CMakeFiles/smallDatabase.dir/requires: CMakeFiles/smallDatabase.dir/main.cpp.o.requires
CMakeFiles/smallDatabase.dir/requires: CMakeFiles/smallDatabase.dir/Person.cpp.o.requires

.PHONY : CMakeFiles/smallDatabase.dir/requires

CMakeFiles/smallDatabase.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/smallDatabase.dir/cmake_clean.cmake
.PHONY : CMakeFiles/smallDatabase.dir/clean

CMakeFiles/smallDatabase.dir/depend:
	cd /mnt/c/Users/mharc/Desktop/smallDatabase && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/mharc/Desktop/smallDatabase /mnt/c/Users/mharc/Desktop/smallDatabase /mnt/c/Users/mharc/Desktop/smallDatabase /mnt/c/Users/mharc/Desktop/smallDatabase /mnt/c/Users/mharc/Desktop/smallDatabase/CMakeFiles/smallDatabase.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/smallDatabase.dir/depend

