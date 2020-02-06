#pragma once

#include "SpacialMaterial.h"
#include <Core/SpacialScene.h>

class LightMaterial : public SpacialMaterial {
private:
    const SpacialScene *scene;
    mutable std::vector<const Texture *> boundShadowMaps;
    float shineFactor = 0;
    float dampFactor = 16;
    mat4 bias_mat = mat4(0.5f, 0.0f, 0.0f, 0.0f,
                         0.0f, 0.5f, 0.0f, 0.0f,
                         0.0f, 0.0f, 0.5f, 0.0f,
                         0.5f, 0.5f, 0.5f, 1.0f);
    int ambient_light_location,
            damp_factor_location,
            shine_factor_location,

            point_light_count_location,
            point_light_positions_location,
            point_light_radius_location,
            point_light_colors_location,

            directional_light_count_location,
            directional_light_shadowMap_location,
            directional_light_color_location,
            directional_light_direction_location,

            light_space_mat_location,

            view_pos_location;

public:
    LightMaterial(const Shader &shader, const SpacialScene &scene);

    LightMaterial(const Shader &shader, const Color &color, const SpacialScene &scene);

    LightMaterial(const Shader &shader, const Texture &texture, const SpacialScene &scene);

    LightMaterial(const Shader &shader, const Texture &texture, const Color &color, const SpacialScene &scene);

    void unbind() const override;

    void bind() const override;

    void shine(float);

    void damp(float);

protected:
    virtual void getUniformsLocations() override ;
};


