#include "entity.h"

void Entity::genVAO() 
{
    GLfloat vertex_buffer_data[sizeof(shape_data)/sizeof(shape_data[0])];
    for(int i {0}; i < (sizeof(shape_data)/sizeof(shape_data[0])); ++i)	{
        vertex_buffer_data[i] = shape_data[i] + entityPos[i%3];
    }

    GLfloat * beg { std::begin(vertex_buffer_data) };
    GLfloat * end { std::end(vertex_buffer_data) };

    // GLuint vbo = 0;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, (end - beg) * sizeof(GLfloat), beg, GL_STATIC_DRAW);

    // Generate wrapping vertex array object.
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
}

void Entity::updatePosition()	
{
    GLfloat * newPos { engineMaths::addMatrix(entityPos, entityVel) };
    for(int i {0}; i < 3; ++i)	{
        entityPos[i] = * (newPos + i);
        // std::cout << entityPos[i] << std::endl;
    }
}

Entity::Entity(GLfloat initialPos[3], GLfloat initialVel[3], GLfloat shape[], int shape_size)	
{
    for(int i {0}; i < 3; ++i)	{
        entityPos[i] = initialPos[i];
        entityVel[i] = initialVel[i];
    }
    for(int i = 0 ; i < shape_size; i++)	{
        // [9] = {
        // 	0.0f, 0.0f, 0.0f,
        // 	0.5f, 0.0f, 0.0f,
        // 	0.250f, 0.5f, 0.0f,
        // };
        shape_data[i] = shape[i];
        // std::cout << i << ":" << shape_data[i] << std::endl;
    }
}

void Entity::draw()	
{
    updatePosition();
    genVAO();
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}