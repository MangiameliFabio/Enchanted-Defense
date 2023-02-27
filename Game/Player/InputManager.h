#pragma once
#include "PlayerCommands.h"
#include "../GameCommands.h"
class Command;

class InputManager : public Observer
{
    Command* buttonW = new MoveUpCommand;
    Command* buttonA = new MoveLeftCommand;
    Command* buttonS = new MoveDownCommand;
    Command* buttonD = new MoveRightCommand;
    Command* buttonUp = new AimUpCommand;
    Command* buttonLeft = new AimLeftCommand;
    Command* buttonDown = new AimDownCommand;
    Command* buttonRight = new AimRightCommand;
    Command* buttonESC = new CloseGameCommand;
    
public:
    InputManager();
    ~InputManager() override = default;
    
    Command* handleInput();
    void close();
    void onNotify(const Event event) override;

    bool disablePlayerInput = false;
};
