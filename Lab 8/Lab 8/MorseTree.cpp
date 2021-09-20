#include "MorseTree.h"

bool MorseTree::hasPath(Node* root, char x)
{
	if (!root)
	{
		return false;
	}

	if (root->value == x)
	{
		return true;
	}
	if (hasPath(root->left, x))
	{
		morseArr.push_back('.');
		return true;
	}
	else if (hasPath(root->right, x))
	{
		morseArr.push_back('-');
		return true;
	}
	else
	{
		return false;
	}
}

void MorseTree::reverse(int n)
{
	for (int low = 0, high = n - 1; low < high; low++, high--)
	{
		swap(morseArr[low], morseArr[high]);
	}
}

string MorseTree::toMorse(string input)
{
	for (int i = 0; i < size(input); i++)
	{
		if (hasPath(root, input[i]))
		{
			reverse(morseArr.size());

			for (int i = 0; i < morseArr.size(); i++)
			{
				cout << morseArr[i];
			}
			
			morseArr.clear();
			cout << " ";
		}
	}

	return "";
}

string MorseTree::toEnglish(string input)
{
	Node* nodePtr = root;
	string returnStr = "";

	// INPUT = .-	-...	-.-.	-..
	//		 = A	B		C		D

	for (int i = 0; i < size(input); i++)
	{
		if (input[i] == '.')
		{
			nodePtr = nodePtr->left;
			if (input[i+1] == ' ')
			{
				returnStr = returnStr + nodePtr->value;
			}
		}
		else if (input[i] == '-')
		{
			nodePtr = nodePtr->right;
			if (input[i + 1] == ' ')
			{
				returnStr = returnStr + nodePtr->value;
			}
		}
		else
		{
			nodePtr = root;
		}
	}

	return returnStr;
}