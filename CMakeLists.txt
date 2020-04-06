cmake_minimum_required(VERSION 3.14)
project(OGL_Engine)

set(CMAKE_CXX_STANDARD 11)

include_directories(src/engine)
include_directories(src/app)
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
set(IMGUI_FILES
        Dependencies/IMGUI/imgui.cpp
        Dependencies/IMGUI/imgui_draw.cpp
        Dependencies/IMGUI/imgui_widgets.cpp
        Dependencies/IMGUI/imgui_impl_opengl3.cpp
        Dependencies/IMGUI/imgui_impl_glfw.cpp)

add_executable(OGL_Engine
        ${IMGUI_FILES}
        Dependencies/STB_IMAGE/stb_image.cpp

        src/main.cpp
        src/engine/API_ALL.h

        src/engine/API/GL/GL_API.cpp
        src/engine/API/GL/GL_Debug.cpp

        src/engine/Core/Engine.cpp
        src/engine/Core/Engine.cpp
        src/engine/Core/Window.cpp
        src/engine/Core/Canvas.cpp
        src/engine/Core/Rendering/Renderer.cpp
        src/engine/Core/Rendering/BatchRenderer.cpp
        src/engine/Core/Rendering/FBO.cpp
        src/engine/Core/Rendering/RBO.cpp
        src/engine/Core/Scene.cpp
        src/engine/Core/Log.cpp
        src/engine/Core/Input.cpp
        src/engine/Core/Input.h


        src/engine/Entities/MeshRenderer.cpp
        src/engine/Entities/Transform.cpp
        src/engine/Entities/FPSController.cpp
        src/engine/Entities/Entity.cpp
        src/engine/Entities/Light/Light.cpp
        src/engine/Entities/Light/DirectionnalLight.cpp
        src/engine/Entities/Light/PointLight.cpp
        src/engine/Entities/Camera.cpp
        src/engine/Entities/Text.cpp
        src/engine/Entities/Text.h

        src/engine/Ressources/Shaders/Shader.cpp
        src/engine/Ressources/Shaders/Material/EntityMaterial.cpp
        src/engine/Ressources/Shaders/Material/LightMaterial.cpp
        src/engine/Ressources/Shaders/Material/FontMaterial.cpp
        src/engine/Ressources/Shaders/Material/FontMaterial.h
        src/engine/Ressources/Shaders/Material/Material.cpp
        src/engine/Ressources/Shaders/Material/TexturedMaterial.cpp

        src/engine/Math/Plane.cpp


        src/engine/Ressources/Mesh.cpp
        src/engine/Ressources/VAO.cpp
        src/engine/Ressources/VBO.cpp
        src/engine/Ressources/Quad.cpp
        src/engine/Ressources/Cube.cpp
        src/engine/Ressources/Cube.h
        src/engine/Ressources/Sphere.cpp
        src/engine/Ressources/Sphere.h
        src/engine/Ressources/Texture.cpp
        src/engine/Ressources/AtlasTexture.cpp
        src/engine/Ressources/Color.cpp


        src/engine/Utils/StringUtils.cpp
        src/engine/Utils/Timer.cpp
        src/engine/Utils/TimeUtils.cpp
        src/engine/Utils/SimplexNoise.cpp
        src/engine/Utils/Geometry.cpp

        src/app/Scenes/Demo3D/SpacialSceneDemo.cpp
        src/app/Scenes/Demo3D/Grass.cpp
        src/app/Scenes/Demo3D/Grass.h

        src/app/Scenes/Editor/Editor.cpp
        src/app/Scenes/Editor/Editor.h
        src/app/Scenes/Editor/PropertyWindow.cpp
        src/app/Scenes/Editor/PropertyWindow.h
        src/app/Scenes/Editor/SceneTreeWindow.cpp
        src/app/Scenes/Editor/SceneTreeWindow.h
        src/app/Scenes/Editor/CameraWindow.cpp
        src/app/Scenes/Editor/CameraWindow.h
        src/app/Scenes/Editor/EntityCreationWindow.cpp
        src/app/Scenes/Editor/EntityCreationWindow.h

        src/app/Scenes/Test/VoxelDictionary.h
        src/app/Scenes/Test/Test.cpp
        src/app/Scenes/Test/Test.h
        src/app/Scenes/Test/Chunk.h
        src/app/Scenes/Test/Chunk.cpp
        src/app/Scenes/Test/ChunkGenerator.cpp
        src/app/Scenes/Test/ChunkGenerator.h
        src/app/Scenes/Test/Voxel.h
        src/app/Scenes/Test/ChunkRenderer.cpp
        src/app/Scenes/Test/ChunkRenderer.h
        src/app/Scenes/Test/ChunkManager.cpp
        src/app/Scenes/Test/ChunkManager.h
        src/app/Scenes/Test/ChunkLoader.cpp
        src/app/Scenes/Test/ChunkLoader.h

        src/engine/Utils/Thread.cpp src/engine/Utils/Thread.h)

target_link_libraries(OGL_Engine glfw3 libglew32.a ${OPENGL_LIBRARIES})
