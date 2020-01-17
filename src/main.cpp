
#include "engine/core/Engine.h"
#include "test/3D/RandomCubes.h"
#include "test/2D/NoiseTextureCreation.h"
#include "test/2D/AtlasTextureTest.h"
#include <test/3D/ImportModelTest.h>
int main() {
    Engine engine=Engine();
    auto s=RandomCubes();
    engine.start(s);
   return 0;
}
