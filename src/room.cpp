//
// Created by Robert JONES on 2016/12/03.
//

#include <42run.h>

Room::Room(GLfloat z,  GLuint surfaceArrayID, GLuint textureIDs[4])
{
    this->z = z;
    flaw = new Flaw(surfaceArrayID, 6, z);
    ceiling = new Ceiling(surfaceArrayID, 6, z);
    leftWall = new Wall(surfaceArrayID, 6, z, 90, (GLfloat)(-3));
    rightWall = new Wall(surfaceArrayID, 6, z, 90, (GLfloat)3);
    this->textureIDs = &textureIDs[0];
    active = true;
}

bool Room::update() {
    z -= 0.25;
    flaw->update();
    ceiling->update();
    leftWall->update();
    rightWall->update();
    return (flaw->getActive());
}

void Room::render(std::vector<t_light> lights, GLuint programID, glm::vec3 viewPos) {
    flaw->render(programID,textureIDs[0], lights, viewPos, true);
    ceiling->render(programID,textureIDs[1], lights, viewPos, true);
    leftWall->render(programID,textureIDs[2], lights, viewPos, true);
    rightWall->render(programID,textureIDs[3], lights, viewPos, true);
}

Room::~Room() {
    /*delete(flaw);
    delete(ceiling);
    delete(leftWall);
    delete(rightWall);*/
}

