﻿#pragma once
#include <memory>
#include <SDL_mixer.h>
#include <string>

class Soundtrack
{
   Mix_Music* mAudio = nullptr;
    
public:
    Soundtrack();
    Soundtrack(const char* path);
    ~Soundtrack();
    
    bool init(const char* path);

    void play(int fade = -1);
    void pause();
    void stop(int fade = -1);

    void close();
};
