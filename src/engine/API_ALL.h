//
// Created by User on 2020-03-03.
//

#pragma once

#include "imgui.h"
#include "Core/Rendering/Renderer.h"
#include "Core/Log.h"
#include "Core/Canvas.h"
#include "Core/Scene.h"
#include "Core/Scene.h"
#include "Core/Input.h"

#include "Entities/Entity.h"
#include "Entities/Transform.h"
#include "Entities/Entity.h"
#include "Entities/FPSController.h"
#include "Entities/Light/Light.h"
#include "Entities/Light/DirectionnalLight.h"
#include "Entities/Light/PointLight.h"
#include "Entities/MeshRenderer.h"
#include "Entities/Camera.h"
#include "Entities/Text.h"


#include "Events/KeyPressListener.h"
#include "Events/CanvasResizeListener.h"

#include "Utils/Geometry.h"
#include "Ressources/Quad.h"
#include "Ressources/Mesh.h"
#include "Ressources/VAO.h"
#include "Ressources/AtlasTexture.h"
#include "Ressources/Texture.h"
#include "Ressources/Color.h"
#include "Ressources/VBO.h"

#include "Ressources/Shaders/Shader.h"
#include "Ressources/Shaders/Material/Material.h"
#include "Ressources/Shaders/Material/TexturedMaterial.h"
#include "Ressources/Shaders/Material/FontMaterial.h"
#include "Ressources/Shaders/Material/EntityMaterial.h"
#include "Ressources/Shaders/Material/LightMaterial.h"

#include "Utils/Timer.h"
#include "Utils/TimeUtils.h"
#include "Utils/StringUtils.h"