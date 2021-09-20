// Lab 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Part.h"

using namespace std;

int main()
{
    string input;
    LinkedList<Part> myList;

    while (true)
    {
        cout << "\nPress number of operation you would like to perform " << endl;

        cout << "1: Add Item\n2: Remove Item\n3: Find out if value is in list\n";
        cout << "4: See if list is empty\n5: Get size of list\n6: See next item in list\n7: See item at specific index\n8: Reset index of counter" << endl;
        cin >> input;

        // Add Part
        if (input.compare("1") == 0)
        {
            //Part(int partNumber, string description, double itemPrice, string unitOfMeasure, int quantityOnHand = 0)

            int newPartNum;
            string newDesc;
            double newPrice;
            string newUOM;
            int newQuantity;

            cout << "Enter a part number for the new part: ";
            cin >> newPartNum;
            cout << "\nEnter a description for the new part: ";
            getline(cin >> ws, newDesc);
            cout << "\nEnter a price for the new part: ";
            cin >> newPrice;
            cout << "\nEnter a unit of measure for the new part: ";
            cin >> newUOM;
            cout << "\nWould you like to add an initial quantity for this part? (y or n): ";
            cin >> input;

            if (input.compare("y") == 0)
            {
                cout << "\nEnter the quantity for the new part: ";
                cin >> newQuantity;

                myList.addItem(Part(newPartNum, newDesc, newPrice, newUOM, newQuantity));
            }
            else
            {
                myList.addItem(Part(newPartNum, newDesc, newPrice, newUOM));
            }

            cout << "\nAdded part! " << endl;
        }

        // Remove Part
        else if (input.compare("2") == 0)
        {
            int searchVal;

            cout << "Enter the part number you would like to remove: ";
            cin >> searchVal;

            Part search(searchVal, "", 0, "");

            myList.getItem(search);
        }

        // Find out if part is in list
        else if (input.compare("3") == 0)
        {
            int searchVal;

            cout << "Enter the part number you would like to search for: ";
            cin >> searchVal;

            if (myList.isInList(Part(searchVal, "", 0, "")))
            {
                cout << "\nFound a part with that number!" << endl;
            }
            else
            {
                cout << "\nNo part with that number in the list." << endl;
            }
        }

        // See if list is empty
        else if (input.compare("4") == 0)
        {
            if (myList.isEmpty())
            {
                cout << "List is empty." << endl;
            }
            else
            {
                cout << "List is not empty." << endl;
            }
        }

        // Get size of list
        else if (input.compare("5") == 0)
        {
            cout << "List is of size: " << myList.size() << endl;
        }

        // See next
        else if (input.compare("6") == 0)
        {
            try
            {
                cout << myList.seeNext()->getPartInfo();
            }
            catch (LinkedList<Part>::EmptyList)
            {
                cout << "\nCannot perform operation on empty list." << endl;
            }
            catch (LinkedList<Part>::BoundsError)
            {
                cout << "\nIndex is out of bounds, must reset." << endl;
            }
        }

        // See at
        else if (input.compare("7") == 0)
        {
            try
            {
                cout << "Enter index of part you are looking for: ";
                cin >> input;

                int in = stoi(input);

                cout << myList.seeAt(in)->getPartInfo() << endl;
            }
            catch (LinkedList<Part>::EmptyList)
            {
                cout << "\nCannot perform operation on empty list." << endl;
            }
            catch (LinkedList<Part>::BoundsError)
            {
                cout << "\nIndex is out of bounds, must reset." << endl;
            }
        }
        else if (input.compare("8") == 0)
        {
            myList.reset();
            cout << "Reset the counter!" << endl;
        }
        else
        {
            cout << "Invalid input, try again. " << endl;
        }
    }
}