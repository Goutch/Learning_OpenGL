
#include "engine/core/Engine.h"
#include "Test/PerformanceTest.h"
#include "Test/TextureCreationTest.h"
#include "Test/AtlasTextureTest.h"
#include <Test/ImportModelTest.h>
#include <Test/LAB2.h>
#include "Test/FullSceneTest.h"
#include "Test/LAB2.h"
int main() {
    Engine engine=Engine();
    auto s=LAB2();
    engine.start(s);
    return 0;
}
