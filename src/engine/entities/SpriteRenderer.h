#include "Entity.h"
class Sprite;
class EntityShader;
class SpriteRenderer:public Entity {
private:
    Sprite* sprite;
    EntityShader* shader;
public:
    SpriteRenderer(Sprite* sprite, EntityShader* shader, glm::vec3 pos);

private:
    void render(Renderer &renderer) override;

    void update(float delta, Window &window) override;

    EntityShader &getShader() override;

    Drawable &getDrawable() override;
};
