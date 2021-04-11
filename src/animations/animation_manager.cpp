#include "animations/animation_manager.h"

bool AnimationManager::is_animation_occurring, AnimationManager::left_or_right_pos;
bool AnimationManager::start_shuffle_animation, AnimationManager::start_move_animation, AnimationManager::start_main_animation;
int AnimationManager::animation_position, AnimationManager::count_iterator;
float AnimationManager::time;
Position AnimationManager::left_pos, AnimationManager::right_pos;

bool AnimationManager::AreAllCardsAnimationPositionsEqualTo(vector<Sprite> cards, float pos){
    bool flag = true;
    for (Sprite &c : cards){
        if (c.animation_position != pos) flag = false;
    }
    return flag;
}

bool AnimationManager::AreAllCardsNotAnimated(vector<Sprite> cards){
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
    Game::cards[pos1].GoTo(Position(Game::cards[pos1].position.x, Game::cards[pos1].position.y-0.2), time/3);
    Game::cards[pos1].GoTo(Position(Game::cards[pos2].position.x, Game::cards[pos2].position.y-0.2), time/3);
    Game::cards[pos1].GoTo(Position(Game::cards[pos2].position.x, Game::cards[pos2].position.y), time/3);
    SoundManager::PlaySound("scrape");
    SoundManager::PlaySound("move_card");
    MoveCard(pos1, pos2);
}

void AnimationManager::MoveCard(float position_1, float position_2){
    Sprite temp = Game::cards[position_1];
    MoveChunkBetweenPositions(position_1, position_2);
    Game::cards[position_2] = temp;
}

void AnimationManager::MoveChunkBetweenPositions(float position_1, float position_2){
    if (position_1 > position_2){
        for (int i = position_1; i > position_2; i--){
            Game::cards[i] = Game::cards[i-1];
            Game::cards[i].GoTo(Position(Game::cards[i].position.x+0.051, Game::cards[i].position.y), time);
        }
    }
    if (position_1 < position_2){
        for (int i = position_1; i < position_2; i++){
            Game::cards[i] = Game::cards[i+1];
            Game::cards[i].GoTo(Position(Game::cards[i].position.x-0.051, Game::cards[i].position.y), time);
        }
    }
    SoundManager::PlaySound("move_card");
}

void AnimationManager::IncrementLeftPos(){
    left_pos.x += 0.05;
    if (left_pos.x >= -0.2) {
        left_pos.x = -0.8;
        left_pos.y -= 0.2;
    }
}

void AnimationManager::IncrementRightPos(){
    right_pos.x += 0.05;
    if (right_pos.x >= 0.8) {
        right_pos.x = 0.2;
        right_pos.y -= 0.2;
    }
}

void AnimationManager::PlayShuffleAnimation(){
    is_animation_occurring = true;
    float movement = 0;
    float speed = 0.01;
    if (animation_position <= 0 && AreAllCardsNotAnimated(Game::cards)){
        for(Sprite &card : Game::cards)
            card.GoTo(Position(-0.75, 0.6), 0.5);
    }
    if(animation_position == 1 && AreAllCardsNotAnimated(Game::cards)){
        for(Sprite &card : Game::cards){
            card.GoTo(Position(-0.75+movement, 0.6), speed, "flick");
            movement += 0.051;
            speed += 0.05;
        }
    }
    if (animation_position == 2 && AreAllCardsNotAnimated(Game::cards)){
        if (count_iterator < 50){
            ShuffleOneCard(0.08);
            count_iterator++;
        }
        // End of animation
        else {
            for (Sprite &card : Game::cards) {
                card.animation_position = 0;
            }
            count_iterator = 0;
            animation_position = 0;
            is_animation_occurring = false;
            start_shuffle_animation = false;
            StartMoveAnimation();
        }
    }
    if (AreAllCardsAnimationPositionsEqualTo(Game::cards, animation_position+1)){
        animation_position++;
    }
}

void AnimationManager::PlayMoveAnimation(){
    is_animation_occurring = true;
    if (animation_position <= 0){
        for(Sprite &card : Game::cards)
            card.GoTo(Position(0, -0.6), 0.5);
    }
    if (AreAllCardsAnimationPositionsEqualTo(Game::cards, animation_position+1)){
        for (Sprite &card : Game::cards){
            card.animation_position = 0;
        }
        start_move_animation = false;
        is_animation_occurring = false;
        animation_position = 0;
        count_iterator = 29;
        StartMainAnimation();
    }
}

