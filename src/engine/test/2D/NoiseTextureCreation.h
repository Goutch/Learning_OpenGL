
#include "core/Scene.h"
#include "graphics/data/Sprite.h"
#include "graphics/data/Texture.h"
#include "graphics/shaders/EntityShader.h"
class Transform;
class NoiseTextureCreation: public Scene {
private:
    Sprite sprite;
    Texture texture;
    EntityShader shader;
    Transform* camera;
public:
    ~NoiseTextureCreation();
    void init(Window &window, Renderer &renderer) override;

    void update(float delta) override;
};



