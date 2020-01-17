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
        src/engine/core/Engine.cpp
        src/engine/core/Engine.h
        src/engine/core/Scene.h
        src/engine/core/Window.cpp
        src/engine/core/Window.h
        src/engine/entities/MeshRenderer.cpp
        src/engine/entities/MeshRenderer.h
        src/engine/graphics/shaders/Shader.cpp
        src/engine/graphics/shaders/Shader.h
        src/engine/graphics/data/Mesh.cpp
        src/engine/graphics/data/Mesh.h
        src/engine/graphics/data/VAO.cpp
        src/engine/graphics/data/VAO.h
        src/engine/graphics/data/VBO.cpp
        src/engine/graphics/data/VBO.h
        src/engine/test/3D/RandomCubes.cpp
        src/engine/test/3D/RandomCubes.h
        src/Debug.h
        src/main.cpp
        src/engine/core/Renderer.cpp
        src/engine/graphics/data/Sprite.cpp
        src/engine/graphics/data/Sprite.h
        src/engine/graphics/data/Texture.cpp
        src/engine/graphics/data/Texture.h
        Dependencies/STB_IMAGE/stb_image.h
        Dependencies/STB_IMAGE/stb_image.cpp
        src/engine/entities/Transform.cpp
        src/engine/entities/Transform.h
        src/engine/entities/FPSController.cpp
        src/engine/entities/FPSController.h
        src/engine/entities/Entity.cpp
        src/engine/graphics/Geometry.h
        src/engine/core/Scene.cpp
        src/engine/graphics/Geometry.cpp
        src/engine/graphics/data/Text.cpp
        src/engine/graphics/data/Text.h
        src/engine/graphics/data/AtlasTexture.cpp
        src/engine/graphics/data/AtlasTexture.h
        src/engine/test/2D/NoiseTextureCreation.cpp
        src/engine/test/2D/NoiseTextureCreation.h
        src/engine/utils/SimplexNoise.h
        src/engine/utils/SimplexNoise.cpp
        src/engine/test/2D/AtlasTextureTest.cpp
        src/engine/test/2D/AtlasTextureTest.h
        src/engine/test/3D/ImportModelTest.cpp
        src/engine/test/3D/ImportModelTest.h
        src/engine/utils/StringUtils.cpp
        src/engine/utils/StringUtils.h
        src/engine/utils/TimeUtils.cpp
        src/engine/utils/TimeUtils.h src/engine/graphics/Material.cpp src/engine/graphics/Material.h)

target_link_libraries(OGL_Engine glfw3 libglew32.a ${OPENGL_LIBRARIES})
