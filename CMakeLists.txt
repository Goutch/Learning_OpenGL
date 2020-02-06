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
        src/engine/Core/Debug/Log.cpp
        src/engine/Core/Canvas.cpp
        src/engine/Core/Rendering/Renderer.cpp
        src/engine/Core/Rendering/SimpleRenderer.cpp
        src/engine/Core/Rendering/BatchRenderer.cpp

        src/engine/Entities/Spacial/MeshRenderer.cpp
        src/engine/Entities/Spacial/Transform.cpp
        src/engine/Entities/Spacial/FPSController.cpp
        src/engine/Entities/Spacial/SpacialEntity.cpp
        src/engine/Entities/Spacial/Light/Light.cpp
        src/engine/Entities/Spacial/Light/DirectionnalLight.cpp
        src/engine/Entities/Spacial/Light/PointLight.cpp
        src/engine/Entities/Spacial/Camera.cpp

        src/engine/Shaders/Shader.cpp
        src/engine/Shaders/Spacial/SpacialMaterial.cpp
        src/engine/Shaders/Spacial/LightMaterial.cpp
        src/engine/Shaders/Canvas/FontMaterial.cpp
        src/engine/Shaders/Canvas/FontMaterial.h

        src/engine/Geometry/Geometry.cpp
        src/engine/Geometry/Mesh.cpp
        src/engine/Geometry/VAO.cpp
        src/engine/Geometry/VBO.cpp
        src/engine/Geometry/Quad.cpp

        src/engine/Data/Texture.cpp
        src/engine/Data/AtlasTexture.cpp
        src/engine/Data/Color.cpp
        src/engine/Data/FBO.cpp
        src/engine/Data/RBO.cpp

        src/engine/Utils/SimplexNoise.cpp
        src/engine/Utils/StringUtils.cpp
        src/engine/Utils/Timer.cpp
        src/engine/Utils/TimeUtils.cpp

        src/engine/Test/SpacialSceneTest.cpp
        src/engine/Test/TextTest.cpp
        src/engine/Test/PrimitivesTest.h

        src/engine/Editor/Editor.cpp
        src/engine/Entities/Canvas/Text.cpp
        src/engine/Entities/Canvas/Text.h
        Dependencies/STB_IMAGE/stb_image.cpp
        src/engine/Test/PrimitivesTest.cpp
        src/engine/Test/LAB3.h
        src/engine/Test/LAB3.cpp


        src/engine/Test/LSystem.cpp src/engine/Test/LSystem.h src/engine/Entities/Canvas/Rect.cpp src/engine/Entities/Canvas/Rect.h src/engine/Entities/Canvas/Ellipse.cpp src/engine/Entities/Canvas/Ellipse.h src/engine/Entities/Canvas/Line.cpp src/engine/Entities/Canvas/Line.h src/engine/Entities/Canvas/CanvasTransform.cpp src/engine/Entities/Canvas/CanvasTransform.h src/engine/Entities/Canvas/CanvasEntity.cpp src/engine/Entities/Canvas/CanvasEntity.h src/engine/Core/SpacialScene.cpp src/engine/Core/SpacialScene.h src/engine/Shaders/Material.h src/engine/Shaders/Material.cpp src/engine/Shaders/Canvas/CanvasMaterial.cpp src/engine/Shaders/Canvas/CanvasMaterial.h src/engine/Shaders/TexturedMaterial.cpp src/engine/Shaders/TexturedMaterial.h)

target_link_libraries(OGL_Engine glfw3 libglew32.a ${OPENGL_LIBRARIES})
