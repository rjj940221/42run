//
// Created by Robert JONES on 2016/11/28.
//

#ifndef INC_42RUN_42RUN_H
#define INC_42RUN_42RUN_H

#include <iostream>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include "../includes/support.h"
// GLEW
#define GLEW_STATIC

#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
#include <ft2build.h>
#include <SOIL.h>
#include FT_FREETYPE_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <map>
#include <iostream>
#define BUFF_SIZE 32
#define WIDTH 800
#define HEIGHT 600
#define DEGREES_RADIANS(x) (x * M_PI) / 180


extern glm::mat4 modle;
extern glm::vec3 g_rotate;
extern glm::mat4 g_projection;
extern glm::mat4 g_view;
extern GLFWwindow *g_window;

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

typedef struct {
    GLint matrixID;
    GLint modelID;
    GLint viewPosID;
    GLuint texturID;
    GLint isTexturedID;
    GLint matAmbiantID;
    GLint matDiffuseID;
    GLint matSpecularID;
    GLint matShinyID;
    GLint lightPosID;
    GLint lightAmbientID;
    GLint lightSpecularID;
    GLint lightDiffuseID;
    GLint lightConstantID;
    GLint lightLinearID;
    GLint lightQuadraticID;
} t_shader_uniforms;



class Object {
protected:
    GLfloat x;
    GLfloat y;
    GLfloat z;
    GLfloat rotateX;
    GLfloat rotateY;
    GLfloat rotateZ;
    glm::mat4 model;
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    float shiny;
    GLuint bufferID;
    int numFace;
public:
    Object();

    GLfloat getX() { return (x); };

    GLfloat getY() { return (y); };

    GLfloat getZ() { return (z); };

    GLfloat getRotateX() { return (rotateX); };

    GLfloat getRotateY() { return (rotateY); };

    GLfloat getRotateZ() { return (rotateZ); };

    void setX(GLfloat val) { x = val; };

    void setY(GLfloat val) { y = val; };

    void setZ(GLfloat val) { z = val; };

    void setRotateX(GLfloat val) { rotateX = val; };

    void setRotateY(GLfloat val) { rotateY = val; };

    void setRotateZ(GLfloat val) { rotateZ = val; };

    void render(GLuint programID, GLuint texturID, std::vector<t_light> lights, glm::vec3 viewPos, bool isTextured);

    virtual ~Object() {};
};

class Player : public Object {
private:
    float dist;
    bool _jump;
    bool primery;
    bool bounce;

    void up(int height);

    void down();

public:
    void update();

    Player(GLuint bufferID, int numFace);

    void moveLeft();

    void moveRight();

    void jump();

    int getDist();

    ~Player() {};
};

class Obstical : public Object {
private:
    bool active;
public:

    void update();

    Obstical(GLuint bufferID, int numFace);

    bool getActive() { return (active); };

    ~Obstical() {};
};

class Flaw : public Object {
private:
    bool active;
public:
    Flaw(GLuint bufferID, int numFace, GLfloat z);

    void update();

    bool getActive() { return (active); };

    ~Flaw() {};
};

class Ceiling : public Object {
private:
    bool active;
public:
    Ceiling(GLuint bufferID, int numFace, GLfloat z);

    void update();

    bool getActive() { return (active); };

    ~Ceiling() {};
};

class Wall : public Object {
private:
    bool active;
public:
    Wall(GLuint bufferID, int numFace, GLfloat z, GLfloat rotateZ, GLfloat x);

    void update();

    bool getActive() { return (active); };

    ~Wall() {};
};

class Room{
private:
    float z;
    Flaw *flaw;
    Ceiling *ceiling;
    Wall *leftWall;
    Wall *rightWall;
    GLuint *textureIDs;
    bool active;
public:
    float getZ(){ return (this->z);};
    bool update();
    void render(std::vector<t_light> lights, GLuint programID, glm::vec3 viewPos);
    Room(GLfloat z, GLuint surfaceArrayID, GLuint textureIDs[4]);
    ~Room();
};


void player_key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

bool loadOBJ(const char *path, std::vector<t_buffer_element> *obj);

GLuint LoadShaders(const char *vertex_file_path, const char *fragment_file_path);

void useShader(GLuint programID, t_shader_uniforms *uniforms);

bool removeObstical(Obstical &o);

void save_ascii();

void RenderText(GLuint programID, std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);

GLuint load_texture(std::string file);

#endif //INC_42RUN_42RUN_H
