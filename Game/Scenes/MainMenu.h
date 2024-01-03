#pragma once
#include <memory>

#include "../../Engine/Scenes/BaseScene.h"
#include "../../Engine/UI/Button.h"
#include "../../Engine/UI/StyledText.h"
#include "../../Engine/UI/TextBox.h"

class MainMenu : public BaseScene
{
    StyledText title;
    Button  startButton;
    Button  creditsButton;
    Button  quitButton;

    Texture background;
    
public:
    MainMenu() = default;
    ~MainMenu() override = default;
    void startScene() override;
    void endScene() override;
};
