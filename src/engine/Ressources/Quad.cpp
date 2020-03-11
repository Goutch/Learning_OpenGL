//
// Created by User on 01-Feb.-2020.
//

#include "Quad.h"
#include <Utils/Geometry.h>

Quad::Quad(float offsetX, float offsetY) {

    Geometry::make_quad(*this, 1, 1, offsetX, offsetY);
}
