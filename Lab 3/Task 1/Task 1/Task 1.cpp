// Task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ComplexNumber.h"
#include <string>
using namespace std;

int main()
{
    int x1;
    int y1;
    string operation;

    int x2 = 0;
    int y2 = 0;
    double scale = 0;

    ComplexNumber num1;
    ComplexNumber num2;

    cout << "Enter the x and y values for the complex number." << endl;
    cout << "x: ";
    cin >> x1;
    cout << "y: ";
    cin >> y1;

    num1 = ComplexNumber(x1, y1);

    bool prompt = true;
	string userContinue;

    while (prompt)
    {
		cout << "\nWhat operation do you want to perform? (+,-,*,/,==) ";
		cin >> operation;

		if (operation.compare("+") == 0 || operation.compare("-") == 0 || operation.compare("==") == 0)
		{
			cout << "Enter the x and y values for the complex number." << endl;
			cout << "x: ";
			cin >> x2;
			cout << "y: ";
			cin >> y2;

			num2 = ComplexNumber(x2, y2);
		}
		else if (operation.compare("*") == 0 || operation.compare("/") == 0)
		{
			cout << "Enter the scaler value. ";
			cin >> scale;
		}
		else
		{
			cout << "Invalid operation. Try again.";
		}


		if (operation.compare("+") == 0)
		{
			num1.operator+(num2);
		}
		else if (operation.compare("-") == 0)
		{
			num1.operator-(num2);
		}
		else if (operation.compare("==") == 0)
		{
			if (num1.operator==(num2))
			{
				cout << "The complex numbers are equal.";
			}
			else
			{
				cout << "The complex numbers are not equal.";
			}
		}
		else if (operation.compare("*") == 0)
		{
			num1.operator*(scale);
		}
		else
		{
			num1.operator/(scale);
		}

		if (operation.compare("+") == 0 || operation.compare("-") == 0 || operation.compare("*") == 0 || operation.compare("/") == 0)
		{
			num1.printValue();
		}
		
		cout << "\nDo you wish to continue? (y or n) ";
		cin >> userContinue;

		if (userContinue.compare("y") != 0)
		{
			prompt = false;
			break;
		}
    }
}
