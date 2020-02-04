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
        src/main.cpp

        src/engine/Core/Engine.cpp
        src/engine/Core/Window.cpp
        src/engine/Core/Scene.cpp
        src/engine/Core/Log.cpp
        src/engine/Core/ViewPort.cpp
        src/engine/Core/Inputs.cpp
        src/engine/Core/Rendering/Renderer.cpp
        src/engine/Core/Rendering/SimpleRenderer.cpp
        src/engine/Core/Rendering/BatchRenderer.cpp

        src/engine/Entities/MeshRenderer.cpp
        src/engine/Entities/Transform.cpp
        src/engine/Entities/FPSController.cpp
        src/engine/Entities/Entity.cpp
        src/engine/Entities/Light/Light.cpp
        src/engine/Entities/Light/DirectionnalLight.cpp
        src/engine/Entities/Light/PointLight.cpp
        src/engine/Entities/Camera.cpp

        src/engine/Shaders/Shader.cpp
        src/engine/Shaders/Material.cpp
        src/engine/Shaders/LightMaterial.cpp
        src/engine/Shaders/FontText.cpp

        src/engine/Geometry/Geometry.cpp
        src/engine/Geometry/Mesh.cpp
        src/engine/Geometry/VAO.cpp
        src/engine/Geometry/VBO.cpp
        src/engine/Geometry/Quad.cpp

        src/engine/Data/Texture.cpp
        src/engine/Data/Text.cpp
        src/engine/Data/AtlasTexture.cpp
        src/engine/Data/Color.cpp
        src/engine/Data/FBO.cpp
        src/engine/Data/RBO.cpp

        src/engine/Utils/SimplexNoise.cpp
        src/engine/Utils/StringUtils.cpp
        src/engine/Utils/Timer.cpp
        src/engine/Utils/TimeUtils.cpp

        src/engine/Test/PerformanceTest.cpp
        src/engine/Test/AtlasTextureTest.cpp
        src/engine/Test/ImportModelTest.cpp
        src/engine/Test/TextureCreationTest.cpp
        src/engine/Test/FullSceneTest.cpp
        src/engine/Test/TextTest.cpp

        src/engine/Editor/Editor.cpp

        Dependencies/STB_IMAGE/stb_image.cpp
        src/engine/Test/PrimitivesTest.cpp src/engine/Test/PrimitivesTest.h src/engine/Core/Rendering/Primitive.cpp src/engine/Core/Rendering/Primitive.h src/engine/Test/LAB3.cpp src/engine/Test/LAB3.h)

target_link_libraries(OGL_Engine glfw3 libglew32.a ${OPENGL_LIBRARIES})
