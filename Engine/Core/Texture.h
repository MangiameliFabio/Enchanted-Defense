#pragma once
#include <SDL_render.h>
#include <string>

#include "Vector.h"

class Texture
{
    void free();

public:
    bool loadTexture(std::string _path);
    void render(SDL_Rect* clip = nullptr, double angle = 0, SDL_Point* center = nullptr);

    void setWidth(int m_width);
    void setHeight(int m_height);
    int getWidth() const;
    int getHeight() const;

    //Create a reference to Object position
    void setDynamicX(float* x);
    void setDynamicY(float* y);

    void setDynamicPosition(Vector* v);

    Texture();
    ~Texture();
    SDL_RendererFlip flip = SDL_FLIP_NONE;

    int staticX = 0;
    int staticY = 0;

    bool markForRender = true;

private:
    SDL_Texture* mTexture;

    std::string path;

    int mWidth = 0;
    int mHeight = 0;

    //Dynamic positions for player and enemies
    float* dynamicX = nullptr;
    float* dynamicY = nullptr;
};
