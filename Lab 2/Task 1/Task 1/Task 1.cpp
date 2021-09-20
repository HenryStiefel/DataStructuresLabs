// Task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string fileName;

	//Enter the file's name
	cout << "Enter the file's name (include '.txt') ";
	cin >> fileName;

    string line;
	int count = 0;

	//Open the file to read text from
    ifstream myFile(fileName);

	if (myFile.is_open())
	{
		while (getline(myFile, line))
		{
			cout << line << endl;
			count++;
			if (count == 10)
			{
				break;
			}
		}
		myFile.close();
	}

	else cout << "Unable to open the file";

	return 0;
}
