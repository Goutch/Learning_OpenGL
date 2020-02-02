//
// Created by User on 2020-01-07.
//
#include <fstream>
#include "Geometry.h"
#include "Mesh.h"
#include "vector"
#include "Utils/StringUtils.h"
#include "Core/Log.h"
#include "math.h"
#include "Utils/Timer.h"
void Geometry::make_text(Mesh &mesh, std::string text, FontText& font) {
    float font_width = 0.2f;
    float font_height = 0.2f;

    //Size: 0
    //return;

    //Size: 1
    //1-------2
    //|       |
    //|       |
    //0-------3

    //vertices
    //{0,0,0}
    //{0,font_height,0}
    //{font_width,font_height,0}
    //{font_width,0,0}

    //indices
    //2
    //1
    //0
    //0
    //3
    //2

    //Size: 2
    //1-------25-------6
    //|       ||       |
    //|       ||       |
    //0-------34-------7

    //vertices
    //{0,0,0}
    //{0,font_height,0}
    //{font_width,font_height,0}
    //{font_width,0,0}
    //{font_width,0,0}
    //{font_width,font_height,0}
    //{font_width*2,font_height,0}
    //{font_width*2,0,0}

    //indices
    //2
    //1
    //0
    //0
    //3
    //2
    //6
    //5
    //4
    //4
    //7
    //6

    //Size: n
    //vertices
    //for i = 1 to n
    //{font_width *(i - 1), 0, 0}
    //{font_width *(i - 1), font_height, 0}
    //{font_width *(i), font_height, 0}
    //{font_width *(i), 0, 0}

    //indices
    //for i = 0 to n - 1
    //2 + (4*i)
    //1 + (4*i)
    //0 + (4*i)
    //0 + (4*i)
    //3 + (4*i)
    //2 + (4*i)

    auto vert = std::vector<float>();
    auto uvs = std::vector<float>();
    for(unsigned int i = 0; i < text.size(); ++i) {
        vert.push_back(font_width * (i));
        vert.push_back(0);
        vert.push_back(0);

        vert.push_back(font_width * (i));
        vert.push_back(font_height);
        vert.push_back(0);

        vert.push_back(font_width * (i + 1));
        vert.push_back(font_height);
        vert.push_back(0);

        vert.push_back(font_width * (i + 1));
        vert.push_back(0);
        vert.push_back(0);

        float uvs_current_char[8];
        font.getCoordinates(uvs_current_char, text[i] - 32);
        for(int j = 0; j < 8; ++j) {
            uvs.push_back(uvs_current_char[j]);
        }
    }

    auto indices = std::vector<unsigned int>();
    for(unsigned int i = 0; i < text.size(); ++i) {
        indices.push_back(2 + (4*i));
        indices.push_back(1 + (4*i));
        indices.push_back(0 + (4*i));
        indices.push_back(0 + (4*i));
        indices.push_back(3 + (4*i));
        indices.push_back(2 + (4*i));
    }

    mesh.indicies(indices.data(), indices.size());
    mesh.put(Mesh::VERTICIES, 3, vert.data(), vert.size());
    mesh.uvs(uvs.data(), uvs.size());
}

void Geometry::make_quad(VAO &vao,float width,float height,float offsetX,float offsetY) {
    //1-------2
    //|       |
    //|       |
    //0-------3

    width/=2;
    height/=2;
    auto vert = std::vector<float>();
    vert.push_back(-width+offsetX);
    vert.push_back(-height+offsetY);
    vert.push_back(0);
    vert.push_back(-width+offsetX);
    vert.push_back(height+offsetY);
    vert.push_back(0);
    vert.push_back(width+offsetX);
    vert.push_back(height+offsetY);
    vert.push_back(0);
    vert.push_back(width+offsetX);
    vert.push_back(-height+offsetY);
    vert.push_back(0);

    auto indices = std::vector<unsigned int>();
    indices.push_back(2);
    indices.push_back(1);
    indices.push_back(0);
    indices.push_back(0);
    indices.push_back(3);
    indices.push_back(2);
    auto uvs = std::vector<float>();
    for (unsigned int i = 0; i < (vert.size() / 3) / 4; ++i) {
        uvs.push_back(0);
        uvs.push_back(0);
        uvs.push_back(0);
        uvs.push_back(1);
        uvs.push_back(1);
        uvs.push_back(1);
        uvs.push_back(1);
        uvs.push_back(0);
    }
    vao.indicies(indices.data(), indices.size());
    vao.put(Mesh::VERTICIES, 3, vert.data(), vert.size());
    vao.put(Mesh::UVS, 2, uvs.data(), uvs.size());
}

