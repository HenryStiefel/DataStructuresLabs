#ifndef GAME_H
#define GAME_H

class Game
{
protected:
	// include at least 2 attributes
	bool gameOver;
	int numPlayers;
public:
	// create a default constructor and an overloaded constructor for setting values of attributes
	Game()
	{
		gameOver = false;
		numPlayers = 2;
	}

	Game(int numOfPlayers)
	{
		gameOver = false;
		numPlayers = numOfPlayers;
	}

	// include getters and setters for the 2 attributes
	void setGameOver(bool);
	bool isGameOver() const { return gameOver; }

	void setPlayers(int);
	int getPlayers() const { return numPlayers; }

	// define a virtual function called Play
	virtual void Play();

	// define a non-virtual function called Winner that prints out the string "Not yet"
	void Winner();
};

#endif 