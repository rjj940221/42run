//
// Created by Robert JONES on 2016/12/01.
//

//#include "object.h"
#include "42run.h"

using namespace glm;
using namespace std;

void Object::render(GLint matrixID) {
    glBindVertexArray(bufferID);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    modle = glm::mat4(1.0f);
    modle = translate(modle, vec3{x, y, z});
    glm::mat4 mvp = g_projection * g_view * modle;
    glUniformMatrix4fv(matrixID, 1, GL_FALSE, &mvp[0][0]);
    glDrawArrays(GL_TRIANGLES, 0, numFace);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindVertexArray(0);
}