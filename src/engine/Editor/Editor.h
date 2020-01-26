//
// Created by le6mon on 2020-01-26.
//
#include <Shaders/Material.h>
#include "Core/Scene.h"
#include "Geometry/Mesh.h"
#include "Shaders/Shader.h"
#include "Data/Texture.h"
#include "Test/FullSceneTest.h"

class Editor : public Scene{
private:
    //TODO Delete reference
    Scene* currentScene = new FullSceneTest();
public:
    void init(Window &window, Renderer &renderer) override;

    void update(float delta) override;

    void render() const override;
};
