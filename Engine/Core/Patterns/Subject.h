#pragma once

#include <vector>
#include "Observer.h"

class Subject
{
    std::vector<Observer*> observers;
    int numObservers = 0;

public:
    void addObserver(Observer* observer)
    {
        observers.push_back(observer);
        numObservers++;
    }

    void removeObserver(Observer* observer)
    {
        //Find observer in vector
        const auto position = std::find(observers.begin(), observers.end(), observer);

        //Remove Observer
        if (position != observers.end())
            observers.erase(position);
        numObservers--;
    }

    void notify(Event event)
    {
        for (int i = 0; i < numObservers; ++i)
        {
            observers[i]->onNotify(event);
        }
    }
};
