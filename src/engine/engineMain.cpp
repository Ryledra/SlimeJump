#include "engineMain.h"

Engine::Engine(const char* name, int size[2])	{
    window_name = name;
    window_size[0] = size[0];
    window_size[1] = size[1];
}

int Engine::createWindow()	{
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(window_size[0], window_size[1], window_name, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        return -1;
    }

    glViewport(0, 0, window_size[0], window_size[1]);

    /* Initialise glad */
    gladLoadGL();

    return 0;
}

void Engine::processInput()	{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

GLFWwindow* Engine::getWindow()	{
    return window;
}