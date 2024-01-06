#pragma once
#include <SDL_mixer.h>

class SoundEffect
{
    Mix_Chunk* mSoundEffect = nullptr;
    
public:
    SoundEffect();
    SoundEffect(const char* path);

    ~SoundEffect();
    bool init(const char* path);

    void play(int volume = 20);
};
