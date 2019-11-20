cmake_minimum_required(VERSION 3.14)
project(OGL_Engine)

set(CMAKE_CXX_STANDARD 11)

include_directories(src/engine)

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
        src/main.cpp
        src/engine/graphics/Mesh.h
        src/engine/graphics/Mesh.cpp
        src/engine/core/Game.h
        src/engine/core/Renderer.h
        src/engine/graphics/VAO.cpp
        src/engine/graphics/VAO.h
        src/engine/graphics/VBO.cpp
        src/engine/graphics/VBO.h
        src/engine/graphics/shaders/ShaderProgram.cpp
        src/engine/graphics/shaders/ShaderProgram.h
        src/engine/core/Window.cpp
        src/engine/core/Window.h
        src/engine/graphics/DefaultRenderer.h
        src/engine/graphics/DefaultRenderer.cpp
        src/Debug.h
        src/engine/core/Engine.cpp
        src/engine/core/Engine.h
        src/engine/test/Test.cpp
        src/engine/test/Test.h
        src/engine/entities/MeshRenderer.cpp
        src/engine/entities/MeshRenderer.h
        src/engine/entities/Transform.cpp
        src/engine/entities/Transform.h
        src/engine/entities/Entity.h)



target_link_libraries(OGL_Engine glfw3 libglew32.a  ${OPENGL_LIBRARIES})
