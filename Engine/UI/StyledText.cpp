#include "StyledText.h"

void StyledText::createShadow(SDL_Color shadowColor)
{
    mTextShadow.init(mText, shadowColor, mFontSize);
    mTextShadow.loadFromFile(path);
    mTextShadow.setPosition(getPosition().x + 3, getPosition().y + 3);
    mTextShadow.setZIndex(getTexture()->getZindex() - 50);
}
