#include "sprite.h"

float Sprite::previous_time, Sprite::delta_time;

Sprite::Sprite(const char* vertexshaderpath, const char* fragmentshaderpath, const char *filename, string sprite_name){
    this->name = sprite_name;
    this->shader.create(vertexshaderpath, fragmentshaderpath);

    position = 0;
    size = 1;

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

    glBindVertexArray(0);

    TextureLoader::load(filename, name);
}

void Sprite::Draw(){
    this->shader.use();
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(position.x, position.y, 0));
    trans = glm::scale(trans, glm::vec3(size.x, size.y, 1));

    unsigned int transformLoc = glGetUniformLocation(this->shader.shaderProgram, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

    glBindTexture(GL_TEXTURE_2D, TextureLoader::get(this->name));
    glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
    //glDrawArrays(GL_TRIANGLES, 0, 6);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Sprite::ChangeSize(Size size){
    this->size.x *= size.x;
    this->size.y *= size.y;
}

void Sprite::ChangeSize(float size){
    this->size.x *= size;
    this->size.y *= size;
}

void Sprite::Update(){
    Move();
    Draw();
}

void Sprite::Move(){
    if (animation_queue.size() > 0){
        Apply(&animation_queue[0]);
        animated = true;
    }
    else animated = false;
}

bool IsGreater(Position pos1, Position pos2){
    if (abs(pos1.x) > abs(pos2.x) || abs(pos1.y) > abs(pos2.y)) return true;
    else return false;
}

void Sprite::Apply(Animation *animation){
    if (!animation->applied){
        animation->delta_position.x = animation->target_position.x - position.x;
        animation->delta_position.y = animation->target_position.y - position.y;
        animation->distance = abs(sqrt(pow(animation->target_position.x - position.x, 2) + pow(animation->target_position.y - position.y, 2)));
        animation->applied = true;
    }
    position.x += animation->delta_position.x/animation->time * delta_time;
    position.y += animation->delta_position.y/animation->time * delta_time;
    distance_travelled += abs(sqrt(pow(animation->delta_position.x/animation->time * delta_time, 2) + pow(animation->delta_position.y/animation->time * delta_time, 2)));
    if (distance_travelled >= animation->distance){
        position.x = animation->target_position.x;
        position.y = animation->target_position.y;
        distance_travelled = 0;
        shuffle_position++;
        if (animation->sound != "") SoundManager::PlaySound(animation->sound);
        animation_queue.erase(animation_queue.begin());
    }
}

void Sprite::GoTo(Position target_position, float time, string sound){
    animation_queue.push_back(Animation(target_position, time, sound));
}
void Sprite::GoTo(Position target_position, float time){
    animation_queue.push_back(Animation(target_position, time));
}

bool Sprite::IsAnimated(){
    return animated;
}