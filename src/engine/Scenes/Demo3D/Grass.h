
#include <API_ALL.h>
class Grass :public SpacialEntity{

    Shader shader=Shader("../src/engine/scenes/Demo3D/GrassShader/GrassVertex.glsl","../src/engine/scenes/Demo3D/GrassShader/GrassGeometry.glsl","../src/engine/scenes/Demo3D/GrassShader/GrassFragment.glsl",false);
    SpacialMaterial* material;
    VAO vao;
    Timer timer;
public:
    SpacialMaterial& getMaterial();
    void init(SpacialScene &scene) override;

    void draw(const SpacialScene &scene) const override;

    void update(float delta, SpacialScene &scene) override;

    void onDestroy(SpacialScene &scene) override;

};

