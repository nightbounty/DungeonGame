#include "../headers/Character/CharacterObserver.h"
#include <iostream>

/**
 * Update the player view (stats)
 */

void CharacterObserver::update(Character* character) {
    
    if (character) {
        cout << "\n*** Character Update ***\n";
        character->displayStats();
    }
}
