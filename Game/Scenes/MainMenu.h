#pragma once
#include "../../Engine/Scenes/BaseScene.h"
#include "../../Engine/UI/TextBox.h"

class MainMenu : public BaseScene
{
    TextBox titel;
    Texture background;
    
public:
    MainMenu();
    ~MainMenu() override;
    void startScene() override;
    void updateScene() override;
    void endScene() override;
};
