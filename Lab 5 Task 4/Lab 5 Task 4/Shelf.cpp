#include "Shelf.h"
#include <iostream>

using namespace std;

void Shelf::addGame(BoardGame newGame) {
	if (numGames < TOTAL_BOARD_GAMES)
	{
		gameArray[numGames] = newGame;
		numGames++;
	}
	else
	{
		throw FullShelf();
	}
	
}

void Shelf::removeGame() {
	if (numGames > 0)
	{
		cout << "Removing game called " << gameArray[numGames - 1].getName() << endl;

		numGames--;
	}
	else
	{
		throw EmptyShelf();
	}
}