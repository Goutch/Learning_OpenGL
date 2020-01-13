
#include "engine/core/Engine.h"
#include "test/3D/RandomCubes.h"
#include "test/2D/NoiseTextureCreation.h"
#include "test/2D/AtlasTextureTest.h"
int main() {
    Engine engine=Engine();

    auto s=AtlasTextureTest();
    engine.start(s);
   return 0;
}
