#include "Animator.h"
#include "Singelton.h"

void Animator::update()
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
        currentSprite = currentSprite < maxSprites - 1 ? currentSprite + 1 : 0;
    }
    else
    {
        currentFrameTime -= SINGLETON->gDeltaTime;
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

void Animator::flip(SDL_RendererFlip flip)
{
    for (const auto sprite : animationSprites)
    {
        sprite->flip = flip;
    }
}

void Animator::disable()
{
    currentFrameTime = 0.f;
    currentSprite = 0;

    for (auto sprite : animationSprites)
    {
        sprite->markForRender = false;
    }
}

void Animator::enable()
{
    currentFrameTime = 0.f;
    animationSprites[currentSprite]->markForRender = true;
}

Animator::Animator()
{
}

Animator::~Animator()
{
}
