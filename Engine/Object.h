#pragma once

class Object
{
    void (Object::*updatePointer)() = nullptr;
    
public:
    virtual ~Object() = default;
    Object();
    virtual void start();
    virtual void update();
    virtual void close();
};

