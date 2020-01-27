
#include "Core/Scene.h"
#include "Geometry/Mesh.h"
#include "Data/Texture.h"
#include "Shaders/Shader.h"
#include "Shaders/Material.h"

class Transform;

class TextureCreationTest : public Scene {
private:
    Mesh mesh;
    Texture texture;
    Material material=Material(shader,texture);
    Shader shader=Shader("../src/engine/Shaders/shadersSources/DefaultVertex.glsl",
                         "../src/engine/Shaders/shadersSources/DefaultFragment.glsl");

public:
    ~TextureCreationTest();

    void init(Viewport &viewport, Renderer &renderer, Window &window) override ;

};



