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
    if (currentKeyStates[SDL_SCANCODE_ESCAPE]) buttonESC->execute();
    
    return nullptr;
}

void InputManager::close()
{
    //Delete commands
    delete buttonW;
    delete buttonA;
    delete buttonS;
    delete buttonD;
    delete buttonESC;

    //Clear Pointer
    buttonW = nullptr;
    buttonA = nullptr;
    buttonS = nullptr;
    buttonD = nullptr;
    buttonESC = nullptr;
}
