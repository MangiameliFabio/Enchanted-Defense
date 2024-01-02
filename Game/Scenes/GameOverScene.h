#pragma once

#include "../../Engine/Core/Texture.h"
#include "../../Engine/Scenes/BaseScene.h"
#include "../../Engine/UI/Button.h"
#include "../../Engine/UI/TextBox.h"

class GameOverScene : public BaseScene
{
    Texture background;
    TextBox title;

    Button  restartButton;
    Button  menuButton;
public:
    void startScene() override;
    void endScene() override;
};
