#include "Light.h"
class PointLight :public Light{
    static std::set<const PointLight*> instances;
public:
    static const std::set<const PointLight*>& getInstances();

private:
    float radius=10;
public:
    void onDestroy(Scene &scene) override;

    void init(Scene &scene) override;

    PointLight(const Color& color, float radius,vec3 position);
    PointLight(const Color& color,vec3 position);
    PointLight(float radius,vec3 position);
    PointLight(vec3 position);
    PointLight();
    float getRadius()const ;
};


