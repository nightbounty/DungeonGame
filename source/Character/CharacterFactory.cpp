#include "../../headers/Character/CharacterFactory.h"

Character* CharacterFactory::createCharacter(const std::string& name, int level, const std::string& characterClass) {
    CharacterBuilder* builder;

    if (characterClass == "Bully") {
        builder = new BullyBuilder(name, level);
    } 
    
    else if (characterClass == "Nimble") {
         builder = new NimbleBuilder(name,level);
     } else if (characterClass == "Tank") {
         builder = new TankBuilder(name,level);
     } else {
        builder = new TankBuilder(name,level);
    }

    builder->buildLevel(level);
    builder->buildAbilityScores();
    Character* character = builder->getCharacter();

    delete builder; // Clean up the builder
    return character;
}
