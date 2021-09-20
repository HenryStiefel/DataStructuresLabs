// Lab 5 Task 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Game.h"
#include "BoardGame.h"
#include "VideoGame.h"
#include "EntertainmentCollection.h"

using namespace std;

int main()
{
    bool go = true;
    string input;
    EntertainmentCollection<Game> shelf;

    while (go)
    {

        cout << "\nPress 1 to add a board game to the shelf.\nPress 2 to add a video game to the shelf." << endl;
        cout << "Press 3 to remove a game from the shelf.\nPress 4 to see how many games are currently on the shelf.\nPress 5 to quit." << endl;
        cin >> input;

        if (input.compare("1") == 0)
        {
            try
            {
                cout << "Enter a name for the game. " << endl;
                cin >> input;
                shelf.addGame(BoardGame(input));
            }
            catch (EntertainmentCollection<Game>::FullShelf)
            {
                cout << "The shelf is full. Can't add game.\n";
            }
        }
        else if (input.compare("2") == 0)
        {
            try
            {
                cout << "Enter a name for the game. " << endl;
                cin >> input;
                shelf.addGame(VideoGame(input));
            }
            catch (EntertainmentCollection<Game>::FullShelf)
            {
                cout << "The shelf is full. Can't add game.\n";
            }
        }
        else if (input.compare("3") == 0)
        {
            try
            {
                shelf.removeGame();
            }
            catch (EntertainmentCollection<Game>::EmptyShelf)
            {
                cout << "The shelf is empty. Can't remove any games.\n";
            }

        }
        else if (input.compare("4") == 0)
        {
            cout << "There are " << shelf.getNumGames() << " games on the shelf." << endl;
        }
        else if (input.compare("5") == 0)
        {
            break;
        }
        else
        {
            cout << "Invalid input, try again." << endl;
        }
    }
}