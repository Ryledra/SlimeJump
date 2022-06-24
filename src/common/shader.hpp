#ifndef SHADER_HPP
#define SHADER_HPP

namespace shader
{
    std::string readShaderCode(const char * shader_file_path);
    bool checkShader(GLuint shaderID, int * InfoLogLength, GLint * Result);
    void compileShader(GLuint * shaderID, std::string shaderCode, const char * shader_file_path);
    GLuint loadShader(const int shaderType, const char * shader_file_path, int * InfoLogLength, GLint * Result);
    bool checkProgramID(GLuint ProgramID, int * InfoLogLength, GLint * Result);
    GLuint loadShaders(const char * vertex_file_path, const char * fragment_file_path);
}

#endif