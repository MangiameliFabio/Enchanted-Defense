#include "SoundManager.h"

#include "../Engine/Enums.h"
#include "../Engine/Core/Soundtrack.h"

void SoundManager::init()
{
    mSoundtrackMap.emplace(std::make_pair(MENU_TRACK, "assets/sounds/music/menu_music.mp3"));
    mSoundtrackMap.emplace(std::make_pair(IN_GAME_TRACK, "assets/sounds/music/game_music.mp3"));

    mSoundEffectMap.emplace(std::make_pair(BUTTON_CLICK, "assets/sounds/effects/button_click.wav"));
    mSoundEffectMap.emplace(std::make_pair(GAME_OVER, "assets/sounds/effects/game_over.wav"));
    mSoundEffectMap.emplace(std::make_pair(SKELETON_DEATH, "assets/sounds/effects/skeleton_kill.wav"));
    mSoundEffectMap.emplace(std::make_pair(SHOOTING, "assets/sounds/effects/shoot_sound.wav"));
    mSoundEffectMap.emplace(std::make_pair(WIN_SOUND, "assets/sounds/effects/win.wav"));
}

Soundtrack* SoundManager::getSoundtrack(ESoundtrack soundtrack)
{
    return &mSoundtrackMap[soundtrack];
}

SoundEffect* SoundManager::getSoundEffect(ESoundEffect soundEffect)
{
    return &mSoundEffectMap[soundEffect];
}
