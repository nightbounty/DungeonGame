#include "MapBuilder2.h"
// empty constructor
MapBuilder2::MapBuilder2() {
}
     // Create a Map Object
     Map2 map2;

        void MapBuilder2::readFile(const std::string &fileName){
            std::ifstream file(fileName); //reads file and creates an instance of ifstream
            if(!file.is_open()){
               std::cout << "File can't open" << std::endl;
               return;
            }
            std::string fileLine;
            while(std::getline(file, fileLine)){
               mapFileCopy.push_back(fileLine);
            }
        }

         int MapBuilder2::importMapLevel(){
            for(std::string line : mapFileCopy){
               if(line.find("Map Level:") == 0){
                  std::string stringMapLvl = line.substr(10);
                  int tempMapLevel = std::stoi(stringMapLvl); //stoi: convert to an int
                  return tempMapLevel;
               }
            }
            return -1;
            // std::cout << "testing to reach here" << std::endl;
         }


          std::string MapBuilder2::importWorldName(){
            for(std::string line : mapFileCopy){
               if(line.find("World Name:") == 0){
                  std::string worldName = line.substr(12);
                  return worldName;
               }
            
            }
             return "Nothing";
         }
          std::string MapBuilder2::importWorldTier(){
            for(std::string line : mapFileCopy){
               if(line.find("World Tier:") == 0){
                  std::string worldTier = line.substr(12);
                  return worldTier;
               }
            }
            return "Nothing";
         }
         std::vector<Item*>& MapBuilder2::importItems(){
            for(std::string line : mapFileCopy){
               if(line.find("Item:") == 0){
                  std::string item = line.substr(6);
                  ItemSub* itemObject = new ItemSub(item);
                  tempItems.push_back(itemObject);
               }
            }
            return tempItems;
         }

         std::vector<std::string> MapBuilder2::importCharacters(){
            for(std::string line : mapFileCopy){
               if(line.find("Character:") == 0){
                  std::string character = line.substr(11);
                  tempChars.push_back(character);
               }
            }
            return tempChars;
         }
         void MapBuilder2::tier1map(){
                map2.setWorldTier(importWorldTier());
                map2.setCharacterTier("Tier 1");
                map2.setItemTier("Common");
                map2.displayMapContents();
            }

            void MapBuilder2::tier2map(){
                map2.setWorldTier(importWorldTier());
                map2.setCharacterTier("Tier 2");
                map2.setItemTier("Uncommon");
                map2.displayMapContents();
            }

            void MapBuilder2::tier3map(){
                map2.setWorldTier(importWorldTier());
                map2.setCharacterTier("Tier 3");
                map2.setItemTier("Rare");
                map2.displayMapContents();
            }

            void MapBuilder2::tier4map(){
                map2.setWorldTier(importWorldTier());
                map2.setCharacterTier("Tier 4");
                map2.setItemTier("Very Rare");
                map2.displayMapContents();
            }

         void MapBuilder2::createMap(){
            {
                 std::cout << map2.getWorldTier() << std::endl;
               if(importWorldTier() == "Beginner"){
                    tier1map();
               }
               if(importWorldTier() == "Intermediate"){
                    tier2map();
               }
               if(importWorldTier() == "Hard"){
                    tier3map();
               }
               if(importWorldTier() == "Advanced"){
                    tier4map();
               }
                    
                 
            }
         }

            
               
