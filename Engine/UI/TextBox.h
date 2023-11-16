#pragma once

#include <SDL_blendmode.h>
#include <SDL_pixels.h>
#include <SDL_rect.h>
#include <SDL_render.h>
#include <SDL_ttf.h>
#include <string>

#include "UIElement.h"
#include "../Core/Texture.h"

class TextBox : public UIElement
{
public:
    //Initializes variables
    TextBox() = default;

    //Deallocates memory
    ~TextBox() override = default;

    void init(const std::string& _text, const SDL_Color* _textColor, int _fontSize = 24, int _zIndex = 500.f);
    
    void setText(const std::string& text);

    //Loads image at specified path
    bool loadFromFile(const std::string& _path);
    
    void free() override;


private:
    SDL_Color mTextColor;
    std::string mText;

    TTF_Font* mFont;

    //Image dimensions
    int mFontSize;
    bool mInitalized = false;

    //Creates image from font string
    bool loadFromRenderedText();
};
