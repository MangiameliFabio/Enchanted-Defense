#include "Animator.h"
#include "Singelton.h"

void Animator::update()
{
    if (currentFrameTime <= 0.f)
    {
        //Reset FrameTime
        currentFrameTime = frameRate;

        animationFrame.x += spriteSheet->getWidth();
        
        if (currentSprite < maxSprites - 1)
        {
            currentSprite++;
        }
        else
        {
            currentSprite = 0;
            animationFrame.x = 0;
        }
    }
    else
    {
        currentFrameTime -= SINGLETON->gDeltaTime;
    }
}

void Animator::addSpriteSheet(Texture* texture, int spriteCount, int widthSprite, int heightSprite)
{
    spriteSheet = texture;
    spriteSheet->markForRender = false;
    spriteSheet->clip = &animationFrame;
    spriteSheet->setHeight(heightSprite);
    spriteSheet->setWidth(widthSprite);

    maxSprites = spriteCount;

    animationFrame.w = widthSprite;
    animationFrame.h = heightSprite;
    animationFrame.y = 0;
}

void Animator::setFrameRate(float framesPerSecond)
{
    frameRate = 1.f / framesPerSecond;
}

void Animator::flip(SDL_RendererFlip flip)
{
    spriteSheet->flip = flip;
}

void Animator::disable()
{
    currentFrameTime = 0.f;
    currentSprite = 0;
    animationFrame.x = 0;

    spriteSheet->markForRender = false;
}

void Animator::enable()
{
    currentFrameTime = 0.f;
    
    spriteSheet->markForRender = true;
}

Animator::Animator()
{
}

Animator::~Animator()
{
}
