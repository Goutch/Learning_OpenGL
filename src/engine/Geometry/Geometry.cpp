//
// Created by User on 2020-01-07.
//
#include <fstream>
#include "Geometry.h"
#include "Mesh.h"
#include "vector"
#include "Utils/StringUtils.h"
#include "Core/Log.h"

void Geometry::make_quad(VAO &vao) {
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
    vao.put(Mesh::VERTICIES, 3, vert.data(), vert.size());
    vao.put(Mesh::UVS, 2, uvs.data(), uvs.size());
}

void Geometry::make_cube(VAO &vao) {
    //front
    //1-------2
    //|       |
    //|       |
    //0-------3
    //back
    // 5-------6
    // |       |
    // |       |
    // 4-------7
    auto vert = std::vector<float>();
    auto indices = std::vector<unsigned int>();
    auto uvs = std::vector<float>();
    auto normals=std::vector<float >();
    for (int i = 0; i <3 ; ++i) {
        vert.push_back(-.5);vert.push_back(-.5);vert.push_back(0.5);//0
        vert.push_back(-.5);vert.push_back(.5f);vert.push_back(0.5);//1
        vert.push_back(.5f);vert.push_back(.5f);vert.push_back(0.5);//2
        vert.push_back(.5f);vert.push_back(-.5);vert.push_back(0.5);//3

        vert.push_back(-.5);vert.push_back(-.5);vert.push_back(-0.5);//4
        vert.push_back(-.5);vert.push_back(.5f);vert.push_back(-0.5);//5
        vert.push_back(.5f);vert.push_back(.5f);vert.push_back(-0.5);//6
        vert.push_back(.5f);vert.push_back(-.5);vert.push_back(-0.5);//7

        uvs.push_back(0);uvs.push_back(0);
        uvs.push_back(0);uvs.push_back(1);
        uvs.push_back(1);uvs.push_back(1);
        uvs.push_back(1);uvs.push_back(0);


        uvs.push_back(1);uvs.push_back(1);
        uvs.push_back(1);uvs.push_back(0);
        uvs.push_back(0);uvs.push_back(0);
        uvs.push_back(0);uvs.push_back(1);
    }
    for (int j = 0; j <4 ; ++j) {
        normals.push_back(0);normals.push_back(-1);normals.push_back(0);
    }
    for (int j = 0; j <4 ; ++j) {
        normals.push_back(0);normals.push_back(1);normals.push_back(0);
    }
    for (int j = 0; j <4 ; ++j) {
        normals.push_back(0);normals.push_back(0);normals.push_back(-1);
    }
    for (int j = 0; j <4 ; ++j) {
        normals.push_back(0);normals.push_back(0);normals.push_back(1);
    }
    for (int j = 0; j <4 ; ++j) {
        normals.push_back(1);normals.push_back(0);normals.push_back(0);
    }
    for (int j = 0; j <4 ; ++j) {
        normals.push_back(-1);normals.push_back(0);normals.push_back(0);
    }



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
    indices.push_back(2+6);
    indices.push_back(1+6);
    indices.push_back(0+6);
    indices.push_back(0+6);
    indices.push_back(3+6);
    indices.push_back(2+6);
    //back
    indices.push_back(4+6);
    indices.push_back(5+6);
    indices.push_back(6+6);
    indices.push_back(6+6);
    indices.push_back(7+6);
    indices.push_back(4+6);
    //right
    indices.push_back(6+12);
    indices.push_back(2+12);
    indices.push_back(3+12);
    indices.push_back(3+12);
    indices.push_back(7+12);
    indices.push_back(6+12);

    //left
    indices.push_back(0+12);
    indices.push_back(1+12);
    indices.push_back(5+12);
    indices.push_back(5+12);
    indices.push_back(4+12);
    indices.push_back(0+12);
    vao.indicies(indices.data(), indices.size());

    vao.put(Mesh::VERTICIES, 3, vert.data(), vert.size());
    vao.put(Mesh::NORMALS, 3, normals.data(), normals.size());
    vao.put(Mesh::UVS, 2, uvs.data(), uvs.size());
}

