#include "StyledText.h"

#include <memory>

StyledText::~StyledText()
{
}

void StyledText::createShadow(SDL_Color shadowColor)
{
    mTextShadow = std::make_shared<StyledText>();
    mTextShadow->init(mText, shadowColor, mFontSize,getTexture()->getZindex() - 50);
    mTextShadow->loadFromFile(path);
    mTextShadow->setPosition(getPosition().x + 3, getPosition().y + 3);
}
