#ifndef GAME_LOGGER_SUBJECT_H
#define GAME_LOGGER_SUBJECT_H

#include <vector>
#include <string>
#include "GameLoggerObserver.h"

/**
 * @brief Interface defining the operations for attaching and 
 * de-attaching observers
 * 
 */
class GameLoggerSubject {
public:
    void Attach(GameLoggerObserver* observer);
    void Detach(GameLoggerObserver* observer);
    void Notify(const std::string& logEntry);

private:
    std::vector<GameLoggerObserver*> observers;
};

#endif