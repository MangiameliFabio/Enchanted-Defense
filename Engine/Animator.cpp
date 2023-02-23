#include "Animator.h"

#include <map>

#include "Singelton.h"
#include "Core/Helper.h"

void Animator::update()
{
    Object::update();
    if (!disabled)
    {
        if (currentFrameTime <= 0.f)
        {
            //Reset FrameTime
            currentFrameTime = frameRate;

            //Set new sprite for rendering
            animationSprites[lastSprite]->markForRender = false;
            animationSprites[currentSprite]->markForRender = true;

            //Set current sprite to last sprite
            lastSprite = currentSprite;

            //If current sprite is over max reset to 0
            currentSprite = currentSprite < maxSprites - 1 ? +1 : 0;
        }
        else
        {
            currentFrameTime -= SINGLETON->gDeltaTime;
        }
    }
}

void Animator::addSprite(Texture* texture)
{
    texture->markForRender = false;
    animationSprites.push_back(texture);
    maxSprites++;
}

void Animator::setFrameRate(float framesPerSecond)
{
    frameRate = 1.f / framesPerSecond;
}

void Animator::disable()
{
    disabled = true;
    currentFrameTime = 0;
    animationSprites[currentSprite]->markForRender = false;
}

void Animator::enable()
{
    disabled = true;
    currentFrameTime = 0;
    animationSprites[currentSprite]->markForRender = true;
}

Animator::Animator()
{
}

Animator::~Animator()
{
}
