#include <structs.h>
#include <support.h>
#include <shader.h>
#include <player.h>
#include <room.h>
#include <obstical.h>


GLFWwindow *g_window;
FT_Library g_ft;
FT_Face g_face;
GLuint g_textArrayID;
GLuint g_textBufferID;
Shader *g_textShader;
GLfloat deltaTime = 0.0f;
GLfloat lastTime = 0.0f;
Player *myPlayer;
map<GLchar, t_char> g_characters;
glm::mat4 g_textProjection = glm::ortho(0.0f, static_cast<GLfloat>(WIDTH), 0.0f, static_cast<GLfloat>(HEIGHT));
vector<Room> rooms;
vector<t_light> lights;
vector<Obstical> obsticals;
bool gameActive = true;
int updates_sec = 60;

void passLights(Shader shader, vector<t_light> lights, glm::vec3 viewPos) {
    int i = 0;
    for (vector<t_light>::iterator light = lights.begin(); light < lights.end(); light++) {
        string temp = "pointLights[";
        temp += to_string(i) += "].ambient";
        glUniform3f(glGetUniformLocation(shader.getProgram(), temp.c_str()), light->ambient.x, light->ambient.y,
                    light->ambient.z);
        temp = "pointLights[";
        temp += to_string(i) += "].diffuse";
        glUniform3f(glGetUniformLocation(shader.getProgram(), temp.c_str()), light->diffuse.x, light->diffuse.y,
                    light->diffuse.z);
        temp = "pointLights[";
        temp += to_string(i) += "].specular";
        glUniform3f(glGetUniformLocation(shader.getProgram(), temp.c_str()), light->specular.x, light->specular.y,
                    light->specular.z);
        temp = "pointLights[";
        temp += to_string(i) += "].position";
        glUniform3f(glGetUniformLocation(shader.getProgram(), temp.c_str()), light->position.x, light->position.y,
                    light->position.z);
        temp = "pointLights[";
        temp += to_string(i) += "].constant";
        glUniform1f(glGetUniformLocation(shader.getProgram(), temp.c_str()), light->constant);
        temp = "pointLights[";
        temp += to_string(i) += "].linear";
        glUniform1f(glGetUniformLocation(shader.getProgram(), temp.c_str()), light->linear);
        temp = "pointLights[";
        temp += to_string(i) += "].quadratic";
        glUniform1f(glGetUniformLocation(shader.getProgram(), temp.c_str()), light->quadratic);
        i++;
    }
    glUniform3f(glGetUniformLocation(shader.getProgram(), "viewPos"), viewPos.x, viewPos.y, viewPos.z);
    glUniform1i(glGetUniformLocation(shader.getProgram(), "NumLights"), i);
}

bool gameLoop(vector<t_light> *lights, vector<Room> *rooms, vector<Obstical> *obsticals) {
    myPlayer->update();
    glm::vec3 playerpos = myPlayer->getLocation();
    for (vector<t_light>::iterator light = lights->begin(); light < lights->end(); light++)
        light->position.z = (light->position.z - 0.25 > -24) ? (GLfloat) (light->position.z - 0.25) : 96;
    for (vector<Room>::iterator it = rooms->begin(); it < rooms->end(); ++it) {
        it->update();
        if (!it->active) {
            rooms->erase(it);
            rooms->push_back(
                    Room((GLchar *) "../Models/room/room.obj", glm::vec3(0, 0, rooms->end()->getLocation().z + 6)));
        }
    }
    for (vector<Obstical>::iterator it = obsticals->begin(); it < obsticals->end(); it++) {
        it->update();
        if (sqrt(pow((playerpos.x - it->getLocation().x), 2) + pow((playerpos.y - it->getLocation().y), 2) +
                 pow((playerpos.z - it->getLocation().z), 2)) < 2) {
            cout << "object hit at " << myPlayer->getDist() << endl;
            return (false);
        }
        if (!it->active) {
            obsticals->erase(it);
            obsticals->push_back(
                    Obstical((GLchar *) "../Models/obstical/block.obj", glm::vec3((rand() % 5 - 2), -3, 120)));
        }

    }

    return (true);
}

void start() {
    rooms.clear();
    obsticals.clear();
    lights.clear();
    for (int i = 0; i < 120; i += 6) {
        if (rand() % 2 && i > 6)
            obsticals.push_back(
                    Obstical((GLchar *) "../Models/obstical/block.obj", glm::vec3((rand() % 5 - 2), -3, i)));
        if (rand() % 2)
            lights.push_back(
                    {glm::vec3((rand() % 5 - 2), 4, i), glm::vec3(1, 1, 0.8), glm::vec3(1, 1, 0.8),
                     glm::vec3(0.8, 0.8, 0.8), 1.0f, 0.2,
                     0.032});
        rooms.push_back(Room((GLchar *) "../Models/room/room.obj", glm::vec3(0, 0, i)));
    }
}

int main() {
    glm::vec3 viewPos = {0, 1, -6};
    oglInit();


    glm::mat4 projection = glm::perspective(glm::radians(60.0f), (float) WIDTH / (float) HEIGHT, 0.1f, 500.0f);
    glm::mat4 view = glm::lookAt(viewPos, glm::vec3(0, -1, 0), glm::vec3(0, 1, 0));
    Shader shader("Shaders/vertex.glsl", "Shaders/fragment.glsl");
    myPlayer = new Player((GLchar *) "../Models/nanosuit/nanosuit.obj");
    start();

    while (!glfwWindowShouldClose(g_window)) {
        //  GLfloat currentFrame = glfwGetTime();
        //  deltaTime = currentFrame - lastFrame;
        //  lastFrame = currentFrame;


        deltaTime += (glfwGetTime() - lastTime) * updates_sec;
        lastTime = glfwGetTime();
        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader.useShader();
        passLights(shader, lights, viewPos);
        myPlayer->Draw(shader, projection, view);
        for (vector<Room>::iterator it = rooms.begin(); it < rooms.end(); it++)
            it->Draw(shader, projection, view);
        for (vector<Obstical>::iterator it = obsticals.begin(); it < obsticals.end(); it++)
            it->Draw(shader, projection, view);
        g_textShader->useShader();
        RenderText(to_string(myPlayer->getDist()), 25.0f, 25.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));
        while (deltaTime >= 1.0f) {
            if (gameActive) {
                gameActive = gameLoop(&lights, &rooms, &obsticals);
                if (myPlayer->getDist() % 100 == 0 && updates_sec < 100)
                    updates_sec += 1;
            } else {
                g_textShader->useShader();
                RenderText("GAME OVER", (float(WIDTH) / 2.0f) - 225, float(HEIGHT) / 2.0f, 1.5f,
                           glm::vec3(1, 0.0f, 0.0f));
            }

            deltaTime--;
        }

        glfwPollEvents();
        glfwSwapBuffers(g_window);
    }

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
    if (key == GLFW_KEY_R && action == GLFW_PRESS) {
        start();
        myPlayer->reset();
        gameActive = true;
        updates_sec = 60;
    }
}