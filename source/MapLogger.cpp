#include "MapLogger.h"
#include <iostream>

void MapLogger::Update(const std::string& logEntry) {
    std::cout << "Map: " << logEntry << std::endl;
}
