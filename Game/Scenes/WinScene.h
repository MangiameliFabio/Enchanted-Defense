#pragma once

#include <memory>

#include "../../Engine/Scenes/BaseScene.h"

class StyledText;
class Texture;
class CustomButton;

class WinScene : public BaseScene
{
    std::shared_ptr<Texture> background = nullptr;
    std::shared_ptr<StyledText> title = nullptr;
    std::shared_ptr<StyledText> secondTitle = nullptr;
    std::shared_ptr<CustomButton> restartButton = nullptr;
    std::shared_ptr<CustomButton> menuButton = nullptr;

public:
    WinScene();
    ~WinScene() override;
    void startScene() override;
    void endScene() override;
};
