//
// Created by Robert JONES on 2016/11/29.
//

#include "player.h"

using namespace glm;

Player::Player()
{
    this->dist = 0;
    this->x = 0;
    this->y = 0;
    modle = glm::mat4(1.0f);
}


void Player::render(GLint matrixID)
{
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    modle = glm::mat4(1.0f);
    modle = translate(modle,vec3{x, y,0.0f});
    glm::mat4 mvp = g_projection * g_view * modle;
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(t_buffer_element), (void*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(t_buffer_element), (void*)(offsetof(t_buffer_element, color)));
    glUniformMatrix4fv(matrixID, 1, GL_FALSE, &mvp[0][0]);
    glDrawArrays(GL_TRIANGLES, 0, 12 * 3); // 3 indices starting at 0 -> 1 triangle
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

void Player::update() {
    dist+=0.25;
    static GLfloat ydir = 0;
    if (glfwGetKey(g_window, GLFW_KEY_LEFT) == GLFW_PRESS && x < 2) {
        x += 0.5;
    }
    if (glfwGetKey(g_window, GLFW_KEY_RIGHT) == GLFW_PRESS && x > -2) {
        x -= 0.5;
    }
    if (glfwGetKey(g_window, GLFW_KEY_UP) == GLFW_PRESS && y == 0) {
        ydir = 0.1;
    }
    if (y < 3 && ydir > 0.0f)
    {
        y += ydir;
        if(y == 3)
            ydir = -0.5;
    }
    else if(y > 0 && ydir < 0.0f)
    {
        y += ydir;
    }

}