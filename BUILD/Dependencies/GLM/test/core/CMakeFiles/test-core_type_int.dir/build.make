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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\User\Documents\GitHub\OGL_Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\User\Documents\GitHub\OGL_Engine\cmake-build-release

# Include any dependencies generated for this target.
include Dependencies/GLM/test/core/CMakeFiles/test-core_type_int.dir/depend.make

# Include the progress variables for this target.
include Dependencies/GLM/test/core/CMakeFiles/test-core_type_int.dir/progress.make

# Include the compile flags for this target's objects.
include Dependencies/GLM/test/core/CMakeFiles/test-core_type_int.dir/flags.make

Dependencies/GLM/test/core/CMakeFiles/test-core_type_int.dir/core_type_int.cpp.obj: Dependencies/GLM/test/core/CMakeFiles/test-core_type_int.dir/flags.make
Dependencies/GLM/test/core/CMakeFiles/test-core_type_int.dir/core_type_int.cpp.obj: Dependencies/GLM/test/core/CMakeFiles/test-core_type_int.dir/includes_CXX.rsp
Dependencies/GLM/test/core/CMakeFiles/test-core_type_int.dir/core_type_int.cpp.obj: ../Dependencies/GLM/test/core/core_type_int.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Documents\GitHub\OGL_Engine\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Dependencies/GLM/test/core/CMakeFiles/test-core_type_int.dir/core_type_int.cpp.obj"
	cd /d C:\Users\User\Documents\GitHub\OGL_Engine\cmake-build-release\Dependencies\GLM\test\core && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\test-core_type_int.dir\core_type_int.cpp.obj -c C:\Users\User\Documents\GitHub\OGL_Engine\Dependencies\GLM\test\core\core_type_int.cpp

Dependencies/GLM/test/core/CMakeFiles/test-core_type_int.dir/core_type_int.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-core_type_int.dir/core_type_int.cpp.i"
	cd /d C:\Users\User\Documents\GitHub\OGL_Engine\cmake-build-release\Dependencies\GLM\test\core && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\User\Documents\GitHub\OGL_Engine\Dependencies\GLM\test\core\core_type_int.cpp > CMakeFiles\test-core_type_int.dir\core_type_int.cpp.i

Dependencies/GLM/test/core/CMakeFiles/test-core_type_int.dir/core_type_int.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-core_type_int.dir/core_type_int.cpp.s"
	cd /d C:\Users\User\Documents\GitHub\OGL_Engine\cmake-build-release\Dependencies\GLM\test\core && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\User\Documents\GitHub\OGL_Engine\Dependencies\GLM\test\core\core_type_int.cpp -o CMakeFiles\test-core_type_int.dir\core_type_int.cpp.s

# Object files for target test-core_type_int
test__core_type_int_OBJECTS = \
"CMakeFiles/test-core_type_int.dir/core_type_int.cpp.obj"

# External object files for target test-core_type_int
test__core_type_int_EXTERNAL_OBJECTS =

Dependencies/GLM/test/core/test-core_type_int.exe: Dependencies/GLM/test/core/CMakeFiles/test-core_type_int.dir/core_type_int.cpp.obj
Dependencies/GLM/test/core/test-core_type_int.exe: Dependencies/GLM/test/core/CMakeFiles/test-core_type_int.dir/build.make
Dependencies/GLM/test/core/test-core_type_int.exe: Dependencies/GLM/test/core/CMakeFiles/test-core_type_int.dir/linklibs.rsp
Dependencies/GLM/test/core/test-core_type_int.exe: Dependencies/GLM/test/core/CMakeFiles/test-core_type_int.dir/objects1.rsp
Dependencies/GLM/test/core/test-core_type_int.exe: Dependencies/GLM/test/core/CMakeFiles/test-core_type_int.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\User\Documents\GitHub\OGL_Engine\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-core_type_int.exe"
	cd /d C:\Users\User\Documents\GitHub\OGL_Engine\cmake-build-release\Dependencies\GLM\test\core && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test-core_type_int.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Dependencies/GLM/test/core/CMakeFiles/test-core_type_int.dir/build: Dependencies/GLM/test/core/test-core_type_int.exe

.PHONY : Dependencies/GLM/test/core/CMakeFiles/test-core_type_int.dir/build

Dependencies/GLM/test/core/CMakeFiles/test-core_type_int.dir/clean:
	cd /d C:\Users\User\Documents\GitHub\OGL_Engine\cmake-build-release\Dependencies\GLM\test\core && $(CMAKE_COMMAND) -P CMakeFiles\test-core_type_int.dir\cmake_clean.cmake
.PHONY : Dependencies/GLM/test/core/CMakeFiles/test-core_type_int.dir/clean

Dependencies/GLM/test/core/CMakeFiles/test-core_type_int.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User\Documents\GitHub\OGL_Engine C:\Users\User\Documents\GitHub\OGL_Engine\Dependencies\GLM\test\core C:\Users\User\Documents\GitHub\OGL_Engine\cmake-build-release C:\Users\User\Documents\GitHub\OGL_Engine\cmake-build-release\Dependencies\GLM\test\core C:\Users\User\Documents\GitHub\OGL_Engine\cmake-build-release\Dependencies\GLM\test\core\CMakeFiles\test-core_type_int.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : Dependencies/GLM/test/core/CMakeFiles/test-core_type_int.dir/depend

