#pragma once
#include <map>
#include <vector>

#include "Core/Texture.h"
#include "Core/Vector.h"

class Animator
{
    std::vector<Texture*> animationSprites;

    float currentFrameTime = 0.f;
    float frameRate = 1.f;

    int lastSprite = 0;
    int currentSprite = 0;
    int maxSprites = 0;

public:
    void update();
    void addSprite(Texture* texture);
    void setFrameRate(float framesPerSecond);
    void flip(SDL_RendererFlip flip);
    void disable();
    void enable();

    Animator();
    ~Animator();
};
