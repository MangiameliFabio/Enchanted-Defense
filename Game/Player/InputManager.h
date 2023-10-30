#pragma once
#include "../../Engine/Core/Patterns/Observer.h"

class Command;

class InputManager : public Observer
{
    Command* buttonW = nullptr;
    Command* buttonA = nullptr;
    Command* buttonS = nullptr;
    Command* buttonD = nullptr;
    Command* buttonUp = nullptr;
    Command* buttonLeft = nullptr;
    Command* buttonDown = nullptr;
    Command* buttonRight = nullptr;
    Command* buttonESC = nullptr;

public:
    InputManager();
    ~InputManager() override;

    void init();

    Command* handleInput();
    void close();
    void onNotify(const Event event) override;

    bool disablePlayerInput = false;
};
