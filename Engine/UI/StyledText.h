#pragma once
#include <memory>

#include "TextBox.h"

class StyledText : public TextBox
{
public:
    StyledText() = default;
    ~StyledText() override;

    void createShadow(SDL_Color shadowColor);

private:
    std::shared_ptr<TextBox> mTextShadow;
};
