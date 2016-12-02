//
// Created by Robert JONES on 2016/11/29.
//

//#include "player.h"
#include "42run.h"

using namespace glm;


Player::Player(GLuint bufferID, int numFace) {
    this->dist = 0;
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->model = glm::mat4(1.0f);
    this->_jump = false;
    this->bufferID = bufferID;
    this->numFace = numFace;
}

void Player::up(int height) {
    y += 0.3;
    if (y > height)
        _jump = false;
}

void Player::down() {
    if (y > 0)
        y -= 0.1;
    y = (y < 0) ? 0 : y;
}

void Player::update() {
    dist += 0.25;
    if (_jump)
        up(4);
    else
        down();
}

void Player::moveLeft() {
    if (x < 2)
        x++;
}

void Player::moveRight() {
    if (x > -2)
        x--;
}

void Player::jump() {
    if (y == 0) {
        _jump = true;
        primery = true;
    }
}

int Player::getDist() {
    return ((int) this->dist);
}