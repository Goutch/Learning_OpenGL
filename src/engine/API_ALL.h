//
// Created by User on 2020-03-03.
//

#pragma once

#include "imgui.h"
#include "Core/Rendering/Renderer.h"
#include "Core/Log.h"
#include "Core/Canvas.h"
#include "Core/Scene.h"
#include "Core/SpacialScene.h"
#include "Core/Input.h"

#include "Entities/Entity.h"
#include "Entities/Spacial/Transform.h"
#include "Entities/Spacial/SpacialEntity.h"
#include "Entities/Spacial/FPSController.h"
#include "Entities/Spacial/Light/Light.h"
#include "Entities/Spacial/Light/DirectionnalLight.h"
#include "Entities/Spacial/Light/PointLight.h"
#include "Entities/Spacial/MeshRenderer.h"
#include "Entities/Spacial/Camera.h"
#include "Entities/Canvas/CanvasTransform.h"
#include "Entities/Canvas/CanvasEntity.h"
#include "Entities/Canvas/Text.h"
#include "Entities/Canvas/Rect.h"
#include "Entities/Canvas/Line.h"
#include "Entities/Canvas/Ellipse.h"

#include "Events/KeyPressListener.h"
#include "Events/CanvasResizeListener.h"

#include "Geometry/Geometry.h"
#include "Ressources/Quad.h"
#include "Ressources/Mesh.h"
#include "Ressources/VAO.h"
#include "Ressources/AtlasTexture.h"
#include "Ressources/Texture.h"
#include "Ressources/Color.h"
#include "Ressources/VBO.h"

#include "Shaders/Shader.h"
#include "Shaders/Material.h"
#include "Shaders/TexturedMaterial.h"
#include "Shaders/Canvas/CanvasMaterial.h"
#include "Shaders/Canvas/FontMaterial.h"
#include "Shaders/Spacial/SpacialMaterial.h"
#include "Shaders/Spacial/LightMaterial.h"

#include "Utils/Timer.h"
#include "Utils/SimplexNoise.h"
#include "Utils/TimeUtils.h"
#include "Utils/StringUtils.h"