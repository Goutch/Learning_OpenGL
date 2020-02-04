//
// Created by User on 2020-01-09.
//

#include "TextureCreationTest.h"
#include "Entities/MeshRenderer.h"
#include "Core/Rendering/BatchRenderer.h"
#include "Utils/SimplexNoise.h"
#include "Geometry/Geometry.h"

void TextureCreationTest::init(Viewport &viewport, Renderer &renderer, Window &window){
    Scene::init(viewport,renderer,window);

    int width = 300;
    int height = 300;
    double scale = 0.0033;

    unsigned char *textureColor = new unsigned char[width * height * 4];
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            float n = (SimplexNoise::noise(x * scale, y * scale) + 1) * 0.5;
            auto c = static_cast<unsigned int>(n * 255);
            int i = ((y * width) + x) * 4;
            textureColor[i] = c;
            textureColor[i + 1] = c;
            textureColor[i + 2] = c;
            textureColor[i + 3] = 255;
        }
    }
    texture.setTexturePixelData(textureColor, width, height, true);

    Geometry::make_quad(mesh);
    addEntity(new MeshRenderer(mesh, material));

    delete[] textureColor;
}

