#include "CharacterLogger.h"
#include <iostream>

void CharacterLogger::Update(const std::string& logEntry) {
    std::cout << "Character: " << logEntry << std::endl;
}