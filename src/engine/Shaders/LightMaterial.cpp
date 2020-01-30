//
// Created by User on 2020-01-19.
//

#include "LightMaterial.h"
#include "vector"
#include "Entities/Light/PointLight.h"
#include "Entities/Light/DirectionnalLight.h"
#include "Core/Scene.h"
#include "Data/Texture.h"
#include "Entities/Camera.h"
void LightMaterial::bind() const {
    Material::bind();
    s->loadUniform(ambient_light_location, (vec3) scene->getAmbientLight().data);
    s->loadUniform(damp_factor_location, dampFactor);
    s->loadUniform(shine_factor_location, shineFactor);

    std::vector<PointLight *> pointLights = scene->getPointLights();
    s->loadUniform(point_light_count_location, (int) pointLights.size());
    s->loadUniform(view_pos_location, scene->getCamera().transform.position());
    if (pointLights.size() > 0) {
        std::vector<float> radius;
        std::vector<vec3> positions;
        std::vector<vec3> colors;
        for (unsigned int i = 0; i < pointLights.size(); ++i) {
            radius.push_back(pointLights[i]->getRadius());
            positions.push_back(pointLights[i]->transform.position());
            colors.emplace_back(pointLights[i]->getColor().data);
            if (i == 4)break;
        }
        s->loadUniformVec3Array(point_light_positions_location, positions.data(), positions.size());
        s->loadUniformVec3Array(point_light_colors_location, colors.data(), colors.size());
        s->loadUniformFloatArray(point_light_radius_location, radius.data(), radius.size());
    }
    std::vector<DirectionalLight *> directionalLights = scene->getDirectionalLights();
    s->loadUniform(directional_light_count_location,(int)directionalLights.size());
    if (directionalLights.size() > 0) {
        boundShadowMaps.push_back(&(directionalLights[0]->shadowMap()));

        glm::mat4 depth_bias_mat=bias_mat* directionalLights[0]->getLightSpaceMat();
        s->loadUniform(light_space_mat_location, depth_bias_mat);
        s->loadUniform(directional_light_shadowMap_location, 1);
        s->loadUniform(directional_light_color_location, vec3(directionalLights[0]->getColor().data));
        s->loadUniform(directional_light_direction_location, vec3(directionalLights[0]->transform.forward()));
        boundShadowMaps[0]->bind(1);
    }


}

void LightMaterial::unbind() const {
    Material::unbind();
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

void LightMaterial::getUniformsLocations() {

    point_light_count_location = s->uniformLocation("point_light_count");
    shine_factor_location = s->uniformLocation("shine_factor");
    damp_factor_location = s->uniformLocation("damp_factor");
    ambient_light_location = s->uniformLocation("ambient_light");
    point_light_positions_location = s->uniformLocation("point_light_positions");
    point_light_radius_location = s->uniformLocation("point_light_radius");
    point_light_colors_location = s->uniformLocation("point_light_colors");
    view_pos_location = s->uniformLocation("view_pos");

    directional_light_shadowMap_location = s->uniformLocation("directional_light_shadowMap");
    directional_light_color_location = s->uniformLocation("directional_light_color");
    light_space_mat_location=s->uniformLocation("depth_bias_mat");
    directional_light_count_location=s->uniformLocation("directional_light_count");
    directional_light_direction_location=s->uniformLocation("directional_light_direction");
}

LightMaterial::LightMaterial() : Material() {
    getUniformsLocations();
}

LightMaterial::LightMaterial(const Shader &shader, const Scene &scene) : Material(shader) {
    getUniformsLocations();
    this->scene = &scene;
}

LightMaterial::LightMaterial(const Shader &shader, const Color &color, const Scene &scene) : Material(shader, color) {
    getUniformsLocations();
    this->scene = &scene;
}

LightMaterial::LightMaterial(const Shader &shader, const Texture &texture, const Scene &scene) : Material(shader, texture) {
    getUniformsLocations();
    this->scene = &scene;
}

LightMaterial::LightMaterial(const Shader &shader, const Texture &texture, const Color &color, const Scene &scene) : Material(shader,
                                                                                                          texture,
                                                                                                          color) {
    getUniformsLocations();
    this->scene = &scene;
}


