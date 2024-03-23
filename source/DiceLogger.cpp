#include "DiceLogger.h"
#include <iostream>

void DiceLogger::Update(const std::string& logEntry) {
    std::cout << "Dice: " << logEntry << std::endl;
}