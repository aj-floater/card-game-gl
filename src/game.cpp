#include "game.h"

// Initializers ------------------------------------------------------------------------------------

void Game::Init(){
    InitGLFW();
    CreateGLFWWindow();
    InitGLAD();
    OpenGLSetup();
    srand( ( unsigned int )std::time( nullptr ) ); // generates random seed

    SoundManager::Init();
    InitCards();
    TextureLoader::Init();

    ENTER.create(GLFW_KEY_ENTER);
    ESCAPE.create(GLFW_KEY_ESCAPE);
    F.create(GLFW_KEY_F);
}

// glfw: initialize glfw
void Game::InitGLFW(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// glfw: create window
void Game::CreateGLFWWindow(){
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Card Game", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

// glad: initialize glad
void Game::InitGLAD(){
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
}

// opengl: setup
void Game::OpenGLSetup(){
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

// cards: initialize card vector

void Game::InitCards(){
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

        cards.push_back(card);
    }
}

// Render Loop  --------------------------------------------------------------------------------

void Game::RenderLoop(){
    while (!glfwWindowShouldClose(window))
    {
        // input
        ProcessKeyInput();

        // render
        glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        Sprite::delta_time = glfwGetTime() - Sprite::previous_time;
        Sprite::previous_time = glfwGetTime();

        AnimationManager::Update();

        // card1.Update();
        
        for (Sprite &card : cards){
            card.Update();
        }
 
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

// Other Functions  ----------------------------------------------------------------------------

void Game::ProcessKeyInput(){
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