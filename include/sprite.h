#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"
#include "texture_loader.h"
#include "structures.h"

using namespace std;

class Sprite{
    unsigned int VBO, VAO, EBO;
    string name;

    // Animations
    static float delta_time, previous_time;
    float speed, internal_clock, animation_time;
    Position delta_position;
    void move();
public:
    Shader shader;
    Position position;
    Size size;

    Sprite(const char* vertexshaderpath, const char* fragmentshaderpath, const char *filename, string name);

    void update();
    void draw();

    bool notAnimated();
    void animate(Position target_position, float time);

    void changeSize(Size size);
    void changeSize(float size);
};