#include "InputManager.h"
#include <SDL_keyboard.h>

#include "PlayerCommands.h"
#include "../../Engine/Singelton.h"

Command* InputManager::handleInput()
{
    //Set texture based on current keystate
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if (PLAYER)
    {
        PLAYER->stateMachine->stateEnum = IDLE;
        if (currentKeyStates[SDL_SCANCODE_W])       buttonW->execute();
        if (currentKeyStates[SDL_SCANCODE_A])       buttonA->execute();
        if (currentKeyStates[SDL_SCANCODE_S])       buttonS->execute();
        if (currentKeyStates[SDL_SCANCODE_D])       buttonD->execute();
        if (currentKeyStates[SDL_SCANCODE_UP])      buttonUp->execute();
        if (currentKeyStates[SDL_SCANCODE_LEFT])    buttonLeft->execute();
        if (currentKeyStates[SDL_SCANCODE_DOWN])    buttonDown->execute();
        if (currentKeyStates[SDL_SCANCODE_RIGHT])   buttonRight->execute();
    }
    if (currentKeyStates[SDL_SCANCODE_ESCAPE]) buttonESC->execute();

    return nullptr;
}

void InputManager::close()
{
    //Clear Pointer
    buttonW = nullptr;
    buttonA = nullptr;
    buttonS = nullptr;
    buttonD = nullptr;
    buttonUp = nullptr;
    buttonLeft = nullptr;
    buttonDown = nullptr;
    buttonRight = nullptr;
    buttonESC = nullptr;

    //Delete commands
    delete buttonW;
    delete buttonA;
    delete buttonS;
    delete buttonD;
    delete buttonUp;
    delete buttonLeft;
    delete buttonDown;
    delete buttonRight;
    delete buttonESC;
}
