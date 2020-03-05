//
// Created by le6mon on 2020-03-05.
//

#include <API_ALL.h>
#include "Sphere.h"

Sphere::Sphere(float radius, int xCount, int yCount) {
    Geometry::make_sphere(*this, radius, xCount, yCount);
}
