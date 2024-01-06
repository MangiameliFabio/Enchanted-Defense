#pragma once
#include <memory>

#include "../../Engine/Scenes/BaseScene.h"

class CustomButton;
class StyledText;
class Texture;
class Soundtrack;

class MainMenuScene : public BaseScene
{
    std::shared_ptr<StyledText> title = nullptr;
    std::shared_ptr<CustomButton> startButton = nullptr;
    std::shared_ptr<CustomButton> creditsButton = nullptr;
    std::shared_ptr<CustomButton> quitButton = nullptr;
    std::shared_ptr<Texture> background = nullptr;

public:
    MainMenuScene() = default;
    ~MainMenuScene() override = default;
    void startScene() override;
    void endScene() override;
};
