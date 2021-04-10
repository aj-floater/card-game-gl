#pragma once

#include "structures.h"

class Animation{
public:
    Position target_position, delta_position;
    float distance, time;
    bool applied, waiter;
    std::string sound;

    Animation(Position target_position, float time){
        this->target_position = target_position;
        this->time = time;
        applied = false;
        waiter = false;
        this->sound = "";
    }
    Animation(Position target_position, float time, std::string sound){
        this->target_position = target_position;
        this->time = time;
        applied = false;
        waiter = false;
        this->sound = sound;
    }
    Animation(float time){
        this->time = time;
        applied = false;
        this->sound = "";
        this->waiter = true;
    }
};