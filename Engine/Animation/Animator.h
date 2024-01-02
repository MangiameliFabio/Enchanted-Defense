#pragma once

#include <memory>

#include "../Core/Texture.h"

class Animator
{
    SDL_Rect animationFrame;

    float currentFrameTime = 0.f;
    float frameRate = 1.f;

    int currentSprite = 0;
    int maxSprites = 0;

    std::shared_ptr<Texture> spriteSheet;

public:
    void update();
    void addSpriteSheet(Texture* texture, int spriteCount, int widthSprite, int widthHeight);
    void setFrameRate(float framesPerSecond);
    void flip(SDL_RendererFlip flip);
    void disable();
    void enable();

    Texture* getSpriteSheet() const;

    Animator() = default;
    ~Animator();
};
