
#include "core/Scene.h"
#include "graphics/data/Sprite.h"
#include "graphics/data/Texture.h"
#include "graphics/shaders/Shader.h"
#include "graphics/Material.h"

class Transform;

class NoiseTextureCreation : public Scene {
private:
    Sprite sprite;
    Texture texture;
    Material material;
    Shader shader = Shader("../src/engine/graphics/shaders/shadersSources/EntityVertex.glsl",
                           "../src/engine/graphics/shaders/shadersSources/EntityFragment.glsl");
    Transform *camera;
public:
    ~NoiseTextureCreation();

    void init(Window &window, Renderer &renderer) override;

    void update(float delta) override;
};