void Geometry::make_cube(VAO &vao) {

    auto vert = std::vector<float>();
    auto indices = std::vector<unsigned int>();
    auto uvs = std::vector<float>();
    auto normals = std::vector<float>();
    //front
    //1-------2
    //|       |
    //|       |
    //0-------3

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
    uvs.push_back(0);
    uvs.push_back(0);
    uvs.push_back(0);
    uvs.push_back(1);
    uvs.push_back(1);
    uvs.push_back(1);
    uvs.push_back(1);
    uvs.push_back(0);
    for (int j = 0; j < 4; ++j) {
        normals.push_back(0);
        normals.push_back(0);
        normals.push_back(1);
    }
    indices.push_back(2);
    indices.push_back(1);
    indices.push_back(0);
    indices.push_back(0);
    indices.push_back(3);
    indices.push_back(2);

    //back
    // 5-------6
    // |       |
    // |       |
    // 4-------7
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
    uvs.push_back(1);
    uvs.push_back(1);
    uvs.push_back(1);
    uvs.push_back(0);
    uvs.push_back(0);
    uvs.push_back(0);
    uvs.push_back(0);
    uvs.push_back(1);
    for (int j = 0; j < 4; ++j) {
        normals.push_back(0);
        normals.push_back(0);
        normals.push_back(-1);
    }
    indices.push_back(0 + 4);
    indices.push_back(1 + 4);
    indices.push_back(2 + 4);
    indices.push_back(2 + 4);
    indices.push_back(3 + 4);
    indices.push_back(0 + 4);
    //top

    vert.push_back(-.5);
    vert.push_back(.5);
    vert.push_back(-0.5);//8
    vert.push_back(-.5);
    vert.push_back(.5f);
    vert.push_back(0.5);//9
    vert.push_back(.5f);
    vert.push_back(.5f);
    vert.push_back(0.5);//10
    vert.push_back(.5f);
    vert.push_back(.5);
    vert.push_back(-0.5);//11
    uvs.push_back(0);
    uvs.push_back(0);
    uvs.push_back(0);
    uvs.push_back(1);
    uvs.push_back(1);
    uvs.push_back(1);
    uvs.push_back(1);
    uvs.push_back(0);
    for (int j = 0; j < 4; ++j) {
        normals.push_back(0);
        normals.push_back(1);
        normals.push_back(0);
    }
    indices.push_back(0 + 8);
    indices.push_back(1 + 8);
    indices.push_back(2 + 8);
    indices.push_back(2 + 8);
    indices.push_back(3 + 8);
    indices.push_back(0 + 8);
    //bottom

    vert.push_back(-.5);
    vert.push_back(-.5);
    vert.push_back(-0.5);//12
    vert.push_back(-.5);
    vert.push_back(-.5f);
    vert.push_back(0.5);//13
    vert.push_back(.5f);
    vert.push_back(-.5f);
    vert.push_back(0.5);//14
    vert.push_back(.5f);
    vert.push_back(-.5);
    vert.push_back(-0.5);//15
    uvs.push_back(1);
    uvs.push_back(1);
    uvs.push_back(1);
    uvs.push_back(0);
    uvs.push_back(0);
    uvs.push_back(0);
    uvs.push_back(0);
    uvs.push_back(1);
    for (int j = 0; j < 4; ++j) {
        normals.push_back(0);
        normals.push_back(-1);
        normals.push_back(0);
    }
    indices.push_back(2 + 12);
    indices.push_back(1 + 12);
    indices.push_back(0 + 12);
    indices.push_back(0 + 12);
    indices.push_back(3 + 12);
    indices.push_back(2 + 12);
    //right
    vert.push_back(.5);
    vert.push_back(-.5);
    vert.push_back(-0.5);//16
    vert.push_back(.5);
    vert.push_back(-.5);
    vert.push_back(0.5);//17
    vert.push_back(.5f);
    vert.push_back(.5);
    vert.push_back(0.5);//18
    vert.push_back(.5f);
    vert.push_back(.5);
    vert.push_back(-0.5);//19
    uvs.push_back(0);
    uvs.push_back(0);
    uvs.push_back(0);
    uvs.push_back(1);
    uvs.push_back(1);
    uvs.push_back(1);
    uvs.push_back(1);
    uvs.push_back(0);
    for (int j = 0; j < 4; ++j) {
        normals.push_back(0);
        normals.push_back(1);
        normals.push_back(0);
    }
    indices.push_back(2 + 16);
    indices.push_back(1 + 16);
    indices.push_back(0 + 16);
    indices.push_back(0 + 16);
    indices.push_back(3 + 16);
    indices.push_back(2 + 16);
    //left

    vert.push_back(-.5);
    vert.push_back(-.5);
    vert.push_back(-0.5);//20
    vert.push_back(-.5);
    vert.push_back(-.5);
    vert.push_back(0.5);//21
    vert.push_back(-.5);
    vert.push_back(.5);
    vert.push_back(0.5);//22
    vert.push_back(-.5);
    vert.push_back(.5);
    vert.push_back(-0.5);//23
    uvs.push_back(1);
    uvs.push_back(1);
    uvs.push_back(1);
    uvs.push_back(0);
    uvs.push_back(0);
    uvs.push_back(0);
    uvs.push_back(0);
    uvs.push_back(1);
    for (int j = 0; j < 4; ++j) {
        normals.push_back(0);
        normals.push_back(-1);
        normals.push_back(0);
    }
    indices.push_back(0 + 20);
    indices.push_back(1 + 20);
    indices.push_back(2 + 20);
    indices.push_back(2 + 20);
    indices.push_back(3 + 20);
    indices.push_back(0 + 20);

    vao.indicies(indices.data(), indices.size());

    vao.put(Mesh::VERTICIES, 3, vert.data(), vert.size());
    vao.put(Mesh::NORMALS, 3, normals.data(), normals.size());
    vao.put(Mesh::UVS, 2, uvs.data(), uvs.size());
}


