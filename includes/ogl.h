//
// Created by Robert JONES on 2016/11/28.
//

#ifndef INC_42RUN_OGL_H
#define INC_42RUN_OGL_H
#define WIDTH 800
#define HEIGHT 600

#include <unistd.h>
#include <iostream>
#include <fstream>
#include "../includes/support.h"
// GLEW
#define GLEW_STATIC

#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

#define BUFF_SIZE 32

using namespace std;

class OGL {
private:
    GLFWwindow *window;
    int width;
    int height;
    GLuint program_id;

public:
    OGL();

    void bindShaders(string vertexShaderName, string fragmentShaderName);

    void load_program(char *vertex_shader, char *fragment_shader);

    GLFWwindow *getWindow() { return (this->window); };

    GLuint getShaderProgram() { return (this->program_id); };
};

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode);


#endif //INC_42RUN_OGL_H
