#include "UIElement.h"

UIElement::~UIElement()
{
}

void UIElement::setPosition(const float x, const float y)
{
    mPosition.x = x;
    mPosition.y = y;
    getTexture()->setStaticPosition({x,y});
}

void UIElement::setPosition(const Vector& pos)
{
    mPosition = pos;
    getTexture()->setStaticPosition(pos);
}

Texture* UIElement::getTexture()
{
    return &mTexture;
}

void UIElement::setZIndex(int _zIndex)
{
    mTexture.setZindex(_zIndex);
}

void UIElement::free()
{
    mTexture.free();
}

Vector UIElement::getPosition() const
{
    return mPosition;
}
