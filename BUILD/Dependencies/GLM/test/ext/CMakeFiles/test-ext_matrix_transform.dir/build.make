# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\User\Documents\Projects\OGL_Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\User\Documents\Projects\OGL_Engine\cmake-build-release

# Include any dependencies generated for this target.
include Dependencies/GLM/test/ext/CMakeFiles/test-ext_matrix_transform.dir/depend.make

# Include the progress variables for this target.
include Dependencies/GLM/test/ext/CMakeFiles/test-ext_matrix_transform.dir/progress.make

# Include the compile flags for this target's objects.
include Dependencies/GLM/test/ext/CMakeFiles/test-ext_matrix_transform.dir/flags.make

Dependencies/GLM/test/ext/CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.obj: Dependencies/GLM/test/ext/CMakeFiles/test-ext_matrix_transform.dir/flags.make
Dependencies/GLM/test/ext/CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.obj: Dependencies/GLM/test/ext/CMakeFiles/test-ext_matrix_transform.dir/includes_CXX.rsp
Dependencies/GLM/test/ext/CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.obj: ../Dependencies/GLM/test/ext/ext_matrix_transform.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Documents\Projects\OGL_Engine\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Dependencies/GLM/test/ext/CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.obj"
	cd /d C:\Users\User\Documents\Projects\OGL_Engine\cmake-build-release\Dependencies\GLM\test\ext && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\test-ext_matrix_transform.dir\ext_matrix_transform.cpp.obj -c C:\Users\User\Documents\Projects\OGL_Engine\Dependencies\GLM\test\ext\ext_matrix_transform.cpp

Dependencies/GLM/test/ext/CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.i"
	cd /d C:\Users\User\Documents\Projects\OGL_Engine\cmake-build-release\Dependencies\GLM\test\ext && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\User\Documents\Projects\OGL_Engine\Dependencies\GLM\test\ext\ext_matrix_transform.cpp > CMakeFiles\test-ext_matrix_transform.dir\ext_matrix_transform.cpp.i

Dependencies/GLM/test/ext/CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.s"
	cd /d C:\Users\User\Documents\Projects\OGL_Engine\cmake-build-release\Dependencies\GLM\test\ext && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\User\Documents\Projects\OGL_Engine\Dependencies\GLM\test\ext\ext_matrix_transform.cpp -o CMakeFiles\test-ext_matrix_transform.dir\ext_matrix_transform.cpp.s

# Object files for target test-ext_matrix_transform
test__ext_matrix_transform_OBJECTS = \
"CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.obj"

# External object files for target test-ext_matrix_transform
test__ext_matrix_transform_EXTERNAL_OBJECTS =

Dependencies/GLM/test/ext/test-ext_matrix_transform.exe: Dependencies/GLM/test/ext/CMakeFiles/test-ext_matrix_transform.dir/ext_matrix_transform.cpp.obj
Dependencies/GLM/test/ext/test-ext_matrix_transform.exe: Dependencies/GLM/test/ext/CMakeFiles/test-ext_matrix_transform.dir/build.make
Dependencies/GLM/test/ext/test-ext_matrix_transform.exe: Dependencies/GLM/test/ext/CMakeFiles/test-ext_matrix_transform.dir/linklibs.rsp
Dependencies/GLM/test/ext/test-ext_matrix_transform.exe: Dependencies/GLM/test/ext/CMakeFiles/test-ext_matrix_transform.dir/objects1.rsp
Dependencies/GLM/test/ext/test-ext_matrix_transform.exe: Dependencies/GLM/test/ext/CMakeFiles/test-ext_matrix_transform.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\User\Documents\Projects\OGL_Engine\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-ext_matrix_transform.exe"
	cd /d C:\Users\User\Documents\Projects\OGL_Engine\cmake-build-release\Dependencies\GLM\test\ext && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test-ext_matrix_transform.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Dependencies/GLM/test/ext/CMakeFiles/test-ext_matrix_transform.dir/build: Dependencies/GLM/test/ext/test-ext_matrix_transform.exe

.PHONY : Dependencies/GLM/test/ext/CMakeFiles/test-ext_matrix_transform.dir/build

Dependencies/GLM/test/ext/CMakeFiles/test-ext_matrix_transform.dir/clean:
	cd /d C:\Users\User\Documents\Projects\OGL_Engine\cmake-build-release\Dependencies\GLM\test\ext && $(CMAKE_COMMAND) -P CMakeFiles\test-ext_matrix_transform.dir\cmake_clean.cmake
.PHONY : Dependencies/GLM/test/ext/CMakeFiles/test-ext_matrix_transform.dir/clean

Dependencies/GLM/test/ext/CMakeFiles/test-ext_matrix_transform.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User\Documents\Projects\OGL_Engine C:\Users\User\Documents\Projects\OGL_Engine\Dependencies\GLM\test\ext C:\Users\User\Documents\Projects\OGL_Engine\cmake-build-release C:\Users\User\Documents\Projects\OGL_Engine\cmake-build-release\Dependencies\GLM\test\ext C:\Users\User\Documents\Projects\OGL_Engine\cmake-build-release\Dependencies\GLM\test\ext\CMakeFiles\test-ext_matrix_transform.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : Dependencies/GLM/test/ext/CMakeFiles/test-ext_matrix_transform.dir/depend

