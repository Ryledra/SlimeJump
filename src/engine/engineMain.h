#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define GL_SILENCE_DEPRECATION

class Engine	{
	private:
		const char* window_name;

	public:
		Engine(char* name)	{
			window_name = name;
		}

		int createWindow()	{
			GLFWwindow* window;

			/* Initialize the library */
			if (!glfwInit())
				return -1;
			/* Create a windowed mode window and its OpenGL context */
			window = glfwCreateWindow(640, 480, window_name, NULL, NULL);
			if (!window)
			{
				glfwTerminate();
				return -1;
			}
			/* Make the window's context current */
			glfwMakeContextCurrent(window);

			/* Initialise glad */
			gladLoadGL();

			/* Loop until the user closes the window */
			while (!glfwWindowShouldClose(window))
			{
				/* Render here */
				glClear(GL_COLOR_BUFFER_BIT);
				/* Swap front and back buffers */
				glfwSwapBuffers(window);
				/* Poll for and process events */
				glfwPollEvents();
			}
			glfwTerminate();
			return 0;
		}
};