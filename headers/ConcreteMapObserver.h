#pragma once
#include "MapObserver.h"

class ConcreteMapObserver : public MapObserver {
public:
    void update(Map* map) override;
};