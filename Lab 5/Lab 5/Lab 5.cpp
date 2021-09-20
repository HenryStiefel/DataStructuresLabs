// Lab 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Shelf.h"
using namespace std;

int main()
{
    bool go = true;

    Shelf myShelf = Shelf();
    string input;

    while (go)
    {
        cout << "\nPress 1 to add a board game to the shelf.\nPress 2 to remove a board game from the shelf.\nPress 3 to see how many board games are currently on the shelf.\nPress 4 to quit." << endl;
        cin >> input;

        if (input.compare("1") == 0)
        {
            try
            {
                cout << "Enter a name for the game. " << endl;
                cin >> input;
                myShelf.addGame(BoardGame(input));
            }
            catch (Shelf::FullShelf)
            {
                cout << "The shelf is full. Can't add game.\n";
            }
            
        }
        else if (input.compare("2") == 0)
        {
            try
            {
                myShelf.removeGame();
            }
            catch (Shelf::EmptyShelf)
            {
                cout << "The shelf is empty. Can't remove any games.\n";
            }
            
        }
        else if (input.compare("3") == 0)
        {
            cout << "There are " << myShelf.getNumGames() << " games on the shelf." << endl;
        }
        else if (input.compare("4") == 0)
        {
            break;
        }
        else
        {
            cout << "Invalid input, try again." << endl;
        }
    }
    
}