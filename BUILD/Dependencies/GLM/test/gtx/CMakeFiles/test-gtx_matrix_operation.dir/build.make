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
include Dependencies/GLM/test/gtx/CMakeFiles/test-gtx_matrix_operation.dir/depend.make

# Include the progress variables for this target.
include Dependencies/GLM/test/gtx/CMakeFiles/test-gtx_matrix_operation.dir/progress.make

# Include the compile flags for this target's objects.
include Dependencies/GLM/test/gtx/CMakeFiles/test-gtx_matrix_operation.dir/flags.make

Dependencies/GLM/test/gtx/CMakeFiles/test-gtx_matrix_operation.dir/gtx_matrix_operation.cpp.obj: Dependencies/GLM/test/gtx/CMakeFiles/test-gtx_matrix_operation.dir/flags.make
Dependencies/GLM/test/gtx/CMakeFiles/test-gtx_matrix_operation.dir/gtx_matrix_operation.cpp.obj: Dependencies/GLM/test/gtx/CMakeFiles/test-gtx_matrix_operation.dir/includes_CXX.rsp
Dependencies/GLM/test/gtx/CMakeFiles/test-gtx_matrix_operation.dir/gtx_matrix_operation.cpp.obj: ../Dependencies/GLM/test/gtx/gtx_matrix_operation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Documents\Projects\OGL_Engine\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Dependencies/GLM/test/gtx/CMakeFiles/test-gtx_matrix_operation.dir/gtx_matrix_operation.cpp.obj"
	cd /d C:\Users\User\Documents\Projects\OGL_Engine\cmake-build-release\Dependencies\GLM\test\gtx && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\test-gtx_matrix_operation.dir\gtx_matrix_operation.cpp.obj -c C:\Users\User\Documents\Projects\OGL_Engine\Dependencies\GLM\test\gtx\gtx_matrix_operation.cpp

Dependencies/GLM/test/gtx/CMakeFiles/test-gtx_matrix_operation.dir/gtx_matrix_operation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-gtx_matrix_operation.dir/gtx_matrix_operation.cpp.i"
	cd /d C:\Users\User\Documents\Projects\OGL_Engine\cmake-build-release\Dependencies\GLM\test\gtx && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\User\Documents\Projects\OGL_Engine\Dependencies\GLM\test\gtx\gtx_matrix_operation.cpp > CMakeFiles\test-gtx_matrix_operation.dir\gtx_matrix_operation.cpp.i

Dependencies/GLM/test/gtx/CMakeFiles/test-gtx_matrix_operation.dir/gtx_matrix_operation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-gtx_matrix_operation.dir/gtx_matrix_operation.cpp.s"
	cd /d C:\Users\User\Documents\Projects\OGL_Engine\cmake-build-release\Dependencies\GLM\test\gtx && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\User\Documents\Projects\OGL_Engine\Dependencies\GLM\test\gtx\gtx_matrix_operation.cpp -o CMakeFiles\test-gtx_matrix_operation.dir\gtx_matrix_operation.cpp.s

# Object files for target test-gtx_matrix_operation
test__gtx_matrix_operation_OBJECTS = \
"CMakeFiles/test-gtx_matrix_operation.dir/gtx_matrix_operation.cpp.obj"

# External object files for target test-gtx_matrix_operation
test__gtx_matrix_operation_EXTERNAL_OBJECTS =

Dependencies/GLM/test/gtx/test-gtx_matrix_operation.exe: Dependencies/GLM/test/gtx/CMakeFiles/test-gtx_matrix_operation.dir/gtx_matrix_operation.cpp.obj
Dependencies/GLM/test/gtx/test-gtx_matrix_operation.exe: Dependencies/GLM/test/gtx/CMakeFiles/test-gtx_matrix_operation.dir/build.make
Dependencies/GLM/test/gtx/test-gtx_matrix_operation.exe: Dependencies/GLM/test/gtx/CMakeFiles/test-gtx_matrix_operation.dir/linklibs.rsp
Dependencies/GLM/test/gtx/test-gtx_matrix_operation.exe: Dependencies/GLM/test/gtx/CMakeFiles/test-gtx_matrix_operation.dir/objects1.rsp
Dependencies/GLM/test/gtx/test-gtx_matrix_operation.exe: Dependencies/GLM/test/gtx/CMakeFiles/test-gtx_matrix_operation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\User\Documents\Projects\OGL_Engine\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-gtx_matrix_operation.exe"
	cd /d C:\Users\User\Documents\Projects\OGL_Engine\cmake-build-release\Dependencies\GLM\test\gtx && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test-gtx_matrix_operation.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Dependencies/GLM/test/gtx/CMakeFiles/test-gtx_matrix_operation.dir/build: Dependencies/GLM/test/gtx/test-gtx_matrix_operation.exe

.PHONY : Dependencies/GLM/test/gtx/CMakeFiles/test-gtx_matrix_operation.dir/build

Dependencies/GLM/test/gtx/CMakeFiles/test-gtx_matrix_operation.dir/clean:
	cd /d C:\Users\User\Documents\Projects\OGL_Engine\cmake-build-release\Dependencies\GLM\test\gtx && $(CMAKE_COMMAND) -P CMakeFiles\test-gtx_matrix_operation.dir\cmake_clean.cmake
.PHONY : Dependencies/GLM/test/gtx/CMakeFiles/test-gtx_matrix_operation.dir/clean

Dependencies/GLM/test/gtx/CMakeFiles/test-gtx_matrix_operation.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User\Documents\Projects\OGL_Engine C:\Users\User\Documents\Projects\OGL_Engine\Dependencies\GLM\test\gtx C:\Users\User\Documents\Projects\OGL_Engine\cmake-build-release C:\Users\User\Documents\Projects\OGL_Engine\cmake-build-release\Dependencies\GLM\test\gtx C:\Users\User\Documents\Projects\OGL_Engine\cmake-build-release\Dependencies\GLM\test\gtx\CMakeFiles\test-gtx_matrix_operation.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : Dependencies/GLM/test/gtx/CMakeFiles/test-gtx_matrix_operation.dir/depend
