#pragma once

#include "../../Engine/Core/Texture.h"
#include "../../Engine/Scenes/BaseScene.h"
#include "../../Engine/UI/Button.h"
#include "../../Engine/UI/TextBox.h"

class WinScene : public BaseScene
{
    Texture background;
    StyledText title;
    StyledText secondTitle;

    Button  restartButton;
    Button  menuButton;

public:
    WinScene();
    ~WinScene() override;
    void startScene() override;
    void endScene() override;
};
