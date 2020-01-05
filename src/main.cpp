
#include "engine/core/Engine.h"
#include "engine/test/Test.h"
#include "engine/test/MathTest.h"
int main() {
    Engine engine=Engine();
    Test test=Test();
    engine.start(test);
   return 0;
}
