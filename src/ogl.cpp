//
// Created by Robert JONES on 2016/11/28.
//

#include "../includes/42run.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
 /*   if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
        g_rotate.x += 0.5;
    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
        g_rotate.x -= 0.5;
    if (key == GLFW_KEY_UP && action == GLFW_PRESS)
        g_rotate.y += 0.5;
    if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
        g_rotate.y -= 0.5;
    if (key == GLFW_KEY_PAGE_UP && action == GLFW_PRESS)
        g_rotate.z += 0.5;
    if (key == GLFW_KEY_PAGE_DOWN && action == GLFW_PRESS)
        g_rotate.z -= 0.5;*/
}