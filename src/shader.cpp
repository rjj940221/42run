//
// Created by Robert JONES on 2016/12/06.
//

#include <shader.h>

void compileFile(const char *file_path, GLuint reID) {
    int InfoLogLength;
    string shaderCode;
    GLint Result = GL_FALSE;

    ifstream shaderStream(file_path, std::ios::in);
    if (shaderStream.is_open()) {
        string Line = "";
        while (getline(shaderStream, Line))
            shaderCode += "\n" + Line;
        shaderStream.close();
    } else {
        printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", file_path);
        getchar();
        return;
    }
    printf("Compiling shader : %s\n", file_path);
    char const *sourcePointer = shaderCode.c_str();
    glShaderSource(reID, 1, &sourcePointer, NULL);
    glCompileShader(reID);

    glGetShaderiv(reID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(reID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0) {
        std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
        glGetShaderInfoLog(reID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        printf("%s\n", &VertexShaderErrorMessage[0]);
    }
}

Shader::Shader(const char *vertex_file_path, const char *fragment_file_path) {

    GLuint VertexShaderID;
    GLuint FragmentShaderID;
    GLint Result = GL_FALSE;
    int InfoLogLength;

    VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    compileFile(vertex_file_path, VertexShaderID);
    compileFile(fragment_file_path, FragmentShaderID);

    printf("Linking program\n");
    this->Program = glCreateProgram();
    glAttachShader(this->Program, VertexShaderID);
    glAttachShader(this->Program, FragmentShaderID);
    glLinkProgram(this->Program);

    glGetProgramiv(this->Program, GL_LINK_STATUS, &Result);
    glGetProgramiv(this->Program, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0) {
        std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
        glGetProgramInfoLog(this->Program, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        printf("%s\n", &ProgramErrorMessage[0]);
    }

    glDetachShader(this->Program, VertexShaderID);
    glDetachShader(this->Program, FragmentShaderID);
    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);
}