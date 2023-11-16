#pragma once
#include "../Core/Texture.h"
#include "../Core/Vector.h"

class UIElement
{
public:
    virtual ~UIElement();
    
    //Sets top left position
    virtual void setPosition(float x, float y);
    virtual void setPosition(const Vector& pos);
    Vector getPosition() const;

    Texture* getTexture();

    //Set set index of texture
    void setZIndex(int _zIndex);
    virtual void free();


private:
    //Top left position
    Vector mPosition = {0, 0};
    
    //The actual hardware texture
    Texture mTexture;
};
