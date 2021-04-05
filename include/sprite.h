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
public:
    Shader shader;
    Position pos;
    Size size;

    Sprite(const char* vertexshaderpath, const char* fragmentshaderpath, const char *filename, string name);
    void draw();
    void changeSize(Size size);
    void changeSize(float size);
};