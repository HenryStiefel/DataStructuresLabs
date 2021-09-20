#pragma once
#include "BoardGame.h"

const int TOTAL_BOARD_GAMES = 10;

class Shelf
{
private:
	BoardGame gameArray[TOTAL_BOARD_GAMES];
	int numGames;
public:
	class FullShelf { };
	class EmptyShelf { };

	Shelf() {
		numGames = 0;
	}

	void addGame(BoardGame);
	void removeGame();

	int getNumGames() const { return numGames; }
};

