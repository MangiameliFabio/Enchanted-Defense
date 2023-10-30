#include "InputManager.h"

#include <SDL_keyboard.h>

#include "PlayerCommands.h"
#include "../GameCommands.h"
#include "../GameSingleton.h"
#include "../../Engine/EngineSingelton.h"
#include "../../Engine/Debuging/Log.h"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

Command* InputManager::handleInput()
{
    //Set texture based on current keystate
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    
    if (!disablePlayerInput && PLAYER)
    {
        PLAYER->stateMachine.stateEnum = IDLE;
        if (currentKeyStates[SDL_SCANCODE_W]) buttonW->execute();
        if (currentKeyStates[SDL_SCANCODE_A]) buttonA->execute();
        if (currentKeyStates[SDL_SCANCODE_S]) buttonS->execute();
        if (currentKeyStates[SDL_SCANCODE_D]) buttonD->execute();
        if (currentKeyStates[SDL_SCANCODE_UP]) buttonUp->execute();
        if (currentKeyStates[SDL_SCANCODE_LEFT]) buttonLeft->execute();
        if (currentKeyStates[SDL_SCANCODE_DOWN]) buttonDown->execute();
        if (currentKeyStates[SDL_SCANCODE_RIGHT]) buttonRight->execute();
    }
    if (currentKeyStates[SDL_SCANCODE_ESCAPE]) buttonESC->execute();
    
    ENGINE->notify(ALL_INPUTS_HANDLED);

    return nullptr;
}

void InputManager::close()
{
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
    
    // //Clear Pointer
    buttonW = nullptr;
    buttonA = nullptr;
    buttonS = nullptr;
    buttonD = nullptr;
    buttonUp = nullptr;
    buttonLeft = nullptr;
    buttonDown = nullptr;
    buttonRight = nullptr;
    buttonESC = nullptr;

    ENGINE->removeObserver(this);
}

void InputManager::init()
{
    buttonW = new MoveUpCommand;
    buttonA = new MoveLeftCommand;
    buttonS = new MoveDownCommand;
    buttonD = new MoveRightCommand;
    buttonUp = new AimUpCommand;
    buttonLeft = new AimLeftCommand;
    buttonDown = new AimDownCommand;
    buttonRight = new AimRightCommand;
    buttonESC = new CloseGameCommand;

    ENGINE->addObserver(this);
}

void InputManager::onNotify(const Event event)
{
    if (event == PLAYER_DIED)
    {
        disablePlayerInput = true;
    }
}
