cmake_minimum_required(VERSION 3.14)
project(OGL_Engine)

set(CMAKE_CXX_STANDARD 11)

include_directories(src/engine)

find_package(OpenGL REQUIRED)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

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

find_package(Vulkan REQUIRED)


add_executable(OGL_Engine
        src/engine/core/Engine.cpp
        src/engine/core/Engine.h
        src/engine/core/Game.h
        src/engine/core/Window.cpp
        src/engine/core/Window.h
        src/engine/entities/MeshRenderer.cpp
        src/engine/entities/MeshRenderer.h
        src/engine/entities/Transform.cpp
        src/engine/entities/Transform.h
        src/engine/graphics/shaders/ShaderProgram.cpp
        src/engine/graphics/shaders/ShaderProgram.h
        src/engine/graphics/Mesh.cpp
        src/engine/graphics/Mesh.h
        src/engine/graphics/VAO.cpp
        src/engine/graphics/VAO.h
        src/engine/graphics/VBO.cpp
        src/engine/graphics/VBO.h
        src/engine/test/Test.cpp
        src/engine/test/Test.h
        src/Debug.h
        src/main.cpp
        src/engine/core/Renderer.cpp
        src/engine/graphics/shaders/BaseShader.cpp
        src/engine/graphics/shaders/BaseShader.h)

target_link_libraries(OGL_Engine glfw3 libglew32.a  ${OPENGL_LIBRARIES} Vulkan::Vulkan)

target_compile_definitions(OGL_Engine PRIVATE VK_USE_PLATFORM_WIN32_KHR)
target_include_directories(OGL_Engine PRIVATE Vulkan::Vulkan)