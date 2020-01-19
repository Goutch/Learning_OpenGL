//
// Created by User on 2020-01-19.
//

#include "LightMaterial.h"
#include "vector"
#include "Entities/Light/PointLight.h"
#include "Core/Scene.h"

void LightMaterial::bind(const Scene &scene) const {
    Material::bind(scene);
    s->loadUniform(ambient_light_location, (vec3)scene.getAmbientLight().data);
    s->loadUniform(damp_factor_location, dampFactor);
    s->loadUniform(shine_factor_location, shineFactor);

    std::vector<PointLight *> pointLights = scene.getPointLights();
    s->loadUniform(point_light_count_location, (int) pointLights.size());
    if(pointLights.size()>0)
    {
        std::vector<float> radius;
        std::vector<vec3> positions;
        std::vector<vec3> colors;
        for (int i = 0; i < pointLights.size(); ++i) {
            radius.push_back(pointLights[i]->getRadius());
            positions.push_back(pointLights[i]->transform.position());
            colors.emplace_back(pointLights[i]->getColor().data);
        }
        s->loadUniformVec3Array(point_light_positions_location,positions.data(),positions.size());
        s->loadUniformVec3Array(point_light_colors_location,colors.data(),colors.size());
        s->loadUniformFloatArray(point_light_radius_location,radius.data(),radius.size());
    }
}

LightMaterial &LightMaterial::shine(float shine) {
    this->shineFactor = shine;
    return *this;
}

LightMaterial &LightMaterial::damp(float damp) {
    this->dampFactor = damp;
    return *this;
}

void LightMaterial::getUniformsLocations() {

    point_light_count_location = s->uniformLocation("point_light_count");
    shine_factor_location = s->uniformLocation("shine_factor");
    damp_factor_location = s->uniformLocation("damp_factor");
    ambient_light_location = s->uniformLocation("ambient_light");
    point_light_positions_location = s->uniformLocation("point_light_positions");
    point_light_radius_location = s->uniformLocation("point_light_radius");
    point_light_colors_location = s->uniformLocation("point_light_colors");
}

LightMaterial::LightMaterial():Material() {
    getUniformsLocations();
}

LightMaterial::LightMaterial(Shader &shader) : Material(shader) {
    getUniformsLocations();
}

LightMaterial::LightMaterial(Shader &shader, const Color &color) : Material(shader, color) {
    getUniformsLocations();
}

LightMaterial::LightMaterial(Shader &shader, Texture &texture) : Material(shader, texture) {
    getUniformsLocations();
}

LightMaterial::LightMaterial(Shader &shader, Texture &texture, const Color &color) : Material(shader, texture, color) {
    getUniformsLocations();
}
