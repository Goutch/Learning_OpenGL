//
// Created by User on 2020-01-19.
//

#include "LightMaterial.h"
#include "Entities/Spacial/Light/PointLight.h"
#include "Entities/Spacial/Light/DirectionnalLight.h"
#include "Core/SpacialScene.h"
#include "Ressources/Texture.h"
#include <Shaders/Shader.h>
#include <Core/Log.h>
void LightMaterial::bind() const {
    SpacialMaterial::bind();
    shader->loadUniform(ambient_light_location, (vec3) scene->getAmbientLight());
    shader->loadUniform(damp_factor_location, dampFactor);
    shader->loadUniform(shine_factor_location, shineFactor);

    std::vector<PointLight *> pointLights = scene->getPointLights();
    shader->loadUniform(point_light_count_location, (int) pointLights.size());
    shader->loadUniform(view_pos_location, scene->getCamera().transform.position());
    if (pointLights.size() > 0) {
        std::vector<float> radius;
        std::vector<vec3> positions;
        std::vector<vec3> colors;
        for (unsigned int i = 0; i < pointLights.size(); ++i) {
            radius.push_back(pointLights[i]->getRadius());
            positions.push_back(pointLights[i]->transform.position());
            colors.emplace_back(pointLights[i]->getColor());
            if (i == 4)break;
        }
        shader->loadUniformVec3Array(point_light_positions_location, positions.data(), positions.size());
        shader->loadUniformVec3Array(point_light_colors_location, colors.data(), colors.size());
        shader->loadUniformFloatArray(point_light_radius_location, radius.data(), radius.size());
    }
    std::vector<DirectionalLight *> directionalLights = scene->getDirectionalLights();
    shader->loadUniform(directional_light_count_location, (int)directionalLights.size());
    if (directionalLights.size() > 0) {
        boundShadowMaps.push_back(&(directionalLights[0]->shadowMap()));

        glm::mat4 depth_bias_mat=bias_mat* directionalLights[0]->getLightSpaceMat();
        shader->loadUniform(light_space_mat_location, depth_bias_mat);
        shader->loadUniform(directional_light_shadowMap_location, 1);
        shader->loadUniform(directional_light_color_location, vec3(directionalLights[0]->getColor()));
        shader->loadUniform(directional_light_direction_location, vec3(directionalLights[0]->transform.forward()));
        boundShadowMaps[0]->bind(1);
    }
}

void LightMaterial::unbind() const {
    SpacialMaterial::unbind();
    for (int i = 0; i < boundShadowMaps.size(); ++i) {
        boundShadowMaps[i]->unbind(i+1);
    }
    boundShadowMaps.clear();
}

void LightMaterial::shine(float shine) {
    this->shineFactor = shine;

}

void LightMaterial::damp(float damp) {
    this->dampFactor = damp;

}

void LightMaterial::getUniformsLocations()  const{
    SpacialMaterial::getUniformsLocations();
    point_light_count_location = shader->uniformLocation("point_light_count");
    shine_factor_location = shader->uniformLocation("shine_factor");
    damp_factor_location = shader->uniformLocation("damp_factor");
    ambient_light_location = shader->uniformLocation("ambient_light");
    point_light_positions_location = shader->uniformLocation("point_light_positions");
    point_light_radius_location = shader->uniformLocation("point_light_radius");
    point_light_colors_location = shader->uniformLocation("point_light_colors");
    view_pos_location = shader->uniformLocation("view_pos");

    directional_light_shadowMap_location = shader->uniformLocation("directional_light_shadowMap");
    directional_light_color_location = shader->uniformLocation("directional_light_color");
    light_space_mat_location=shader->uniformLocation("depth_bias_mat");
    directional_light_count_location=shader->uniformLocation("directional_light_count");
    directional_light_direction_location=shader->uniformLocation("directional_light_direction");
}



LightMaterial::LightMaterial(const Shader &shader, SpacialScene &scene) : SpacialMaterial(shader) {
    this->scene = &scene;
}

LightMaterial::LightMaterial(const Shader &shader, const Color &color,SpacialScene &scene) : SpacialMaterial(shader, color) {
    this->scene = &scene;
}

LightMaterial::LightMaterial(const Shader &shader, const Texture &texture,SpacialScene &scene) : SpacialMaterial(shader, texture) {
    this->scene = &scene;
}

LightMaterial::LightMaterial(const Shader &shader, const Texture &texture, const Color &color,SpacialScene &scene) : SpacialMaterial(shader,
                                                                                                                                     texture,
                                                                                                                                     color) {
    this->scene = &scene;
}


