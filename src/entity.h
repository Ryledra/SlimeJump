#include <iostream>

class Entity	{
	private:
		GLfloat g_vertex_buffer_data[9] = {
			-1.0f, -1.0f, 0.0f,
			1.0f, -1.0f, 0.0f,
			0.0f,  1.0f, 0.0f,
		};
		// This will identify our vertex buffer
		GLuint vertexbuffer;
		GLuint vao;

		void genVAO() {
			GLfloat * beg = std::begin(g_vertex_buffer_data);
			GLfloat * end = std::end(g_vertex_buffer_data);

			GLuint vbo = 0;
			glGenBuffers(1, &vbo);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, (end - beg) * sizeof(GLfloat), beg, GL_STATIC_DRAW);

			// Generate wrapping vertex array object.
			glGenVertexArrays(1, &vao);
			glBindVertexArray(vao);
			glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
		};

	public:
		Entity()	{
			// Generate 1 buffer, put the resulting identifier in vertexbuffer
			glGenBuffers(1, &vertexbuffer);
			// The following commands will talk about our 'vertexbuffer' buffer
			glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
			// Give our vertices to OpenGL.
			glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
			genVAO();
		}

		void draw()	{
			// 1st attribute buffer : vertices
			// glEnableVertexAttribArray(0);
			glBindVertexArray(vao);
			// Draw the triangle !
			glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
			glDisableVertexAttribArray(0);
			// std::cout << "here" << std::endl;
		}
};