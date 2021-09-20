#ifndef QUEUE_H
#define QUEUE_H

#include <vector>
using namespace std;

template <class T>
class Queue
{
private:
	vector<T> myQueue;
	int numItems;
public:
	Queue();

	void enqueue(T);
	T dequeue();
	int getNumItems() const { return numItems; }

};

template <class T>
Queue<T>::Queue()
{
	numItems = 0;
}

template <class T>
void Queue<T>::enqueue(T item)
{
	numItems++;
	myQueue.insert(myQueue.end(), item);
}

template <class T>
T Queue<T>::dequeue()
{
	numItems--;
	T returnValue = myQueue[0];
	myQueue.erase(myQueue.begin());

	return returnValue;
}
#endif