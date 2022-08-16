#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../engine/engineMaths.h"

class Entity	
{
	private:

		GLfloat entityPos[3];
		GLfloat entityVel[3];

		GLfloat * p_shape_data {};
		int shape_data_size {};

		bool isPlayer {false};

		// This will identify our vertex buffer
		GLuint vbo;
		GLuint vao;

		void genVAO();
		GLfloat* updateVelocity();

	public:
		Entity();
		Entity(GLfloat initialPos[3], GLfloat initialVel[3], GLfloat shape[], int shape_size, bool isPlayer);
		void draw();
		void updatePosition();
};

#endif