#pragma once

#include <string>

float RandomFloat(float a, float b);

class Size{
public:
    float x, y;
    Size(){}
    Size(float x, float y){
        this->x = x; this->y = y;
    }
    void operator=(const float &p){
        this->x = p;
        this->y = p;
    }
    void operator=(const Size &p){
        this->x = p.x;
        this->y = p.y;
    }
};

class Position{
public:
    float x, y;
    Position(){}
    Position(float x, float y){
        this->x = x; this->y = y;
    }
    Position(float both){
        this->x = both; this->y = both;
    }
    Position(const Position &p){
        this->x = p.x; this->y = p.y;
    }  
    std::string returnString(){
        return "x: " + std::to_string(x) + ", y: " + std::to_string(y);
    }
    bool operator==(const Position &p){
        if (this->x == p.x && this->y == p.y)
            return true;
        else return false;
    }
    bool operator!=(const Position &p){
        if (this->x != p.x && this->y != p.y)
            return true;
        else return false;
    }
    bool operator!=(const float &p){
        if (this->x != p && this->y != p)
            return true;
        else return false;
    }
    void operator=(const float &p){
        this->x = p;
        this->y = p;
    }
    void operator=(const Position &p){
        this->x = p.x;
        this->y = p.y;
    }
};