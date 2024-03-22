#pragma once
#include "GameLoggerObserver.h"

/**
 * @brief Observer class for the game log of GameController
 * 
 */
class GameControllerLogger : public GameLoggerObserver {
public:
    void Update(const std::string& logEntry) override;
};
