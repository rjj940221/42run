//
// Created by Robert JONES on 2016/12/01.
//

#include "42run.h"

Flaw::Flaw(GLuint bufferID, int numFace, GLfloat z){
    this->z = z;
    x = 0;
    y = -1;
    active = true;
    this->bufferID = bufferID;
    this->numFace = numFace;
}

void Flaw::update() {
    z -= 0.25;
    if (z < -6)
        active = false;
}