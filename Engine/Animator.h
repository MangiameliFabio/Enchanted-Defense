#pragma once
#include <map>
#include <vector>

#include "Core/Object.h"
#include "Core/Texture.h"
#include "Core/Vector.h"

class Animator : public Object
{
    std::vector<Texture*> animationSprites;

    Vector* posSprite;

    float currentFrameTime = 0.f;
    float frameRate = 1.f;

    int lastSprite = 0;
    int currentSprite = 0;
    int maxSprites = 0;

    bool disabled;

public:
    void update() override;
    void addSprite(Texture* texture);
    void setFrameRate(float framesPerSecond);
    void disable();
    void enable();

    Animator();
    ~Animator();
};
