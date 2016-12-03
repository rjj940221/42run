
#include "42run.h"

Ceiling::Ceiling(GLuint bufferID, int numFace, GLfloat z){
    this->z = z;
    x = 0;
    y = 5;
    active = true;
    this->bufferID = bufferID;
    this->numFace = numFace;
}

void Ceiling::update() {
    z -= 0.25;
    if (z < -12)
        active = false;
}