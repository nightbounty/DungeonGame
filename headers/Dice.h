#ifndef DICE_H
#define DICE_H

#include <string>
#include "GameLoggerSubject.h"

/**
 * Dice class which only has one functionality which is to roll.
*/
class Dice : public GameLoggerSubject {
    public: 
        static int rollDice(const std::string& diceInput);
        void LogEvent(const std::string& event); // Game log related function
        
    private:
        std::string logEntry; // Game Log related member
	    void NotifyObservers(); // Game Log related private function
};

#endif