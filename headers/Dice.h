#ifndef DICE_H
#define DICE_H

#include <string>

/**
 * Dice class which only has one functionality which is to roll.
*/
class Dice {
    public: 
        static int rollDice(const std::string& diceInput);
        
};

#endif