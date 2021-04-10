#include "game.h"

int main(){
    Game::Init();

    Game::RenderLoop();

    glfwTerminate();
    return 0;
}