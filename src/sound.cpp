#include "sound.h"

ISoundEngine* SoundManager::engine = createIrrKlangDevice();
map<string, Sound> SoundManager::sounds;

void InitMoveCardSound(){
    vector<string> filenames;
    for (int i = 0; i < 3; i++)
        filenames.push_back("audio/CardMovement/CardPass/CardPass" + to_string(i) + ".wav");
    SoundManager::AddSounds(filenames, "move_card");
}

void InitMoveMultipleCardsSound(){
    vector<string> filenames;
    for (int i = 0; i < 7; i++)
        filenames.push_back("audio/CardMovement/CardDrop/CardDrop " + to_string(i) + ".wav");
    SoundManager::AddSounds(filenames, "move_multiple_cards");
}

void SoundManager::Init(){
    InitMoveMultipleCardsSound();
    InitMoveCardSound();
    SoundManager::AddSound("audio/CardMovement/CardScrape.wav", "scrape");
}