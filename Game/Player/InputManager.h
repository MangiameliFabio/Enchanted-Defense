#pragma once
#include "PlayerCommands.h"
#include "../GameCommands.h"
class Command;

class InputManager
{
public:
    Command* handleInput();
    void close();

private:
    Command* buttonW = new MoveUpCommand;
    Command* buttonA = new MoveLeftCommand;
    Command* buttonS = new MoveDownCommand;
    Command* buttonD = new MoveRightCommand;
    Command* buttonUp = new AimUpCommand;
    Command* buttonLeft = new AimLeftCommand;
    Command* buttonDown = new AimDownCommand;
    Command* buttonRight = new AimRightCommand;
    Command* buttonESC = new CloseGameCommand;
};