void Geometry::make_plane(VAO &vao,int sizeX,int sizeZ) {

    auto vertices = std::vector<float>();
    vertices.resize((sizeX + 1) * (sizeZ + 1) * 3);
    auto indices = std::vector<unsigned int>();
    indices.resize(sizeX * sizeZ * 6);
    auto normals = std::vector<float>();
    normals.resize((sizeX + 1) * (sizeZ + 1) * 3);
    auto uvs = std::vector<float>();
    uvs.resize((sizeX + 1) * (sizeZ + 1) * 2);
    for (int z = 0; z < sizeZ + 1; z++) {
        for (int x = 0; x < sizeX + 1; x++) {
            int index = (x * (sizeZ + 1)) + z;
            vertices[index * 3] = x - (float) sizeX / 2;
            vertices[index * 3 + 1] = 0;
            vertices[index * 3 + 2] = z - (float) sizeZ / 2;
        }
    }

    for (int x = 0; x < sizeX; x++) {
        for (int z = 0; z < sizeZ; z++) {
            int index = (x * (sizeZ) + z);
            indices[index * 6] = index + x;
            indices[index * 6 + 1] = index + x + 1;
            indices[index * 6 + 2] = index + x + sizeZ + 1;
            indices[index * 6 + 3] = index + x + sizeZ + 1;
            indices[index * 6 + 4] = index + x + 1;
            indices[index * 6 + 5] = index + x + sizeZ + 2;
        }
    }
    for (int i = 0; i < (sizeX + 1) * (sizeZ + 1); i++) {
        normals[i * 3] = 0;
        normals[i * 3 + 1] = 1;
        normals[i * 3 + 2] = 0;
    }
    for (int x = 0; x < sizeX+1; ++x) {
        for (int z = 0; z <sizeZ+1 ; ++z) {
            int index = (x * (sizeZ + 1)) + z;
            uvs[index*2]=(float(x)/(sizeX+1));
            uvs[(index*2)+1]=(float(z)/(sizeZ+1));
        }
    }
    vao.indicies(indices.data(), indices.size());
    vao.put(Mesh::VERTICIES, 3, vertices.data(), vertices.size());
    vao.put(Mesh::NORMALS, 3, normals.data(), normals.size());
    vao.put(Mesh::UVS, 2, uvs.data(), uvs.size());
}
void Geometry::import(VAO &vao, std::string path) {
    Log::status("Loading model:" + path);
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
        auto orderedNormals = std::vector<float>();
        orderedUvs.resize((vertices.size() / 3) * 2);
        orderedNormals.resize(vertices.size());
        orderedIndices.resize(indices.size());
        auto data = std::vector<std::string>();
        for (unsigned int i = 0; i < indices.size(); ++i) {
            StringUtils::split(data, indices[i], '/');
            unsigned int vertexPointer = std::stoi(data.at(0)) - 1;
            unsigned int uvPointer = std::stoi(data.at(1)) - 1;
            int normalPointer = std::stoi(data.at(2)) - 1;
            data.clear();
            orderedIndices[i] = vertexPointer;
            if (!uvs.empty()) {
                orderedUvs[vertexPointer * 2] = uvs[uvPointer*2];
                orderedUvs[vertexPointer * 2 + 1] = 1 - uvs[uvPointer*2+1];
            }
            if (!normals.empty()) {
                orderedNormals[vertexPointer * 3] = normals[normalPointer*3];
                orderedNormals[vertexPointer * 3 + 1] = normals[normalPointer*3+1];
                orderedNormals[vertexPointer * 3 + 2] = normals[normalPointer*3+2];
            }
        }
        vao.indicies(orderedIndices.data(), orderedIndices.size());
        vao.put(Mesh::VERTICIES, 3, vertices.data(), vertices.size());
        if (!orderedUvs.empty())
            vao.put(Mesh::UVS, 2, orderedUvs.data(), uvs.size());
        if (!orderedNormals.empty())
            vao.put(Mesh::NORMALS, 3, orderedNormals.data(), orderedNormals.size());
    }
    catch (const std::exception &e) {
        Log::error("cant import model:" + path + "\n" + e.what());
    }


}


