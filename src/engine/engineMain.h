#ifndef ENGINE_MAIN_H
#define ENGINE_MAIN_H

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

		void processInput()	{
			if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(window, true);
		}

		GLFWwindow* getWindow()	{
			return window;
		}
};

#endif