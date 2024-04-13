#include "Character/CharacterCreator.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

Character* CharacterCreator::LoadCharacter()
{
    std::ifstream file(".\\source\\Character\\SavedChars.txt");
    if (!file.is_open()) {
        std::cout << "Failed to open file for reading.\n";
        return nullptr;
    }

    std::vector<std::string> characters;
    std::string line;
    std::cout << "Available characters:\n";

    int index = 1;
    while (getline(file, line)) {
        characters.push_back(line);

        // Splitting the line into name, level, and class
        std::istringstream iss(line);
        std::string name, cls;
        int lvl;
        iss >> name >> lvl >> cls;

        // Outputting with labels
        std::cout << index++ << ". Name: " << name << ", Level: " << lvl << ", Class: " << cls << "\n";
    }
    file.close();


    if (characters.empty()) {
        std::cout << "No characters available.\n";
        return nullptr;
    }

    std::cout << "Select a character by number: ";
    int choice;
    std::cin >> choice;

    if (choice < 1 || choice > characters.size()) {
        std::cout << "Invalid choice.\n";
        return nullptr;
    }

    std::stringstream ss(characters[choice - 1]);
    std::string name, cls;
    int lvl;
    ss >> name >> lvl >> cls;

    Character* newCharacter = new Character(name, new Vector2(0, 0), new HumanPlayerStrategy(), lvl, cls);
    std::cout << "You have selected: " << name << "\n";
    newCharacter->DisplayStats();

    return newCharacter;
}

Character* CharacterCreator::CreateCharacter()
{
    Character* newCharacter;

    string name;
    string cls;
    int classChoice;
    int lvl = 1; // Starting level, adjust as needed

    cout << "Let's create your character for the game!\n\n";
    cout << "Enter character's name: ";
    cin >> name;
    cout << "\nChoose a class:\n";
    cout << "1. Bully\n";
    cout << "2. Nimble\n";
    cout << "3. Tank\n";
    cout << "Enter choice (1-3): ";
    cin >> classChoice;

    switch (classChoice) {
    case 1:
        cls = "Bully";
        break;
    case 2:
        cls = "Nimble";
        break;
    case 3:
        cls = "Tank";
        break;
    default:
        std::cout << "Invalid choice. Defaulting to Bully.\n";
        cls = "Bully";
    }
    newCharacter = new Character(name, new Vector2(0, 0), new HumanPlayerStrategy(), lvl, cls);
    std::cout << "\nCharacter Creation COMPLETED!\n";

    // Writing character to file
    std::ofstream outFile(".\\source\\Character\\SavedChars.txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << name << " " << lvl << " " << cls << std::endl;
        std::cout << "Character saved to file successfully!\n";
        outFile.close();
    }
    else {
        std::cout << "Failed to open file for writing.\n";
    }

    newCharacter->DisplayStats();
    return newCharacter;
}

Weapon* CharacterCreator::SelectWeapon(Character* c)
{
    Weapon* newWeapon;

    cout << "\nWhat weapon would you like to start with?\n";
    cout << "Press 1 for a bow, or 2 for a sword:";
    int weaponChoice;
    cin >> weaponChoice;
    switch (weaponChoice) {
    case 1:
        newWeapon = new Weapon("Bow", "1d8", 5);
        break;
    case 2:
        newWeapon = new Weapon("Sword", "1d12", 2);
        break;
    default:
        newWeapon = new Weapon("Sword", "1d12", 2);
        break;
    }

    c->AddToInventory(newWeapon);
    Item* item = c->takeItem(newWeapon->getName());
    c->equipItem(item);
    c->displayEquippedItems();

    std::cout << "\nYou have sucessfully equipped your weapon!\n";
    return newWeapon;
}
