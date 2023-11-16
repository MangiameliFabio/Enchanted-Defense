#include "TextBox.h"

#include "../EngineSingelton.h"
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

    if (!mInitalized)
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

void TextBox::free()
{
    UIElement::free();
    
    TTF_CloseFont(mFont);
    getTexture()->free();

    mFont = nullptr;
    mInitalized = false;
}

bool TextBox::loadFromRenderedText()
{
    //Get rid of preexisting texture
    getTexture()->free();

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(mFont, mText.c_str(), mTextColor);
    if (textSurface == NULL)
    {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
        return false;
    }

    //Create texture from surface pixels
    if (!getTexture()->loadTexture(textSurface))
    {
        printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    //Return success
    return true;
}

void TextBox::setText(const std::string& text)
{
    mText = text;
    loadFromRenderedText();
}
