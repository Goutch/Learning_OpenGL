
#include "core/Scene.h"
#include "Geometry/VAO.h"
#include "graphics/data/Texture.h"
#include "graphics/shaders/Shader.h"
#include "graphics/Material.h"

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



