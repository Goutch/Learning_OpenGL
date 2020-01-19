#include "Light.h"
class PointLight :public Light{
    float radius=10;
public:
    PointLight(const Color& color, float radius,vec3 position);
    PointLight(const Color& color,vec3 position);
    PointLight(float radius,vec3 position);
    PointLight(vec3 position);
    PointLight();
    float getRadius();
};


