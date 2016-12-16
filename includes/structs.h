//
// Created by Robert JONES on 2016/12/06.
//

#ifndef INC_42RUN_STRUCTS_H
#define INC_42RUN_STRUCTS_H

// GLEW
#define GLEW_STATIC

#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;
// GL Includes
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Importer.hpp>
#include <scene.h>
#include <postprocess.h>
#include <SOIL.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <map>

#define WIDTH 800
#define HEIGHT 600
#define DEGREES_RADIANS(x) (x * M_PI) / 180
#define GAMEPACE 0.25;



typedef struct s_vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
} t_vertex;

typedef struct s_texture {
    GLuint id;
    string type;
    aiString path;
} t_texture;

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
    float constant;
    float linear;
    float quadratic;
} t_light;

#endif //INC_42RUN_STRUCTS_H
