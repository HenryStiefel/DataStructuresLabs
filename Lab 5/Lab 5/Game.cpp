#include "Game.h"
#include <iostream>
using namespace std;

void Game::setGameOver(bool gameStatus) { 
	gameOver = gameStatus; 
}

void Game::setPlayers(int numOfPlayers) { 
	numPlayers = numOfPlayers; 
}

void Game::Play() {
	cout << "Play the game." << endl;
}

void Game::Winner() { 
	cout << "Not yet" << endl;
}