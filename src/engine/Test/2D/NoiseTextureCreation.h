
#include "core/Scene.h"
#include "Geometry/VAO.h"
#include "Geometry/data/Texture.h"
#include "Geometry/shaders/Shader.h"
#include "Geometry/Material.h"

class Transform;

class NoiseTextureCreation : public Scene {
private:
    VAO sprite;
    Texture texture;
    Material material;
    Shader shader = Shader("../src/engine/Geometry/shaders/shadersSources/EntityVertex.glsl",
                           "../src/engine/Geometry/shaders/shadersSources/EntityFragment.glsl");
    Transform *camera;
public:
    ~NoiseTextureCreation();

    void init(Window &window, Renderer &renderer) override;

    void update(float delta) override;
};



