#include "ComplexNumber.h"
#include <cmath>
#include <iostream>
using namespace std;

void ComplexNumber::setX(double x) { myX = x; }
void ComplexNumber::setY(double y) { myY = y; }

double ComplexNumber::getPhi()
{
	if (myX > 0 || myY != 0)
	{
		return 2 * atan(myY / (getR() + myX));
	}
	else if (myX < 0 && myY == 0)
	{
		return atan(1) * 4;
	}
	
	return 0;
}

double ComplexNumber::getR()
{
	return sqrt(pow(myX,2) + pow(myY,2));
}

void ComplexNumber::printValue()
{
	if (isCartesian)
	{
		cout << "\n" << myX << " + " << myY << "i" << endl;
	}

	else
	{
		cout << getR() << "\n(cos(" << getPhi() << ") + isin(" << getPhi() << "))" << endl;
	}
}

void ComplexNumber::operator+(const ComplexNumber& rval)
{
	myX += rval.getX();
	myY += rval.getY();
}
void ComplexNumber::operator-(const ComplexNumber& rval)
{
	myX -= rval.getX();
	myY -= rval.getY();
}
void ComplexNumber::operator*(double scale)
{
	myX *= scale;
	myY *= scale;
}
void ComplexNumber::operator/(double scale)
{
	myX /= scale;
	myY /= scale;
}
bool ComplexNumber::operator==(ComplexNumber& rval)
{
	if (myX == rval.getX() && myY == rval.getY())
	{
		return true;
	}
	
	return false;
}