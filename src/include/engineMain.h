#ifndef ENGINE_MAIN_H
#define ENGINE_MAIN_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Engine	
{
	private:
		const char* window_name;
		int window_size[2];
		GLFWwindow* window;

	public:
		Engine(const char* name, int size[2]);

		int createWindow();
		void processInput();
		GLFWwindow* getWindow();

		bool keyPressed(int gl_key_token);
		bool keyReleased(int gl_key_token);
};

#endif