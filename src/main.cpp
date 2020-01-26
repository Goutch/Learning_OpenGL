
#include "engine/core/Engine.h"
#include "Test/PerformanceTest.h"
#include "Test/TextureCreationTest.h"
#include "Test/FullSceneTest.h"
#include "Editor/Editor.h"

int main() {
    Engine engine=Engine();
    auto s=Editor();
    engine.start(s);
    return 0;
}
