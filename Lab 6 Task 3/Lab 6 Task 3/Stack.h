#ifndef STACK_H
#define STACK_H

using namespace std;

#define SIZE 10

template <class T>
class Stack
{
private:
	T* arr;
	int position;
	int capacity;

public:
	Stack(int size = SIZE);

	void push(T);
	T pop();
	T top();
	int length();
	void empty();
	friend void printArr(Stack<T> stack);

	class FullStack {};
	class EmptyStack {};
};

template <class T>
Stack<T>::Stack(int size)
{
	arr = new T[size];
	capacity = size;
	position = -1;
}

template <class T>
void Stack<T>::push(T t)
{
	if (position >= capacity)
	{
		throw FullStack();
	}
	else
	{
		arr[++position] = t;
	}
}

template <class T>
T Stack<T>::pop()
{
	if (position == -1)
	{
		throw EmptyStack();
	}
	else
	{
		return arr[position--];
	}
}

template <class T>
T Stack<T>::top()
{
	if (position == -1)
	{
		throw EmptyStack();
	}
	else
	{
		return arr[position];
	}
}

template <class T>
int Stack<T>::length()
{
	return position + 1;
}

template <class T>
void Stack<T>::empty()
{
	for (int i = 0; i < capacity; i++)
	{
		delete arr[i];
	}
}
#endif