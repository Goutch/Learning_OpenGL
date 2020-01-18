#include <GL/glew.h>

#include <stdio.h>
#include <stdlib.h>

#define S(x) SS(x)
#define SS(x) #x

int main(int argc, char* argv[]) {
    printf("GLEW CMake Test, %s build\n",
        S(GLEW_CMAKE_TEST_CONFIG));
    printf("-- linked to %s which is %s\n",
        S(GLEW_CMAKE_TEST_TARGET_FILE_NAME),
        S(GLEW_CMAKE_TEST_TARGET_TYPE));
    const GLubyte* v = glewGetString(GLEW_VERSION);
    if(v) {
        printf("-- glewGetString(GLEW_VERSION) returns %s\n-- Test passed.\n", v);
        return EXIT_SUCCESS;
    } else {
        printf("-- glewGetString(GLEW_VERSION) returns NULL\n-- Test failed.\n");
        return EXIT_FAILURE;
    }
}
