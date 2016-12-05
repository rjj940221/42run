//
// Created by Robert JONES on 2016/12/05.
//

#ifndef INC_42RUN_MESH_H
#define INC_42RUN_MESH_H

#include <structs.h>
#include <globals.h>
#define DEGREES_RADIANS(x) (x * M_PI) / 180
/*#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;
// GL Includes
#include <GL/glew.h> // Contains all the necessery OpenGL includes
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

typedef struct s_vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
} t_vertex;
typedef struct texture {
    GLuint id;
    string type;
} t_texture;*/

class Mesh {
private:
    GLuint vertexArrayObj;
    GLuint vertexBufferObj;
    GLuint elementBufferObj;
    glm::mat4 model;
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    glm::vec3 translateion;
    glm::vec3 rotation;
    float shiny;
    void setupMesh();
public:
    vector<t_vertex> vertices;
    vector<GLuint> indices;
    vector<t_texture> textures;
    Mesh(vector<t_vertex> verices, vector<GLuint> indices, vector<t_texture> textures);
    void Draw(GLuint programID, GLuint texturID, vector<t_light> lights, glm::vec3 viewPos, bool isTextured);
};
#endif //INC_42RUN_MESH_H
