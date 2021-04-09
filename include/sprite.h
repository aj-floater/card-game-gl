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

    // Animations
    vector<Animation> animation_queue;
    bool animated = false;
    float distance_travelled;
    void Move();
    void Apply(Animation *animation);
public:
    string colour;
    int number;
    bool flipped;

    Shader shader;
    Position position;
    int shuffle_position;
    Size size;

    static float delta_time, previous_time;

    Sprite(){}
    Sprite(const char* vertexshaderpath, const char* fragmentshaderpath);

    void Update();
    void Draw();

    bool IsAnimated();
    void GoTo(Position target_position, float time);
    void GoTo(Position target_position, float time, string sound);

    void ChangeSize(Size size);
    void ChangeSize(float size);
};