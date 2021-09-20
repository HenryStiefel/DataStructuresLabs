#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;

struct Node;

template <class T>
class LinkedList
{
private:
	struct Node
	{
		T value;
		Node* next;
	};

	Node* head;
	Node* nextPtr;
	int index;

public:
	class EmptyList {};
	class BoundsError {};

	LinkedList()
	{
		head = nullptr;
		nextPtr = nullptr;
		index = 0;
	}

	~LinkedList();

	void addItem(T);
	T* getItem(T);
	bool isInList(T);
	bool isEmpty();
	int size();
	T* seeNext();
	T* seeAt(int);
	void reset();
};

template <class T>
void LinkedList<T>::addItem(T newValue)
{
	Node* newNode; // new node
	Node* nodePtr; // for list traversal
	Node* previousNode = nullptr; //for the previous node

	// Allocate new node with parameter value
	newNode = new Node;
	newNode->value = newValue;

	// If the list is empty insert at head
	if (isEmpty())
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else
	{
		nodePtr = head;
		previousNode = nullptr;

		while (nodePtr != nullptr && nodePtr->value < newValue)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}

	nextPtr = head;
}

template <class T>
T* LinkedList<T>::getItem(T searchValue)
{
	T* returnPtr;
	T returnValue;
	Node* nodePtr; // for list traversal
	Node* previousNode = nullptr; //for the previous node

	// If the list is empty insert at head
	if (isEmpty())
	{
		return nullptr;
	}
	else
	{
		nodePtr = head;
		previousNode = nullptr;

		while (nodePtr != nullptr && nodePtr->value < searchValue)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr == nullptr)
		{
			return nullptr;
		}

		// If head contains search value
		if (previousNode == nullptr)
		{
			returnValue = head->value;
			returnPtr = &returnValue;
			
			delete nodePtr;
			head = nullptr;

			return returnPtr;
		}
		else
		{
			returnValue = nodePtr->value;
			returnPtr = &returnValue;

			previousNode->next = nodePtr->next;
			delete nodePtr;

			return returnPtr;
		}
	}

	nextPtr = head;
}

template <class T>
bool LinkedList<T>::isInList(T searchVal)
{
	Node* nodePtr; // for list traversal

	// If the list is empty
	if (isEmpty())
	{
		return false;
	}
	else
	{
		nodePtr = head;

		while (nodePtr != nullptr)
		{
			if (nodePtr->value == searchVal)
			{
				return true;
			}
			else
			{
				nodePtr = nodePtr->next;
			}
		}

		return false;
	}
}

template <class T>
bool LinkedList<T>::isEmpty()
{
	if (!head)
	{
		return true;
	}

	return false;
}

template <class T>
int LinkedList<T>::size()
{
	Node* nodePtr; // for list traversal
	int count = 0;

	// If the list is empty insert at head
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		nodePtr = head;

		while (nodePtr != nullptr)
		{
			nodePtr = nodePtr->next;
			count++;
		}

		return count;
	}
}

template <class T>
T* LinkedList<T>::seeNext()
{
	Node* nodePtr = head;
	T* returnPtr;

	if (isEmpty())
	{
		throw EmptyList();
	}
	else
	{
		if (index < size())
		{
			for (int i = 0; i < index; i++)
			{
				nodePtr = nodePtr->next;
			}

			index++;

			returnPtr = &nodePtr->value;

			return returnPtr;
		}
		else
		{
			throw BoundsError();
		}
	}
}

template <class T>
T* LinkedList<T>::seeAt(int i)
{
	Node* nodePtr = head;
	T* returnPtr;

	if (isEmpty())
	{
		throw EmptyList();
	}
	else
	{
		if (i >= size())
		{
			throw BoundsError();
		}
		else
		{
			index = i;

			for (int i = 0; i < index; i++)
			{
				nodePtr = nodePtr->next;
			}

			index++;
		
			returnPtr = &nodePtr->value;

			return returnPtr;
		}
		
	}
}

template <class T>
void LinkedList<T>::reset()
{
	index = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	Node* nodePtr;
	Node* nextNode;

	nodePtr = head;

	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}
#endif