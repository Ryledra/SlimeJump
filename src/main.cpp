#include <iostream>
#include <vector>
#include <fstream>
#include "engine/engineMain.h"
#include "engine/engineMaths.h"
#include "entities/entity.h"
#include "common/shader.hpp"
// #include "common/listDIR.h"

int loop(Engine engine);
void redraw(Engine engine);

std::vector<Entity> entities;
GLuint programID;

int main()  {
    const char* name { "SlimeJump" };
    int window_size[2] = {640, 480};
    Engine engine = Engine(name, window_size);
    engine.createWindow();

    GLfloat triPos[3] = {0.0f,0.0f,0.0f};
    GLfloat triVel[3] = {0.0f,-0.005f,0.0f};
    GLfloat triShape[] = {
    -0.5f, 0.5f, 0.0f, // top left point
    0.5f, 0.5f, 0.0f, // top right point
    0.5f, -0.5f, 0.0f, // bottom right point
    
    0.5f, -0.5f, 0.0f, // bottom right point
    -0.5f, -0.5f, 0.0f, // bottom left point
    -0.5f, 0.5f, 0.0f, // top left point
    };
    entities.push_back(Entity(triPos, triVel, triShape, 18));
    // std::ifstream in("src/simpleVertexShader.glsl");
    // std::string vertexSrc((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    // std::cout << vertexSrc << std::endl;
    // ListDIR().list_dir(".");
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

    programID = shader::loadShaders("shaders/simpleVertexShader.glsl", "shaders/simpleFragmentShader.glsl");

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

void tick()
{
    // update state of all entities
}

void redraw(Engine engine)   {
    /* Render here */
    // glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Use our shader
    glUseProgram(programID);

    for(int i { 0 }; i < entities.size(); ++i)    {
        // std::cout << "printing entity " << i << std::endl;
        entities[i].draw();
    }

    /* Swap front and back buffers */
    glfwSwapBuffers(engine.getWindow());
    /* Poll for and process events */
    glfwPollEvents();
}
