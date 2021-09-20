// This program produces a sales report for DLC, Inc.
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes

struct Product {
	int id;
	int units;
	double prices;
	double sales;
};

void calcSales(Product[]);
void showOrder(Product[]);
void dualSort(Product[]);
void showTotals(Product[]);

// NUM_PRODS is the number of products produced.
const int NUM_PRODS = 9;



int main()
{
	Product products[NUM_PRODS];

	products[0] = { 914, 842, 12.95, 0 };
	products[1] = { 915, 416, 14.95, 0 };
	products[2] = { 916, 127, 18.95, 0 };
	products[3] = { 917, 514, 16.95, 0 };
	products[4] = { 918, 437, 21.95, 0 };
	products[5] = { 919, 269, 31.95, 0 };
	products[6] = { 920, 97, 14.95, 0 };
	products[7] = { 921, 492, 14.95, 0 };
	products[8] = { 922, 212, 16.95, 0 }; 
	
	// Calculate each product's sales.
	calcSales(products);

	// Sort the elements in the sales array in descending
	// order and shuffle the ID numbers in the id array to
	// keep them in parallel.
	dualSort(products);

	// Set the numeric output formatting.
	cout << setprecision(2) << fixed << showpoint;

	// Display the products and sales amounts.
	showOrder(products);

	// Display total units sold and total sales.
	showTotals(products);
	return 0;
}

//****************************************************************
// Definition of calcSales. Accepts units, prices, and sales     *
// arrays as arguments. The size of these arrays is passed       *
// into the num parameter. This function calculates each         *
// product's sales by multiplying its units sold by each unit's  *
// price. The result is stored in the sales array.               *
//****************************************************************

void calcSales(Product prod[])
{
	for (int i = 0; i < NUM_PRODS; i++)
	{
		prod[i].sales = prod[i].units * prod[i].prices;
	}
		
}

//***************************************************************
// Definition of function dualSort. Accepts id and sales arrays *
// as arguments. The size of these arrays is passed into size.  *
// This function performs a descending order selection sort on  *
// the sales array. The elements of the id array are exchanged  *
// identically as those of the sales array. size is the number  *
// of elements in each array.                                   *
//***************************************************************

void dualSort(Product prod[])
{
	int startScan, maxIndex, tempid;
	double maxValue;

	for (startScan = 0; startScan < (NUM_PRODS - 1); startScan++)
	{
		maxIndex = startScan;
		maxValue = prod[startScan].sales;
		tempid = prod[startScan].id;
		for (int index = startScan + 1; index < NUM_PRODS; index++)
		{
			if (prod[index].sales > maxValue)
			{
				maxValue = prod[index].sales;
				tempid = prod[index].id;
				maxIndex = index;
			}
		}
		prod[maxIndex].sales = prod[startScan].sales;
		prod[maxIndex].id = prod[startScan].id;
		prod[startScan].sales = maxValue;
		prod[startScan].id = tempid;
	}
}

//****************************************************************
// Definition of showOrder function. Accepts sales and id arrays *
// as arguments. The size of these arrays is passed into num.    *
// The function first displays a heading, then the sorted list   *
// of product numbers and sales.                                 *
//****************************************************************

void showOrder(Product prod[])
{
	cout << "Product Number\tSales\n";
	cout << "----------------------------------\n";
	for (int index = 0; index < NUM_PRODS; index++)
	{
		cout << prod[index].id << "\t\t$";
		cout << setw(8) << prod[index].sales << endl;
	}
	cout << endl;
}

//*****************************************************************
// Definition of showTotals function. Accepts sales and id arrays *
// as arguments. The size of these arrays is passed into num.     *
// The function first calculates the total units (of all          *
// products) sold and the total sales. It then displays these     *
// amounts.                                                       *
//*****************************************************************

void showTotals(Product prod[])
{
	int totalUnits = 0;
	double totalSales = 0.0;

	for (int index = 0; index < NUM_PRODS; index++)
	{
		totalUnits += prod[index].units;
		totalSales += prod[index].sales;
	}
	cout << "Total units Sold:  " << totalUnits << endl;
	cout << "Total sales:      $" << totalSales << endl;
}