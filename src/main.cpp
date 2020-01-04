
#include "engine/core/Engine.h"
#include "engine/test/Test.h"
#include "engine/test/MathTest.h"
int main() {
    Engine engine=Engine();
    MathTest test=MathTest();
    engine.start(test);
   return 0;
}
