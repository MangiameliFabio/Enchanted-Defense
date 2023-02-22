#include "Texture.h"

#include <SDL_image.h>
#include <SDL_render.h>

#include "Singelton.h"

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
        newTexture = SDL_CreateTextureFromSurface(SINGLETON->gRenderer, loadedSurface);
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
    SINGLETON->gTextureContainer.push_back(this);

    return mTexture != nullptr;
}

void Texture::render(SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
    SDL_Rect renderQuad;
    if (dynamicX && dynamicY)
    {
        //Rendering for dynamic textures like the player or enemies

        //Convert float pos into int for rendering
        int tempX = static_cast<int>(*dynamicX);
        int tempY = static_cast<int>(*dynamicY);

        //Set rendering space and render to screen
        renderQuad = {tempX, tempY, mWidth, mHeight};
    }
    else
    {
        //Rendering for static textures like the background
        
        //Set rendering space and render to screen
        renderQuad = {staticX, staticY, mWidth, mHeight};
    }

    //Set clip rendering dimensions
    if (clip != nullptr)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //Render to screen
    SDL_RenderCopyEx(SINGLETON->gRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

void Texture::free()
{
    //Free texture if it exists
    if (mTexture != nullptr)
    {
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
        dynamicX = nullptr;
        dynamicY = nullptr;
        mWidth = 0;
        mHeight = 0;
        staticX = 0;
        staticY = 0;
    }
}

Texture::Texture()
{
}

Texture::~Texture()
{
    mTexture = nullptr;
    dynamicX = nullptr;
    dynamicY = nullptr;
}

void Texture::setDynamicX(float* x)
{
    this->dynamicX = x;
}

void Texture::setDynamicY(float* y)
{
    this->dynamicY = y;
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
