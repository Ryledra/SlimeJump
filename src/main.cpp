#include <iostream>
#include "engine/engineMain.h"

int loop(Engine engine);
void redraw(Engine engine);

int main()  {
    const char* name = "SlimeJump";
    Engine engine = Engine(name);
    engine.createWindow();
    // std::cout << "Hello World" << std::endl;
    loop(engine);
    return 0;
}

int loop(Engine engine) {
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(engine.getWindow()))
    {
        redraw(engine);
    }
    glfwTerminate();
    return 0;
}

void redraw(Engine engine)   {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);
    /* Swap front and back buffers */
    glfwSwapBuffers(engine.getWindow());
    /* Poll for and process events */
    glfwPollEvents();
}