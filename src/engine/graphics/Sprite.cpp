
#include "Sprite.h"
#include "Texture.h"
Sprite::Sprite(Texture* texture):Drawable() {
    this->texture=texture;
    float vert[8]={-0.5f,-0.5f,
                 -0.5f,0.5,
                 0.5f,0.5f,
                 0.5f,-0.5f};
    float uvs[8]={0,0,
                  0,1,
                  1,1,
                  1,0};
    unsigned int indices[6]={0,1,2,2,3,0};
    vao->indicies(indices,6);

    vao->put(0,2,vert,8);
    vao->put(2,2,uvs,8);
    vertex_count=6;
}
void Sprite::bind() {
    Drawable::bind();
    texture->bind();
}
