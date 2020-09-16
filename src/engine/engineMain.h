#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define GL_SILENCE_DEPRECATION

class Engine	{
	private:
		const char* window_name;
		GLFWwindow* window;

	public:
		Engine(const char* name)	{
			window_name = name;
		}

		int createWindow()	{
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

			return 0;
		}

		GLFWwindow* getWindow()	{
			return window;
		}
};