//
// Created by User on 2020-01-19.
//

#include "LightMaterial.h"
#include "Entities/Light/PointLight.h"
#include "Entities/Light/DirectionnalLight.h"
#include "Core/Scene.h"
#include "Ressources/Texture.h"
#include <Ressources/Shaders/Shader.h>
#include <Entities/Camera.h>
#include <set>
void LightMaterial::bind() const {
    EntityMaterial::bind();
    shader->loadUniform(has_normal_map_location,has_normal_map);
    if(has_normal_map){
        shader->loadUniform(normal_map_location,1);
        normal_map->bind(1);
    }
    shader->loadUniform(ambient_light_location, (vec3) scene->getAmbientLight());
    shader->loadUniform(damp_factor_location, dampFactor);
    shader->loadUniform(shine_factor_location, shineFactor);
    shader->loadUniform(tonal_mapping_location, scene->isTonalMapping());

    auto pointLights =PointLight::getInstances();
    shader->loadUniform(point_light_count_location, (int) pointLights.size());
    shader->loadUniform(view_pos_location, scene->getCamera().transform.position());
    int count=0;
    if (pointLights.size() > 0) {
        std::vector<float> radius;
        std::vector<vec3> positions;
        std::vector<vec3> colors;
        for (auto pl  = pointLights.begin(); pl!=pointLights.end() ; pl++) {
            radius.push_back((*pl)->getRadius());
            positions.push_back((*pl)->transform.position());
            colors.emplace_back((*pl)->getColor());
            if (count == MAX_POINT)break;
            count++;
        }
        shader->loadUniformVec3Array(point_light_positions_location, positions.data(), positions.size());
        shader->loadUniformVec3Array(point_light_colors_location, colors.data(), colors.size());
        shader->loadUniformFloatArray(point_light_radius_location, radius.data(), radius.size());
    }
    count=0;
    auto directionalLights = DirectionalLight::getInstances();
    shader->loadUniform(directional_light_count_location, (int)directionalLights.size());
    for (auto dl=directionalLights.begin(); dl!=directionalLights.end(); ++dl) {
        glm::mat4 depth_bias_mat=bias_mat* (*dl)->getLightSpaceMat();
        shader->loadUniform(light_space_mat_location, depth_bias_mat);
        shader->loadUniform(directional_light_shadowMap_location, count+2);
        shader->loadUniform(directional_light_color_location, vec3((*dl)->getColor()));
        shader->loadUniform(directional_light_direction_location, vec3((*dl)->transform.forward()));
        (*dl)->getShadowMap().bind(count+2);
        count++;
    }

}

void LightMaterial::unbind() const {
    EntityMaterial::unbind();
    if(has_normal_map)normal_map->unbind(1);
    auto directionalLights = DirectionalLight::getInstances();
    int count=0;
    for (auto dl=directionalLights.begin(); dl!=directionalLights.end(); ++dl) {
        (*dl)->getShadowMap().unbind(count+2);
        count++;
    }

}

void LightMaterial::shine(float shine) {
    this->shineFactor = shine;

}

void LightMaterial::damp(float damp) {
    this->dampFactor = damp;

}

void LightMaterial::getUniformsLocations()  const{
    EntityMaterial::getUniformsLocations();
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
    tonal_mapping_location=shader->uniformLocation("tonal_mapping");
    has_normal_map_location=shader->uniformLocation("has_normal_map");
    normal_map_location=shader->uniformLocation("normal_map");

}



LightMaterial::LightMaterial(const Shader &shader, Scene &scene) : EntityMaterial(shader) {
    this->scene = &scene;
}

LightMaterial::LightMaterial(const Shader &shader, const Color &color,Scene &scene) : EntityMaterial(shader, color) {
    this->scene = &scene;
}

LightMaterial::LightMaterial(const Shader &shader, const Texture &texture,Scene &scene) : EntityMaterial(shader, texture) {
    this->scene = &scene;
}

LightMaterial::LightMaterial(const Shader &shader, const Texture &texture, const Color &color,Scene &scene) : EntityMaterial(shader,
                                                                                                                             texture,
                                                                                                                             color) {
    this->scene = &scene;
}

void LightMaterial::normalMap(Texture *normal_map) {
    if(normal_map)
    {
        this->normal_map=normal_map;
        has_normal_map=true;

    } else{
        has_normal_map=false;
    }
}


