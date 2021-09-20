#ifndef ENTERTAINMENTCOLLECTION_H
#define ENTERTAINMENTCOLLECTION_H

#include <iostream>
using namespace std;

const int TOTAL_BOARD_GAMES = 10;

template <class T>
class EntertainmentCollection
{
private:
	T gameArray[TOTAL_BOARD_GAMES];
	int numGames;
public:
	class FullShelf { };
	class EmptyShelf { };

	EntertainmentCollection() {
		numGames = 0;
	}


	template <class T>
	void addGame(T newGame) {
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

	void removeGame() {
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

	int getNumGames() const { return numGames; }
};

#endif