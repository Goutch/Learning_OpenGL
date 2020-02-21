
#include "engine/Core/Engine.h"

#include <Test/PrimitivesTest.h>
#include <Test/TextTest.h>
#include <Editor/Editor.h>

#include "Test/SpacialSceneTest.h"
#include "Test/LAB3.h"
#include "Test/LAB4.h"
#include <Test/LSystem.h>
#include <Test/ImguiTest.h>
#include <Test/LAB5.h>

int main() {
    Engine engine=Engine();
    auto s=LAB5();
    auto e=Editor(s);
    engine.start(e);
    return 0;
}
