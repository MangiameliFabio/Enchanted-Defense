#pragma once

#include <vector>

#include "../../Engine/Scenes/BaseScene.h"
#include "../../Engine/Animation/Animator.h"
#include "../../Engine/UI/Button.h"
#include "../../Engine/UI/TextBox.h"

class CreditsMenu : public BaseScene
{
    Texture background;
    TextBox title;
    TextBox secondTitle;

    Button backButton;
    
    std::vector<std::shared_ptr<Animator>> skeletons;

    Animator playerIdle;

    int amountOfSkelis = 6;
    
public:
    void startScene() override;
    void endScene() override;
    void updateScene() override;
};
