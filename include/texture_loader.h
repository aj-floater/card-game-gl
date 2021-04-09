#pragma once
#include <map>
#include <string>
#include <iostream>

#include <third_parties/glad/glad.h>
#include <GLFW/glfw3.h>

#include <stb_image.h>

using namespace std;

class TextureLoader{
    static map<string, unsigned int> Textures;
public:
    static void Init();
    static void load(const char *filename, string name);
    static unsigned int get(string name);
};