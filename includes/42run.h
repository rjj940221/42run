//
// Created by Robert JONES on 2016/11/28.
//

#ifndef INC_42RUN_42RUN_H
#define INC_42RUN_42RUN_H

#include <iostream>
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
#define WIDTH 800
#define HEIGHT 600

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include "player.h"
#include "obstical.h"

extern glm::mat4 modle;
extern glm::vec3 g_rotate;
extern glm::mat4 g_projection;
extern glm::mat4 g_view;
extern GLFWwindow *g_window;
typedef struct{
    GLfloat point[3];
    GLfloat normal[3];
    GLfloat color[3];
    GLfloat text[2];
}   t_buffer_element;


void    key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
bool    loadOBJ(const char * path, std::vector<t_buffer_element>*obj);
GLuint  LoadShaders(const char * vertex_file_path,const char * fragment_file_path);


#endif //INC_42RUN_42RUN_H
