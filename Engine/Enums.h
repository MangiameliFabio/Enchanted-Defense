#pragma once

enum EEvent
{
    NULL_EVENT,
    HANDLE_INPUT,
    ALL_INPUTS_HANDLED,
    PLAYER_DIED,
};

enum EPlayerAnim
{
    IDLE,
    LEFT,
    RIGHT,
    UP,
    DOWN,
};

enum EEnemies
{
    SKELETON
};

enum ESoundtrack
{
    MENU_TRACK,
    IN_GAME_TRACK,
};

enum ESoundEffect
{
    BUTTON_CLICK,
    GAME_OVER,
    SKELETON_DEATH,
    SHOOTING,
    WIN_SOUND
};
