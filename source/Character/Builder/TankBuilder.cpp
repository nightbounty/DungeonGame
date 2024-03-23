#include "../../../headers/Character/Builder/TankBuilder.h"
#include "../../../headers/Dice.h"
#include <vector>
#include <algorithm>
#include "Strategies/HumanPlayerStrategy.h"

TankBuilder::TankBuilder(const std::string& name, int level) {
    this->character = new Character(name, new Vector2(0, 0), new HumanPlayerStrategy(), level, "Tank");
}

void TankBuilder::buildAbilityScores() {
    std::vector<int> scores(6, 0);
    for (int & score : scores) {
        std::vector<int> rolls(4);
        for (int & roll : rolls) {
            roll = Dice::rollDice("1d6");
        }
        std::sort(rolls.begin(), rolls.end(), std::greater<int>());
        score = rolls[0] + rolls[1] + rolls[2];
    }
    // Tank prioritizes CON, then STR and DEX
    std::sort(scores.begin(), scores.end(), std::greater<int>());
    character->abilityScores = {scores[1], scores[2], scores[0], scores[3], scores[5], scores[4]};
}

void TankBuilder::buildLevel(int level) {
    this->character->level = level;
}

Character* TankBuilder::getCharacter() { return this->character; }

TankBuilder::~TankBuilder() { delete character; }
