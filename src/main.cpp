// Include standard headers
#include <42run.h>

using namespace glm;
using namespace std;
Player *myPlayer;
int UPDATES_SECOND = 60;
GLFWwindow *g_window;
//FTGLPixmapFont g_font("/home/user/Arial.ttf");
mat4 g_projection = glm::perspective(glm::radians(60.0f), (float) WIDTH / (float) HEIGHT, 0.1f, 100.0f);
glm::mat4 g_textProjection = glm::ortho(0.0f, static_cast<GLfloat>(WIDTH), 0.0f, static_cast<GLfloat>(HEIGHT));
mat4 g_view = glm::lookAt(glm::vec3(0, 2, -6), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
map<GLchar, t_char> Characters;
FT_Library g_ft;
FT_Face g_face;
GLuint g_textArrayID;
GLuint g_textBufferID;
GLuint g_textProgramID;

t_buffer_element g_vertex_buffer_obstical[] = {
        {{-1.0f, -1.0f, -1.0f}, {0.583f, 0.771f, 0.014f},  {}, {}},
        {{-1.0f, -1.0f, 1.0f},  {0.609f, 0.115f, 0.436f},  {}, {}},
        {{-1.0f, 1.0f,  1.0f},  {0.327f, 0.483f, 0.844f},  {}, {}}, // triangle 1 : end
        {{1.0f,  1.0f,  -1.0f}, {0.822f, 0.569f, 0.201f},  {}, {}}, // triangle 2 : begin
        {{-1.0f, -1.0f, -1.0f}, {0.435f, 0.602f, 0.223f},  {}, {}},
        {{-1.0f, 1.0f,  -1.0f}, {0.310f, 0.747f, 0.185f},  {}, {}}, // triangle 2 : end
        {{1.0f,  -1.0f, 1.0f},  {0.310f, 0.747f, 0.185f},  {}, {}},
        {{-1.0f, -1.0f, -1.0f}, {0.597f, 0.770f, 0.761f},  {}, {}},
        {{1.0f,  -1.0f, -1.0f}, {0.559f, 0.436f, 0.730f},  {}, {}},
        {{1.0f,  1.0f,  -1.0f}, {0.359f, 0.583f, 0.152f},  {}, {}},
        {{1.0f,  -1.0f, -1.0f}, {0.483f, 0.596f, 0.789f},  {}, {}},
        {{-1.0f, -1.0f, -1.0f}, {0.559f, 0.861f, 0.639f},  {}, {}},
        {{-1.0f, -1.0f, -1.0f}, {0.195f, 0.548f, 0.859f},  {}, {}},
        {{-1.0f, 1.0f,  1.0f},  {0.014f, 0.184f, 0.576f},  {}, {}},
        {{-1.0f, 1.0f,  -1.0f}, {0.771f, 0.328f, 0.970f},  {}, {}},
        {{1.0f,  -1.0f, 1.0f},  {0.406f, 0.615f, 0.116f},  {}, {}},
        {{-1.0f, -1.0f, 1.0f},  {0.676f, 0.977f, 0.133f},  {}, {}},
        {{-1.0f, -1.0f, -1.0f}, {0.971f, 0.572f, 0.833f},  {}, {}},
        {{-1.0f, 1.0f,  1.0f},  {0.140f, 0.616f, 0.489f},  {}, {}},
        {{-1.0f, -1.0f, 1.0f},  {0.997f, 0.513f, 0.064f},  {}, {}},
        {{1.0f,  -1.0f, 1.0f},  {0.945f, 0.719f, 0.592f},  {}, {}},
        {{1.0f,  1.0f,  1.0f},  {0.543f, 0.021f, 0.978f,}, {}, {}},
        {{1.0f,  -1.0f, -1.0f}, {0.279f, 0.317f, 0.505f,}, {}, {}},
        {{1.0f,  1.0f,  -1.0f}, {0.167f, 0.620f, 0.077f},  {}, {}},
        {{1.0f,  -1.0f, -1.0f}, {0.347f, 0.857f, 0.137f},  {}, {}},
        {{1.0f,  1.0f,  1.0f},  {0.055f, 0.953f, 0.042f},  {}, {}},
        {{1.0f,  -1.0f, 1.0f},  {0.714f, 0.505f, 0.345f},  {}, {}},
        {{1.0f,  1.0f,  1.0f},  {0.783f, 0.290f, 0.734f},  {}, {}},
        {{1.0f,  1.0f,  -1.0f}, {0.722f, 0.645f, 0.174f},  {}, {}},
        {{-1.0f, 1.0f,  -1.0f}, {0.302f, 0.455f, 0.848f},  {}, {}},
        {{1.0f,  1.0f,  1.0f},  {0.225f, 0.587f, 0.040f},  {}, {}},
        {{-1.0f, 1.0f,  -1.0f}, {0.517f, 0.713f, 0.338f},  {}, {}},
        {{-1.0f, 1.0f,  1.0f},  {0.053f, 0.959f, 0.120f},  {}, {}},
        {{1.0f,  1.0f,  1.0f},  {0.393f, 0.621f, 0.362f},  {}, {}},
        {{-1.0f, 1.0f,  1.0f},  {0.673f, 0.211f, 0.457f},  {}, {}},
        {{1.0f,  -1.0f, 1.0f},  {0.820f, 0.883f, 0.371f},  {}, {}}
};
t_buffer_element g_vertex_buffer_player[] = {
        {{-1.0f, -1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1, 1, 1}, {0, 0}},
        {{1.0f,  -1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1, 1, 1}, {0, 0}},
        {{0.0f,  1.0f,  0.0f}, {0.0f, 0.0f, 1.0f}, {1, 1, 1}, {0, 0}}
};
t_buffer_element g_vertex_buffer_surface[] = {
        {{3.0f,  0.0f, 3.0f},  {0.0f, 1.0f, 0.0f}, {1, 1, 1}, {0, 0}},
        {{-3.0f, 0.0f, -3.0f}, {0.0f, 1.0f, 0.0f}, {1, 1, 1}, {0, 0}},
        {{-3.0f, 0.0f, 3.0f},  {0.0f, 1.0f, 0.0f}, {1, 1, 1}, {0, 0}},
        {{3.0f,  0.0f, 3.0f},  {0.0f, 1.0f, 0.0f}, {1, 1, 1}, {0, 0}},
        {{3.0f,  0.0f, -3.0f}, {0.0f, 1.0f, 0.0f}, {1, 1, 1}, {0, 0}},
        {{-3.0f, 0.0f, -3.0f}, {0.0f, 1.0f, 0.0f}, {1, 1, 1}, {0, 0}},
};

bool init() {
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        getchar();
        return false;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    g_window = glfwCreateWindow(WIDTH, HEIGHT, "42run", NULL, NULL);
    if (g_window == NULL) {
        fprintf(stderr,
                "Failed to open GLFW g_window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
        getchar();
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(g_window);
    glViewport(0, 0, WIDTH, HEIGHT);
    glewExperimental = true; // Needed for core profile
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return false;
    }
    if (FT_Init_FreeType(&g_ft))
        std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
    if (FT_New_Face(g_ft, "fonts/arial.ttf", 0, &g_face))
        std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
    FT_Set_Pixel_Sizes(g_face, 0, 48);
    if (FT_Load_Char(g_face, 'X', FT_LOAD_RENDER))
        std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
    save_ascii();
    FT_Done_Face(g_face);
    FT_Done_FreeType(g_ft);
    glGenVertexArrays(1, &g_textArrayID);
    glGenBuffers(1, &g_textBufferID);
    glBindVertexArray(g_textArrayID);
    glBindBuffer(GL_ARRAY_BUFFER, g_textBufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    g_textProgramID = LoadShaders("textVertex.glsl", "textFragment.glsl");
    return (true);
}

GLuint bind_data(t_buffer_element *data, int size) {
    GLuint VertexArrayID;
    GLuint vertexbuffer;

    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(t_buffer_element), (void *) 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(t_buffer_element),
                          (void *) (offsetof(t_buffer_element, color)));
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    return VertexArrayID;
}

int main(void) {

    double lastTime;
    double deltaTime;
    GLuint obsticalArrayID;
    GLuint playerArrayID;
    GLuint surfaceArrayID;
    GLuint programID;
    GLint matrixID;
    vector<Obstical> incomming;
    vector<Flaw> flaw;


    if (!init())
        return (EXIT_FAILURE);
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    obsticalArrayID = bind_data(g_vertex_buffer_obstical, sizeof(g_vertex_buffer_obstical));
    playerArrayID = bind_data(g_vertex_buffer_player, sizeof(g_vertex_buffer_player));
    surfaceArrayID = bind_data(g_vertex_buffer_surface, sizeof(g_vertex_buffer_surface));
    myPlayer = new Player(playerArrayID, 3);
    for (int i = 0; i < 100; i += 3) {
        Flaw *nFlaw = new Flaw(surfaceArrayID, 6, i);
        flaw.push_back(*nFlaw);
    }
    cout << "size of flaw: " << flaw.size();

    programID = LoadShaders("vertex.glsl", "fragment.glsl");
    matrixID = glGetUniformLocation(programID, "MVP");
    glEnable(GL_DEPTH_TEST);
    glfwSetKeyCallback(g_window, player_key_callback);
    lastTime = glfwGetTime();
    deltaTime = 0.0f;
    //glDepthFunc(GL_LESS);
    do {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        RenderText(g_textProgramID, to_string(myPlayer->getDist()), 25.0f, 25.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));
        glUseProgram(programID);
        //glBindVertexArray(VertexArrayID);
        deltaTime += (glfwGetTime() - lastTime) * UPDATES_SECOND;
        lastTime = glfwGetTime();
        for (vector<Obstical>::iterator it = incomming.begin(); it != incomming.end(); it++)
            it->render(matrixID);
        for (vector<Flaw>::iterator it = flaw.begin(); it != flaw.end(); it++) {
            it->render(matrixID);
        }
        myPlayer->render(matrixID);
        while (deltaTime >= 1.0f) {
            if (incomming.size() < 5) {
                Obstical *neowObsical = new Obstical(obsticalArrayID, (3 * 12));
                incomming.push_back(*neowObsical);
            }
            myPlayer->update();
            for (vector<Flaw>::iterator it = flaw.begin(); it != flaw.end(); it++) {
                it->update();
                if (!it->getActive()) {
                    flaw.erase(it);
                    flaw.push_back(*(new Flaw(surfaceArrayID, 7, 100)));
                }
            }
            for (vector<Obstical>::iterator it = incomming.begin(); it != incomming.end(); it++) {
                it->update();
                if (sqrt(pow(it->getX() - myPlayer->getX(), 2) + pow(it->getY() - myPlayer->getY(), 2) +
                         pow(it->getZ() - myPlayer->getZ(), 2)) < 2) {
                    cout << "you hit an object at a distence of: " << myPlayer->getDist() << endl;
                    glfwSetWindowShouldClose(g_window, GL_TRUE);
                    break;
                }
                if (!it->getActive())
                    incomming.erase(it);
            }
            if (myPlayer->getDist() % 100 == 0)
                UPDATES_SECOND += 1;
            deltaTime--;
        }
        glfwSwapBuffers(g_window);
        glfwPollEvents();
    } while (glfwWindowShouldClose(g_window) == 0);
    glDeleteVertexArrays(1, &obsticalArrayID);
    glDeleteVertexArrays(1, &playerArrayID);
    glDeleteProgram(programID);
    glfwTerminate();
    return 0;
}

void player_key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
        myPlayer->moveLeft();
    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
        myPlayer->moveRight();
    if (key == GLFW_KEY_UP && action == GLFW_PRESS)
        myPlayer->jump();
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

void save_ascii() {
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // Disable byte-alignment restriction

    for (GLubyte c = 0; c < 128; c++) {
        // Load character glyph
        if (FT_Load_Char(g_face, c, FT_LOAD_RENDER)) {
            std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
            continue;
        }
        // Generate texture
        GLuint texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(
                GL_TEXTURE_2D,
                0,
                GL_RED,
                g_face->glyph->bitmap.width,
                g_face->glyph->bitmap.rows,
                0,
                GL_RED,
                GL_UNSIGNED_BYTE,
                g_face->glyph->bitmap.buffer
        );
        // Set texture options
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // Now store character for later use
        t_char character = {
                texture,
                glm::ivec2(g_face->glyph->bitmap.width, g_face->glyph->bitmap.rows),
                glm::ivec2(g_face->glyph->bitmap_left, g_face->glyph->bitmap_top),
                (GLuint) g_face->glyph->advance.x
        };
        Characters.insert(std::pair<GLchar, t_char>(c, character));
    }
}

void RenderText(GLuint programID, std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color) {
    // Activate corresponding render state

    glUseProgram(programID);
    glUniformMatrix4fv(glGetUniformLocation(programID, "Pro"), 1, GL_FALSE, &g_textProjection[0][0]);
    glUniform3f(glGetUniformLocation(programID, "textColor"), color.x, color.y, color.z);
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(g_textArrayID);

    // Iterate through all characters
    std::string::const_iterator c;
    for (c = text.begin(); c != text.end(); c++) {
        t_char ch = Characters[*c];

        GLfloat xpos = x + ch.Bearing.x * scale;
        GLfloat ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

        GLfloat w = ch.Size.x * scale;
        GLfloat h = ch.Size.y * scale;
        // Update VBO for each character
        GLfloat vertices[6][4] = {
                {xpos,     ypos + h, 0.0, 0.0},
                {xpos,     ypos,     0.0, 1.0},
                {xpos + w, ypos,     1.0, 1.0},

                {xpos,     ypos + h, 0.0, 0.0},
                {xpos + w, ypos,     1.0, 1.0},
                {xpos + w, ypos + h, 1.0, 0.0}
        };
        // Render glyph texture over quad
        glBindTexture(GL_TEXTURE_2D, ch.TextureID);
        // Update content of VBO memory
        glBindBuffer(GL_ARRAY_BUFFER, g_textBufferID);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices),
                        vertices); // Be sure to use glBufferSubData and not glBufferData

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        // Render quad
        glDrawArrays(GL_TRIANGLES, 0, 6);
        // Now advance cursors for next glyph (note that advance is number of 1/64 pixels)
        x += (ch.Advance >> 6) *
             scale; // Bitshift by 6 to get value in pixels (2^6 = 64 (divide amount of 1/64th pixels by 64 to get amount of pixels))
    }
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}