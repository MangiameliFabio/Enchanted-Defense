// ReSharper disable CppClangTidyBugproneNarrowingConversions
// ReSharper disable CppClangTidyClangDiagnosticImplicitIntFloatConversion

#include "Button.h"

#include <utility>

#include "../EngineSingelton.h"

void Button::init(const SDL_Color* buttonColor)
{
    ENGINE->addButton(this);

    if (buttonColor)
        mButtonColor = *buttonColor;
}

void Button::setButtonText(const std::string& text, const int fontSize)
{
    mButtonText = std::make_shared<TextBox>();
    mButtonText->init(text, &mButtonColor, fontSize);
    mButtonText->loadFromFile("assets/fonts/alagard.ttf");
    mButtonText->setPosition(getPosition().x + mTextOffset, getPosition().y + mTextOffset);

    updateDimension();
}

void Button::setCallback(std::function<void()> callback)
{
    mCallback = std::move(callback);
}

void Button::handleEvent(const SDL_Event* e) const
{
    //If mouse event happened
    if (e->type == SDL_MOUSEBUTTONDOWN)
    {
        //Get mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);

        //Mouse is left of the button
        if (x > getPosition().x
            && x < getPosition().x + mWidth
            && y > getPosition().y
            && y < getPosition().y + mHeight)
            mCallback();
    }
}

void Button::free()
{
    UIElement::free();
    
    ENGINE->removeButton(this);
    mButtonText->free();
}

void Button::updateDimension()
{
    mWidth = mButtonText->getTexture()->getWidth() + mTextOffset * 2;
    mHeight = mButtonText->getTexture()->getHeight() + mTextOffset * 2;
}

int Button::getWidth() const
{
    return mWidth;
}

int Button::getHeight() const
{
    return mHeight;
}

void Button::setPosition(float x, float y)
{
    UIElement::setPosition(x, y);

    mButtonText->setPosition(x,y);
}

void Button::setPosition(const Vector& pos)
{
    UIElement::setPosition(pos);

    mButtonText->setPosition(pos);
}
