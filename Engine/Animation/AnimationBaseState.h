#pragma once
#include <cstdio>
#include <vcruntime_typeinfo.h>
#include <memory>

#include "Animator.h"

class Animator;

class BaseState
{
    Texture mSpriteSheet;
    
public:
    std::shared_ptr<Animator> animation = nullptr;

    virtual ~BaseState()
    {
    }

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