void Geometry::make_sphere(VAO &vao, float radius,int xCount,int yCount) {
    //https://www.songho.ca/opengl/gl_sphere.html
    const double PI = 3.14159265359;
    auto vertices = std::vector<float>();
    auto normals = std::vector<float>();
    auto indices = std::vector<unsigned int>();
    auto uvs = std::vector<float>();

    float x, y, z, xy;                              // vertex position
    float nx, ny, nz, lengthInv = 1.0f / radius;    // vertex normal
    float s, t;                                     // vertex texCoord

    float sectorStep = 2 * PI / xCount;
    float stackStep = PI / yCount;
    float sectorAngle, stackAngle;

    for(int i = 0; i <= yCount; ++i)
    {
        stackAngle = PI / 2 - i * stackStep;        // starting from pi/2 to -pi/2
        xy = radius * cosf(stackAngle);             // r * cos(u)
        z = radius * sinf(stackAngle);              // r * sin(u)

        // add (sectorCount+1) vertices per stack
        // the first and last vertices have same position and normal, but different tex coords
        for(int j = 0; j <= xCount; ++j)
        {
            sectorAngle = j * sectorStep;           // starting from 0 to 2pi

            // vertex position (x, y, z)
            x = xy * cosf(sectorAngle);             // r * cos(u) * cos(v)
            y = xy * sinf(sectorAngle);             // r * cos(u) * sin(v)
            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);

            // normalized vertex normal (nx, ny, nz)
            nx = x * lengthInv;
            ny = y * lengthInv;
            nz = z * lengthInv;
            normals.push_back(nx);
            normals.push_back(ny);
            normals.push_back(nz);

            // vertex tex coord (s, t) range between [0, 1]
            s = (float)j / xCount;
            t = (float)i / yCount;
            uvs.push_back(s);
            uvs.push_back(t);
        }
    }
    int k1, k2;
    for(int i = 0; i <yCount; ++i)
    {
        k1 = i * (xCount + 1);     // beginning of current stack
        k2 = k1 + xCount + 1;      // beginning of next stack

        for(int j = 0; j < xCount; ++j, ++k1, ++k2)
        {
            // 2 triangles per sector excluding first and last stacks
            // k1 => k2 => k1+1
            if(i != 0)
            {
                indices.push_back(k1);
                indices.push_back(k2);
                indices.push_back(k1 + 1);
            }

            // k1+1 => k2 => k2+1
            if(i != (yCount-1))
            {
                indices.push_back(k1 + 1);
                indices.push_back(k2);
                indices.push_back(k2 + 1);
            }
        }
    }

    vao.indicies(indices.data(),indices.size());
    vao.put(Mesh::VERTICIES, 3, vertices.data(), vertices.size());
    vao.put(Mesh::NORMALS, 3, normals.data(), normals.size());
    vao.put(Mesh::UVS, 2, uvs.data(), uvs.size());
}

