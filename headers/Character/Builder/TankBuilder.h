#ifndef TANK_BUILDER_H
#define TANK_BUILDER_H

#include "CharacterBuilder.h"

class TankBuilder : public CharacterBuilder {
private:
    Character* character;
public:
    TankBuilder(const std::string& name, int level);
    void buildAbilityScores() override;
    void buildLevel(int level) override;
    Character* getCharacter() override;
    ~TankBuilder();
};

#endif
