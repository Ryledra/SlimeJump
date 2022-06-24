#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

#include <stdlib.h>
#include <string.h>

#include <glad/glad.h>

#include "shader.hpp"

std::string shader::readShaderCode(const char * shader_file_path)
{
	std::string shaderCode {};
	std::ifstream shaderStream(shader_file_path,  std::ios::in);
	if(shaderStream.is_open())
	{
		std::stringstream sstr {};
		sstr << shaderStream.rdbuf();
		shaderCode = sstr.str();
		shaderStream.close();
	} 
	else
	{
		std::cout << "Impossible to open " << shader_file_path 
			<< ". Are you in the right directory ? Don't forget to read the FAQ !\n";
		getchar();
		return 0;
	}
	return shaderCode;
}

bool shader::checkShader(GLuint shaderID, int * InfoLogLength, GLint * Result)
{
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, Result);
	glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, InfoLogLength);
	if ( *InfoLogLength > 0 )
	{
		std::vector<char> shaderErrorMessage(*InfoLogLength+1);
		glGetShaderInfoLog(shaderID, *InfoLogLength, NULL, &shaderErrorMessage[0]);
		std::cout << &shaderErrorMessage[0] << '\n';
		return false;
	}
	return true;
}

void shader::compileShader(GLuint * shaderID, std::string shaderCode, const char * shader_file_path)
{
	std::cout << "Compiling shader : " << shader_file_path << "\n";
	char const * sourcePointer = shaderCode.c_str();
	std::cout << *shaderID << '\n';
	glShaderSource(*shaderID, 1, &sourcePointer , NULL);
	std::cout << *shaderID << '\n';
	glCompileShader(*shaderID);
	std::cout << *shaderID << '\n';
}

GLuint shader::loadShader(const int shaderType, const char * shader_file_path, int * InfoLogLength, GLint * Result)
{
	// create a shader
	GLuint shaderID {};
	if (shaderType == 0)
		shaderID = glCreateShader(GL_VERTEX_SHADER);
	else
		shaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// read shader code from file
	std::string shaderCode { shader::readShaderCode(shader_file_path) };

	// compile the shader
	shader::compileShader(&shaderID, shaderCode,  shader_file_path);
	// check the shader
	if ( shader::checkShader(shaderID, InfoLogLength, Result) )
		std::cout << shader_file_path << " : PASS\n";
	else
		std::cout << shader_file_path << " : FAIL\n";

	return shaderID;
}

bool shader::checkProgramID(GLuint ProgramID, int * InfoLogLength, GLint * Result)
{
	// check the program
	glGetProgramiv(ProgramID, GL_LINK_STATUS, Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, InfoLogLength);
	if ( *InfoLogLength > 0 ){
		std::vector<char> ProgramErrorMessage(*InfoLogLength+1);
		glGetProgramInfoLog(ProgramID, *InfoLogLength, NULL, &ProgramErrorMessage[0]);
		std::cout << &ProgramErrorMessage[0] << '\n';
		return false;
	}
	return true;
}

GLuint shader::loadShaders(const char * vertex_file_path, const char * fragment_file_path)
{
	int InfoLogLength {};
	GLint Result { GL_FALSE };

	GLuint VertexShaderID { shader::loadShader(0, vertex_file_path, & InfoLogLength, & Result) };
	GLuint FragmentShaderID { shader::loadShader(1, fragment_file_path, & InfoLogLength, & Result) };

	// Link the program
	printf("Linking program\n");
	GLuint ProgramID { glCreateProgram() };
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	// Check the program
	if ( shader::checkProgramID(ProgramID, & InfoLogLength, & Result) )
		std::cout << " Shaders successfully linked to Program.\n";
	else
		std::cout << " Shaders link to Program failed.\n";
	
	glDetachShader(ProgramID, VertexShaderID);
	glDetachShader(ProgramID, FragmentShaderID);
	
	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);

	return ProgramID;
}