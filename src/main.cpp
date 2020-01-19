
#include "engine/core/Engine.h"
#include "Test/RandomCubes.h"
#include "Test/NoiseTextureCreation.h"
#include "Test/AtlasTextureTest.h"
#include <Test/ImportModelTest.h>
#include "Test/FullSceneTest.h"
int main() {
    Engine engine=Engine();
    auto s=FullSceneTest();
    engine.start(s);
   return 0;
}
