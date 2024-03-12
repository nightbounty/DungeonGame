#include <iostream>
#include "ConcreteMapObserver.h"

void ConcreteMapObserver::update(Map* map) {
    std::cout << "Updated Observer Map:\n";
    std::cout << map->ToString() << std::endl;
}