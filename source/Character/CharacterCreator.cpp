#include "Character/CharacterCreator.h"

Character* CharacterCreator::LoadCharacter()
{
    std::cout << "Here are a set of character that you can choose:\n";
    std::cout << "1. Brick Malone, The Bully: Brick, with his intimidating presence, rules the back alleys, using brute force to get his way.\n";
    std::cout << "2. Lila Vale, The Nimble: Silent and swift, Lila strikes from the shadows, always one step ahead.\n";
    std::cout << "3. Garrick Thorvald, The Tank: An armored fortress, Garrick stands tall, unfazed by the chaos of battle.\n";
    std::cout << "Which one would you like to use? (1-3)\n";

    int choice;
    std::cin >> choice;

    Character* newCharacter;

    switch (choice) {
    case 1:
        newCharacter = new Character("Brick Malone", new Vector2(0, 0), new HumanPlayerStrategy(), 3, "Bully");
        break;
    case 2:
        newCharacter = new Character("Lila Vale", new Vector2(0, 0), new HumanPlayerStrategy(), 3, "Nimble");
        break;
    case 3:
        newCharacter = new Character("Garrick Thorvald", new Vector2(0, 0), new HumanPlayerStrategy(), 3, "Tank");
        break;
    default:
        newCharacter = new Character("Brick Malone", new Vector2(0, 0), new HumanPlayerStrategy(), 3, "Bully");
        break;
    }
    std::cout << "\nHere is your selected character:\n";
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
