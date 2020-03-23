#pragma once

#include <Ressources/Color.h>
#include <string>
#include <utility>
enum VOXELS{
    AIR,
    GRASS,
    DIRT,
    SAND,
    WATER,
};
struct Voxel {
    Color color;
    unsigned char id;
    bool is_transparent;
    std::string name;
    Voxel(unsigned char id,std::string name,Color color):id(id),name(std::move(name)),color(color){
        is_transparent=color.a!=1;
    };
    bool operator==(const Voxel& other)const{
        return (id==other.id);
    }
    bool operator!=(const Voxel& other)const{
        return (id!=other.id);
    }
};

