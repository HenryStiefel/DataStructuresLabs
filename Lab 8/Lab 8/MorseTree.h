#ifndef MORSETREE_H
#define MORSETREE_H
#include "BinaryTree.h"

class MorseTree : public BinaryTree
{
private: 
	vector<char> morseArr;

	bool hasPath(Node*, char);
	void reverse(int);
public:
	MorseTree() : BinaryTree()
	{

	}

	string toMorse(string);
	string toEnglish(string);
};

#endif