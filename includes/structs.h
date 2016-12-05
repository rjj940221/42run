//
// Created by Robert JONES on 2016/12/05.
//

#ifndef INC_42RUN_STRUCTS_H
#define INC_42RUN_STRUCTS_H
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;
// GL Includes
// GLEW
#define GLEW_STATIC

#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
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
} t_texture;

typedef struct {
    GLfloat point[3];
    GLfloat normal[3];
    GLfloat color[3];
    GLfloat text[2];
} t_buffer_element;

typedef struct {
    GLuint TextureID;  // ID handle of the glyph texture
    glm::ivec2 Size;       // Size of glyph
    glm::ivec2 Bearing;    // Offset from baseline to left/top of glyph
    GLuint Advance;    // Offset to advance to next glyph
} t_char;

typedef struct {
    glm::vec3 position;
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    float     constant;
    float     linear;
    float     quadratic;

} t_light;
#endif //INC_42RUN_STRUCTS_H
