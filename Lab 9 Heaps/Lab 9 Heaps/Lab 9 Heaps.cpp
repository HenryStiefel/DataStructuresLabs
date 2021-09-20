// Lab 9 Heaps.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MinHeap.h"
#include "MaxHeap.h"
#include "JobNode.h"
#include "MachineNode.h"

void task3();

int main()
{
    int t = 0;

    MaxHeap<JobNode> j;
    MinHeap<MachineNode> m;

    j.insert(JobNode(1, 2));
    j.insert(JobNode(2, 14));
    j.insert(JobNode(3, 4));
    j.insert(JobNode(4, 16));
    j.insert(JobNode(5, 6));
    j.insert(JobNode(6, 5));
    j.insert(JobNode(7, 3));
    
    for (int i = 0; i < 3; i++)
    {
        m.insert(MachineNode(i + 1, 0));
    }

    while (!j.isEmpty())
    {

        while (m.top()->val() <= t)
        {
            if (m.top()->val() == t)
            {
                MachineNode newMachine(m.top()->getID(), t + j.top()->val());

                m.insert(newMachine);
                m.remove();
                j.remove();
            }
        }
        t++;
    }

    int max = m.remove()->val();

    while (!m.isEmpty())
    {
        if (max < m.top()->val())
        {
            max = m.remove()->val();
        }
        else
        {
            m.remove();
        }
    }
    
    cout << "Time to finish jobs was " << max << endl;

    cout << "\n\n\nNow performing task 3 with n = 10 and m = 5." << endl;

    task3();
    

   // code to print the top node value and store it safely in y
    //int y = *h.top();
    //cout << y;
}

void task3()
{
    int t = 0;

    MaxHeap<JobNode> j;
    MinHeap<MachineNode> m;
    
    for (int i = 0; i < 10; i++)
    {
        int random = rand() % 20 + 1;
        JobNode newJ(i + 1, random);
        j.insert(newJ);
    }

    for (int k = 0; k < 5; k++)
    {
        m.insert(MachineNode(k + 1, 0));
    }

    while (!j.isEmpty())
    {

        while (m.top()->val() <= t)
        {
            if (m.top()->val() == t)
            {
                MachineNode newMachine(m.top()->getID(), t + j.top()->val());

                m.insert(newMachine);
                m.remove();
                j.remove();
            }
        }
        t++;
    }

    int max = m.remove()->val();

    while (!m.isEmpty())
    {
        if (max < m.top()->val())
        {
            max = m.remove()->val();
        }
        else
        {
            m.remove();
        }
    }

    cout << "Time to finish jobs was " << max;
}