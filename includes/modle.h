//
// Created by Robert JONES on 2016/12/05.
//

#ifndef INC_42RUN_MODLE_H
#define INC_42RUN_MODLE_H

#include <structs.h>
#include <globals.h>
#include <mesh.h>

class Modle{
private:
    vector<Mesh> meshes;
    string directory;
public:
    Modle(GLchar *path){this->loadModel(path);};
    void draw(GLuint programID, GLuint texturID, vector<t_light> lights, glm::vec3 viewPos, bool isTextured);
};
#endif //INC_42RUN_MODLE_H
