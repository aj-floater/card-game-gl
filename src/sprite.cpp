#include "sprite.h"

Sprite::Sprite(const char* vertexshaderpath, const char* fragmentshaderpath, const char *filename, string name){
    this->name = name;
    this->shader.create(vertexshaderpath, fragmentshaderpath);

    pos.x = 0; pos.y = 0;
    size.x = 1; size.y = 1;

    // set up vertex data (and buffer(s)) and configure vertex attributes
    float vertices[] = {
    /*  Positions           Texture Coordinates */
        0.5f, 0.5f, 0.0f,   1.0f, 1.0f,         // top right
        0.5f, -0.5f, 0.0f,  1.0f, 0.0f,         // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,         // bottom left
        -0.5f, 0.5f, 0.0f,  0.0f, 1.0f          // top left
    };

    unsigned int indices[] = { // note that we start from 0!
        0, 1, 3, // first triangle
        1, 2, 3 // second triangle
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);

    TextureLoader::load(filename, name);
}

void Sprite::draw(){
    this->shader.use();
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::scale(trans, glm::vec3(size.x, size.y, 1));
    trans = glm::translate(trans, glm::vec3(pos.x, pos.y, 0));

    unsigned int transformLoc = glGetUniformLocation(this->shader.shaderProgram, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

    glBindTexture(GL_TEXTURE_2D, TextureLoader::get(this->name));
    glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
    //glDrawArrays(GL_TRIANGLES, 0, 6);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Sprite::changeSize(Size size){
    this->size.x *= size.x;
    this->size.y *= size.y;
}

void Sprite::changeSize(float size){
    this->size.x *= size;
    this->size.y *= size;
}