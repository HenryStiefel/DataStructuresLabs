#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include "Game.h"
#include <string>

using namespace std;

class VideoGame : public Game
{
private:
	int myDifficulty;
public:
	VideoGame() : Game()
	{
		myDifficulty = 1;
	}
	VideoGame(string name) : Game(name)
	{
		myDifficulty = 0;
	}

	int getDifficulty() const { return myDifficulty; }

	void Winner();
	void Play();
};
#endif