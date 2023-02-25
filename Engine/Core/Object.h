#pragma once

class Object
{
public:
    bool shouldUpdate = true;
    bool queuedForDelete = false;
    
    virtual void start();
    virtual void update();
    virtual void close();
    
    Object();
    virtual ~Object();
};

