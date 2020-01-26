cmake_minimum_required(VERSION 3.14)
project(OGL_Engine)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
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
        src/main.cpp

        src/engine/Core/Engine.cpp
        src/engine/Core/Engine.h
        src/engine/Core/Scene.h
        src/engine/Core/Window.cpp
        src/engine/Core/Window.h
        src/engine/Core/Debug.h
        src/engine/Core/Renderer.cpp
        src/engine/Core/Scene.cpp
        src/engine/Core/Log.cpp
        src/engine/Core/Log.h

        src/engine/Entities/MeshRenderer.cpp
        src/engine/Entities/MeshRenderer.h
        src/engine/Entities/Transform.cpp
        src/engine/Entities/Transform.h
        src/engine/Entities/FPSController.cpp
        src/engine/Entities/FPSController.h
        src/engine/Entities/Entity.cpp
        src/engine/Entities/Light/Light.cpp
        src/engine/Entities/Light/Light.h
        src/engine/Entities/Light/DirectionnalLight.cpp
        src/engine/Entities/Light/DirectionnalLight.h
        src/engine/Entities/Light/PointLight.cpp
        src/engine/Entities/Light/PointLight.h

        src/engine/Shaders/Shader.cpp
        src/engine/Shaders/Shader.h
        src/engine/Shaders/Material.cpp
        src/engine/Shaders/Material.h
        src/engine/Shaders/LightMaterial.cpp
        src/engine/Shaders/LightMaterial.h

        src/engine/Geometry/Geometry.h
        src/engine/Geometry/Geometry.cpp
        src/engine/Geometry/Mesh.cpp
        src/engine/Geometry/Mesh.h
        src/engine/Geometry/VAO.cpp
        src/engine/Geometry/VAO.h
        src/engine/Geometry/VBO.cpp
        src/engine/Geometry/VBO.h

        src/engine/Data/Texture.cpp
        src/engine/Data/Texture.h
        src/engine/Data/Text.cpp
        src/engine/Data/Text.h
        src/engine/Data/AtlasTexture.cpp
        src/engine/Data/AtlasTexture.h
        src/engine/Data/Color.cpp
        src/engine/Data/Color.h
        src/engine/Data/FBO.cpp
        src/engine/Data/FBO.h
        src/engine/Data/RBO.cpp
        src/engine/Data/RBO.h

        src/engine/Utils/SimplexNoise.h
        src/engine/Utils/SimplexNoise.cpp
        src/engine/Utils/StringUtils.cpp
        src/engine/Utils/StringUtils.h
        src/engine/Utils/Timer.cpp
        src/engine/Utils/Timer.h
        src/engine/Utils/TimeUtils.h
        src/engine/Utils/TimeUtils.cpp


        src/engine/Test/PerformanceTest.cpp
        src/engine/Test/PerformanceTest.h
        src/engine/Test/AtlasTextureTest.cpp
        src/engine/Test/AtlasTextureTest.h
        src/engine/Test/ImportModelTest.cpp
        src/engine/Test/ImportModelTest.h
        src/engine/Test/TextureCreationTest.cpp
        src/engine/Test/TextureCreationTest.h
        src/engine/Test/FullSceneTest.cpp
        src/engine/Test/FullSceneTest.h
        src/engine/Test/LAB2.cpp
        src/engine/Test/LAB2.h

        src/engine/Events/WindowSizeListener.h

        Dependencies/STB_IMAGE/stb_image.h
        Dependencies/STB_IMAGE/stb_image.cpp
        Dependencies/STB_IMAGE/stb_image_write.h
        src/engine/Editor/Editor.cpp src/engine/Editor/Editor.h)

target_link_libraries(OGL_Engine glfw3 libglew32.a ${OPENGL_LIBRARIES})
