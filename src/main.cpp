#include <third_parties/glad/glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "sprite.h"
#include "structures.h"
#include "animations/animation_manager.h"
#include "texture_loader.h"
#include "game.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 900;
const unsigned int SCR_HEIGHT = 675;

using namespace std;

float posX = 0;
float posY = 0;

bool shuffling = false;
int shufflepos = 0;
int j = 0;

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

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    srand( ( unsigned int )std::time( nullptr ) );

    SoundManager::Init();

    for (int i = 0; i < 30; i++){
        Sprite card("./shaders/vertex_triangle.glsl", "./shaders/fragment_triangle.glsl");
        card.ChangeSize(Size(0.25, 0.5));
        card.position = Position(RandomFloat(-1, 1), RandomFloat(-1, 1));

        int colour_num = (i - i % 10) / 10;
        if (colour_num == 0) card.colour = "R";
        if (colour_num == 1) card.colour = "Y";
        if (colour_num == 2) card.colour = "B";
        card.number = i % 10;

        card.flipped = false;

        AnimationManager::cards.push_back(card);
    }

    TextureLoader::Init();

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

        AnimationManager::Update();

        // card1.Update();
        
        for (Sprite &card : AnimationManager::cards){
            card.Update();
        }
 
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
    return 0;
}

Key ENTER(GLFW_KEY_ENTER), ESCAPE(GLFW_KEY_ESCAPE), F(GLFW_KEY_F);

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow *window)
{
    if (ESCAPE.keyPressRelease(window)){
        glfwSetWindowShouldClose(window, true);
    }
    if (ENTER.keyPressRelease(window)){
        AnimationManager::StartShuffleAnimation(true);
    }
    if (F.keyPressRelease(window)){
        for (Sprite &c : AnimationManager::cards){
            c.flipped = (c.flipped) ? false : true;
        }
    }
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}