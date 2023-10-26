#include "TextBox.h"

#include "../EngineSingelton.h"

TextBox::TextBox()
{
}

TextBox::~TextBox()
{
    TTF_CloseFont(mFont);
    mFont = NULL;
    mTexture.~Texture();
}

void TextBox::init(const std::string& _text, const SDL_Color* _textColor, int _fontSize, int _zIndex)
{
    mInitalized = true;
    mText = _text;
    mTextColor = *_textColor;
    mFontSize = _fontSize;
    setZIndex(_zIndex);
}

bool TextBox::loadFromFile(const std::string& path)
{
    //Loading success flag
    bool success = true;

    if(!mInitalized)
    {
        printf("Text box was not initialized. Abort!\n");
        return false;
    }

    //Open the font
    mFont = TTF_OpenFont(path.c_str(), mFontSize);
    if (mFont == NULL)
    {
        printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
        success = false;
    }
    else
    {
        if (!loadFromRenderedText())
        {
            printf("Failed to render text texture!\n");
            success = false;
        }
    }

    return success;
}

bool TextBox::loadFromRenderedText()
{
    //Get rid of preexisting texture
    mTexture.free();

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(mFont, mText.c_str(), mTextColor);
    if (textSurface == NULL)
    {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
        return false;
    }

    //Create texture from surface pixels
    if (!mTexture.loadTexture(textSurface))
    {
        printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    //Return success
    return true;
}

void TextBox::setZIndex(const int _zIndex)
{
    mTexture.setZindex(_zIndex);
}

void TextBox::setPosition(const Vector& _pos)
{
    mTexture.staticX = _pos.x;
    mTexture.staticY = _pos.y;
}

Texture* TextBox::getTexture()
{
    return &mTexture;
}
