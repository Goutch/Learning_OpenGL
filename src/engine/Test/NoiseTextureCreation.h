
#include "Core/Scene.h"
#include "Geometry/VAO.h"
#include "Data/Texture.h"
#include "Shaders/Shader.h"
#include "Shaders/Material.h"

class Transform;

class NoiseTextureCreation : public Scene {
private:
    VAO sprite;
    Texture texture;
    Material material;
    Shader shader=Shader("../src/engine/Shaders/shadersSources/EntityVertex.glsl",
                         "../src/engine/Shaders/shadersSources/EntityFragment.glsl");

public:
    ~NoiseTextureCreation();

    void init(Window &window, Renderer &renderer) override;

};



