#include "GameManagerLogger.h"
#include <iostream>

void GameManagerLogger::Update(const std::string& logEntry) {
    std::cout << "Game Controller: " << logEntry << std::endl;
}
