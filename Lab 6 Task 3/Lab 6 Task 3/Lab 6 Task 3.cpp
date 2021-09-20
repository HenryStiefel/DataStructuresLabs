// New Lab 6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Stack.h"
#include "Queue.h"
#include <iostream>

using namespace std;

void printArr(Stack<int>, int);
bool moveFromStack(Stack<int>&, int);
bool moveToStack(Stack<int>&, Stack<int>&, int);

struct moves
{
	string fromStack;
	string toStack;
	int discSize;
};

int main()
{
	bool validInput = false;

	int discs;
	string moveFrom;
	string moveTo;
	int discSize = 0;

	// User input for number of discs
	cout << "How many discs would you like to use? ";
	cin >> discs;

	// Create the 3 towers
	Stack<int> stackA(3);
	Stack<int> stackB(3);
	Stack<int> stackC(3);

	Queue<moves> x;

	// Initialize Stack A with number of discs
	for (int i = discs; i > 0; i--)
	{
		stackA.push(i);
	}

	while (stackC.length() < 3)
	{
		// Begin each iteration by displaying the stacks
		cout << "\nStack A: " << endl;
		printArr(stackA, discs);

		cout << "\nStack B: " << endl;
		printArr(stackB, discs);

		cout << "\nStack C: " << endl;
		printArr(stackC, discs);

		// Ask the user which tower to move from
		while (!validInput)
		{
			cout << "\nWhich tower would you like to move from? (a, b, c) ";
			cin >> moveFrom;

			if (moveFrom.compare("a") == 0)
			{
				validInput = moveFromStack(stackA, discs);
			}
			else if (moveFrom.compare("b") == 0)
			{
				validInput = moveFromStack(stackB, discs);
			}
			else if (moveFrom.compare("c") == 0)
			{
				validInput = moveFromStack(stackC, discs);
			}
			else
			{
				cout << "Invalid input. " << endl;
			}
		}

		validInput = false;

		// Ask the user which tower to move to
		while (!validInput)
		{
			cout << "Which tower would you like to move to? (a, b, c) ";
			cin >> moveTo;

			// Catch moving to and from same tower
			if (moveTo.compare(moveFrom) == 0)
			{
				// Illegal move exception
				cout << "Cannot move disc to/from same tower. Try again. " << endl;
			}
			else
			{
				if (moveTo.compare("a") == 0)
				{
					if (moveFrom.compare("b") == 0)
					{
						validInput = moveToStack(stackA, stackB, discs);
					}
					else
					{
						validInput = moveToStack(stackA, stackC, discs);
					}

					discSize = stackA.top();
				}
				else if (moveTo.compare("b") == 0)
				{
					if (moveFrom.compare("a") == 0)
					{
						validInput = moveToStack(stackB, stackA, discs);
					}
					else
					{
						validInput = moveToStack(stackB, stackC, discs);
					}

					discSize = stackB.top();
				}
				else if (moveTo.compare("c") == 0)
				{
					if (moveFrom.compare("a") == 0)
					{
						validInput = moveToStack(stackC, stackA, discs);
					}
					else
					{
						validInput = moveToStack(stackC, stackB, discs);
					}

					discSize = stackC.top();
				}
				else
				{
					cout << "Invalid input. " << endl;
				}
			}
		}

		moves newMove = { moveFrom, moveTo, discSize };
		x.enqueue(newMove);

		
		validInput = false;
	}

	cout << "\nSuccessfully completed the Towers of Hanoi." << endl;
	cout << "Move summary: " << endl;

	int queueSize = x.getNumItems();

	for (int i = 0; i < queueSize; i++)
	{
		moves temp = x.dequeue();
		cout << "Moved disc of size " << temp.discSize << " from Tower " << temp.fromStack << " to Tower " << temp.toStack << endl;
	}
}







/////////////////////////////////////////////
//   HELPER FUNCTIONS                      //
/////////////////////////////////////////////
void printArr(Stack<int> stack, int numDiscs)
{
	Stack<int> popBack(numDiscs);
	int x;

	while (stack.length() > 0)
	{
		x = stack.pop();
		popBack.push(x);

		string printDisc = "";

		for (int i = 0; i < x; i++)
		{
			printDisc = printDisc + "*";
		}

		cout << printDisc << endl;
	}
	while (popBack.length() > 0)
	{
		x = popBack.pop();
		stack.push(x);
	}
}

bool moveFromStack(Stack<int>& testStack, int numDiscs)
{
	if (testStack.length() <= 0)
	{
		// INVALID
		cout << "Invalid move, try again." << endl;
		return false;
	}
	else
	{
		return true;
	}
}

bool moveToStack(Stack<int>& testStack, Stack<int>& fromStack, int numDiscs)
{
	if (testStack.length() == 0)
	{
		testStack.push(fromStack.pop());
		return true;
	}
	if (testStack.top() < fromStack.top())
	{
		// DISCS MUST FOLLOW ORDER
		cout << "Invalid move, try again." << endl;
		return false;
	}
	else
	{
		testStack.push(fromStack.pop());
		return true;
	}
	if (testStack.length() >= numDiscs)
	{
		// FULL STACK
		cout << "Invalid move, cannot move to full tower." << endl;
		return false;
	}
	else
	{
		testStack.push(fromStack.pop());
		return true;
	}
}