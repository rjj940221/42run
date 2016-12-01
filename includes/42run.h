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
#include FT_FREETYPE_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <map>

#define BUFF_SIZE 32
#define WIDTH 800
#define HEIGHT 600


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


class Object {
protected:
    GLfloat x;
    GLfloat y;
    GLfloat z;
    glm::mat4 modle;
    GLuint bufferID;
    int numFace;
public:
    GLfloat getX() { return (x); };

    GLfloat getY() { return (y); };

    GLfloat getZ() { return (z); };

    void render(GLint matrixID);

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

    ~Flaw(){};
};

void player_key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

bool loadOBJ(const char *path, std::vector<t_buffer_element> *obj);

GLuint LoadShaders(const char *vertex_file_path, const char *fragment_file_path);

bool removeObstical(Obstical &o);

void save_ascii();

void RenderText(GLuint programID, std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);


#endif //INC_42RUN_42RUN_H
