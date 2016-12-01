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
    this->bufferID = bufferID;
    this->numFace = numFace;
}

void Obstical::update() {
    z -= 0.25f;
    if (z < -4)
        active = false;
}