#pragma once
#include <SDL_mixer.h>

class SoundEffect
{
    Mix_Chunk* mSoundEffect = nullptr;
    
public:
    bool init(const char* path, int volume = 20);

    void play();
};
