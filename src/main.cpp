
#include "engine/Core/Engine.h"

#include <Test/PrimitivesTest.h>
#include <Test/TextTest.h>
#include <Editor/Editor.h>

#include "Test/SpacialSceneTest.h"
#include "Test/LAB3.h"
#include "Test/LAB4.h"
#include <Test/LSystem.h>
int main() {
    Engine engine=Engine();
    auto s=LAB4();
    //auto e=Editor(s);
    engine.start(s);
    return 0;
}
