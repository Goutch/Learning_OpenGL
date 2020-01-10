//
// Created by User on 2020-01-09.
//

#include "TextureCreation.h"
#include "entities/MeshRenderer.h"
#include "core/Renderer.h"

void TextureCreation::init(Window &window, Renderer &renderer) {
    Scene::init(window, renderer);
    camera = new Transform(vec3(0), vec3(0), vec3(1));
    unsigned char *textureColor = new unsigned char[4 * 4];
    textureColor[0] = 255;
    textureColor[1] = 0;
    textureColor[2] = 0;
    textureColor[3] = 255;

    textureColor[4] = 0;
    textureColor[5] = 255;
    textureColor[6] = 0;
    textureColor[7] = 255;

    textureColor[8] = 0;
    textureColor[9] = 0;
    textureColor[10] = 255;
    textureColor[11] = 255;

    textureColor[12] = 255;
    textureColor[13] = 255;
    textureColor[14] = 255;
    textureColor[15] = 255;
    texture.setTexturePixelData(textureColor, 2, 2,true);

    sprite.setTexture(texture);

    texture.bind();

    addEntity(new MeshRenderer(sprite, shader, vec3(0), vec3(0), vec3(1)));
    renderer.setCamera(*camera);
    delete[] textureColor;
}

void TextureCreation::update(float delta) {
    Scene::update(delta);
}

TextureCreation::~TextureCreation() {
    delete camera;
}
