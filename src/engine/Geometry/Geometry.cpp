//
// Created by User on 2020-01-07.
//
#include <fstream>
#include "Geometry.h"
#include "Mesh.h"
#include "vector"
#include <utils/StringUtils.h>
#include "core/Log.h"

void Geometry::makeQuad(VAO &vao) {
    auto vert = std::vector<float>();
    vert.push_back(-.5);
    vert.push_back(-.5);
    vert.push_back(0);
    vert.push_back(-.5);
    vert.push_back(.5f);
    vert.push_back(0);
    vert.push_back(.5f);
    vert.push_back(.5f);
    vert.push_back(0);
    vert.push_back(.5f);
    vert.push_back(-.5);
    vert.push_back(0);

    auto indices = std::vector<unsigned int>();
    indices.push_back(2);
    indices.push_back(1);
    indices.push_back(0);
    indices.push_back(0);
    indices.push_back(3);
    indices.push_back(2);
    auto uvs = std::vector<float>();
    for (int i = 0; i < (vert.size() / 3) / 4; ++i) {
        uvs.push_back(0);
        uvs.push_back(1);
        uvs.push_back(0);
        uvs.push_back(0);
        uvs.push_back(1);
        uvs.push_back(0);
        uvs.push_back(1);
        uvs.push_back(1);
    }
    vao.indicies(indices.data(), indices.size());
    vao.put(0, 3, vert.data(), vert.size());
    vao.put(1, 2, uvs.data(), uvs.size());
}

void Geometry::makeCube(Mesh &mesh) {
    //1-------2     5-------6
    //|       |     |       |
    //|       |     |       |
    //0-------3     4-------7
    auto vert = std::vector<float>();
    vert.push_back(-.5);
    vert.push_back(-.5);
    vert.push_back(0.5);//0
    vert.push_back(-.5);
    vert.push_back(.5f);
    vert.push_back(0.5);//1
    vert.push_back(.5f);
    vert.push_back(.5f);
    vert.push_back(0.5);//2
    vert.push_back(.5f);
    vert.push_back(-.5);
    vert.push_back(0.5);//3

    vert.push_back(-.5);
    vert.push_back(-.5);
    vert.push_back(-0.5);//4
    vert.push_back(-.5);
    vert.push_back(.5f);
    vert.push_back(-0.5);//5
    vert.push_back(.5f);
    vert.push_back(.5f);
    vert.push_back(-0.5);//6
    vert.push_back(.5f);
    vert.push_back(-.5);
    vert.push_back(-0.5);//7

    auto uvs = std::vector<float>();

    uvs.push_back(0);
    uvs.push_back(0);
    uvs.push_back(0);
    uvs.push_back(1);
    uvs.push_back(1);
    uvs.push_back(1);
    uvs.push_back(1);
    uvs.push_back(0);


    uvs.push_back(1);
    uvs.push_back(1);
    uvs.push_back(1);
    uvs.push_back(0);
    uvs.push_back(0);
    uvs.push_back(0);
    uvs.push_back(0);
    uvs.push_back(1);

    auto indices = std::vector<unsigned int>();
    //down
    indices.push_back(3);
    indices.push_back(0);
    indices.push_back(4);
    indices.push_back(4);
    indices.push_back(7);
    indices.push_back(3);
    //up
    indices.push_back(5);
    indices.push_back(1);
    indices.push_back(2);
    indices.push_back(2);
    indices.push_back(6);
    indices.push_back(5);
    //front
    indices.push_back(2);
    indices.push_back(1);
    indices.push_back(0);
    indices.push_back(0);
    indices.push_back(3);
    indices.push_back(2);
    //back
    indices.push_back(4);
    indices.push_back(5);
    indices.push_back(6);
    indices.push_back(6);
    indices.push_back(7);
    indices.push_back(4);
    //right
    indices.push_back(6);
    indices.push_back(2);
    indices.push_back(3);
    indices.push_back(3);
    indices.push_back(7);
    indices.push_back(6);

    //left
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(5);
    indices.push_back(5);
    indices.push_back(4);
    indices.push_back(0);

    mesh.vertices(vert.data(), vert.size()).indices(indices.data(), indices.size()).uvs(uvs.data(), uvs.size());
}


void Geometry::import(VAO &vao, std::string path) {
    Log::status( "Loading model:"+path);
    try {
        std::ifstream file(path);
        std::string line;
        std::vector<float> vertices = std::vector<float>();
        std::vector<float> uvs = std::vector<float>();
        std::vector<float> normals = std::vector<float>();
        std::vector<std::string> indices = std::vector<std::string>();
        while (getline(file, line)) {
            auto data = std::vector<std::string>();
            StringUtils::split(data, line, ' ');
            if (!data.empty()) {
                if (data[0] == "v") {
                    for (unsigned int i = 1; i < data.size(); ++i) {
                        vertices.push_back(std::stof(data[i]));
                    }
                } else if (data[0] == "vn") {
                    for (unsigned int i = 1; i < data.size(); ++i) {
                        normals.push_back(std::stof(data[i]));
                    }
                } else if (data[0] == "vt") {

                    for (unsigned int i = 1; i < data.size(); ++i) {
                        uvs.push_back(std::stof(data[i]));
                    }
                } else if (data[0] == "f") {
                    for (unsigned int i = 1; i < data.size(); ++i) {
                        indices.push_back(data[i]);
                    }
                }
            }
        }
        auto orderedUvs = std::vector<float>();
        auto orderedIndices = std::vector<unsigned int>();
        //auto orderedNormals = std::vector<float>();
        orderedUvs.resize((vertices.size() / 3) * 2);
        //orderedNormals.resize(vertices.size());
        orderedIndices.resize(indices.size());
        auto data = std::vector<std::string>();
        for (unsigned int i = 0; i < indices.size(); ++i) {
            StringUtils::split(data, indices[i], '/');
            unsigned int vertexPointer = std::stoi(data.at(0)) - 1;
            unsigned int uvPointer = std::stoi(data.at(1)) - 1;
            //int normalPointer = std::stoi(data.at(2)) - 1;
            data.clear();
            orderedIndices[i] = vertexPointer;
            if (!uvs.empty()) {
                orderedUvs[vertexPointer * 2] = uvs[uvPointer];
                orderedUvs[vertexPointer * 2 + 1] = 1-uvs[uvPointer];
            }
            //if (!normals.empty()) {
            //    orderedNormals[vertexPointer * 3] = normals[normalPointer];
            //    orderedNormals[vertexPointer * 3 + 1] = normals[normalPointer];
            //    orderedNormals[vertexPointer * 3 + 2] = normals[normalPointer];
            //}
        }

        vao.put(0, 3, vertices.data(), vertices.size());
        vao.indicies(orderedIndices.data(),orderedIndices.size());
        if(!orderedUvs.empty())
            vao.put(1, 2,orderedUvs.data(), uvs.size());
    }
    catch (const std::exception &e) {
        Log::error("cant import model:"+path+"\n"+e.what());
    }


}