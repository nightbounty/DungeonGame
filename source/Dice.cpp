#include "../headers/Dice.h"
#include <iostream>
#include <regex>
#include <random>

/**
 * The implementation of the dice being rolled.
 * The function takes as input the string as a pattern from the user.
 * This will validate the pattern if it is correct which is in the form of xdy[+z]
 * and based on that, it will randomly roll the dice and adds the result. The z in 
 * here is optional, so if present, the total from the rolled dice will be added with the z.
*/
int Dice::rollDice(const std::string& diceInput) {
    std::string validPattern = "([0-9]+)d([0-9]+)([+]?[0-9]+)?";
    std::regex pattern(validPattern);
    std::smatch match;
    
    if(std::regex_match(diceInput, match, pattern)) {
        // xdy[+z] is the pattern of the input dice
        int x = std::stoi(match[1]);
        int y = std::stoi(match[2]);
        // since z is optional, it is default to 0
        int z = match[3].length() > 0 ? std::stoi(match[3]) : 0;

        // Randomly roll dice
        std::random_device randomDevice;
        std::mt19937 gen(randomDevice());
        std::uniform_int_distribution<int> produceRandomInt(1, y);
        int total = 0;
        for (int i = 0; i < x; ++i) {
            total += produceRandomInt(gen);
        }

        return total+z;
    } else {
        std::cerr << "Invalid dice input format of the following pattern: xdy[+z]" << std::endl;
        return 0;
    }
}