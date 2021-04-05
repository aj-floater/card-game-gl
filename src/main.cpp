#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <irrKlang/irrKlang.h>

#include "sprite.h"
#include "structures.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 900;
const unsigned int SCR_HEIGHT = 675;

using namespace std;
using namespace irrklang;

float posX = 0;
float posY = 0;

ISoundEngine* engine = createIrrKlangDevice();

vector<Sprite> cards;

float RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

bool isNear(float a, float b, float threshold){
    if (a + threshold > b && a - threshold < b){
        return true;
    } else return false;
}

int RandomNegative(){
    int num = 0;
    while (num == 0) {
        num = rand() % 3 - 1;
    }
    return num;
}

void playFlip();

int main()
{
    // glfw: initialize and configure --------------------------------------------------------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Card Game", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // build and compile our shader program

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    srand( ( unsigned int )std::time( nullptr ) );

    for (int i = 0; i < 30; i++){
        Sprite card("shaders/vertex_triangle.glsl", "shaders/fragment_triangle.glsl", "images/card2.png", "card");
        card.changeSize(Size(0.25, 0.5));
        card.position = Position(RandomFloat(-1, 1), RandomFloat(-1, 1));
        cards.push_back(card);
    }

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);

        // render
        glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        Sprite::delta_time = glfwGetTime() - Sprite::previous_time;
        Sprite::previous_time = glfwGetTime();
        
        for (Sprite &card : cards){
            card.update();
        }
 
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
    return 0;
}

struct Key{
    bool keypressed;
    bool keyPressRelease(u_int32_t key, GLFWwindow *window){
        if (glfwGetKey(window, key) == GLFW_PRESS)
            keypressed = true;
        if (glfwGetKey(window, key) == GLFW_RELEASE && keypressed){
            keypressed = false;
            return true;
        }
        else return false;
    }
};

Key ENTER, ESCAPE;

void playFlip(){
    int num = rand() % 8 + 1;
    string filename = "audio/FLIP/" + to_string(num) + ".wav";
    engine->play2D(filename.c_str(), false);
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow *window)
{
    if (ESCAPE.keyPressRelease(GLFW_KEY_ESCAPE, window)){
        glfwSetWindowShouldClose(window, true);
    }
    if (ENTER.keyPressRelease(GLFW_KEY_ENTER, window)){
        for(Sprite &card : cards){
            card.animate(Position(-0.75, 0.6), 0.5);
        }
    }
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}