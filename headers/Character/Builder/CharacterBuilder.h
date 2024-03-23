#ifndef CHARACTER_BUILDER_H
#define CHARACTER_BUILDER_H

#include "../Character.h"

// The Builder Interface
class CharacterBuilder {
public:
    virtual void buildAbilityScores() = 0;
    virtual void buildLevel(int level) = 0;
    virtual Character* getCharacter() = 0;
    virtual ~CharacterBuilder() {}
};

#endif 