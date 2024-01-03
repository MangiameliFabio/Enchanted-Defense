#pragma once
#include "TextBox.h"

class StyledText : public TextBox
{
public:
    StyledText() = default;
    ~StyledText() = default;

    void createShadow(SDL_Color shadowColor);

private:
    TextBox mTextShadow;
};
