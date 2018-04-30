#pragma once
#include "AVLInterface.h"
#include "Node.h"

class AVL: public AVLInterface {
public:
	AVL() { root = NULL;}
	~AVL() { AVL::clear(); }
	NodeInterface* getRootNode() const;
	bool foundRecursion(Node* currentPosition, int value);
	bool found(int value);
	Node* addRecursion(Node* currentPosition, int value);
	void RightRight(Node* temp, Node* temp2);
	void RightLeft(Node* temp, Node* temp2, Node* temp3);
	void LeftLeft(Node* temp, Node* temp2);
	void LeftRight(Node* temp, Node* temp2, Node* temp3);
	Node* balanceTree(Node* temp);
	bool add(int data);
	Node* maxValueNodeLeftTree(Node* node);
	Node* removeRecursion(Node* curr, int x);
	bool remove(int data);
	void clear();

protected:
	Node* root;
};
