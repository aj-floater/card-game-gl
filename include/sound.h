#pragma once

#include <third_parties/irrKlang/irrKlang.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
using namespace irrklang;

class Sound{
public:
    vector<string> file_paths;
    Sound(){}
    Sound(string file_path){
        this->file_paths.push_back(file_path);
    }
    Sound(vector<string> file_paths){
        for (string s : file_paths){
            this->file_paths.push_back(s);
        }
    }
    bool IsSingleFile(){
        if (file_paths.size() == 1) return true;
        else return false;
    }
};

class SoundManager{
    static map<string, Sound> sounds;
    static ISoundEngine* engine;
public:
    static void AddSound(string file_path, string sound_name){
        sounds[sound_name] = Sound(file_path);
    }
    static void AddSounds(vector<string> file_paths, string sound_name){
        sounds[sound_name] = Sound(file_paths);
    }
    static void PlaySound(string sound_name, int volume){
        Sound *sound = &sounds[sound_name];
        int temp_volume =  engine->getSoundVolume();
        SetVolume(volume);
        if (sound->IsSingleFile()){
            engine->play2D(sound->file_paths[0].c_str(), false);
        }
        else {
            int number = rand() % sound->file_paths.size();
            engine->play2D(sound->file_paths[number].c_str(), false);
        }
        SetVolume(temp_volume);
    }
    static void SetVolume(int volume){
        engine->setSoundVolume(volume);
    }
    static void Init();
};