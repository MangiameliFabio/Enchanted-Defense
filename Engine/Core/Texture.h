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

    void setDynamicPosition(Vector* v);
    void setStaticPosition(const Vector& v);

    Vector getPosition();

    SDL_Texture* getSDLTexture();

    ~Texture();
    SDL_RendererFlip flip = SDL_FLIP_NONE;

    bool markForRender = true;

    SDL_Rect* clip = nullptr;

private:
    SDL_Texture* mTexture = nullptr;

    std::string path;

    int mWidth = 0;
    int mHeight = 0;

    //Dynamic positions for player and enemies. Safe the reference of a position instead of an actual value
    Vector* mDynamicPos = nullptr;

    //Static position if the texture won't move and therefore doesn't need to be updated
    Vector mStaticPos = {0,0};

    int zIndex = 0;
};
