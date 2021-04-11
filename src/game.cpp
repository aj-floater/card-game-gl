#include "game.h"

// Variables    ------------------------------------------------------------------------------------

Key Game::ENTER, Game::ESCAPE, Game::F, Game::E;

std::vector<Sprite> Game::cards;
std::vector<Sprite> Game::player_1_cards, Game::player_2_cards;

GLFWwindow* Game::window;
float Game::time, Game::delta_time, Game::previous_time; 
int Game::fps;

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
    E.create(GLFW_KEY_E);
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

        delta_time = glfwGetTime() - previous_time;
        previous_time = glfwGetTime();

        AnimationManager::Update();
        
        for (Sprite &card : cards){
            card.Update();
        }

        for (Sprite &card : player_1_cards){
            card.Update();
        }

        for (Sprite &card : player_2_cards){
            card.Update();
        }

        // OutputFPS();
 
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

// Window Settings  ----------------------------------------------------------------------------

void Game::ProcessKeyInput(){
    if (ESCAPE.keyPressRelease(window)){
        glfwSetWindowShouldClose(window, true);
    }
    if (ENTER.keyPressRelease(window)){
        AnimationManager::StartShuffleAnimation();
    }
    if (E.keyPressRelease(window)){
        AnimationManager::StartMoveAnimation();
    }
    if (F.keyPressRelease(window)){
        for (Sprite &c : Game::cards){
            c.flipped = (c.flipped) ? false : true;
        }
    }
}

// FPS  ----------------------------------------------------------------------------------------

void Game::OutputFPS(){
    if (time <= 1){
        time += delta_time;
        fps += 1;
    }
    else {
        cout << fps << endl;
        time = 0;
        fps = 0;
    }
}

// Game Functions   ----------------------------------------------------------------------------

int Game::Compare(Sprite player_1, Sprite player_2){
    int who_wins = CompareColour(player_1.colour, player_2.colour);
    if (who_wins == 0)
        who_wins = (player_1.number > player_2.number) ? 1 : 2;
    return who_wins;
}

int Game::CompareColour(std::string player_1_colour, std::string player_2_colour){
    // Red + Black = Red
    if (player_1_colour == "R" && player_2_colour == "B")
        return 1;
    if (player_2_colour == "R" && player_1_colour == "B")
        return 2;
    // Yellow + Red = Yellow
    if (player_1_colour == "Y" && player_2_colour == "R")
        return 1;
    if (player_2_colour == "Y" && player_1_colour == "R")
        return 2;
    // Black + Yellow = Black
    if (player_1_colour == "B" && player_2_colour == "Y")
        return 1;
    if (player_2_colour == "B" && player_1_colour == "Y")
        return 2;
    else return 0;
}