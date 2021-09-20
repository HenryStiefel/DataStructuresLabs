#ifndef GAME_H
#define GAME_H

#include <string>

using namespace std;

class Game
{
protected:
	// include at least 2 attributes
	bool gameOver;
	int numPlayers;
	string myName;
public:
	// create a default constructor and an overloaded constructor for setting values of attributes
	Game()
	{
		gameOver = false;
		numPlayers = 2;
		myName = "";
	}

	Game(string aName)
	{
		gameOver = false;
		numPlayers = 2;
		myName = aName;
	}

	// include getters and setters for the attributes
	void setGameOver(bool);
	bool isGameOver() const { return gameOver; }

	void setName(string aName) { myName = aName; }
	string getName() const { return myName; }

	void setPlayers(int);
	int getPlayers() const { return numPlayers; }

	// define a virtual function called Play
	virtual void Play();

	// define a non-virtual function called Winner that prints out the string "Not yet"
	void Winner();
};

#endif 