#include "Animator.h"

#include <memory>

#include "../EngineSingelton.h"

void Animator::update()
{
    if (currentFrameTime <= 0.f)
    {
        //Reset FrameTime
        currentFrameTime = frameRate;

        animationFrame.x += getWidth();
        
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
        currentFrameTime -= DELTA_TIME;
    }
}

void Animator::addSpriteSheet(Vector* position, const std::string& path, int spriteCount)
{
    spriteSheet = std::make_shared<Texture>();
    spriteSheet->loadTexture(path);
    spriteSheet->setDynamicPosition(position);
    
    animationFrame.w = spriteSheet->getWidth() / spriteCount;
    animationFrame.h = spriteSheet->getHeight();
    animationFrame.y = 0;
    animationFrame.x = 0;

    spriteSheet->setWidth(animationFrame.w);
    spriteSheet->setHeight(animationFrame.h);
    
    spriteSheet->markForRender = false;
    spriteSheet->clip = &animationFrame;

    maxSprites = spriteCount;
}

void Animator::addSpriteSheet(const Vector& position, const std::string& path, int spriteCount)
{
    spriteSheet = std::make_shared<Texture>();
    spriteSheet->loadTexture(path);
    spriteSheet->setStaticPosition(position);
    
    animationFrame.w = spriteSheet->getWidth() / spriteCount;
    animationFrame.h = spriteSheet->getHeight();
    animationFrame.y = 0;
    animationFrame.x = 0;

    spriteSheet->setWidth(animationFrame.w);
    spriteSheet->setHeight(animationFrame.h);
    
    spriteSheet->markForRender = false;
    spriteSheet->clip = &animationFrame;

    maxSprites = spriteCount;
}

Animator::~Animator()
{
    spriteSheet->free();
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

Texture* Animator::getSpriteSheet() const
{
    return spriteSheet.get();
}

int Animator::getWidth()
{
    return animationFrame.w;
}

int Animator::getHeight()
{
    return animationFrame.h;
}
