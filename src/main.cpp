// Include standard headers
#include <42run.h>
using namespace glm;
using namespace std;
GLFWwindow *g_window;
glm::mat4 g_projection = glm::perspective(glm::radians(60.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
glm::mat4 g_view = glm::lookAt(glm::vec3(0,2,-6), glm::vec3(0,0,0), glm::vec3(0,1,0));
int main( void )
{
    // Initialise GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        getchar();
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    g_window = glfwCreateWindow( WIDTH, HEIGHT, "Tutorial 02 - Red triangle", NULL, NULL);
    if( g_window == NULL ){
        fprintf( stderr, "Failed to open GLFW g_window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
        getchar();
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(g_window);

    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return false;
    }

    glfwSetKeyCallback(g_window, key_callback);
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    GLuint programID = LoadShaders( "vertex.glsl", "fragment.glsl" );

    t_buffer_element g_vertex_buffer_data[] = {
            {{-1.0f,-1.0f,-1.0f},{0.583f,  0.771f,  0.014f},{}},
            {{-1.0f,-1.0f, 1.0f},{0.609f,  0.115f,  0.436f},{}},
            {{-1.0f, 1.0f, 1.0f},{0.327f,  0.483f,  0.844f},{}}, // triangle 1 : end
            {{1.0f, 1.0f,-1.0f},{0.822f,  0.569f,  0.201f},{}}, // triangle 2 : begin
            {{-1.0f,-1.0f,-1.0f},{0.435f,  0.602f,  0.223f},{}},
            {{-1.0f, 1.0f,-1.0f},{0.310f,  0.747f,  0.185f},{}}, // triangle 2 : end
            {{1.0f,-1.0f, 1.0f},{0.310f,  0.747f,  0.185f},{}},
            {{-1.0f,-1.0f,-1.0f},{0.597f,  0.770f,  0.761f},{}},
            {{1.0f,-1.0f,-1.0f},{0.559f,  0.436f,  0.730f},{}},
            {{1.0f, 1.0f,-1.0f},{0.359f,  0.583f,  0.152f},{}},
            {{1.0f,-1.0f,-1.0f},{0.483f,  0.596f,  0.789f},{}},
            {{-1.0f,-1.0f,-1.0f},{0.559f,  0.861f,  0.639f},{}},
            {{-1.0f,-1.0f,-1.0f},{0.195f,  0.548f,  0.859f},{}},
            {{-1.0f, 1.0f, 1.0f},{0.014f,  0.184f,  0.576f},{}},
            {{-1.0f, 1.0f,-1.0f},{0.771f,  0.328f,  0.970f},{}},
            {{1.0f,-1.0f, 1.0f},{0.406f,  0.615f,  0.116f},{}},
            {{-1.0f,-1.0f, 1.0f},{0.676f,  0.977f,  0.133f},{}},
            {{-1.0f,-1.0f,-1.0f},{0.971f,  0.572f,  0.833f},{}},
            {{-1.0f, 1.0f, 1.0f},{0.140f,  0.616f,  0.489f},{}},
            {{-1.0f,-1.0f, 1.0f},{0.997f,  0.513f,  0.064f},{}},
            {{1.0f,-1.0f, 1.0f},{0.945f,  0.719f,  0.592f},{}},
            {{1.0f, 1.0f, 1.0f},{0.543f,  0.021f,  0.978f,},{}},
            {{1.0f,-1.0f,-1.0f},{0.279f,  0.317f,  0.505f,},{}},
            {{1.0f, 1.0f,-1.0f},{0.167f,  0.620f,  0.077f},{}},
            {{1.0f,-1.0f,-1.0f},{0.347f,  0.857f,  0.137f},{}},
            {{1.0f, 1.0f, 1.0f},{0.055f,  0.953f,  0.042f},{}},
            {{1.0f,-1.0f, 1.0f},{0.714f,  0.505f,  0.345f},{}},
            {{1.0f, 1.0f, 1.0f},{0.783f,  0.290f,  0.734f},{}},
            {{1.0f, 1.0f,-1.0f},{0.722f,  0.645f,  0.174f},{}},
            {{-1.0f, 1.0f,-1.0f},{0.302f,  0.455f,  0.848f},{}},
            {{1.0f, 1.0f, 1.0f},{0.225f,  0.587f,  0.040f},{}},
            {{-1.0f, 1.0f,-1.0f},{0.517f,  0.713f,  0.338f},{}},
            {{-1.0f, 1.0f, 1.0f},{0.053f,  0.959f,  0.120f},{}},
            {{1.0f, 1.0f, 1.0f},{0.393f,  0.621f,  0.362f},{}},
            {{-1.0f, 1.0f, 1.0f},{0.673f,  0.211f,  0.457f},{}},
            {{1.0f,-1.0f, 1.0f},{0.820f,  0.883f,  0.371f},{}}
    };
    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
    GLint matrixID = glGetUniformLocation(programID, "MVP");
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glEnable(GL_DEPTH_TEST);
    Player myPlayer;
    Obstical incomming;
    //glDepthFunc(GL_LESS);
    do{

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(programID);
        incomming.render(matrixID);
        myPlayer.render(matrixID);
        myPlayer.update();
        incomming.update();
        glfwSwapBuffers(g_window);
        glfwPollEvents();
    }
    while(glfwWindowShouldClose(g_window) == 0);
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteVertexArrays(1, &VertexArrayID);
    glDeleteProgram(programID);
    glfwTerminate();
    return 0;
}


