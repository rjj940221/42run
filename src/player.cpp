//
// Created by Robert JONES on 2016/12/16.
//

#include <player.h>

Player::Player(){
    jumpModel = new Model((GLchar *) "Models/nanosuit/nanosuitjump.obj");
    leftModel = new Model((GLchar *) "Models/nanosuit/nanosuitleft.obj");
    rightModel = new Model((GLchar *) "Models/nanosuit/nanosuitright.obj");
    side = 0;
    this->translation = glm::vec3(0,-3,0);
    this->dist = 0;
    this->_jump = false;
}

void Player::update() {
    static int swich = 0;
    if (swich == 20)
    {
        swich = 0;
        side = (side == 0)? 1 : 0;
    }
    else
        swich++;
    this->dist += 0.25;
    if (_jump)
        up(1);
    else
        down();
   /* if (glfwGetKey(g_window, GLFW_KEY_LEFT) && this->translation.x < 2)
        this->translation.x += 0.06;
    if (glfwGetKey(g_window, GLFW_KEY_RIGHT) && this->translation.x > -2)
        this->translation.x -= 0.06;*/
}

void Player::Draw(Shader shader, glm::mat4 projection, glm::mat4 view) {
    glm::mat4 model = glm::mat4(1.0);
    model = glm::translate(model, this->translation);
    model = rotate(model, (float) (DEGREES_RADIANS(this->rotation.x)), glm::vec3{1, 0, 0});
    model = rotate(model, (float) (DEGREES_RADIANS(this->rotation.y)), glm::vec3{0, 1, 0});
    model = rotate(model, (float) (DEGREES_RADIANS(this->rotation.z)), glm::vec3{0, 0, 1});
    glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "model"), 1, GL_FALSE, &model[0][0]);
    glm::mat4 MVP = projection * view * model;
    glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "MVP"), 1, GL_FALSE, &MVP[0][0]);
    if (_jump || translation.y > -3)
        jumpModel->Draw(shader);
    else {
        if (side == 1)
            leftModel->Draw(shader);
        else
            rightModel->Draw(shader);
    }
}

void Player::up(int height) {
    this->translation.y += 0.3;
    if (this->translation.y > height)
        _jump = false;
}

void Player::down() {
    if (this->translation.y > -3)
        this->translation.y -= 0.1;
    this->translation.y = (this->translation.y < -3) ? -3 : this->translation.y;
}


void Player::moveLeft() {
    if (this->translation.x < 2)
        this->translation.x++;
}

void Player::moveRight() {
    if (this->translation.x > -2)
        this->translation.x--;
}

void Player::jump() {
    if (this->translation.y == -3) {
        _jump = true;
    }
}

void Player::reset() {
    this->dist = 0;
    this->translation = glm::vec3(0,-3,0);
    this->_jump = false;
}