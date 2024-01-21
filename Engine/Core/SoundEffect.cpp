#include "SoundEffect.h"

SoundEffect::SoundEffect()
{
}

SoundEffect::SoundEffect(const char* path)
{
    //Load sound effects
    mSoundEffect = Mix_LoadWAV( path );
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
        return  false;
    }
    
    return true;
}

void SoundEffect::play(const int volume)
{
    Mix_VolumeChunk(mSoundEffect, volume);
    
    Mix_PlayChannel( -1, mSoundEffect, 0 );
}
