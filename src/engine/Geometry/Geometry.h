
#pragma once
//https://www.songho.ca/opengl/gl_sphere.html
//    //https://en.wikipedia.org/wiki/Wavefront_.obj_file
class VAO;
#include <string>
#include <Shaders/Canvas/FontMaterial.h>
#include "Ressources/Mesh.h"

namespace Geometry{
    void make_triangle(VAO& vao,float x1,float y1,float x2,float y2,float x3,float y3);
    void make_sphere(VAO &vao, float radius,int xCount,int yCount) ;
    void make_cube(VAO &vao);
    void make_quad(VAO& vao,float width=1,float height=1,float offsetX=0,float offsetY=0);
    void make_text(Mesh &mesh, std::string text, FontMaterial& font);
    void make_plane(VAO& vao,int sizeX,int sizeZ);
    void import(VAO& vao,std::string path);

}