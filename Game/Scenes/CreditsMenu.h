#pragma once

#include <vector>

#include "../../Engine/Scenes/BaseScene.h"
#include "../../Engine/UI/Button.h"
#include "../../Engine/UI/TextBox.h"

class Animator;

class CreditsMenu : public BaseScene
{
    Texture background;
    TextBox title;

    Button backButton;

    Texture spriteSheet;
    
    std::vector<std::shared_ptr<Animator>> skeletons;

    size_t amountOfSkelis = 4;
    
public:
    void startScene() override;
    void endScene() override;
};
