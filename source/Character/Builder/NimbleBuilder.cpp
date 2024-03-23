#include "../../../headers/Character/Builder/NimbleBuilder.h"
#include "../../../headers/Dice.h"
#include <vector>
#include <algorithm>
#include "Strategies/HumanPlayerStrategy.h"

NimbleBuilder::NimbleBuilder(const std::string& name, int level) {
    this->character = new Character(name, new Vector2(0, 0), new HumanPlayerStrategy(), level, "Nimble");
}

void NimbleBuilder::buildAbilityScores() {
    std::vector<int> scores(6, 0);
    for (int & score : scores) {
        std::vector<int> rolls(4);
        for (int & roll : rolls) {
            roll = Dice::rollDice("1d6");
        }
        std::sort(rolls.begin(), rolls.end(), std::greater<int>());
        score = rolls[0] + rolls[1] + rolls[2];
    }
    // Nimble prioritizes DEX, then STR and CON
    std::sort(scores.begin(), scores.end(), std::greater<int>());
    character->abilityScores = {scores[2], scores[0], scores[1], scores[3], scores[5], scores[4]};
}

void NimbleBuilder::buildLevel(int level) {
    this->character->level = level;
}

Character* NimbleBuilder::getCharacter() { return this->character; }

NimbleBuilder::~NimbleBuilder() { delete character; }