void AnimationManager::PlayMainAnimation(){
    is_animation_occurring = true;
    float animation_speed = 0.1;
    // cout << animation_position << endl;
    if (animation_position < 2){
        if (left_or_right_pos){
            Game::player_1_cards.push_back(Game::cards[Game::cards.size()-1]);
            Game::cards.pop_back();
            left_or_right_pos = false;
        }
        else {
            Game::player_2_cards.push_back(Game::cards[Game::cards.size()-1]);
            Game::cards.pop_back();
            left_or_right_pos = true;
        }
        animation_position++;
    }
    if (animation_position == 2){
        SoundManager::PlaySound("scrape");
        Game::player_1_cards[Game::player_1_cards.size()-1].GoTo(Position(-0.3, -0.6), animation_speed);
        Game::player_2_cards[Game::player_2_cards.size()-1].GoTo(Position(0.3, -0.6), animation_speed);
        animation_position++;
    }
    if (animation_position == 3){
        bool flag = true;
        for (Sprite &c : Game::player_1_cards){
            if (c.IsAnimated()) flag = false;
        }
        for (Sprite &c : Game::player_2_cards){
            if (c.IsAnimated()) flag = false;
        }
        if (flag) animation_position++;
    }
    if (animation_position == 4){
        Game::player_1_cards[Game::player_1_cards.size()-1].flipped = true;
        Game::player_2_cards[Game::player_2_cards.size()-1].flipped = true;
        time += Game::delta_time;
        if (time >= 0.1){
            animation_position++;
            time = 0;
        }
    }
    if (animation_position == 5){
        SoundManager::PlaySound("scrape");
        if (Game::Compare(Game::player_1_cards[Game::player_1_cards.size()-1], Game::player_2_cards[Game::player_2_cards.size()-1]) == 1){
            Game::player_1_cards.push_back(Game::player_2_cards[Game::player_2_cards.size()-1]);
            Game::player_2_cards.pop_back();
            Game::player_1_cards[Game::player_1_cards.size()-2].GoTo(Position(left_pos.x, left_pos.y), animation_speed, "move_card");
            IncrementLeftPos();
            Game::player_1_cards[Game::player_1_cards.size()-1].GoTo(Position(left_pos.x, left_pos.y), animation_speed);
            IncrementLeftPos();
        }
        else {
            Game::player_2_cards.push_back(Game::player_1_cards[Game::player_1_cards.size()-1]);
            Game::player_1_cards.pop_back();
            Game::player_2_cards[Game::player_2_cards.size()-2].GoTo(Position(right_pos.x, right_pos.y), animation_speed, "move_card");
            IncrementRightPos();
            Game::player_2_cards[Game::player_2_cards.size()-1].GoTo(Position(right_pos.x, right_pos.y), animation_speed);
            IncrementRightPos();
        }
        animation_position++;
    }
    if (animation_position == 6){
        bool flag = true;
        for (Sprite &c : Game::player_1_cards){
            if (c.IsAnimated()) flag = false;
        }
        for (Sprite &c : Game::player_2_cards){
            if (c.IsAnimated()) flag = false;
        }
        if (flag && count_iterator <= 15) {count_iterator++; animation_position=0;}
        if (count_iterator == 15){
            start_main_animation = false;
            is_animation_occurring = false;
            while (Game::player_1_cards.size() > 0){
                Game::cards.push_back(Game::player_1_cards[0]);
                Game::player_1_cards.erase(Game::player_1_cards.begin());
            }
            while (Game::player_2_cards.size() > 0){
                Game::cards.push_back(Game::player_2_cards[0]);
                Game::player_2_cards.erase(Game::player_2_cards.begin());
            }
        }
    }
}

void AnimationManager::StartShuffleAnimation(){
    if (!is_animation_occurring) {
        start_shuffle_animation = true;
        for (Sprite &card : Game::cards){
            card.flipped = false;
            card.animation_position = 0;
        }
    }
}
void AnimationManager::StartMoveAnimation(){
    if (!is_animation_occurring){
        start_move_animation = true;
        for (Sprite &card : Game::cards){
            card.animation_position = 0;
        }
    }
}
void AnimationManager::StartMainAnimation(){
    if (!is_animation_occurring){
        left_pos = Position(-0.8, 0.6);
        right_pos = Position(0.2, 0.6);
        start_main_animation = true;
        left_or_right_pos = true;
        time = 0;
        count_iterator = 0;
        for (Sprite &card : Game::cards){
            card.animation_position = 0;
        }
    }
}

void AnimationManager::Update(){
    if (start_shuffle_animation)
        PlayShuffleAnimation();
    if (start_move_animation)
        PlayMoveAnimation();
    if (start_main_animation)
        PlayMainAnimation();
}