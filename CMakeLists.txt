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

message("Including IMGUI")
include_directories(Dependencies/IMGUI)
set(IMGUI_FILES         Dependencies/IMGUI/imgui.cpp
        Dependencies/IMGUI/imgui_draw.cpp
        Dependencies/IMGUI/imgui_widgets.cpp
        Dependencies/IMGUI/imgui_impl_opengl3.cpp
        Dependencies/IMGUI/imgui_impl_glfw.cpp )

add_executable(OGL_Engine
        ${IMGUI_FILES}
        Dependencies/STB_IMAGE/stb_image.cpp

        src/main.cpp

        src/engine/API/GL/GL_API.cpp
        src/engine/API/GL/GL_Debug.cpp

        src/engine/Core/Engine.cpp
        src/engine/Core/Engine.cpp
        src/engine/Core/Window.cpp
        src/engine/Core/Scene.cpp
        src/engine/Core/Canvas.cpp
        src/engine/Core/Rendering/Renderer.cpp
        src/engine/Core/Rendering/SimpleRenderer.cpp
        src/engine/Core/Rendering/BatchRenderer.cpp
        src/engine/Core/SpacialScene.cpp
        src/engine/Core/Log.cpp

        src/engine/Entities/Spacial/MeshRenderer.cpp
        src/engine/Entities/Spacial/Transform.cpp
        src/engine/Entities/Spacial/FPSController.cpp
        src/engine/Entities/Spacial/SpacialEntity.cpp
        src/engine/Entities/Spacial/Light/Light.cpp
        src/engine/Entities/Spacial/Light/DirectionnalLight.cpp
        src/engine/Entities/Spacial/Light/PointLight.cpp
        src/engine/Entities/Spacial/Camera.cpp
        src/engine/Entities/Canvas/Rect.cpp
        src/engine/Entities/Canvas/Line.cpp
        src/engine/Entities/Canvas/CanvasTransform.cpp
        src/engine/Entities/Canvas/CanvasEntity.cpp
        src/engine/Entities/Canvas/Text.cpp
        src/engine/Entities/Canvas/Text.h
        src/engine/Entities/Entity.cpp
        src/engine/Entities/Canvas/Image.cpp

        src/engine/Shaders/Shader.cpp
        src/engine/Shaders/Spacial/SpacialMaterial.cpp
        src/engine/Shaders/Spacial/LightMaterial.cpp
        src/engine/Shaders/Canvas/FontMaterial.cpp
        src/engine/Shaders/Canvas/FontMaterial.h
        src/engine/Shaders/Material.cpp
        src/engine/Shaders/Canvas/CanvasMaterial.cpp
        src/engine/Shaders/TexturedMaterial.cpp

        src/engine/Geometry/Geometry.cpp
        src/engine/Ressources/Mesh.cpp
        src/engine/Ressources/VAO.cpp
        src/engine/Ressources/VBO.cpp
        src/engine/Ressources/Quad.cpp

        src/engine/Ressources/Texture.cpp
        src/engine/Ressources/AtlasTexture.cpp
        src/engine/Ressources/Color.cpp
        src/engine/Core/Rendering/FBO.cpp
        src/engine/Core/Rendering/RBO.cpp

        src/engine/Utils/SimplexNoise.cpp
        src/engine/Utils/StringUtils.cpp
        src/engine/Utils/Timer.cpp
        src/engine/Utils/TimeUtils.cpp

        src/engine/Scenes/Editor/Editor.cpp

        src/engine/Scenes/SpacialSceneDemo.cpp
        src/engine/Scenes/TextTest.cpp
        src/engine/Scenes/ApplicationDrawing2D.cpp

        src/engine/Scenes/Editor/Editor.cpp
        src/engine/Entities/Entity.cpp src/engine/Entities/Entity.h
        src/engine/Core/Input.cpp src/engine/Core/Input.h
        src/engine/Entities/Canvas/Ellipse.cpp
        src/engine/Entities/Canvas/Ellipse.h
        src/engine/API_ALL.h
)

target_link_libraries(OGL_Engine glfw3 libglew32.a ${OPENGL_LIBRARIES})
