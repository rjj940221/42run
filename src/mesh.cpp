//
// Created by Robert JONES on 2016/12/06.
//

#include "../includes/mesh.h"

Mesh::Mesh(vector<t_vertex> vertices, vector<GLuint> indices, vector<t_texture> textures) {
    this->vertices = vertices;
    this->indices = indices;
    this->textures = textures;

    this->ambient = {0.6, 0.6, 0.6};
    this->specular = {1, 1, 1};
    this->shiny = 32;
    this->diffuse = {0.6, 0.6, 0.6};
    this->setupMesh();
}

void Mesh::Draw(Shader shader) {
    GLuint diffuseNr = 1;
    GLuint specularNr = 1;
    bool isTextured = false;
    for (GLuint i = 0; i < this->textures.size(); i++) {
        glActiveTexture(GL_TEXTURE0 + i); // Activate proper texture unit before binding
        stringstream ss;
        string number;
        string name = this->textures[i].type;
        if (name == "texture_diffuse")
            ss << diffuseNr++; // Transfer GLuint to stream
        else if (name == "texture_specular")
            ss << specularNr++; // Transfer GLuint to stream
        number = ss.str();

        glUniform1f(glGetUniformLocation(shader.getProgram(), ("material." + name + number).c_str()), i);
        glBindTexture(GL_TEXTURE_2D, this->textures[i].id);
        isTextured = true;
    }
    glActiveTexture(GL_TEXTURE0);

    // Draw mesh
    glUniform3f(glGetUniformLocation(shader.getProgram(), "material.ambient"), ambient.x, ambient.y, ambient.z);
    glUniform3f(glGetUniformLocation(shader.getProgram(), "material.specular"), specular.x, specular.y, specular.z);
    glUniform3f(glGetUniformLocation(shader.getProgram(), "material.diffuse"), diffuse.x, diffuse.y, diffuse.z);
    glUniform1f(glGetUniformLocation(shader.getProgram(), "material.shininess"), shiny);
    glUniform1i(glGetUniformLocation(shader.getProgram(), "isTextured"), isTextured);
    glBindVertexArray(this->VAO);
    glDrawElements(GL_TRIANGLES, (GLsizei) this->indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Mesh::setupMesh() {
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    glGenBuffers(1, &this->EBO);

    glBindVertexArray(this->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(t_vertex), &this->vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(GLuint), &this->indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(t_vertex), (GLvoid *) 0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(t_vertex), (GLvoid *) offsetof(t_vertex, Normal));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(t_vertex), (GLvoid *) offsetof(t_vertex, TexCoords));

    glBindVertexArray(0);
}