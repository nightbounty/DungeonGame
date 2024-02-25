// comp345A1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Map.h>

using namespace std;

int main()
{
    
    // MAP TESTING!
    int rows, columns, startY;

    cout << "Welcome to the d20 Map Generator! :D\n";
    cout << "************************************\n";
    
    cout << "Please enter the number of rows for the map: \n";
    cin >> rows;

    cout << "Please enter the number of columns for the map: \n";
    cin >> columns;

    cout << "Please enter the y start coordinate for the map: \n";
    cin >> startY;

    cout << "Generating a map based on your input! :D" << endl;
    Map* testMap = new Map(rows, columns, new Vector2(0, startY));
   
    cout << "\n=== LEGEND ===\nD: Door\nE: Enemy\nC: Chest\nO: Empty\nW: Wall";
    
    cout << "\n=== YOUR MAP!! *^* ===\n\n" << testMap->ToString();
}


