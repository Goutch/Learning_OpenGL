cmake_minimum_required(VERSION 3.14)
project(OGL_Engine)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

find_package(OpenGL REQUIRED)


message("Including GLEW")
include_directories(Dependencies/GLEW/include)
message("Linking GLEW")
link_directories(Dependencies/GLEW/lib)

message("Including GLFW")
include_directories("Dependencies/GLFW/include")
message("Linking GLFW")
link_directories("Dependencies/GLFW/lib-mingw")
message("Including GLM")
include_directories(Dependencies/GLM)
add_subdirectory(Dependencies/GLM)

add_executable(OGL_Engine
        src/engine/core/Game.h
        src/engine/graphics/Renderer.h
        src/engine/graphics/VAO.cpp
        src/engine/graphics/VAO.h
        src/engine/graphics/VBO.cpp
        src/engine/graphics/VBO.h
        src/engine/shaders/ShaderProgram.cpp
        src/engine/shaders/ShaderProgram.h
        src/engine/Window.cpp
        src/engine/Window.h
        src/main.cpp)

target_link_libraries(OGL_Engine  glfw3 libglew32.a  ${OPENGL_LIBRARIES})