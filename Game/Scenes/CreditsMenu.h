#pragma once

#include <vector>

#include "../../Engine/Scenes/BaseScene.h"
#include "../../Engine/Animation/Animator.h"
#include "../../Engine/UI/Button.h"
#include "../../Engine/UI/TextBox.h"

class CreditsMenu : public BaseScene
{
    std::shared_ptr<Texture> background = nullptr;
    
    std::shared_ptr<StyledText> title = nullptr;
    std::shared_ptr<StyledText> secondTitle = nullptr;

    std::shared_ptr<Button> backButton;
    
    std::vector<std::shared_ptr<Animator>> skeletons;

    std::shared_ptr<Animator> playerIdle;

    int amountOfSkelis = 6;
    
public:
    void startScene() override;
    void endScene() override;
    void updateScene() override;
};
