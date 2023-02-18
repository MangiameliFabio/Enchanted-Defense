#pragma once
#include <SDL_render.h>
#include <string>

class Texture
{
    void free();

public:
    bool loadTexture(std::string _path);
    void render(SDL_Rect* clip = nullptr, double angle = 0, SDL_Point* center = nullptr,
                SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    void setWidth(int m_width);
    void setHeight(int m_height);
    int getWidth() const;
    int getHeight() const;
    
    Texture();
    ~Texture();

    int x = 0;
    int y = 0;

private:
    SDL_Texture* mTexture;

    std::string path;

    int mWidth = 0;
    int mHeight = 0;
};
