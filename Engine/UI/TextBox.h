#pragma once

#include <SDL_blendmode.h>
#include <SDL_pixels.h>
#include <SDL_rect.h>
#include <SDL_render.h>
#include <SDL_ttf.h>
#include <string>
#include "../Core/Texture.h"

class TextBox
{
public:
    //Initializes variables
    TextBox();

    //Deallocates memory
    ~TextBox();

    void init(const std::string& _text, const SDL_Color* _textColor, int _fontSize = 24, int _zIndex = 500.f);

    //Loads image at specified path
    bool loadFromFile(const std::string& _path);

    //Creates image from font string
    bool loadFromRenderedText();

    //Set set index of texture
    void setZIndex(int _zIndex);
    void setPosition(const Vector& _pos);
    
    Texture* getTexture();
    void free();   


private:
    //The actual hardware texture
    Texture mTexture;
    SDL_Color mTextColor;
    std::string mText;

    TTF_Font* mFont;

    //Image dimensions
    int mFontSize;

    bool mInitalized = false;
};
