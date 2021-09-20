#include "BinaryTree.h"


void BinaryTree::insertNode(char value)
{
	Node* newNode = nullptr;

	newNode = new Node;
	newNode->value = value;
	newNode->left = nullptr;
	newNode->right = nullptr;

	insert(root, newNode);
}

void BinaryTree::insert(Node*& nodePtr, Node*& newNode)
{
	queue<Node*> q;
	q.push(nodePtr);

	while (!q.empty())
	{
		Node* temp = q.front();
		q.pop();

		if (temp->left != nullptr)
		{
			q.push(temp->left);
		}
		else
		{
			temp->left = newNode;
			break;
		}

		if (temp->right != nullptr)
		{
			q.push(temp->right);
		}
		else
		{
			temp->right = newNode;
			break;
		}
	}
}

void BinaryTree::deleteLast(Node* last)
{
	Node* nodePtr = root;

	queue<Node*> q;
	q.push(nodePtr);

	Node* temp;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		if (temp == last)
		{
			temp = nullptr;
			delete(last);
			break;
		}
		if (temp->right)
		{
			if (temp->right == last)
			{
				temp->right = nullptr;
				delete(last);
				break;
			}
			else
			{
				q.push(temp->right);
			}
		}
		if (temp->left)
		{
			if (temp->left == last)
			{
				temp->left = nullptr;
				delete(last);
				break;
			}
			else
			{
				q.push(temp->left);
			}
		}
	}
}

void BinaryTree::remove(char key)
{
	Node* nodePtr = root;

	if (nodePtr->left != nullptr)
	{
		queue<Node*> q;
		q.push(nodePtr);

		Node* temp = nullptr;
		Node* keyNode = nullptr;

		while (!q.empty())
		{
			temp = q.front();
			q.pop();

			if (temp->value == key)
			{
				keyNode = temp;
			}
			if (temp->left)
			{
				q.push(temp->left);
			}
			if (temp->right)
			{
				q.push(temp->right);
			}
		}

		if (keyNode != nullptr)
		{
			char myChar = temp->value;
			deleteLast(temp);
			keyNode->value = myChar;
		}
	}
}

bool BinaryTree::find(Node*& nodePtr, char key)
{
	if (nodePtr == nullptr)
	{
		return false;
	}
	if (nodePtr->value == key)
	{
		return true;
	}
	
	bool findL = find(nodePtr->left, key);
	if (findL)
	{
		return true;
	}

	bool findR = find(nodePtr->right, key);
	if (findR)
	{
		return true;
	}

	return false;
}

bool BinaryTree::findNode(char key)
{
	return find(root, key);
}

void BinaryTree::printInOrder(Node*& nodePtr)
{
	if (!nodePtr)
	{
		return;
	}

	printInOrder(nodePtr->left);
	if (nodePtr != root && nodePtr->value != ' ')
	{
		cout << nodePtr->value;
	}
	printInOrder(nodePtr->right);
}

void BinaryTree::inOrder()
{
	printInOrder(root);
}