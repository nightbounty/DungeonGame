#ifndef BULLY_BUILDER_H
#define BULLY_BUILDER_H

#include "CharacterBuilder.h"

class BullyBuilder : public CharacterBuilder {
private:
    Character* character;
public:
    BullyBuilder(const std::string& name, int level);
    void buildAbilityScores() override;
    void buildLevel(int level) override;
    Character* getCharacter() override;
    ~BullyBuilder();
};

#endif 