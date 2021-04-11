#include "texture_loader.h"

std::map<std::string, unsigned int>    TextureLoader::Textures;

void TextureLoader::load(const char *filename, string name){
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the texture
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(filename, &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    Textures[name] = texture;
}

void TextureLoader::Init(){
    TextureLoader::load("./images/card-back.png", "card-back");
    for (int i = 0; i < 30; i++){
        int colour_num = (i - i % 10) / 10;
        string filename, colour;
        if (colour_num == 0) colour = "R";
        if (colour_num == 1) colour = "Y";
        if (colour_num == 2) colour = "B";
        filename = colour + "-" + to_string(i % 10);
        string filepath = "./images/cards/" + colour + "/" + filename + ".png";
        TextureLoader::load(filepath.c_str(), filename);
    }
}

unsigned int TextureLoader::get(string name){
    return Textures[name];
}