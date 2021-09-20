#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
#include <iostream>
#include <string>
using namespace std;

template <class T>
class MinHeap
{
private:
	vector<T> v;
	
	void heapify_up(int i)
	{
		if (i && v[parent(i)] > v[i])
		{
			swap(v[i], v[parent(i)]);

			heapify_up(parent(i));
		}
	}

	void heapify_down(int i)
	{
		if (left(i) < v.size() && v[left(i)] < v[i])
		{
			swap(v[i], v[left(i)]);
			heapify_down(left(i));
		}
		if (right(i) < v.size() && v[right(i)] < v[i])
		{
			swap(v[i], v[right(i)]);
			heapify_down(right(i));
		}
	}

	int left(int i)
	{
		return (2 * i) + 1;
	}

	int right(int i)
	{
		return (2 * i) + 2;
	}

	int parent(int i)
	{
		return (i - 1) / 2;
	}

public:
	MinHeap() {};

	int heapSize()
	{
		return v.size();
	}

	bool isEmpty()
	{
		return v.size() == 0;
	}

	void insert(T val)
	{
		v.push_back(val);
		heapify_up(v.size() - 1);
	}

	T* remove()
	{
		T* returnVal = nullptr;

		if (!isEmpty())
		{
			returnVal = &v[0];

			v[0] = v.back();
			v.pop_back();

			heapify_down(0);
		}

		return returnVal;
	}

	T* top()
	{
		if (!isEmpty())
		{
			return &v[0];
		}
		
		return nullptr;
	}

	void print()
	{
		for (int i = 0; i < v.size(); i++)
		{
			cout << "" << v[i].val();
			cout << " ";
		}

		cout << "\n\n";
	}
};

#endif