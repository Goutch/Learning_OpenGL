
#include "engine/core/Engine.h"
#include "test/RandomCubes.h"
#include "test/TextureCreation.h"
int main() {
    Engine engine=Engine();
    TextureCreation s=TextureCreation();
    engine.start(s);
   return 0;
}
