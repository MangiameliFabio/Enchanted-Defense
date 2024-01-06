#pragma once

#include <memory>

#include "../../Engine/Scenes/BaseScene.h"

class CustomButton;
class StyledText;
class Texture;

class GameOverScene : public BaseScene
{
    std::shared_ptr<Texture> background = nullptr;
    std::shared_ptr<StyledText> title = nullptr;

    std::shared_ptr<CustomButton>  restartButton = nullptr;
    std::shared_ptr<CustomButton>  menuButton = nullptr;
    
public:
    void startScene() override;
    void endScene() override;
};
