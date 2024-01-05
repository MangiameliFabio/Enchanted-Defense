// ReSharper disable CppClangTidyBugproneNarrowingConversions
// ReSharper disable CppClangTidyClangDiagnosticImplicitIntFloatConversion

#include "Button.h"

#include <memory>
#include <memory>
#include <utility>

#include "../EngineSingelton.h"
#include "../Core/SoundEffect.h"
#include "../Core/Soundtrack.h"

Button::Button()
{
    mButtonText = std::make_shared<StyledText>();
}

Button::~Button()
{
    ENGINE->removeButton(this);
    mCallback = nullptr;
}

void Button::init(const SDL_Color* buttonColor)
{
    ENGINE->addButton(this);

    if (buttonColor)
        mButtonColor = *buttonColor;
}

void Button::init(const SDL_Color& buttonColor)
{
    ENGINE->addButton(this);

    clickSound = std::make_shared<SoundEffect>();
    clickSound->init("assets/sounds/effects/button_click.wav", 30);
    
    mButtonColor = buttonColor;
}

void Button::setButtonText(const std::string& text, const int fontSize)
{
    mButtonText->init(text, mButtonColor, fontSize);
    mButtonText->loadFromFile("assets/fonts/alagard.ttf");
    mButtonText->setPosition(getPosition().x + mTextOffset, getPosition().y + mTextOffset);

    updateDimension();
}

void Button::setCallback(std::function<void()> callback)
{
    mCallback = std::move(callback);
}

bool Button::handleEvent(const SDL_Event* e) const
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
        {
            clickSound->play();
            mCallback();
            return true;
        }
    }
    return false;
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

StyledText* Button::getButtonText() const
{
    return mButtonText.get();
}
