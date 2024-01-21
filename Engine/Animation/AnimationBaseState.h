#pragma once

#include "Animator.h"
#include "../Core/Texture.h"

class BaseState
{
    Texture mSpriteSheet;

public:
    std::shared_ptr<Animator> animation = nullptr;

    BaseState(Vector* position, const std::string& path, float frameRate, int spriteCount,
              SDL_RendererFlip flip = SDL_FLIP_NONE);
    virtual ~BaseState() = default;

    virtual void startState()
    {
        if (!animation)
        {
            printf("Can't start State, animation is invalid -> %s", typeid(*animation).name());
            return;
        }
        animation->enable();
    }

    virtual void updateState()
    {
        if (!animation)
        {
            printf("Can't update State, animation is invalid -> %s", typeid(*animation).name());
            return;
        }
        animation->update();
    }

    virtual void endState()
    {
        if (!animation)
        {
            printf("Can't end State, animation is invalid -> %s", typeid(*animation).name());
            return;
        }
        animation->disable();
    }

    Texture* getSpriteSheet()
    {
        return &mSpriteSheet;
    }

    void free()
    {
        mSpriteSheet.free();
    }
};

inline BaseState::BaseState(Vector* position, const std::string& path, const float frameRate, const int spriteCount, const SDL_RendererFlip flip)
{
    animation = std::make_shared<Animator>();
    animation->setFrameRate(frameRate);
    animation->addSpriteSheet(position, path, spriteCount);

    animation->flip(flip);
}
