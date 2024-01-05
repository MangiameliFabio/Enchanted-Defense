#include "SoundEffect.h"

#include <cstdio>

bool SoundEffect::init(const char* path, const int volume)
{
    //Load sound effects
    mSoundEffect = Mix_LoadWAV( path );
    if( mSoundEffect == NULL )
    {
        printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        return  false;
    }

    Mix_VolumeChunk(mSoundEffect, volume);
    
    return true;
}

void SoundEffect::play()
{
    Mix_PlayChannel( -1, mSoundEffect, 0 );
}
