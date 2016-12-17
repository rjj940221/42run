//
// Created by Robert JONES on 2016/12/16.
//

#ifndef INC_42RUN_OBSTICAL_H
#define INC_42RUN_OBSTICAL_H

#include "structs.h"
#include "model.h"

class Obstical : public Model {
public :
    bool active;

    void Draw(Shader shader, glm::mat4 projection, glm::mat4 view);

    Obstical(GLchar *path, glm::vec3 location, glm::vec3 rotation);

    glm::vec3 getLocation() { return (translation); };

    void update();

    void setLocation(glm::vec3 location) { this->translation = location; };

    void setRotation(glm::vec3 rotation) {
        this->rotation = rotation;
    };
private:
    glm::vec3 translation;
    glm::vec3 rotation;
};

#endif //INC_42RUN_OBSTICAL_H
