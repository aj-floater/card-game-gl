#pragma once

#include <vector>

#include "sprite.h"

class AnimationManager{
    static bool shuffling;
    static int shufflepos, j;

    static float time;

    static bool AreAllCardsAnimationPositionsEqualTo(float pos);
    static bool AreAllCardsAnimated();
    static void ShuffleOneCard(float timeToTake);
    static void MoveCard(float position_1, float position_2);
    static void MoveChunkBetweenPositions(float position_1, float position_2);
public:
    static vector<Sprite> cards;

    static void PlayShuffleAnimation();
    static void StartShuffleAnimation(bool is_start);
    static void Update();
};