#ifndef PART_H
#define PART_H

#include <string>
using namespace std;

struct Date {
		int day, month, year;
	};

class Part
{
private:
	int partNum;
	double price;
	string desc, UOM;
	int quantity, leadTime;

	Date today = { 20, 10, 2020 };
public:
	Part()
	{
		partNum = 0;
		quantity = 0;
		leadTime = 0;
		price = 0.0;
		desc = "";
		UOM = "";
	}

	Part(int partNumber, string description, double itemPrice, string unitOfMeasure, int quantityOnHand = 0)
	{
		partNum = partNumber;
		desc = description;
		price = itemPrice;
		UOM = unitOfMeasure;
		quantity = quantityOnHand;
		leadTime = 0;
	}

	int getPartNum() const { return partNum; }
	string getPartInfo();
	double getPrice() const { return price; }
	bool inStock() const { return quantity > 0; }
	bool available(Date);

	bool operator>(const Part& rval);
	bool operator<(const Part& rval);
	bool operator==(const Part& rval);
};

#endif