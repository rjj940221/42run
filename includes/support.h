//
// Created by Robert JONES on 2016/12/06.
//

#ifndef INC_42RUN_SUPPORT_H
#define INC_42RUN_SUPPORT_H

#include "structs.h"
#include "globals.h"

GLint TextureFromFile(const char* path, string directory);

bool oglInit();

void player_key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

void save_ascii();

void RenderText( std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);

#endif //INC_42RUN_SUPPORT_H
