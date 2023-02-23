#pragma once

class Object
{
public:
    bool shouldUpdate = true;
    
    virtual void start();
    virtual void update();
    virtual void close();
    
    Object();
    virtual ~Object();
};

