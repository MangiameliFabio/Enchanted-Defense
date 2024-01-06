#pragma once
#include <unordered_map>

#include "../Engine/Core/SoundEffect.h"
#include "../Engine/Core/Soundtrack.h"

enum ESoundtrack : int;
enum ESoundEffect : int;

class SoundManager
{
    std::unordered_map<ESoundEffect, SoundEffect> mSoundEffectMap;
    std::unordered_map<ESoundtrack, Soundtrack> mSoundtrackMap;

public:
    void init();

    Soundtrack* getSoundtrack(ESoundtrack soundtrack);
    SoundEffect* getSoundEffect(ESoundEffect soundEffect);
};
