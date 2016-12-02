//
// Created by Robert JONES on 2016/12/01.
//

//#include "object.h"
#include "42run.h"

using namespace glm;
using namespace std;

void Object::render(GLint matrixID, GLint modelID, GLuint lightColID, GLuint lightPosID, GLuint textureID, vec3 lightColor, vec3 lightPos) {
    glBindTexture(GL_TEXTURE_2D, textureID);
    glBindVertexArray(bufferID);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glEnableVertexAttribArray(3);
    model = glm::mat4(1.0f);
    model = translate(model, vec3{x, y, z});
    glm::mat4 mvp = g_projection * g_view * model;
    glUniformMatrix4fv(matrixID, 1, GL_FALSE, &mvp[0][0]);
    glUniformMatrix4fv(modelID, 1, GL_FALSE, &model[0][0]);
    glUniform3f(lightColID, lightColor.x, lightColor.y, lightColor.z);
    glUniform3f(lightPosID, lightPos.x, lightPos.y, lightPos.z);
    glDrawArrays(GL_TRIANGLES, 0, numFace);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    glDisableVertexAttribArray(3);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}