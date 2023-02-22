#include "InputManager.h"
#include <SDL_keyboard.h>

#include "PlayerCommands.h"
#include "../../Engine/Singelton.h"

Command* InputManager::handleInput()
{
    //Set texture based on current keystate
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if (currentKeyStates[SDL_SCANCODE_W]) buttonW->execute(); 
    if (currentKeyStates[SDL_SCANCODE_A]) buttonA->execute(); 
    if (currentKeyStates[SDL_SCANCODE_S]) buttonS->execute(); 
    if (currentKeyStates[SDL_SCANCODE_D]) buttonD->execute(); 
    return nullptr;
}

void InputManager::init()
{
    buttonW = new MoveUpCommand;
    buttonA = new MoveLeftCommand;
    buttonS = new MoveDownCommand;
    buttonD = new MoveRightCommand;
}

void InputManager::close()
{
    delete buttonW;
    delete buttonA;
    delete buttonS;
    delete buttonD;

    buttonW = nullptr;
    buttonA = nullptr;
    buttonS = nullptr;
    buttonD = nullptr;
}
