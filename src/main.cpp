#include <iostream>
#include <vector>
#include <fstream>
#include "engine/engineMain.h"
#include "engine/engineMaths.h"
#include "entity.h"
#include "common/shader.hpp"
// #include "common/listDIR.h"

int loop(Engine engine);
void redraw(Engine engine);

std::vector<Entity> entities;
GLuint programID;

int main()  {
    const char* name = "SlimeJump";
    int window_size[2] = {640, 480};
    Engine engine = Engine(name, window_size);
    engine.createWindow();

    GLfloat triPos[3] = {0.0f,0.0f,0.0f};
    GLfloat triVel[3] = {0.0f,-0.01f,0.0f};
    GLfloat triShape[9] = {
        0.0f, 0.0f, 0.0f,
        0.5f, 0.0f, 0.0f,
        0.250f, 0.5f, 0.0f
    };
    entities.push_back(Entity(triPos, triVel, triShape, 9));
    // std::ifstream in("src/simpleVertexShader.glsl");
    // std::string vertexSrc((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    // std::cout << vertexSrc << std::endl;
    // ListDIR().list_dir(".");
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

    programID = LoadShaders("src/simpleVertexShader.glsl", "src/simpleFragmentShader.glsl");

    loop(engine);
    return 0;
}

int loop(Engine engine) {
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(engine.getWindow()))
    {
        engine.processInput();
        redraw(engine);
    }
    std::cout << "Closing window" << std::endl;
    glfwTerminate();
    return 0;
}

void redraw(Engine engine)   {
    /* Render here */
    // glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Use our shader
    glUseProgram(programID);

    for(int i = 0; i < entities.size(); i++)    {
        // std::cout << "printing entity " << i << std::endl;
        entities[i].draw();
    }

    /* Swap front and back buffers */
    glfwSwapBuffers(engine.getWindow());
    /* Poll for and process events */
    glfwPollEvents();
}
