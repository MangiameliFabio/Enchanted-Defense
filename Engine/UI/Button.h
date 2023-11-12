#pragma once
#include <functional>
#include <SDL_events.h>

#include "TextBox.h"
#include "../Debuging/Log.h"

class TextBox;

class Button : public UIElement
{
public:
    ~Button();

    void init(const SDL_Color* buttonColor = nullptr);
    void setButtonText(const std::string& text, int fontSize);
    void setCallback(std::function<void()> callback);
    //Handles mouse event
    void handleEvent(const SDL_Event* e) const;
    void free() override;
    void updateDimension();
    
    int getWidth() const;
    int getHeight() const;
    void setPosition(float x, float y) override;
    void setPosition(const Vector& pos) override;

private:
    //Text displayed in the button
    TextBox mButtonText;
    SDL_Color mButtonColor = {0, 0, 0, 0};

    std::function<void()> mCallback = nullptr;

    int mTextOffset = 4;
    
    int mWidth = 200;

private:
    int mHeight = 200;
};
