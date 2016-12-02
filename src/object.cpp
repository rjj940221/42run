//
// Created by Robert JONES on 2016/12/01.
//

//#include "object.h"
#include "42run.h"

using namespace glm;
using namespace std;

Object::Object() {
    x = 0;
    y = 0;
    z = 0;
    rotateX = 0;
    rotateY = 0;
    rotateZ = 0;
}

void Object::render(GLint isTexturedID, GLint matrixID, GLint modelID, GLuint lightColID, GLuint lightPosID,
                    GLuint viewPosID, GLuint textureID, vec3 lightColor, vec3 lightPos, vec3 viewPos, int isTextured) {
    glBindTexture(GL_TEXTURE_2D, textureID);
    glBindVertexArray(bufferID);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glEnableVertexAttribArray(3);
    model = glm::mat4(1.0f);
    model = rotate(model, rotateX, vec3{1, 0, 0});
    model = rotate(model, rotateY, vec3{0, 1, 0});
    model = rotate(model, rotateZ, vec3{0, 0, 1});
    model = translate(model, vec3{x, y, z});
    glm::mat4 mvp = g_projection * g_view * model;
    glUniformMatrix4fv(matrixID, 1, GL_FALSE, &mvp[0][0]);
    glUniformMatrix4fv(modelID, 1, GL_FALSE, &model[0][0]);
    glUniform3f(lightColID, lightColor.x, lightColor.y, lightColor.z);
    glUniform3f(lightPosID, lightPos.x, lightPos.y, lightPos.z);
    glUniform3f(viewPosID, viewPos.x, viewPos.y, viewPos.z);
    glUniform1i(isTexturedID, isTextured);
    glDrawArrays(GL_TRIANGLES, 0, numFace);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    glDisableVertexAttribArray(3);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}