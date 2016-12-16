//
// Created by Robert JONES on 2016/12/06.
//

#ifndef INC_42RUN_MESH_H
#define INC_42RUN_MESH_H

#include "structs.h"
#include "shader.h"

class Mesh{
public:
    /*  Mesh Data  */
    vector<t_vertex> vertices;
    vector<GLuint> indices;
    vector<t_texture> textures;

    /*  Functions  */
    // Constructor
    Mesh(vector<t_vertex> vertices, vector<GLuint> indices, vector<t_texture> textures);
    // Render the mesh
    void Draw(Shader shader);
    ~Mesh(){};
private:
    /*  Render data  */
    GLuint VAO, VBO, EBO;
    GLfloat shiny;
    glm::vec3 ambient;
    glm::vec3 specular;
    glm::vec3 diffuse;

    void setupMesh();
};



#endif
