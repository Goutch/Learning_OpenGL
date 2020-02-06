//
// Created by User on 01-Feb.-2020.
//

#include "Quad.h"
#include <Geometry/Geometry.h>
Quad::Quad(PIVOT pivot) {
   switch(pivot)
   {
       case CENTER: Geometry::make_quad(*this);
           break;
       case DOWN_LEFT: Geometry::make_quad(*this,1,1,0.5,0.5);
           break;


   }

}
