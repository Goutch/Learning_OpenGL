
#include "core/Scene.h"
#include "graphics/data/Sprite.h"
#include "graphics/data/AtlasTexture.h"
#include "graphics/shaders/EntityShader.h"
class Transform;
class TextureCreation:public Scene {
private:
    Sprite sprite;
    Texture texture;
    EntityShader shader;
    Transform* camera;
public:
    ~TextureCreation();
    void init(Window &window, Renderer &renderer) override;

    void update(float delta) override;
};



