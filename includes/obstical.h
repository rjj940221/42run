//
// Created by Robert JONES on 2016/11/29.
//

#ifndef INC_42RUN_OBSTICAL_H
#define INC_42RUN_OBSTICAL_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "support.h"
#include "42run.h"

class Obstical {
private:
    GLfloat z;
    GLfloat x;
    GLfloat y;
    glm::mat4 modle;

public:
    void render(GLint matrixID);
    bool update();
    Obstical();
};


#endif //INC_42RUN_OBSTICAL_H
