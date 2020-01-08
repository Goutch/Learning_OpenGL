//
// Created by User on 2020-01-07.
//
#include "Geometry.h"
#include "data/Mesh.h"
#include "vector"
#include "iostream"

void Geometry::makeCube(Mesh &mesh) {

    auto vert = std::vector<float>();
    vert.push_back(-.5);
    vert.push_back(-.5);
    vert.push_back(0.5);
    vert.push_back(-.5);
    vert.push_back(.5f);
    vert.push_back(0.5);
    vert.push_back(.5f);
    vert.push_back(.5f);
    vert.push_back(0.5);
    vert.push_back(.5f);
    vert.push_back(-.5);
    vert.push_back(0.5);

    vert.push_back(-.5);
    vert.push_back(-.5);
    vert.push_back(-0.5);
    vert.push_back(-.5);
    vert.push_back(.5f);
    vert.push_back(-0.5);
    vert.push_back(.5f);
    vert.push_back(.5f);
    vert.push_back(-0.5);
    vert.push_back(.5f);
    vert.push_back(-.5);
    vert.push_back(-0.5);

    vert.push_back(0.5);
    vert.push_back(-.5);
    vert.push_back(-.5);
    vert.push_back(0.5);
    vert.push_back(.5f);
    vert.push_back(-.5);
    vert.push_back(0.5);
    vert.push_back(.5f);
    vert.push_back(.5f);
    vert.push_back(0.5);
    vert.push_back(-.5);
    vert.push_back(.5f);

    vert.push_back(-0.5);
    vert.push_back(-.5);
    vert.push_back(-.5);
    vert.push_back(-0.5);
    vert.push_back(.5f);
    vert.push_back(-.5);
    vert.push_back(-0.5);
    vert.push_back(.5f);
    vert.push_back(.5f);
    vert.push_back(-0.5);
    vert.push_back(-.5);
    vert.push_back(.5f);

    vert.push_back(-.5);
    vert.push_back(0.5);
    vert.push_back(-.5);
    vert.push_back(.5f);
    vert.push_back(0.5);
    vert.push_back(-.5);
    vert.push_back(.5f);
    vert.push_back(0.5);
    vert.push_back(.5f);
    vert.push_back(-.5);
    vert.push_back(0.5);
    vert.push_back(.5f);

    vert.push_back(-.5);
    vert.push_back(-0.5);
    vert.push_back(-.5);
    vert.push_back(.5f);
    vert.push_back(-0.5);
    vert.push_back(-.5);
    vert.push_back(.5f);
    vert.push_back(-0.5);
    vert.push_back(.5f);
    vert.push_back(-.5);
    vert.push_back(-0.5);
    vert.push_back(.5f);

    auto indices = std::vector<unsigned int>();
    for (int i = 0;i < vert.size()/ 3; ++i) {
        indices.push_back(i);
    }
    auto uvs = std::vector<float>();
    for (int i = 0;i < (vert.size()/ 3) / 4; ++i) {
        uvs.push_back(0);
        uvs.push_back(0);
        uvs.push_back(1);
        uvs.push_back(0);
        uvs.push_back(0);
        uvs.push_back(1);
        uvs.push_back(1);
        uvs.push_back(1);
    }
    mesh.vertices(vert.data(), vert.size()).indices(indices.data(), indices.size()).uvs(uvs.data(), uvs.size());
}