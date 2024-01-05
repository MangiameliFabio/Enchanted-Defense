#pragma once

enum Event
{
    NULL_EVENT,
    HANDLE_INPUT,
    ALL_INPUTS_HANDLED,
    PLAYER_DIED,
    SCENE_SWITCH,
};

enum playerAnim
{
    IDLE,
    LEFT,
    RIGHT,
    UP,
    DOWN,
};

enum Enemies
{
    SKELETON
};

enum SceneState
{
    MENU,
    IN_GAME
};
