# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/linghan/clion-2017.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/linghan/clion-2017.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/linghan/CIS563FEMSimulation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/linghan/CIS563FEMSimulation/cmake-build-debug

# Include any dependencies generated for this target.
include Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/depend.make

# Include the progress variables for this target.
include Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/progress.make

# Include the compile flags for this target's objects.
include Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/flags.make

Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/main.cpp.o: Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/flags.make
Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/main.cpp.o: ../Projects/parseTetrahedralFile/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/linghan/CIS563FEMSimulation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/main.cpp.o"
	cd /home/linghan/CIS563FEMSimulation/cmake-build-debug/Projects/parseTetrahedralFile && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/parseTetraFile.dir/main.cpp.o -c /home/linghan/CIS563FEMSimulation/Projects/parseTetrahedralFile/main.cpp

Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parseTetraFile.dir/main.cpp.i"
	cd /home/linghan/CIS563FEMSimulation/cmake-build-debug/Projects/parseTetrahedralFile && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/linghan/CIS563FEMSimulation/Projects/parseTetrahedralFile/main.cpp > CMakeFiles/parseTetraFile.dir/main.cpp.i

Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parseTetraFile.dir/main.cpp.s"
	cd /home/linghan/CIS563FEMSimulation/cmake-build-debug/Projects/parseTetrahedralFile && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/linghan/CIS563FEMSimulation/Projects/parseTetrahedralFile/main.cpp -o CMakeFiles/parseTetraFile.dir/main.cpp.s

Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/main.cpp.o.requires:

.PHONY : Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/main.cpp.o.requires

Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/main.cpp.o.provides: Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/main.cpp.o.requires
	$(MAKE) -f Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/build.make Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/main.cpp.o.provides.build
.PHONY : Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/main.cpp.o.provides

Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/main.cpp.o.provides.build: Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/main.cpp.o


# Object files for target parseTetraFile
parseTetraFile_OBJECTS = \
"CMakeFiles/parseTetraFile.dir/main.cpp.o"

# External object files for target parseTetraFile
parseTetraFile_EXTERNAL_OBJECTS =

../Projects/parseTetrahedralFile/parseTetraFile_debug: Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/main.cpp.o
../Projects/parseTetrahedralFile/parseTetraFile_debug: Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/build.make
../Projects/parseTetrahedralFile/parseTetraFile_debug: Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/linghan/CIS563FEMSimulation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../Projects/parseTetrahedralFile/parseTetraFile_debug"
	cd /home/linghan/CIS563FEMSimulation/cmake-build-debug/Projects/parseTetrahedralFile && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/parseTetraFile.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/build: ../Projects/parseTetrahedralFile/parseTetraFile_debug

.PHONY : Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/build

Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/requires: Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/main.cpp.o.requires

.PHONY : Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/requires

Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/clean:
	cd /home/linghan/CIS563FEMSimulation/cmake-build-debug/Projects/parseTetrahedralFile && $(CMAKE_COMMAND) -P CMakeFiles/parseTetraFile.dir/cmake_clean.cmake
.PHONY : Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/clean

Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/depend:
	cd /home/linghan/CIS563FEMSimulation/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/linghan/CIS563FEMSimulation /home/linghan/CIS563FEMSimulation/Projects/parseTetrahedralFile /home/linghan/CIS563FEMSimulation/cmake-build-debug /home/linghan/CIS563FEMSimulation/cmake-build-debug/Projects/parseTetrahedralFile /home/linghan/CIS563FEMSimulation/cmake-build-debug/Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Projects/parseTetrahedralFile/CMakeFiles/parseTetraFile.dir/depend

