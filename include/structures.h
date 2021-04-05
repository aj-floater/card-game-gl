#pragma once

#include <string>

class Size{
public:
    float x, y;
    Size(float x, float y){
        this->x = x; this->y = y;
    }
    Size(){}
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
    Position(float x, float y){
        this->x = x; this->y = y;
    }
    Position(float both){
        this->x = both; this->y = both;
    }
    Position(){}
    std::string returnString(){
        return "x: " + to_string(x) + ", y: " + to_string(y);
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