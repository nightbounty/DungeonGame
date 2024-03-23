#pragma once
#include "GameLoggerObserver.h"

/**
 * @brief Observer class for the game log of Dice
 * 
 */
class DiceLogger : public GameLoggerObserver {
public:
    void Update(const std::string& logEntry) override;
};
