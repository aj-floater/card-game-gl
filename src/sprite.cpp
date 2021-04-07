#include "sprite.h"

float Sprite::previous_time, Sprite::delta_time;

Sprite::Sprite(const char* vertexshaderpath, const char* fragmentshaderpath, const char *filename, string sprite_name){
    this->name = sprite_name;
    this->shader.create(vertexshaderpath, fragmentshaderpath);

    animated = false;

    internal_clock = 0;
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

void Sprite::Update(){
    Draw();
    Move();
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

void Sprite::Move(){
    if (animation_queue.size() > 0){
        Animation *a = &animation_queue.at(0);
        if (!a->started){
            a->CalculateDeltaPosition(position);
            animated = true;
            a->started = true;
        }
        if (internal_clock < a->time){
            internal_clock += delta_time;

            distance += sqrt(pow(a->delta_position.x * delta_time, 2) + pow(a->delta_position.y * delta_time, 2));

            position.x += a->delta_position.x * delta_time;
            position.y += a->delta_position.y * delta_time;
        }
        else if (internal_clock > a->time) {
            position.x = a->target_position.x;
            position.y = a->target_position.y;
            if (this->sound) {
                SoundManager::PlaySound("move_card", RandomFloat(50, 75));
                SoundManager::PlaySound("scrape", RandomFloat(0.01, 1));
            }
            internal_clock = 0;
            animated = false;
            shuffle_position++;
            animation_queue.erase(animation_queue.begin()+0);
        }
    }
}

void Sprite::GoTo(Position target_position, float time){
    animation_queue.push_back(Animation(
        target_position,
        time
    ));
    this->sound = true;
}

void Sprite::GoTo(Position target_position, float time, bool play_sound){
    animation_queue.push_back(Animation(
        target_position,
        time
    ));
    this->sound = play_sound;
}

bool Sprite::IsAnimated(){
    if (animated) return true;
    else return false;
}