

//
// Created by User on 2020-01-06.
//

class VAO;
#include <string>
namespace Geometry{
    void make_cube(VAO &vao);
    void make_quad(VAO& vao);
    void make_plane(VAO& vao,int sizeX,int sizeZ);
    void import(VAO& vao,std::string path);
}