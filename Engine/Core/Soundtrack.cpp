#include "Soundtrack.h"

#include <memory>

Soundtrack::Soundtrack()
{
}

Soundtrack::Soundtrack(const char* path)
{
    //Load music
    mAudio = Mix_LoadMUS( path );
    if( mAudio == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
    }

    Mix_VolumeMusic(20);
}

Soundtrack::~Soundtrack()
{
    Mix_FreeMusic( mAudio );
    mAudio = nullptr;
}

bool Soundtrack::init(const char* path)
{
    //Load music
    mAudio = Mix_LoadMUS( path );
    if( mAudio == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }

    Mix_VolumeMusic(20);
    
    return true;
}

void Soundtrack::play(int fade)
{
    if(fade == -1)
    {
        Mix_PlayMusic(mAudio, -1);
    } else
    {
        //fade in music
        Mix_FadeInMusic(mAudio, -1, fade);
    }
}

void Soundtrack::pause()
{
    Mix_PauseMusic();
}

void Soundtrack::stop(int fade)
{
    if(fade == -1)
    {
        Mix_HaltMusic();
    } else
    {
        //fade in music
        Mix_FadeOutMusic( fade);
    }
}

void Soundtrack::close()
{
}
