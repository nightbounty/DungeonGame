#ifndef GAME_LOGGER_OBSERVER_H
#define GAME_LOGGER_OBSERVER_H

#include <string>

/**
 * @brief Observer abstract class for the Game Logger
 * to be used to notify Observer
 * 
 */
class GameLoggerObserver {
public:
    virtual void Update(const std::string& logEntry) = 0;
};

#endif 
