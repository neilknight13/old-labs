#pragma once
#include "NodeInterface.h"
#include <iostream>
using namespace std;

class Node : public NodeInterface {
	friend class AVL; // Allow AVL to access data members
public:
	Node(int value) {data = value; leftChild = NULL; rightChild = NULL; height = 0;}
	~Node() {}

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	int getData() const;

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	NodeInterface * getLeftChild() const;

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	NodeInterface * getRightChild() const;
	int getHeight();
	void changeHeight();
	int getBalance();
protected:

	int data;
	Node *leftChild;
	Node *rightChild;
	int height;

};
