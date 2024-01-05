#pragma once
#include <memory>

#include "../../Engine/Scenes/BaseScene.h"

class Button;
class StyledText;
class Texture;
class Soundtrack;

class MainMenu : public BaseScene
{
    std::shared_ptr<StyledText> title = nullptr;

    std::shared_ptr<Button> startButton = nullptr;
    std::shared_ptr<Button> creditsButton = nullptr;
    std::shared_ptr<Button> quitButton = nullptr;

    std::shared_ptr<Texture> background = nullptr;

public:
    MainMenu() = default;
    ~MainMenu() override = default;
    void startScene() override;
    void endScene() override;
};
