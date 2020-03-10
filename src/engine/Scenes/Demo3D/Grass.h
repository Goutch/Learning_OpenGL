
#include <API_ALL.h>
class Grass :public Entity{

    Shader shader=Shader("../src/engine/scenes/Demo3D/GrassShader/GrassVertex.glsl","../src/engine/scenes/Demo3D/GrassShader/GrassGeometry.glsl","../src/engine/scenes/Demo3D/GrassShader/GrassFragment.glsl",false);
    EntityMaterial* material;
    VAO vao;
    Timer timer;
public:
    EntityMaterial& getMaterial();
    void init(Scene &scene) override;

    void draw(const Scene &scene) const override;

    void update(float delta, Scene &scene) override;

    void onDestroy(Scene &scene) override;

};

