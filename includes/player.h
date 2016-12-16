//
// Created by Robert JONES on 2016/12/16.
//

#ifndef INC_42RUN_PLAYER_H
#define INC_42RUN_PLAYER_H

#include "structs.h"
#include <model.h>

class Player : public Model{
public:
    bool alive;
    Player(GLchar* Path);
    void update();
    void Draw(Shader shader, glm::mat4 projection, glm::mat4 view);
    void up(int height);
    void down();
    void moveLeft();
    void moveRight();
    void jump();
    int getDist(){ return (this->dist);};
    glm::vec3 getLocation(){ return (translation);};
    void reset();

private:
    glm::vec3 translation;
    glm::vec3 rotation;
    float dist;
    bool _jump;
};

#endif //INC_42RUN_PLAYER_H
