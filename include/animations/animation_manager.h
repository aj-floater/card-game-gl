#pragma once

#include <vector>

#include "game.h"
#include "sprite.h"

class AnimationManager{
    static bool is_animation_occurring, left_or_right_pos;
    static bool start_shuffle_animation, start_move_animation, start_main_animation;

    static int animation_position, count_iterator;
    static Position left_pos, right_pos;

    static float time;

    static bool AreAllCardsAnimationPositionsEqualTo(vector<Sprite> cards, float pos);
    static bool AreAllCardsNotAnimated(vector<Sprite> cards);

    static void ShuffleOneCard(float timeToTake);
    static void MoveCard(float position_1, float position_2);
    static void MoveChunkBetweenPositions(float position_1, float position_2);

    static void IncrementLeftPos();
    static void IncrementRightPos();
public:
    static void PlayShuffleAnimation();
    static void PlayMoveAnimation();
    static void PlayMainAnimation();

    static void StartShuffleAnimation();
    static void StartMoveAnimation();
    static void StartMainAnimation();

    static void Update();
};