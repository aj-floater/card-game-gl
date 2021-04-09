#include "animations/animation_manager.h"

bool AnimationManager::shuffling = false;
int AnimationManager::shufflepos, AnimationManager::j;
vector<Sprite> AnimationManager::cards;
float AnimationManager::time;

bool AnimationManager::AreAllCardsAnimationPositionsEqualTo(float pos){
    bool flag = true;
    for (Sprite &c : cards){
        if (c.shuffle_position != pos) flag = false;
    }
    return flag;
}

bool AnimationManager::AreAllCardsAnimated(){
    bool flag = true;
    for (Sprite &c : cards){
        if (c.IsAnimated()) flag = false;
    }
    return flag;
}

void AnimationManager::ShuffleOneCard(float timeToTake){
    time = timeToTake;
    // Determine swap positions
    int pos1 = rand() % 30;
    int pos2 = rand() % 30;
    // Move card from position 1 to just below position 2
    cards[pos1].GoTo(Position(cards[pos1].position.x, cards[pos1].position.y-0.2), time/3);
    cards[pos1].GoTo(Position(cards[pos2].position.x, cards[pos2].position.y-0.2), time/3);
    cards[pos1].GoTo(Position(cards[pos2].position.x, cards[pos2].position.y), time/3);
    SoundManager::PlaySound("scrape");
    SoundManager::PlaySound("move_card");
    MoveCard(pos1, pos2);
}

void AnimationManager::MoveCard(float position_1, float position_2){
    Sprite temp = cards[position_1];
    MoveChunkBetweenPositions(position_1, position_2);
    cards[position_2] = temp;
}

void AnimationManager::MoveChunkBetweenPositions(float position_1, float position_2){
    if (position_1 > position_2){
        for (int i = position_1; i > position_2; i--){
            cards[i] = cards[i-1];
            cards[i].GoTo(Position(cards[i].position.x+0.051, cards[i].position.y), time);
        }
    }
    if (position_1 < position_2){
        for (int i = position_1; i < position_2; i++){
            cards[i] = cards[i+1];
            cards[i].GoTo(Position(cards[i].position.x-0.051, cards[i].position.y), time);
        }
    }
    SoundManager::PlaySound("move_card");
}

void AnimationManager::PlayShuffleAnimation(){
    if (shuffling){
        float movement = 0;
        float speed = 0.01;
        for(Sprite &card : cards){
            if (shufflepos <= 0 && card.shuffle_position <= 0 && !card.IsAnimated()){
                card.GoTo(Position(-0.75, 0.6), 0.5);
            }
            if(shufflepos == 1 && card.shuffle_position == 1 && !card.IsAnimated()){
                card.GoTo(Position(-0.75+movement, 0.6), speed, "flick");
                movement += 0.051;
                speed += 0.05;
            }
        }
        if (shufflepos == 2 && AreAllCardsAnimated()){
            if (j < 30){
                ShuffleOneCard(0.1);
                j++;
            }
            else {
                for (Sprite &card : cards) {
                    card.shuffle_position = 0;
                }
                j = 0;
                shufflepos = 0;
                shuffling = false;
            }
        }
        if (AreAllCardsAnimationPositionsEqualTo(shufflepos+1)){
            shufflepos++;
        }
    }
}

void AnimationManager::StartShuffleAnimation(bool is_start){
    shuffling = is_start;
}

void AnimationManager::Update(){
    PlayShuffleAnimation();
}