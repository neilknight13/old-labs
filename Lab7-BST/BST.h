#pragma once
#include "BSTInterface.h"
#include "Node.h"
#include <iostream>

class BST: public BSTInterface {
public:
	BST() { root = NULL;}
	~BST() { BST::clear(); }
	NodeInterface* getRootNode() const;
	bool foundRecursion(Node* currentPosition, int value);
	bool found(int value);
	Node* addRecursion(Node* currentPosition, int value);
	bool add(int data);
	Node* maxValueNodeLeftTree(Node* node);
	Node* removeRecursion(Node* curr, int x);
	bool remove(int data);
	void clear();

protected:
	Node* root;
};
