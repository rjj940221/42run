//
// Created by Robert JONES on 2016/12/16.
//

#ifndef INC_42RUN_GLOBALS_H
#define INC_42RUN_GLOBALS_H

#include "shader.h"

extern GLFWwindow *g_window;
extern FT_Library g_ft;
extern FT_Face g_face;
extern GLuint g_textArrayID;
extern GLuint g_textBufferID;
extern Shader *g_textShader;
extern map<GLchar, t_char> g_characters;
extern glm::mat4 g_textProjection;
#endif //INC_42RUN_GLOBALS_H
