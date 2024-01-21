#pragma once

#include <memory>
#include <SDL.h>
#include <string>

struct Vector;
class Texture;

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
    void addSpriteSheet(Vector* position, const std::string& path, int spriteCount);
    void addSpriteSheet(const Vector& position, const std::string& path, int spriteCount);
    void setFrameRate(float framesPerSecond);
    void flip(SDL_RendererFlip flip);
    void disable();
    void enable();

    Texture* getSpriteSheet() const;

    int getWidth();
    int getHeight();

    Animator() = default;
    ~Animator();
};
