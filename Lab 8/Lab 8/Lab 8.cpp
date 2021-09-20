// Lab 8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "BinaryTree.h"
#include "MorseTree.h"

void buildMorseTree(BinaryTree&);

int main()
{
    MorseTree myTree;
    buildMorseTree(myTree);

    while (true)
    {
        string input;
        cout << "Press 1 to decode, 2 to encode " << endl;
        cin >> input;

        if (input.compare("1") == 0)
        {
            // TAKE MORSE STRING, OUTPUT NORMAL TRANSLATION
            cout << "Enter the morse code." << endl;
            getline(cin >> ws, input);
            input = input + ' ';

            cout << myTree.toEnglish(input) << endl;
        }
        else if (input.compare("2") == 0)
        {
            // TAKE NORMAL STRING, OUTPUT MORSE TRANSLATION
            cout << "Enter the string to translate to morse." << endl;
            getline(cin >> ws, input);

            myTree.toMorse(input);
            cout << "\n" << endl;
        }
        else
        {
            cout << "Invalid input, try again." << endl;
        }
    }
}

void buildMorseTree(BinaryTree& T)
{
    T.insertNode('E');
    T.insertNode('T');
    T.insertNode('I');
    T.insertNode('A');
    T.insertNode('N');
    T.insertNode('M');
    T.insertNode('S');
    T.insertNode('U');
    T.insertNode('R');
    T.insertNode('W');
    T.insertNode('D');
    T.insertNode('K');
    T.insertNode('G');
    T.insertNode('O');
    T.insertNode('H');
    T.insertNode('V');
    T.insertNode('F');
    T.insertNode(' ');
    T.insertNode('L');
    T.insertNode(' ');
    T.insertNode('P');
    T.insertNode('J');
    T.insertNode('B');
    T.insertNode('X');
    T.insertNode('C');
    T.insertNode('Y');
    T.insertNode('Z');
    T.insertNode('Q');
}