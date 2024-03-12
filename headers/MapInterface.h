//Map Interface
#ifndef MAPINTERFACE_H
#define MAPINTERFACE_H

#include <string>
#include <vector>
#include "Items/Item.h"
class MapInterface{

    public:
        virtual ~MapInterface(){};
        virtual void readFile(const std::string &fileName)=0;
        virtual int importMapLevel() = 0;
        virtual std::string importWorldName() = 0;
        virtual std::string importWorldTier() = 0;
        virtual std::vector<Item*> &importItems() = 0;
        virtual std::vector<std::string> importCharacters() = 0;

};

#endif