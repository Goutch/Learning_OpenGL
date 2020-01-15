

//
// Created by User on 2020-01-06.
//
class Mesh;
class VAO;

#include <string>
namespace Geometry{
    void makeCube(Mesh& mesh);
    void makeQuad(VAO& vao);
    void import(VAO& vao,std::string path);
}