//
// Created by Robert JONES on 2016/12/03.
//

#include "42run.h"

Wall::Wall(GLuint bufferID, int numFace, GLfloat z, GLfloat rotateZ, GLfloat x){
    this->z = z;
    this->x = x;
    this->y = 2;
    this->rotateZ = rotateZ;
    active = true;
    this->bufferID = bufferID;
    this->numFace = numFace;
}

void Wall::update() {
    z -= 0.25;
    if (z < -12)
        active = false;
}