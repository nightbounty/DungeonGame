#include "../../../headers/Character/Builder/BullyBuilder.h"
#include "../../../headers/Dice.h"
#include <vector>
#include <algorithm>

BullyBuilder::BullyBuilder(const std::string& name, int level) {
    this->character = new Character(name, level, "Bully");
}

void BullyBuilder::buildAbilityScores() {
    std::vector<int> scores(6, 0);
    for (int & score : scores) {
        std::vector<int> rolls(4);
        for (int & roll : rolls) {
            roll = Dice::rollDice("1d6");
        }
        std::sort(rolls.begin(), rolls.end(), std::greater<int>());
        score = rolls[0] + rolls[1] + rolls[2];
    }
    // Bully prioritizes STR and CON
    std::sort(scores.begin(), scores.end(), std::greater<int>());
    character->abilityScores = {scores[0], scores[2], scores[1], scores[3], scores[5], scores[4]};
}

void BullyBuilder::buildLevel(int level) {
    this->character->level = level;
}

Character* BullyBuilder::getCharacter() { return this->character; }

BullyBuilder::~BullyBuilder() { delete character; }
