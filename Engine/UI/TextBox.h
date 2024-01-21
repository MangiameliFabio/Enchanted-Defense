#pragma once

#include <SDL_ttf.h>
#include "UIElement.h"

class TextBox : public UIElement
{
public:
    //Initializes variables
    TextBox() = default;

    //Deallocates memory
    ~TextBox() override;

    void init(const std::string& _text, const SDL_Color& _textColor, int _fontSize = 24, int _zIndex = 500.f);
    
    void setColor(const SDL_Color& color);
    void setText(const std::string& text);

    //Loads image at specified path
    bool loadFromFile(const std::string& _path);
    
protected:
    SDL_Color mTextColor;
    std::string mText;

    TTF_Font* mFont;

    std::string path;

    //Image dimensions
    int mFontSize;
    bool mInitalized = false;

    //Creates image from font string
    bool loadFromRenderedText();
};
