#include "CustomButton.h"

#include "GameSingleton.h"
#include "SoundManager.h"

void CustomButton::playButtonSound()
{
    GAME->gSoundManager->getSoundEffect(BUTTON_CLICK)->play(30);
}
