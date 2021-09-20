#ifndef BOARDGAME_H
#define BOARDGAME_H
#include "Game.h"

class BoardGame : public Game
{
private:
	int myTurn;
public:
	BoardGame() : Game()
	{
		myTurn = 1;
	}

	void setTurn() { myTurn += 1; }
	int getTurn() const { return myTurn; }

	void Winner();
	void Play();
};
#endif