

//
// Created by User on 2020-01-06.
//
class Mesh;
class VAO;

#include <string>
namespace Geometry{
    void make_cube(Mesh& mesh);
    void make_quad(VAO& vao);
    void import(VAO& vao,std::string path);
}