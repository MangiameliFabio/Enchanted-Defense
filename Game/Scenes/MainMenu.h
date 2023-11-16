#pragma once
#include <memory>

#include "../../Engine/Scenes/BaseScene.h"
#include "../../Engine/UI/Button.h"
#include "../../Engine/UI/TextBox.h"

class MainMenu : public BaseScene
{
    std::shared_ptr<TextBox> titel;
    std::shared_ptr<Button>  startButton;

    Texture background;
    
public:
    MainMenu();
    ~MainMenu() override = default;
    void startScene() override;
    void updateScene() override;
    void endScene() override;
};
