#pragma once

#include <third_parties/glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <iostream>
#include <string>

#include "sprite.h"
#include "sound.h"
#include "texture_loader.h"
#include "animations/animation_manager.h"
#include "keys.h"

class Game{

    // Initializers --------------------------------
    static void InitGLFW();
    static void CreateGLFWWindow();
    static void InitGLAD();
    static void OpenGLSetup();
    static void InitCards();
    // Window Settings  ----------------------------
    static const unsigned int SCR_WIDTH = 900;
    static const unsigned int SCR_HEIGHT = 675;

    static void ProcessKeyInput();
    static Key ENTER, ESCAPE, F, E;
    // FPS  ----------------------------------------
    static void OutputFPS();
    static float time;
    static int fps;
    static float previous_time;
    // Game Functions   ----------------------------
    static int CompareColour(std::string player_1_colour, std::string player_2_colour);
public:
    static std::vector<Sprite> cards;
    static std::vector<Sprite> player_1_cards, player_2_cards;

    static GLFWwindow* window;
    static float delta_time;

    // Game Functions   ----------------------------
    static int Compare(Sprite player_1, Sprite player_2);

    static void Init();
    static void RenderLoop();
};