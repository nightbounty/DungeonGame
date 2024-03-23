#ifndef NIMBLE_BUILDER_H
#define NIMBLE_BUILDER_H

#include "CharacterBuilder.h"

class NimbleBuilder : public CharacterBuilder {
private:
    Character* character;
public:
    NimbleBuilder(const std::string& name, int level);
    void buildAbilityScores() override;
    void buildLevel(int level) override;
    Character* getCharacter() override;
    ~NimbleBuilder();
};

#endif
