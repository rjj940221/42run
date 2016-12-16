//
// Created by Robert JONES on 2016/12/16.
//

#include <obstical.h>

Obstical::Obstical(GLchar *path, glm::vec3 location) : Model(path) {
    this->translation = location;
    this->active = true;
}

void Obstical::Draw(Shader shader, glm::mat4 projection, glm::mat4 view) {
    glm::mat4 model = glm::mat4(1.0);
    model = glm::translate(model, this->translation);
    model = rotate(model, (float) (DEGREES_RADIANS(this->rotation.x)), glm::vec3{1, 0, 0});
    model = rotate(model, (float) (DEGREES_RADIANS(this->rotation.y)), glm::vec3{0, 1, 0});
    model = rotate(model, (float) (DEGREES_RADIANS(this->rotation.z)), glm::vec3{0, 0, 1});
    glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "model"), 1, GL_FALSE, &model[0][0]);
    glm::mat4 MVP = projection * view * model;
    glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "MVP"), 1, GL_FALSE, &MVP[0][0]);
    Model::Draw(shader);
}

void Obstical::update() {
    this->translation.z -= 0.25;
    if (this->translation.z < -12)
        active = false;
}