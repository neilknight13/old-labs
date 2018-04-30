#include "Node.h"
    /*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	int Node::getData() const
	{
		 //cout << "entered data";
	    return data;
	}

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	NodeInterface * Node::getLeftChild() const {
		return leftChild;
	}

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	NodeInterface * Node::getRightChild() const {
		return rightChild;
	}

	int Node::getHeight() {
		return height;
	}
	
	void Node::changeHeight() {
		//cout << "Entered change height" << endl;
		int rightHeight;
		int leftHeight;
		if (leftChild == NULL) {
			//cout << "Left height set to -1" << endl;
			leftHeight = -1;
		}
		else {
			leftHeight = leftChild->height;
		}
		if (rightChild == NULL) {
			rightHeight = -1;
			//cout << "right height to set -1" << endl;
		}
		else {
			rightHeight = rightChild->height;
		}
		height = max(leftHeight, rightHeight) + 1;
	}
	
	int Node::getBalance() {
		int leftHeight;
		if (leftChild == NULL) {
			leftHeight = -1;
		}
		else {
			leftHeight = leftChild->height;
		}
		int rightHeight;
		if (rightChild == NULL) {
			rightHeight = -1;
		}
		else {
			rightHeight = rightChild->height;	
		}
		return rightHeight - leftHeight;
	}