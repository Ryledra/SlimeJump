#include <iostream>
#include <vector>
#include "engineMain.h"
#include "entity.h"
#include "shader.hpp"
#include "time.hpp"

int loop(Engine * engine, GLuint programID);
void tick();
void redraw(Engine * engine, GLuint programID);

struct {
    const char* name { "SlimeJump" };
    int window_size [2] { 640, 480 };

    int frame_rate { 60 };
    long ms_since_last_frame {};

    int tick_rate { 120 };
    long ms_since_last_tick {};
} window_details;

std::vector<Entity> entities;

int main()  {
    Engine engine = Engine( window_details.name, window_details.window_size);
    engine.createWindow();

    GLfloat triPos [3] { 0.0f, 0.0f, 0.0f };
    GLfloat triVel [3] { 0.0f, 0.0f, 0.0f };
    GLfloat triShape [] {
    -0.5f, 0.5f, 0.0f, // top left point
    0.5f, 0.5f, 0.0f, // top right point
    0.5f, -0.5f, 0.0f, // bottom right point
    
    0.5f, -0.5f, 0.0f, // bottom right point
    -0.5f, -0.5f, 0.0f, // bottom left point
    -0.5f, 0.5f, 0.0f, // top left point
    };
    entities.push_back( Entity(triPos, triVel, triShape, 18, true) );
    
    // background colour
    glClearColor( 0.0f, 0.0f, 0.4f, 0.0f );

    // load shaders
    GLuint programID { shader::loadShaders("shaders/simpleVertexShader.glsl", "shaders/simpleFragmentShader.glsl") };

    loop(&engine, programID);
    return 0;
}

int loop(Engine * engine, GLuint programID) {
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose((*engine).getWindow()))
    {
        (*engine).processInput();
        if (timings::elapsed_time( window_details.ms_since_last_tick ) > 1000/window_details.tick_rate)
            tick();
        if (timings::elapsed_time( window_details.ms_since_last_frame ) > 1000/window_details.frame_rate) 
            redraw(engine, programID);
    }
    std::cout << "Closing window" << std::endl;
    glfwTerminate();
    return 0;
}

void tick()
{
    // update state of all entities
    for(int i { 0 }; i < entities.size(); ++i)    {
        // std::cout << "printing entity " << i << std::endl;
        entities[i].updatePosition();
    }
}

void redraw(Engine * engine, GLuint programID)   {
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
    glfwSwapBuffers((*engine).getWindow());
    /* Poll for and process events */
    glfwPollEvents();
}
