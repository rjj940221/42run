//
// Created by Robert JONES on 2016/12/03.
//

#include <42run.h>

Room::Room(GLfloat z,  GLuint surfaceArrayID, GLuint textureIDs[4])
{
    flaw = new Flaw(surfaceArrayID, 6, z);
    ceiling = new Ceiling(surfaceArrayID, 6, z);
    leftWall = new Wall(surfaceArrayID, 6, z, 90, (GLfloat)(-3));
    rightWall = new Wall(surfaceArrayID, 6, z, 90, (GLfloat)3);
    this->textureIDs = &textureIDs[0];
    active = true;
}

bool Room::update() {
    flaw->update();
    ceiling->update();
    leftWall->update();
    rightWall->update();
    return (flaw->getActive());
}

