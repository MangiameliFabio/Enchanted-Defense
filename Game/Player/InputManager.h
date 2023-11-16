#pragma once
#include <memory>

#include "../../Engine/Core/Patterns/Observer.h"

class Command;

class InputManager : public Observer
{
    std::shared_ptr<Command> buttonW = nullptr;
    std::shared_ptr<Command> buttonA = nullptr;
    std::shared_ptr<Command> buttonS = nullptr;
    std::shared_ptr<Command> buttonD = nullptr;
    std::shared_ptr<Command> buttonUp = nullptr;
    std::shared_ptr<Command> buttonLeft = nullptr;
    std::shared_ptr<Command> buttonDown = nullptr;
    std::shared_ptr<Command> buttonRight = nullptr;
    std::shared_ptr<Command> buttonESC = nullptr;

public:
    InputManager();
    ~InputManager() override;

    void init();

    Command* handleInput();
    void onNotify(const Event event) override;

    bool disablePlayerInput = false;
};
