// Include standard headers
#include <42run.h>

using namespace glm;
using namespace std;
Player *myPlayer;
int UPDATES_SECOND = 60;
GLFWwindow *g_window;
mat4 g_projection = glm::perspective(glm::radians(60.0f), (float) WIDTH / (float) HEIGHT, 0.1f, 500.0f);
glm::mat4 g_textProjection = glm::ortho(0.0f, static_cast<GLfloat>(WIDTH), 0.0f, static_cast<GLfloat>(HEIGHT));
mat4 g_view = glm::lookAt(glm::vec3(0, 2, -6), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
map<GLchar, t_char> Characters;
FT_Library g_ft;
FT_Face g_face;
GLuint g_textArrayID;
GLuint g_textBufferID;
GLuint g_textProgramID;

t_buffer_element g_vertex_buffer_obstical[] = {
        {{-1.0f, -1.0f, -1.0f}, {-1.0f, 0.0f,  0.0f},  {1, 1, 1}, {}},
        {{-1.0f, -1.0f, 1.0f},  {-1.0f, 0.0f,  0.0f},  {1, 1, 1}, {}},
        {{-1.0f, 1.0f,  1.0f},  {-1.0f, 0.0f,  0.0f},  {1, 1, 1}, {}},
        {{1.0f,  1.0f,  -1.0f}, {0.0f,  0.0f,  -1.0f}, {1, 1, 1}, {}},
        {{-1.0f, -1.0f, -1.0f}, {0.0f,  0.0f,  -1.0f}, {1, 1, 1}, {}},
        {{-1.0f, 1.0f,  -1.0f}, {0.0f,  0.0f,  -1.0f}, {1, 1, 1}, {}},
        {{1.0f,  -1.0f, 1.0f},  {0.0f,  -1.0f, 0.0f},  {1, 1, 1}, {}},
        {{-1.0f, -1.0f, -1.0f}, {0.0f,  -1.0f, 0.0f},  {1, 1, 1}, {}},
        {{1.0f,  -1.0f, -1.0f}, {0.0f,  -1.0f, 0.0f},  {1, 1, 1}, {}},
        {{1.0f,  1.0f,  -1.0f}, {0.0f,  0.0f,  -1.0f}, {1, 1, 1}, {}},
        {{1.0f,  -1.0f, -1.0f}, {0.0f,  0.0f,  -1.0f}, {1, 1, 1}, {}},
        {{-1.0f, -1.0f, -1.0f}, {0.0f,  0.0f,  -1.0f}, {1, 1, 1}, {}},
        {{-1.0f, -1.0f, -1.0f}, {-1.0f, 0.0f,  0.0f},  {1, 1, 1}, {}},
        {{-1.0f, 1.0f,  1.0f},  {-1.0f, 0.0f,  0.0f},  {1, 1, 1}, {}},
        {{-1.0f, 1.0f,  -1.0f}, {-1.0f, 0.0f,  0.0f},  {1, 1, 1}, {}},
        {{1.0f,  -1.0f, 1.0f},  {0.0f,  -1.0f, 0.0f},  {1, 1, 1}, {}},
        {{-1.0f, -1.0f, 1.0f},  {0.0f,  -1.0f, 0.0f},  {1, 1, 1}, {}},
        {{-1.0f, -1.0f, -1.0f}, {0.0f,  -1.0f, 0.0f},  {1, 1, 1}, {}},
        {{-1.0f, 1.0f,  1.0f},  {0.0f,  0.0f,  1.0f},  {1, 1, 1}, {}},
        {{-1.0f, -1.0f, 1.0f},  {0.0f,  0.0f,  1.0f},  {1, 1, 1}, {}},
        {{1.0f,  -1.0f, 1.0f},  {0.0f,  0.0f,  1.0f},  {1, 1, 1}, {}},
        {{1.0f,  1.0f,  1.0f},  {1.0f,  0.0f,  0.0f},  {1, 1, 1}, {}},
        {{1.0f,  -1.0f, -1.0f}, {1.0f,  0.0f,  0.0f},  {1, 1, 1}, {}},
        {{1.0f,  1.0f,  -1.0f}, {1.0f,  0.0f,  0.0f},  {1, 1, 1}, {}},
        {{1.0f,  -1.0f, -1.0f}, {1.0f,  0.0f,  0.0f},  {1, 1, 1}, {}},
        {{1.0f,  1.0f,  1.0f},  {1.0f,  0.0f,  0.0f},  {1, 1, 1}, {}},
        {{1.0f,  -1.0f, 1.0f},  {1.0f,  0.0f,  0.0f},  {1, 1, 1}, {}},
        {{1.0f,  1.0f,  1.0f},  {0.0f,  1.0f,  0.0f},  {1, 1, 1}, {}},
        {{1.0f,  1.0f,  -1.0f}, {0.0f,  1.0f,  0.0f},  {1, 1, 1}, {}},
        {{-1.0f, 1.0f,  -1.0f}, {0.0f,  1.0f,  0.0f},  {1, 1, 1}, {}},
        {{1.0f,  1.0f,  1.0f},  {0.0f,  1.0f,  0.0f},  {1, 1, 1}, {}},
        {{-1.0f, 1.0f,  -1.0f}, {0.0f,  1.0f,  0.0f},  {1, 1, 1}, {}},
        {{-1.0f, 1.0f,  1.0f},  {0.0f,  1.0f,  0.0f},  {1, 1, 1}, {}},
        {{1.0f,  1.0f,  1.0f},  {0.0f,  0.0f,  1.0f},  {1, 1, 1}, {}},
        {{-1.0f, 1.0f,  1.0f},  {0.0f,  0.0f,  1.0f},  {1, 1, 1}, {}},
        {{1.0f,  -1.0f, 1.0f},  {0.0f,  0.0f,  1.0f},  {1, 1, 1}, {}}
};
t_buffer_element g_vertex_buffer_player[] = {
        {{-1.0f, -1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {1, 0, 0}, {0, 0}},
        {{1.0f,  -1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0, 1, 0}, {0, 0}},
        {{0.0f,  1.0f,  0.0f}, {0.0f, 0.0f, 1.0f}, {0, 0, 1}, {0, 0}}
};
t_buffer_element g_vertex_buffer_surface[] = {
        {{3.0f,  0.0f, 3.0f},  {0.0f, 1.0f, 0.0f}, {1, 1, 1}, {0.99, 0.01}},
        {{-3.0f, 0.0f, -3.0f}, {0.0f, 1.0f, 0.0f}, {1, 1, 1}, {0.01, 0.99}},
        {{-3.0f, 0.0f, 3.0f},  {0.0f, 1.0f, 0.0f}, {1, 1, 1}, {0.01, 0.01}},
        {{3.0f,  0.0f, 3.0f},  {0.0f, 1.0f, 0.0f}, {1, 1, 1}, {0.99, 0.01}},
        {{3.0f,  0.0f, -3.0f}, {0.0f, 1.0f, 0.0f}, {1, 1, 1}, {0.99, 0.99}},
        {{-3.0f, 0.0f, -3.0f}, {0.0f, 1.0f, 0.0f}, {1, 1, 1}, {0.01, 0.99}},
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
                "Failed to open GLFW g_window.\n");
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
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(t_buffer_element),
                          (void *) (offsetof(t_buffer_element, text)));
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(t_buffer_element),
                          (void *) (offsetof(t_buffer_element, normal)));
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
    GLuint texturID;
    GLuint wallTextureID;
    vector<t_light> lights;
    vector<Obstical> incomming;
    GLuint textureIDs[4];
    //vector<Flaw> flaw;
    vector<Room> rooms;


    if (!init())
        return (EXIT_FAILURE);

    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    obsticalArrayID = bind_data(g_vertex_buffer_obstical, sizeof(g_vertex_buffer_obstical));
    playerArrayID = bind_data(g_vertex_buffer_player, sizeof(g_vertex_buffer_player));
    surfaceArrayID = bind_data(g_vertex_buffer_surface, sizeof(g_vertex_buffer_surface));
    textureIDs[0] = load_texture("parkay.jpeg");
    textureIDs[1] = load_texture("celing.jpeg");
    textureIDs[2] = load_texture("Red-brick-wall-window.jpg");
    textureIDs[3] = load_texture("Red-brick-wall-window.jpg");
    myPlayer = new Player(playerArrayID, 3);
    for (int i = 0; i <= 120; i += 6) {
        rooms.push_back(Room(i,surfaceArrayID,textureIDs));
        /*Flaw *nFlaw = new Flaw(surfaceArrayID, 6, i);
        flaw.push_back(*nFlaw);*/
        if (rand() % 2)
            lights.push_back({vec3((rand() % 3 - 2),4,i), vec3(1, 1, 0.8), vec3(1,1,0.8), vec3(0.8,0.8,0.8), 1.0f, 0.2, 0.032});
    }
    programID = LoadShaders("vertex.glsl", "fragment.glsl");
    texturID = load_texture("parkay.jpeg");
    wallTextureID = load_texture("Red-brick-wall-window.jpg");
    glEnable(GL_DEPTH_TEST);
    glfwSetKeyCallback(g_window, player_key_callback);
    lastTime = glfwGetTime();
    deltaTime = 0.0f;
    do {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        RenderText(g_textProgramID, to_string(myPlayer->getDist()), 25.0f, 25.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));
        deltaTime += (glfwGetTime() - lastTime) * UPDATES_SECOND;
        lastTime = glfwGetTime();
        for (vector<Obstical>::iterator it = incomming.begin(); it < incomming.end(); it++)
            it->render(programID, -1, lights, vec3(0, 2, -6), false);
        for (vector<Room>::iterator it = rooms.begin(); it < rooms.end(); it++)
            it->render(lights, programID, vec3(0, 2, -6));
        /*for (vector<Flaw>::iterator it = flaw.begin(); it < flaw.end(); it++)
            it->render(programID, wallTextureID, lights, vec3(0, 2, -6), true);*/
        myPlayer->render(programID, -1, lights, vec3(0, 2, -6), false);
        while (deltaTime >= 1.0f) {
            if (incomming.size() < 5) {
                Obstical *neowObsical = new Obstical(obsticalArrayID, (3 * 12));
                incomming.push_back(*neowObsical);
            }
            myPlayer->update();
      /*      for (vector<Flaw>::iterator it = flaw.begin(); it < flaw.end(); it++) {
                it->update();
                if (!it->getActive()) {
                    flaw.erase(it);
                    flaw.push_back(*(new Flaw(surfaceArrayID, 7, flaw.end()->getZ()+ 6)));
                }
            }*/
            for (vector<Room>::iterator room = rooms.begin();  room < rooms.end(); ++room) {
                if (!(room->update())) {
                    rooms.erase(room);
                    rooms.push_back(Room(rooms.end()->getZ() + 6,surfaceArrayID,textureIDs));
                }
            }
            for (vector<t_light>::iterator light = lights.begin(); light < lights.end(); light++)
                light->position.z = (light->position.z - 0.25 > -24) ? (GLfloat)(light->position.z - 0.25) : 96;
            for (vector<Obstical>::iterator it = incomming.begin(); it < incomming.end(); it++) {
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

GLuint load_texture(string file) {
    int width;
    int height;

    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    unsigned char *image = SOIL_load_image(file.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);
    return (texture);
}