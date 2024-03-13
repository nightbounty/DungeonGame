#include "../headers/Character.h"
#include "../headers/CharacterObserver.h"
#include <iostream>
#include <string>
#include <cstdlib> // For srand() and rand()
#include <ctime>   // For time()

using namespace std;
/*
* int main() {
    cout << "Welcome to the GAME! +_+\n";
    cout << "************************\n";

    cout << "Let's create your character...\n";
    cout << "***************************\n";

    // Seed the random number generator once
    srand(static_cast<unsigned int>(time(0)));

    // Prompt for character creation details
    string name;
    string characterClass = "Fighter"; 
    int level;

    cout << "Enter your Fighter's name: ";
    cin >> name; 

    cout << "Enter your character's level: ";
    cin >> level;

    // Create the character
    cout << "\nCreating your character...\n";
    Character myCharacter(level, characterClass);

    // Attach observer to character
    CharacterObserver observer;
    myCharacter.attachObserver(&observer);

    // Display initial character stats
    cout << "\nDisplaying initial character stats...\n";
    myCharacter.displayStats();

    // Prompt the player about adding extra levels
    cout << "\nDo you want to add extra levels to your character? (yes/no): ";
    string response;
    cin >> response;

    if (response == "yes" || response == "Yes") {
        int extraLevels;
        cout << "How many levels do you want to add?: ";
        cin >> extraLevels;

        cout << "\nAdding " << extraLevels << " levels to your character...\n";
        myCharacter.level += extraLevels; // Add extra levels

        // Increment each ability score by 1 for each level added
        for (int level = 0; level < extraLevels; ++level) {
            for (int& score : myCharacter.abilityScores) {
                score += 1;
            }
        }
        myCharacter.attackBonus += extraLevels;
        // Notify observers of the change to re-display updated stats
        myCharacter.notifyObservers();
    } else {
        cout << "No levels added. Keeping the character as is.\n";
    }

    cout << "\nCharacter setup complete! Proceed with your adventure.\n";

    return 0;
}
*/

