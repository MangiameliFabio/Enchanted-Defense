#pragma once

#include <memory>
#include <vector>

#include "../../Engine/Scenes/BaseScene.h"

class Animator;
class StyledText;
class Texture;
class CustomButton;

class CreditsScene : public BaseScene
{
    std::shared_ptr<Texture> background = nullptr;
    std::shared_ptr<StyledText> title = nullptr;
    std::shared_ptr<StyledText> secondTitle = nullptr;
    std::shared_ptr<CustomButton> backButton= nullptr;
    std::shared_ptr<Animator> playerIdle = nullptr;

    std::vector<std::shared_ptr<Animator>> skeletons;


    int amountOfSkelis = 6;
    
public:
    void startScene() override;
    void endScene() override;
    void updateScene() override;
};
