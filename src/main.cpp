
#include <engine/core/Engine.h>
#include <engine/test/Test.h>
int main(void) {
    Engine engine=Engine();
    Test test=Test();
    engine.start(test);
   return 0;
}
