#include "ItemCreation.h"
#include <random>

ItemCreation::ItemCreation() {};

std::vector<Item*> ItemCreation::startingChestItems() {
	std::cout << "Would you like to create a set of Starting Items for Chest Loot or \n" <<
		"load a random set?" << std::endl;
	std::cout << "Press 1 load or 2 to create your own set" << std::endl;

	int choice;
	std::cin >> choice;

	if (choice == 1) {
		//chest->setChestLoot(chestLoot);
		std::cout << "You chose to load a random set !" << std::endl;
		std::cout << "Random set of items have been added to Chest !";
		return chestLoot;
	}
	else if (choice == 2) {
		std::cout << "Enter which items you'd like your chest to have. Enter items in lower case and input a space after each. \n" <<
			"Options: shield, bow, armor, belt, boots, helmet and ring \n ";
		std::string line;
		std::getline(std::cin >> std::ws, line); // Read the entire line; std::ws to consume any leading whitespace

		std::istringstream iss(line);
		std::string itemInput;

		// Read user Input
		while (iss >> itemInput) { 
			Item* newItem = createItem(itemInput);
			if (newItem != nullptr) {
				item.push_back(newItem); // Add the created item to the vector
			}
			else {
				std::cout << "Invalid item name: " << itemInput << std::endl;
			}
		}
		std::cout << "Your chosen items have been added to the chest !" << std::endl;
		chestLoot = item;
		return chestLoot;
	}
	return chestLoot;
}


 // HERE
void ItemCreation::startingUserItems() {
	 std::cout << "Would you like to create a set of Starting Items To Use In Game or \n" <<
		 " Choose From Loaded Set?" << std::endl;
	 std::cout << "Press 1 load or 2 to create your own set" << std::endl;

	 std::ofstream outFile("UserChoiceItems.txt");
	 int choice;
	 std::cin >> choice;


	 if (choice == 1) {
		 
		 std::cout << "You chose to load a set of Items ! Press 1 or 2 " << std::endl;
		 std::cout << "1: Item Set 1 or \n " << "2: Item Set 2 \n";

		 int choice2;
		 std::cin >> choice2;
		 if (choice2 == 1) {
			 loadItemsFromFile("ItemSet1.txt");
		 }
		 else if (choice2 == 2) {
			 loadItemsFromFile("ItemSet2.txt");
		 }
	 }
	 else if (choice == 2) {
		 std::cout << "Enter which items you'd like your chest to have. Enter items in lower case and input a space after each. \n" <<
			 "Options: shield, bow, armor, belt, boots, helmet, sword, bow and ring \n ";
		 std::string line;
		 std::getline(std::cin >> std::ws, line); // Read the entire line and remove spaces

		 std::istringstream iss(line);
		 std::string itemInput;

		 while (iss >> itemInput) {
			
			 outFile << itemInput << std::endl;
			 std::cout << "Added " << itemInput << " to the file.\n";
		 }
		 std::cout << "\nYour Items Have been save to " << "UserChoiceItems.txt !" << std::endl;
		 loadItemsFromFile("UserChoiceItems.txt");

		 // Read user Input
		 //while (iss >> itemInput) {
			// Item* newItem = createItem(itemInput);
			// if (newItem != nullptr) {
			//	 item.push_back(newItem); // Add the created item to the vector
			// }
			// else {
			//	 std::cout << "Invalid item name: " << itemInput << std::endl;
			// }
		 //}
		 

	 }

 }
 std::string ItemCreation::toLower(const std::string& str) {
	 std::string lowerStr = str;
	 std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
		 [](unsigned char c) { return std::tolower(c); });
	 return lowerStr;
 }

Item* ItemCreation::createItem(const std::string& itemName) {
	std::string lowerCaseItem = toLower(itemName);

	if (lowerCaseItem.find("shield") != std::string::npos) {
		return new Shield(itemName);
	}
	else if (lowerCaseItem.find("bow") != std::string::npos) {
		return new Weapon(lowerCaseItem, "1d8", 5); // Example parameters
	}
	else if (lowerCaseItem.find("sword") != std::string::npos) {
		return new Weapon(lowerCaseItem, "1d8", 2); // Example parameters
	}
	else if (lowerCaseItem.find("armor") != std::string::npos) {
		return new Armor(lowerCaseItem);
	}
	else if (lowerCaseItem.find("belt") != std::string::npos) {
		return new Belt(lowerCaseItem);
	}
	else if (lowerCaseItem.find("boots") != std::string::npos) {
		return new Boots(itemName);
	}
	else if (lowerCaseItem.find("helmet") != std::string::npos) {
		return new Helmet(itemName);
	}
	else if (lowerCaseItem.find("ring") != std::string::npos) {
		return new Ring(itemName);
	}

	return nullptr;
}

void ItemCreation::saveChestLootToFile(const std::string& filename) {
	std::ofstream outFile(filename);

	if (!outFile) {
		std::cerr << "File not not found: " << filename << std::endl;
		return;
	}

	for (Item* item : chestLoot) {
		if (item != nullptr) {
			outFile << item->getName() << std::endl;
		}
	}

	outFile.close();
	std::cout << "Chest loot was saved to " << filename << std::endl;
}

void ItemCreation::readChestLootFromFile(const std::string& filename) {
	std::vector<Item*> items;
	std::ifstream inFile(filename);

	if (!inFile.is_open()) {
		std::cerr << "Text File not Found: " << filename << std::endl;

	}

	std::string itemName;
	while (std::getline(inFile, itemName)) {
		Item* newItem = createItem(itemName);
		if (newItem != nullptr) {
			item.push_back(newItem); // Add the created item to the vector
		}
		else {
			std::cout << "Invalid item name: " << itemName << std::endl;
		}
	}
	std::cout << "The Items have been loaded into chest!" << std::endl;

	inFile.close();

}

std::vector<Item*> ItemCreation::loadItemsFromFile(const std::string& filename) {
	std::ifstream inFile(filename);

	if (!inFile.is_open()) {
		std::cerr << "Text File not Found: " << filename << std::endl;
		return item;
	}

	std::string itemName;
	std::cout << " \nYour Chosen Items Are The Following! : \n";
	while (std::getline(inFile, itemName)) {
		Item* newItem = createItem(itemName);
		if (newItem != nullptr) {
			userItemChoice.push_back(newItem); // Add the created item to the vector
			
			std::cout << newItem->getName() << "\n";
		}
		else {
			std::cout << "Invalid item name: " << itemName << std::endl;
		}
	}
	
	std::cout << "\nYou Chose To Have Items From " << filename << " Loaded Into The World!!" << std::endl;

	inFile.close();
	return userItemChoice;
}

std::vector<Item*> ItemCreation::getUserItemChoice() {
	return userItemChoice;
}