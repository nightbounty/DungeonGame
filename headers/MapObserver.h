#pragma once
#include "Map.h"

/**
 * @brief Abstract class containing a virtual update method
 * to indicate a Map Observer
 * 
 */
class MapObserver {
public:
    virtual void update(Map* map) = 0;
};