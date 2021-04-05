#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>
#include <iostream>

class Shader{
private:
    std::string extractShader(const char* shaderpath){
        std::string shadersource, line;
        std::ifstream file;
        file.open(shaderpath);
        if (file.is_open()){
            while(getline (file,line)){
                shadersource += line + "\n";
            }
            file.close();
        }
        else std::cout << "error opening file" << std::endl;
        return shadersource;
    }
    unsigned int compileShader(const char *shadersource, uint32_t shaderkind){
        int success;
        char infoLog[512];
        // compile shader
        unsigned int shader = glCreateShader(shaderkind);
        glShaderSource(shader, 1, &shadersource, NULL);
        glCompileShader(shader);
        // check for shader compile errors
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
        return shader;
    }
public:
    unsigned int shaderProgram;
    Shader(const char* vertexshaderpath, const char* fragmentshaderpath){
        create(vertexshaderpath, fragmentshaderpath);
    }
    Shader(){}
    void create(const char* vertexshaderpath, const char* fragmentshaderpath){ // creates a new shader in the determined shader object (even if another shader has been created previously)
        // extract shaders from path to source
        std::string vertexsource = extractShader(vertexshaderpath);
        std::string fragmentsource = extractShader(fragmentshaderpath);

        // compile vertex shader into unsigned int
        const char *vertexShaderSource = vertexsource.c_str();
        unsigned int vertexShader = compileShader(vertexShaderSource, GL_VERTEX_SHADER);
        // compile fragment shader into unsigned int
        const char *fragmentShaderSource = fragmentsource.c_str();
        unsigned int fragmentShader = compileShader(fragmentShaderSource, GL_FRAGMENT_SHADER);

        // link shaders
        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);

        // deletes compiled vertex and fragment shaders
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }
    void use(){
        glUseProgram(shaderProgram);
    }
};