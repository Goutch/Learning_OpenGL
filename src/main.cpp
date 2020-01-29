
#include "engine/core/Engine.h"
#include "Test/PerformanceTest.h"
#include "Test/TextureCreationTest.h"
#include "Test/AtlasTextureTest.h"
#include <Test/ImportModelTest.h>
#include <Test/LAB2.h>
#include <Editor/Editor.h>
#include "Test/FullSceneTest.h"
#include "Test/LAB2.h"
int main() {
    Engine engine=Engine();
    auto s=FullSceneTest();
    auto e=Editor(s);

    engine.start(e);
    return 0;
}
