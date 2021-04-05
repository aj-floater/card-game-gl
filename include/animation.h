#pragma once

#include "structures.h"

class Animation{
public:
    Position delta_position, target_position;
    float time;
    Animation(Position delta_position, Position target_position, float time){
        this->delta_position = delta_position;
        this->target_position = target_position;
        this->time = time;
    }
};