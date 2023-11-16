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
    ENGINE->removeObserver(this);
}

Command* InputManager::handleInput()
{
    //Set texture based on current keystate
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if (!disablePlayerInput && PLAYER)
    {
        PLAYER->stateMachine->stateEnum = IDLE;
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

void InputManager::init()
{
    buttonW = std::make_shared<MoveUpCommand>();
    buttonA = std::make_shared<MoveLeftCommand>();
    buttonS = std::make_shared<MoveDownCommand>();
    buttonD = std::make_shared<MoveRightCommand>();
    buttonLeft = std::make_shared<AimLeftCommand>();
    buttonDown = std::make_shared<AimDownCommand>();
    buttonUp = std::make_shared<AimUpCommand>();
    buttonRight = std::make_shared<AimRightCommand>();
    buttonESC = std::make_shared<CloseGameCommand>();

    ENGINE->addObserver(this);
}

void InputManager::onNotify(const Event event)
{
    if (event == PLAYER_DIED)
    {
        disablePlayerInput = true;
    }
}
