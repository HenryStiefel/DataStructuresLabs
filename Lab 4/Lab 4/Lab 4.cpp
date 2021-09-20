// Lab 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Game.h"
#include "BoardGame.h"
#include "VideoGame.h"

using namespace std;

void moveEat(Game*);

int main()
{
	string input;
	bool go = true;

	while (go)
	{
		cout << "Press 1 for an instance of game.\nPress 2 for an instance of board game.\nPress 3 for an instance of video game.\n";
		cout << "Press 4 for an instance of a board game declared as a game.\nPress 5 for an instance of a video game declared as a game.\n";

		cin >> input;

		Game* gamePtr;

		if (input.compare("1") == 0) {
			Game newGame = Game();
			gamePtr = &newGame;
		}

		else if (input.compare("2") == 0) {
			BoardGame newGame = BoardGame();
			gamePtr = &newGame;
		}

		else if (input.compare("3") == 0) {
			VideoGame newGame = VideoGame();
			gamePtr = &newGame;
		}

		else if (input.compare("4") == 0) {
			Game newGame = BoardGame();
			gamePtr = &newGame;
		}

		else {
			Game newGame = VideoGame();
			gamePtr = &newGame;
		}

		gamePtr->Play();
		gamePtr->Winner();
		moveEat(gamePtr);

		cout << "\nDo you wish to continue? (y or n) ";
		cin >> input;

		if (!input.compare("y") == 0)
		{
			break;
		}
	}
}

void moveEat(Game* aGame)
{
	aGame->Play();
	aGame->Winner();
}