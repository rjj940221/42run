//
// Created by Robert JONES on 2016/12/05.
//

#include "../includes/mesh.h"

Mesh::Mesh(vector<t_vertex> verices, vector<GLuint> indices, vector<t_texture> textures) {
    this->vertices = verices;
    this->indices = indices;
    this->textures = textures;

    this->setupMesh();
}

void Mesh::setupMesh() {
    glGenVertexArrays(1,&this->vertexArrayObj);
    glGenBuffers(1,&this->vertexBufferObj);
    glGenBuffers(1, &this->elementBufferObj);
    glBindVertexArray(this->vertexArrayObj);
    glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferObj);
    glBufferData(GL_ARRAY_BUFFER, this->vertices.size() *sizeof(t_vertex), &this->vertices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->elementBufferObj);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(GLuint), &this->indices[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, sizeof(t_vertex),(void*)offsetof(t_vertex,position));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1,3,GL_FLOAT, GL_FALSE, sizeof(t_vertex),(void*)offsetof(t_vertex,normal));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2,2,GL_FLOAT, GL_FALSE, sizeof(t_vertex),(void*)offsetof(t_vertex,texCoords));
    glBindVertexArray(0);
}

void Mesh::Draw(GLuint programID, GLuint texturID, vector<t_light> lights, glm::vec3 viewPos, bool isTextured) {
    GLuint diffuseNr = 1;
    GLuint specularNr = 1;
    int i = 0;
    /*for(GLuint i = 0; i < this->textures.size(); i++)
    {
        glActiveTexture(GL_TEXTURE0 + i); // Activate proper texture unit before binding
        // Retrieve texture number (the N in diffuse_textureN)
        stringstream ss;
        string number;
        string name = this->textures[i].type;
        if(name == "texture_diffuse")
            ss << diffuseNr++; // Transfer GLuint to stream
        else if(name == "texture_specular")
            ss << specularNr++; // Transfer GLuint to stream
        number = ss.str();

        glUniform1f(glGetUniformLocation(programID, ("material." + name + number).c_str()), i);
        glBindTexture(GL_TEXTURE_2D, this->textures[i].id);
    }
    glActiveTexture(GL_TEXTURE0);*/

    // Draw mesh
    glUseProgram(programID);
    glBindTexture(GL_TEXTURE_2D, texturID);
    glBindVertexArray(this->vertexArrayObj);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glEnableVertexAttribArray(3);
    model = glm::mat4(1.0f);

    model = translate(model, translateion);
    model = rotate(model, (float)(DEGREES_RADIANS(rotation.x)), glm::vec3{1, 0, 0});
    model = rotate(model, (float) (DEGREES_RADIANS(rotation.y)), glm::vec3{0, 1, 0});
    model = rotate(model, (float) (DEGREES_RADIANS(rotation.z)), glm::vec3{0, 0, 1});
    glm::mat4 mvp = g_projection * g_view * model;
    glUniformMatrix4fv(glGetUniformLocation(programID, "MVP"), 1, GL_FALSE, &mvp[0][0]);
    glUniformMatrix4fv(glGetUniformLocation(programID, "model"), 1, GL_FALSE, &model[0][0]);
    glUniform1i(glGetUniformLocation(programID,"NumLights"), (GLint)lights.size());
    for (vector<t_light>::iterator light = lights.begin(); light < lights.end(); light++) {
        string temp = "pointLights[";
        temp += to_string(i) += "].ambient";
        glUniform3f(glGetUniformLocation(programID, temp.c_str()), light->ambient.x, light->ambient.y, light->ambient.z);
        temp = "pointLights[";
        temp += to_string(i) += "].diffuse";
        glUniform3f(glGetUniformLocation(programID, temp.c_str()), light->diffuse.x, light->diffuse.y, light->diffuse.z);
        temp = "pointLights[";
        temp += to_string(i) += "].specular";
        glUniform3f(glGetUniformLocation(programID, temp.c_str()), light->specular.x, light->specular.y, light->specular.z);
        temp = "pointLights[";
        temp += to_string(i) += "].position";
        glUniform3f(glGetUniformLocation(programID, temp.c_str()), light->position.x, light->position.y, light->position.z);
        temp = "pointLights[";
        temp += to_string(i) += "].constant";
        glUniform1f(glGetUniformLocation(programID, temp.c_str()), light->constant);
        temp = "pointLights[";
        temp += to_string(i) += "].linear";
        glUniform1f(glGetUniformLocation(programID, temp.c_str()), light->linear);
        temp = "pointLights[";
        temp += to_string(i) += "].quadratic";
        glUniform1f(glGetUniformLocation(programID, temp.c_str()), light->quadratic);
        i++;
    }
    glUniform3f(glGetUniformLocation(programID, "viewPos"), viewPos.x, viewPos.y, viewPos.z);
    glUniform1i(glGetUniformLocation(programID, "isTextured"), isTextured);
    glUniform3f(glGetUniformLocation(programID, "material.ambient"), ambient.x, ambient.y, ambient.z);
    glUniform3f(glGetUniformLocation(programID, "material.specular"), specular.x, specular.y, specular.z);
    glUniform3f(glGetUniformLocation(programID, "material.diffuse"), diffuse.x, diffuse.y, diffuse.z);
    glUniform1f(glGetUniformLocation(programID, "material.shininess"), shiny);
    glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    glDisableVertexAttribArray(3);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}