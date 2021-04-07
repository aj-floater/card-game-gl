#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

#include "shader.h"
#include "texture_loader.h"
#include "structures.h"
#include "animations/animation.h"
#include "sound.h"

using namespace std;

class Sprite{
    unsigned int VBO, VAO, EBO;
    string name;

    // Animations
    float internal_clock, distance;
    bool animated, sound;
    vector<Animation> animation_queue;
    void Move();
public:
    int ID;
    Shader shader;
    Position position;
    Size size;
    int shuffle_position;

    static float delta_time, previous_time;

    Sprite(){}
    Sprite(const char* vertexshaderpath, const char* fragmentshaderpath, const char *filename, string name);

    void Update();
    void Draw();

    bool IsAnimated();
    void GoTo(Position target_position, float time);
    void GoTo(Position target_position, float time, bool play_sound);

    void ChangeSize(Size size);
    void ChangeSize(float size);
};