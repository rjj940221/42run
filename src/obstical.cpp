//
// Created by Robert JONES on 2016/11/29.
//

#include "obstical.h"

Obstical::Obstical() {
    z = 100;
    x = rand()% 3 - 1;
    y = 0;
}
void Obstical::render(GLint matrixID)
{
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    modle = glm::mat4(1.0f);
    modle = glm::translate(modle,glm::vec3{x, y, z});
    glm::mat4 mvp = g_projection * g_view * modle;
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(t_buffer_element), (void*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(t_buffer_element), (void*)(offsetof(t_buffer_element, color)));
    glUniformMatrix4fv(matrixID, 1, GL_FALSE, &mvp[0][0]);
    glDrawArrays(GL_TRIANGLES, 0, 12 * 3); // 3 indices starting at 0 -> 1 triangle
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

bool Obstical::update() {
    z -= 0.25;
    if (z > 0)
        return true;
    return false;
}