//
// Created by Robert JONES on 2016/12/01.
//

#include <42run.h>

using namespace glm;
using namespace std;

Object::Object() {
    x = 0;
    y = 0;
    z = 0;
    rotateX = 0;
    rotateY = 0;
    rotateZ = 0;
    ambient = vec3(1,1,1);
    diffuse = vec3(1,1,1);
    specular = vec3(1,1,1);
    shiny = 32;
}

void Object::render(GLuint programID, GLuint texturID, vector<t_light> lights, vec3 viewPos, bool isTextured) {
    int i = 0;

    glUseProgram(programID);
    glBindTexture(GL_TEXTURE_2D, texturID);
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
    glUniformMatrix4fv(glGetUniformLocation(programID, "MVP"), 1, GL_FALSE, &mvp[0][0]);
    glUniformMatrix4fv(glGetUniformLocation(programID, "model"), 1, GL_FALSE, &model[0][0]);
    glUniform1i(glGetUniformLocation(programID,"NumLights"), (GLint)lights.size());
    for (vector<t_light>::iterator light = lights.begin(); light < lights.end(); light++) {
        string temp = "pointLights[";
        temp += to_string(i) += "].ambient";
        glUniform3f(glGetUniformLocation(programID, temp.c_str()), light->ambient.x, light->ambient.y, light->ambient.z);
        temp = "pointLights[";
        temp += to_string(i) += "].diffuse";
        glUniform3f(glGetUniformLocation(programID, temp.c_str()), light->diffuse.x, light->diffuse.y, light->diffuse.z);
        temp = "pointLights[";
        temp += to_string(i) += "].specular";
        glUniform3f(glGetUniformLocation(programID, temp.c_str()), light->specular.x, light->specular.y, light->specular.z);
        temp = "pointLights[";
        temp += to_string(i) += "].position";
        glUniform3f(glGetUniformLocation(programID, temp.c_str()), light->position.x, light->position.y, light->position.z);
        temp = "pointLights[";
        temp += to_string(i) += "].constant";
        glUniform1f(glGetUniformLocation(programID, temp.c_str()), light->constant);
        temp = "pointLights[";
        temp += to_string(i) += "].linear";
        glUniform1f(glGetUniformLocation(programID, temp.c_str()), light->linear);
        temp = "pointLights[";
        temp += to_string(i) += "].quadratic";
        glUniform1f(glGetUniformLocation(programID, temp.c_str()), light->quadratic);
        i++;
    }

    glUniform3f(glGetUniformLocation(programID, "viewPos"), viewPos.x, viewPos.y, viewPos.z);
    glUniform1i(glGetUniformLocation(programID, "isTextured"), isTextured);
    glUniform3f(glGetUniformLocation(programID, "material.ambient"), ambient.x, ambient.y, ambient.z);
    glUniform3f(glGetUniformLocation(programID, "material.specular"), specular.x, specular.y, specular.z);
    glUniform3f(glGetUniformLocation(programID, "material.diffuse"), diffuse.x, diffuse.y, diffuse.z);
    glUniform1f(glGetUniformLocation(programID, "material.shininess"), shiny);
    glDrawArrays(GL_TRIANGLES, 0, numFace);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    glDisableVertexAttribArray(3);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}