#include "GameControllerLogger.h"
#include <iostream>

void GameControllerLogger::Update(const std::string& logEntry) {
    std::cout << "Game Controller: " << logEntry << std::endl;
}
