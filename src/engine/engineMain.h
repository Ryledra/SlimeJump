#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define GL_SILENCE_DEPRECATION

class Engine	{
	private:
		const char* window_name;
		int window_size[2];
		GLFWwindow* window;

	public:
		Engine(const char* name, int size[2])	{
			window_name = name;
			window_size[0] = size[0];
			window_size[1] = size[1];
		}

		int createWindow()	{
			/* Initialize the library */
			if (!glfwInit())
				return -1;
			/* Create a windowed mode window and its OpenGL context */
			window = glfwCreateWindow(window_size[0], window_size[1], window_name, NULL, NULL);
			if (!window)
			{
				glfwTerminate();
				return -1;
			}
			/* Make the window's context current */
			glfwMakeContextCurrent(window);

			/* Initialise glad */
			gladLoadGL();

			return 0;
		}

		GLFWwindow* getWindow()	{
			return window;
		}
};