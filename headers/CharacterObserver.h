#ifndef CHARACTER_OBSERVER_H
#define CHARACTER_OBSERVER_H

#include "Character.h"

/**
 * Class CharacterObserver
 * Class that let's us display the updated view (stats)
 */
class CharacterObserver {
public:
    void update(Character* character);
};

#endif 
