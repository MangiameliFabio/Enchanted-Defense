#include "SoundEffect.h"

#include <cstdio>

SoundEffect::SoundEffect()
{
}

SoundEffect::SoundEffect(const char* path)
{
    //Load sound effects
    mSoundEffect = Mix_LoadWAV( path );
    if( mSoundEffect == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
    }
}

SoundEffect::~SoundEffect()
{
    Mix_FreeChunk(mSoundEffect);
    mSoundEffect = nullptr;
}

bool SoundEffect::init(const char* path)
{
    //Load sound effects
    mSoundEffect = Mix_LoadWAV( path );
    if( mSoundEffect == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        return  false;
    }
    
    return true;
}

void SoundEffect::play(const int volume)
{
    Mix_VolumeChunk(mSoundEffect, volume);
    
    Mix_PlayChannel( -1, mSoundEffect, 0 );
}
