#ifndef BINARYTREE_H
#define BINARYTREE_H

using namespace std;
#include<queue>
#include<iostream>

class BinaryTree
{
protected:
	struct Node
	{
		char value;
		Node* left;
		Node* right;
	};

	Node* root;

	void insert(Node*&, Node*&);
	void deleteLast(Node*);
	bool find(Node*&, char); 
	void printInOrder(Node*&);

public:
	BinaryTree()
	{
		root = new Node{ '0', nullptr, nullptr };
	}

	void insertNode(char);
	void remove(char);
	bool findNode(char);
	void inOrder();
};

#endif