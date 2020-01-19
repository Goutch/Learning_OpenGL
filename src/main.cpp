
#include "engine/core/Engine.h"
#include "Test/RandomCubes.h"
#include "Test/NoiseTextureCreation.h"
#include "Test/AtlasTextureTest.h"
#include <Test/ImportModelTest.h>
int main() {
    Engine engine=Engine();
    auto s=ImportModelTest();
    engine.start(s);
   return 0;
}
