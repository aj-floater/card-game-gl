#pragma once

#include <map>
#include <string>

#include "structures.h"

using namespace std;

class AnimationQueue{
public:
    static map<string, Position> deltapos_queue;
    static map<string, Position> targetpos_queue;
    static map<string, float> animationtime_queue;
};