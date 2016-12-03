//
// Created by Robert JONES on 2016/11/29.
//

//#include "obstical.h"
#include "42run.h"

Obstical::Obstical(GLuint bufferID, int numFace) {

    z = rand() % 50 + 50;
    x = rand() % 5 - 2;
    y = 0;
    active = true;
    this->ambient = glm::vec3(0.8, 0.8, 0.8);
    this->diffuse = glm::vec3(0.8, 0.8, 0.8);
    this->bufferID = bufferID;
    this->numFace = numFace;
}

void Obstical::update() {
    z -= 0.25f;
    if (z < -4)
        active = false;
}