#include <vector>
#include "Voxel.h"
#include <Ressources/Color.h>

static const std::vector<Voxel> VOXELS_DICTIONNARY={
        {AIR,"AIR",Color(0,0,0,0)},
        {GRASS,"GRASS",Color(0.2,0.4,0.1)},
        {DIRT,"DIRT",Color(0.7,0.5,0.5)},
        {SAND,"SAND",Color(0.7,0.7,0.2)},
        {WATER,"WATER",Color(0,0.8,0.8,0.5)},
};


