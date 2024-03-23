#ifndef CHARACTER_FACTORY_H
#define CHARACTER_FACTORY_H

#include "Builder/CharacterBuilder.h" 
#include "Builder/BullyBuilder.h" 
#include "Builder/NimbleBuilder.h"
#include "Builder/TankBuilder.h"     
#include "Character.h"       

class CharacterFactory {
public:
    static Character* createCharacter(const std::string& name, int level, const std::string& characterClass);
};

#endif 
