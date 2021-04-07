#pragma once

#include "structures.h"

class Animation{
public:
    Position target_position, delta_position;
    float distance;
    float time;
    bool started;

    Animation(Position target_position, float time){
        this->target_position = target_position;
        this->time = time;
        this->started = false;
    }

    void CalculateDeltaPosition(Position position){
        delta_position = Position((target_position.x-position.x)/time, (target_position.y-position.y)/time);
        this->distance = abs(sqrt(pow(target_position.x-position.x, 2) + pow(target_position.x-position.x, 2)));
        // cout << distance << endl;
    }
};