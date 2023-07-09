#pragma once
#include <SDL_render.h>
#include <string>

#include "Vector.h"

class Texture
{
public:
    void free();

    bool loadTexture(std::string _path);
    bool loadTexture(SDL_Surface* textureSurface);
    void render(double angle = 0, SDL_Point* center = nullptr);

    void setWidth(int m_width);
    void setHeight(int m_height);
    int getWidth() const;
    int getHeight() const;
    
    int getZindex() const;
    void setZindex(int _zIndex);

    //Create a reference to Object position
    void setDynamicX(float* x);
    void setDynamicY(float* y);

    void setDynamicPosition(Vector* v);

    Texture();
    ~Texture();
    SDL_RendererFlip flip = SDL_FLIP_NONE;

    float staticX = 0;
    float staticY = 0;

    bool markForRender = true;

    SDL_Rect* clip = nullptr;

private:
    SDL_Texture* mTexture;

    std::string path;

    int mWidth = 0;
    int mHeight = 0;

    //Dynamic positions for player and enemies
    float* dynamicX = nullptr;
    float* dynamicY = nullptr;

    int zIndex = 0;
};
