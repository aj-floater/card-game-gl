#pragma once

struct Size{
    float x, y;
    Size(float x, float y){
        this->x = x; this->y = y;
    }
    Size(){}
};

struct Position{
    float x, y;
};