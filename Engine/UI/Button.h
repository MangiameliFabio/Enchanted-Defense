#pragma once
#include <functional>
#include <memory>
#include <SDL.h>

#include "StyledText.h"
#include "TextBox.h"
#include "../../Game/Styles.h"
#include "../Debuging/Log.h"

class SoundEffect;
class TextBox;

class Button : public UIElement
{
public:
    Button();
    ~Button() override;

    void init(const SDL_Color* buttonColor = nullptr);
    void init(const SDL_Color& buttonColor);

    void setButtonText(const std::string& text, int fontSize);
    void setCallback(std::function<void()> callback);
    //Handles mouse event
    virtual bool handleEvent(const SDL_Event* e);
    virtual void playButtonSound();
    void updateDimension();
    
    StyledText* getButtonText() const;
    
    int getWidth() const;
    int getHeight() const;
    void setPosition(float x, float y) override;
    void setPosition(const Vector& pos) override;

    bool enableHover = true;

private:
    //Text displayed in the button
    std::shared_ptr<StyledText> mButtonText = nullptr;
    
    SDL_Color mButtonColor = {0, 0, 0, 0};
    SDL_Color mHoverColor = HOVER_COLOR;

    std::function<void()> mCallback = nullptr;

    int mTextOffset = 4;
    int mWidth = 200;
    int mHeight = 200;

    bool mIsHovering = false;
};
