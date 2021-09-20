#pragma once
using namespace std;

#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

class ComplexNumber
{
private:
	double myX;
	double myY;
	bool isCartesian;
public:
	// CONSTRUCTORS
	ComplexNumber()
	{
		myX = 0;
		myY = 0;
		isCartesian = false;
	}

	ComplexNumber(double x, double y)
	{
		myX = x;
		myY = y;
		isCartesian = true;
	}

	ComplexNumber(double x, double y, bool type)
	{
		myX = x;
		myY = y;
		isCartesian = type;
	}
	// SETTERS
	void setX(double);
	void setY(double);

	// GETTERS
	double getX() const { return myX; }
	double getY() const { return myY; }
	double getPhi();
	double getR();

	// Method to print value of complex number
	void printValue();

	// Operator overloads
	void operator+(const ComplexNumber &rval);
	void operator-(const ComplexNumber &rval);
	void operator*(double scale);
	void operator/(double scale);
	bool operator==(ComplexNumber &rval);
};
#endif