void Geometry::make_plane(VAO &vao, int sizeX, int sizeZ) {

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
    for (int x = 0; x < sizeX + 1; ++x) {
        for (int z = 0; z < sizeZ + 1; ++z) {
            int index = (x * (sizeZ + 1)) + z;
            uvs[index * 2] = (float(x) / (sizeX + 1));
            uvs[(index * 2) + 1] = (float(z) / (sizeZ + 1));
        }
    }
    vao.indicies(indices.data(), indices.size());
    vao.put(Mesh::VERTICIES, 3, vertices.data(), vertices.size());
    vao.put(Mesh::NORMALS, 3, normals.data(), normals.size());
    vao.put(Mesh::UVS, 2, uvs.data(), uvs.size());
}


void Geometry::import(VAO &vao, std::string path) {
    //https://en.wikipedia.org/wiki/Wavefront_.obj_file
    Log::status("Loading model:" + path);
    Timer t;
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
        file.close();
        float* orderedUvs=new float[(vertices.size() / 3) * 2];
        unsigned int* orderedIndices=new unsigned int[indices.size()];
        float* orderedNormals=new float[vertices.size()];
        auto data = std::vector<std::string>();
        data.reserve(3);
        for (unsigned int i = 0; i < indices.size(); ++i) {
            StringUtils::split(data, indices[i], '/');
            unsigned int vertexPointer = std::stoi(data.at(0)) - 1;
            unsigned int uvPointer = std::stoi(data.at(1)) - 1;
            int normalPointer = std::stoi(data.at(2)) - 1;
            data.clear();
            data.reserve(3);
            orderedIndices[i] = vertexPointer;
            if (!uvs.empty()) {
                orderedUvs[vertexPointer * 2] = uvs[uvPointer * 2];
                orderedUvs[vertexPointer * 2 + 1] = 1 - uvs[uvPointer * 2 + 1];
            }
            if (!normals.empty()) {
                orderedNormals[vertexPointer * 3] = normals[normalPointer * 3];
                orderedNormals[vertexPointer * 3 + 1] = normals[normalPointer * 3 + 1];
                orderedNormals[vertexPointer * 3 + 2] = normals[normalPointer * 3 + 2];
            }
        }
        vao.indicies(orderedIndices, indices.size());
        vao.put(Mesh::VERTICIES, 3, vertices.data(), vertices.size());
        if (!uvs.empty())
            vao.put(Mesh::UVS, 2, orderedUvs, (vertices.size()/3)*2);
        if (!normals.empty())
            vao.put(Mesh::NORMALS, 3, orderedNormals, vertices.size());
        delete[](orderedIndices);
        delete[](orderedNormals);
        delete[](orderedUvs);
    }
    catch (const std::exception &e) {
        Log::error("cant import model:" + path + "\n" + e.what());
    }
    Log::message(path +" loaded in "+std::to_string(t.ms())+"s with "+std::to_string(vao.getVertexCount())+" vertices" );
}
