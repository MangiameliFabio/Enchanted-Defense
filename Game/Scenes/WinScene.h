﻿#pragma once

#include "../../Engine/Core/Texture.h"
#include "../../Engine/Scenes/BaseScene.h"
#include "../../Engine/UI/Button.h"
#include "../../Engine/UI/TextBox.h"

class WinScene : public BaseScene
{
    std::shared_ptr<Texture> background = nullptr;
    std::shared_ptr<StyledText> title = nullptr;
    std::shared_ptr<StyledText> secondTitle = nullptr;

    std::shared_ptr<Button> restartButton = nullptr;
    std::shared_ptr<Button> menuButton = nullptr;

public:
    WinScene();
    ~WinScene() override;
    void startScene() override;
    void endScene() override;
};