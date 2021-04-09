#pragma once

#include <GLFW/glfw3.h>
#include <third_parties/glad/glad.h>

#include <vector>

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
    Key ENTER, ESCAPE, F;
public:
    static std::vector<Sprite> cards;
    static GLFWwindow* window;

    static void Init();
    static void RenderLoop();
};