#include "entity.h"

void Entity::genVAO() 
{
    GLfloat* vertex_buffer_data = new GLfloat[shape_data_size];

    for(int i {0}; i < shape_data_size; ++i)	
    {
        vertex_buffer_data[i] = *(p_shape_data + i) + entityPos[i%3];
    }

    GLfloat * beg { vertex_buffer_data };
    GLfloat * end { vertex_buffer_data + (shape_data_size - 1) };

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
    }
}

Entity::Entity(GLfloat initialPos[3], GLfloat initialVel[3], GLfloat shape[], int shape_size)	
{
    std::cout << "entity created\n";
    for(int i {0}; i < 3; ++i)	{
        entityPos[i] = initialPos[i];
        entityVel[i] = initialVel[i];
    }
    p_shape_data = shape;
    shape_data_size = shape_size;
    // std::cout << shape_data << '\n';
}

void Entity::draw()	
{
    updatePosition();
    genVAO();
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, shape_data_size/3);
}