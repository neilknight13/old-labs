#include "AVL.h"
#include "Node.h"
#include <iostream>

using namespace std;

	NodeInterface * AVL::getRootNode() const {
		//cout << "Getrootnode called and value contains " << root->data << endl;
	   return root;
	}

	bool AVL::foundRecursion(Node* currentPosition, int value) {
		bool found = false;
		if (currentPosition == NULL){
			return false;
		}
		if (value == currentPosition->data) {
			//cout << "data matches current Node" << endl;
			found = true;
		}
		else if (value < currentPosition->data){
			//cout << "data is less than current node, entering left subtree" << endl;
			found = foundRecursion(currentPosition->leftChild, value);
		}
		else if (value > currentPosition->data){
			//cout << "data is greater than current node, entering right subtree" << endl;
			found = foundRecursion(currentPosition->rightChild, value);
		}
		else {
			found = false;
		}
		return found;
	}

	bool AVL::found(int value){
		if (root == NULL)	{
			//cout << "tree is empty, returning false for found" << endl;
			return false;
		}
		else {
			bool found = AVL::foundRecursion(root, value);
			return found;
		}
	}

	Node* AVL::addRecursion(Node* currentPosition, int value){
		if (currentPosition== NULL){
			//cout << "Nothing in current position, making new node" << endl;
			return new Node(value);
		}
		else if (value < currentPosition->data){ //enter left subtree
			currentPosition->leftChild = addRecursion(currentPosition->leftChild, value);
			return balanceTree(currentPosition);
		}
		else if (value > currentPosition->data){ //enter right subtree
		//cout << "trying to add data to right subtree" << endl;
			currentPosition->rightChild = addRecursion(currentPosition->rightChild, value);
			return balanceTree(currentPosition);
		}
		//return balanceTree(currentPosition); //check if needed
	}
	
	void AVL::RightRight(Node* temp, Node* temp2) {
		//cout << "Entered right right" << endl;
		temp->rightChild = temp2->leftChild;
		temp2->leftChild = temp;
		
		temp->changeHeight();
		temp2->changeHeight();
	}
	
	void AVL::RightLeft(Node* temp, Node* temp2, Node* temp3) {
		//cout << "Entered Right left" << endl;
		temp->rightChild = temp3;
		temp2->leftChild = temp3->rightChild;
		temp3->rightChild = temp2;
		
		AVL::RightRight(temp, temp3);
		temp->changeHeight();
		temp2->changeHeight();
		temp3->changeHeight();
	}
	
	void AVL::LeftLeft(Node* temp, Node* temp2) {
		//cout << "Entered Left Left" << endl;
		temp->leftChild = temp2->rightChild;
		temp2->rightChild = temp;
		
		temp->changeHeight();
		temp2->changeHeight();
	}
	
	void AVL::LeftRight(Node* temp, Node* temp2, Node* temp3) {
		//cout << "Entered left right" << endl;
		temp->leftChild = temp3;
		temp2->rightChild = temp3->leftChild;
		temp3->leftChild = temp2;
		
		AVL::LeftLeft(temp, temp3);
		temp->changeHeight();
		temp2->changeHeight();
		temp3->changeHeight();
	}
	
	Node* AVL::balanceTree(Node* temp) {
		//cout << "Entered balance tree" << endl;
		if (temp == NULL) {
			//cout << "value is null" << endl;
			return NULL;
		}
		temp->changeHeight();
		if (temp->getBalance() > 1) {
			//cout << "Perform right right or right left balance" << endl;
			Node* temp2 = temp->rightChild;
			
			if (temp2->getBalance() < 0) {
				Node* temp3 = temp2->leftChild;
				AVL::RightLeft(temp, temp2, temp3);
				return temp3;
			}
			else {
				AVL::RightRight(temp, temp2);
				return temp2;
			}
		}
		else if (temp->getBalance() < -1) {
			//cout << "Left left or left right" << endl;
			Node* temp2 = temp->leftChild;
			
			if (temp2->getBalance() > 0) {
				Node* temp3 = temp2->rightChild;
				AVL::LeftRight(temp, temp2, temp3);
				return temp3;
			}
			else {
				AVL::LeftLeft(temp, temp2);
				return temp2;
			}
		}
		else {
			//cout << "returning temp" << endl;
			return temp;
		}
	}

	bool AVL::add(int data){
		if (!AVL::found(data)){ //if not already in tree, add value to tree
			root = AVL::addRecursion(root, data);
			return true;
		}
		else {
			return false;
		}
	}
	
	Node * AVL::maxValueNodeLeftTree(Node* node) {
   		Node* currentPosition = node;
    /* loop down to find the rightmost leaf */
    	while (currentPosition->rightChild != NULL)
        	currentPosition = currentPosition->rightChild;
 
    	return currentPosition;
	}

	Node* AVL::removeRecursion(Node* currentPosition, int value){
    	if (currentPosition == NULL) { // base case
    		return balanceTree(currentPosition);
    	}
    	// Find value in left subtree if less than current position
    	if (value < currentPosition->data) {
        	currentPosition->leftChild = removeRecursion(currentPosition->leftChild, value);
    	}
    	// Find value in right subtree if greater than current position
	   else if (value > currentPosition->data) {
	   	currentPosition->rightChild = removeRecursion(currentPosition->rightChild, value);
	   }
	    //this else statement should run if current position equals data, meaning we found
	    //the node to delete
	    else {
	        // node with only one child or no child
	        if (currentPosition->leftChild == NULL) {
	            Node* temp = currentPosition->rightChild;
	            delete currentPosition;
	            return balanceTree(temp);
	        }
	        else if (currentPosition->rightChild == NULL) {
	            Node* temp = currentPosition->leftChild;
	            delete currentPosition;
	            return balanceTree(temp);
	        }
	        // node with two children: Get the inorder predecessor (smallest
	        // in the left subtree)
	        Node* temp = maxValueNodeLeftTree(currentPosition->leftChild);
	        // Copy the inorder predecessor's content to this node
	        currentPosition->data = temp->data;
	        // Delete the inorder predecessor
	        currentPosition->leftChild = removeRecursion(currentPosition->leftChild, temp->data);
	    }
	    return balanceTree(currentPosition);
	}
	
	bool AVL::remove(int data){
		if (AVL::found(data)){
			root = AVL::removeRecursion(root, data);
			return true;
		}
		else {
			return false;
		}
	}

	void AVL::clear() {
		while (root != NULL) {
			remove(root->data);
		}
	}