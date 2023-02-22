#pragma once
class Command;

class InputManager
{
public:
    Command* handleInput();

    void init();
    void close();

private:
    Command* buttonW = nullptr;
    Command* buttonA = nullptr;
    Command* buttonS = nullptr;
    Command* buttonD = nullptr;
};
