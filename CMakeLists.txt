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

message("Including STB")
include_directories(Dependencies/STB_IMAGE)


add_executable(OGL_Engine
        src/engine/Core/Engine.cpp
        src/engine/Core/Engine.h
        src/engine/Core/Scene.h
        src/engine/Core/Window.cpp
        src/engine/Core/Window.h
        src/engine/Entities/MeshRenderer.cpp
        src/engine/Entities/MeshRenderer.h
        src/engine/Geometry/shaders/Shader.cpp
        src/engine/Geometry/shaders/Shader.h
        src/engine/Geometry/Mesh.cpp
        src/engine/Geometry/Mesh.h
        src/engine/Geometry/VAO.cpp
        src/engine/Geometry/VAO.h
        src/engine/Geometry/VBO.cpp
        src/engine/Geometry/VBO.h
        src/engine/Test/3D/RandomCubes.cpp
        src/engine/Test/3D/RandomCubes.h
        src/Debug.h
        src/main.cpp
        src/engine/Core/Renderer.cpp
        src/engine/Geometry/data/Texture.cpp
        src/engine/Geometry/data/Texture.h
        Dependencies/STB_IMAGE/stb_image.h
        Dependencies/STB_IMAGE/stb_image.cpp
        src/engine/Entities/Transform.cpp
        src/engine/Entities/Transform.h
        src/engine/Entities/FPSController.cpp
        src/engine/Entities/FPSController.h
        src/engine/Entities/Entity.cpp
        src/engine/Geometry/Geometry.h
        src/engine/Core/Scene.cpp
        src/engine/Geometry/Geometry.cpp
        src/engine/Geometry/data/Text.cpp
        src/engine/Geometry/data/Text.h
        src/engine/Geometry/data/AtlasTexture.cpp
        src/engine/Geometry/data/AtlasTexture.h
        src/engine/Test/2D/NoiseTextureCreation.cpp
        src/engine/Test/2D/NoiseTextureCreation.h
        src/engine/Utils/SimplexNoise.h
        src/engine/Utils/SimplexNoise.cpp
        src/engine/Test/2D/AtlasTextureTest.cpp
        src/engine/Test/2D/AtlasTextureTest.h
        src/engine/Test/3D/ImportModelTest.cpp
        src/engine/Test/3D/ImportModelTest.h
        src/engine/Utils/StringUtils.cpp
        src/engine/Utils/StringUtils.h
        src/engine/Utils/Timer.cpp
        src/engine/Utils/Timer.h src/engine/Geometry/Material.cpp src/engine/Geometry/Material.h)

target_link_libraries(OGL_Engine glfw3 libglew32.a ${OPENGL_LIBRARIES})
