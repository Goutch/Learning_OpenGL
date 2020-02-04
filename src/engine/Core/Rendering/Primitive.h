
#pragma once
#include <Entities/Transform.h>
#include <Data/Color.h>

class Material;
class VAO;
class Primitive {


public:
    const Material *material;
    Color color;
    Transform transform;
    bool customColor=false;
    const VAO* vao;
    Primitive(const VAO& vao,Transform transform,const Material& material,Color color);
    Primitive(const VAO& vao,const Transform& transform,const Material& material);

    void setCustomMaterialAttributes();
};



