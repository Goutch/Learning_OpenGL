#include "Entity.h"
class Sprite;
class BaseShader;
class SpriteRenderer:public Entity {
private:
    Sprite* sprite;
    BaseShader* shader;
public:
    SpriteRenderer(Sprite* sprite,BaseShader* shader,glm::vec3 pos);

private:
    void render(Renderer &renderer) override;

    void update(float delta, Window &window) override;

    BaseShader &getShader() override;

    Drawable &getDrawable() override;
};
