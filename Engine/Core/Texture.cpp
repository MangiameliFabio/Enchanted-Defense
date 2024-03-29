﻿#include "Texture.h"

#include <SDL_image.h>
#include "..\EngineSingelton.h"

bool Texture::loadTexture(std::string _path)
{
    //Get rid of preexisting texture
    free();
    path = std::move(_path);

    //The final texture
    SDL_Texture* newTexture = nullptr;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());

    if (loadedSurface == nullptr)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        //Color key image
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(ENGINE->gSDL_Renderer, loadedSurface);
        if (newTexture == nullptr)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        else
        {
            //Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    //Return success
    mTexture = newTexture;
    ENGINE->gRenderer->addTexture(this);

    return mTexture != nullptr;
}

bool Texture::loadTexture(SDL_Surface* textureSurface)
{
    //Get rid of preexisting texture
    free();

    //The final texture
    SDL_Texture* newTexture = nullptr;

    if (textureSurface == nullptr)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(ENGINE->gSDL_Renderer, textureSurface);
        if (newTexture == nullptr)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        else
        {
            //Get image dimensions
            mWidth = textureSurface->w;
            mHeight = textureSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(textureSurface);
    }

    //Return success
    mTexture = newTexture;
    ENGINE->gRenderer->addTexture(this);

    return mTexture != nullptr;
}

void Texture::render(double angle, SDL_Point* center)
{
    SDL_Rect renderQuad;
    if (mDynamicPos)
    {
        //Rendering for dynamic textures like the player or enemies

        //Convert float pos into int for rendering
        int tempX = static_cast<int>(mDynamicPos->x);
        int tempY = static_cast<int>(mDynamicPos->y);

        //Center Texture in the middle of the Object
        tempX = tempX - getWidth() / 2;
        tempY = tempY - getHeight() / 2;

        //Set rendering space and render to screen
        renderQuad = {tempX, tempY, mWidth, mHeight};
    }
    else
    {
        //Rendering for static textures like the background

        //Set rendering space and render to screen
        renderQuad = {static_cast<int>(mStaticPos.x), static_cast<int>(mStaticPos.y), mWidth, mHeight};
    }

    //Set clip rendering dimensions
    if (clip != nullptr)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //Render to screen
    SDL_RenderCopyEx(ENGINE->gSDL_Renderer, mTexture, clip, &renderQuad, angle, center, flip);
}

void Texture::free()
{
    //Free texture if it exists
    if (mTexture != nullptr)
    {
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
        mDynamicPos = nullptr;
        mWidth = 0;
        mHeight = 0;
        mStaticPos = {0, 0};
        ENGINE->gRenderer->removeTexture(this);
    }
}

Texture::~Texture()
{
    free();
}

int Texture::getZindex() const
{
    return zIndex;
}

void Texture::setZindex(int _zIndex)
{
    zIndex = _zIndex;
}

void Texture::setDynamicPosition(Vector* v)
{
    mDynamicPos = v;
}

void Texture::setStaticPosition(const Vector& v)
{
    mStaticPos = v;
}

Vector Texture::getPosition()
{
    if(mDynamicPos)
    {
        return *mDynamicPos;
    }

    return mStaticPos;
}

SDL_Texture* Texture::getSDLTexture()
{
    return mTexture;
}

int Texture::getWidth() const
{
    return mWidth;
}

int Texture::getHeight() const
{
    return mHeight;
}

void Texture::setWidth(int m_width)
{
    mWidth = m_width;
}

void Texture::setHeight(int m_height)
{
    mHeight = m_height;
}
