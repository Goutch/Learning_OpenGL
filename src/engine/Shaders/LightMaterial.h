#pragma once

#include "Material.h"

class LightMaterial : public Material {
private:
    float shineFactor = 1;
    float dampFactor = 1;
    int ambient_light_location,
            damp_factor_location,
            shine_factor_location,
            point_light_count_location,
            point_light_positions_location,
            point_light_radius_location,
            point_light_colors_location;

public:
    LightMaterial();

    LightMaterial(Shader &shader);

    LightMaterial(Shader &shader, const Color &color);

    LightMaterial(Shader &shader, Texture &texture);

    LightMaterial(Shader &shader, Texture &texture, const Color &color);

    void bind(const Scene &scene) const override;

    LightMaterial &shine(float);

    LightMaterial &damp(float);

private:
    void getUniformsLocations();
};


