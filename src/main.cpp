#include <iostream>
#include <vector>
#include "engine/engineMain.h"
#include "entity.h"

int loop(Engine engine);
void redraw(Engine engine);

std::vector<Entity> entities;

int main()  {
    const char* name = "SlimeJump";
    int window_size[2] = {640, 480};
    Engine engine = Engine(name, window_size);
    engine.createWindow();

    entities.push_back(Entity());

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

    for(int i = 0; i < entities.size(); i++)    {
        // std::cout << "printing entity " << i << std::endl;
        entities[i].draw();
    }

    /* Swap front and back buffers */
    glfwSwapBuffers(engine.getWindow());
    /* Poll for and process events */
    glfwPollEvents();
}
