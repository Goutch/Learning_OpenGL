#include "Core/Engine.h"
#include "Scenes/Test/Test.h"
int main() {
  Engine engine=Engine();
  engine.run<Test>();
  engine.start();
    return 0;
}
