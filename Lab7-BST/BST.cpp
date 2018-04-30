#include "BST.h"
#include "Node.h"
#include <iostream>

using namespace std;

	NodeInterface * BST::getRootNode() const {
		//cout << "Getrootnode called and value contains " << root->data << endl;
	   return root;
	}

	bool BST::foundRecursion(Node* currentPosition, int value) {
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

	bool BST::found(int value){
		if (root == NULL)	{
			//cout << "tree is empty, returning false for found" << endl;
			return false;
		}
		else {
			bool found = BST::foundRecursion(root, value);
			return found;
		}
	}

	Node* BST::addRecursion(Node* currentPosition, int value){
		if (currentPosition== NULL){
			//cout << "Nothing in current position, making new node" << endl;
			return new Node(value);
		}
		else if (value < currentPosition->data){ //enter left subtree
			currentPosition->leftChild = addRecursion(currentPosition->leftChild, value);
			return currentPosition;
		}
		else if (value > currentPosition->data){ //enter right subtree
			currentPosition->rightChild = addRecursion(currentPosition->rightChild, value);
			return currentPosition;
		}
		return currentPosition;
	}

	bool BST::add(int data){
		if (!BST::found(data)){ //if not already in tree, add value to tree
			root = BST::addRecursion(root, data);
			return true;
		}
		else {
			return false;
		}
	}
	
	Node * BST::maxValueNodeLeftTree(Node* node) {
   		Node* currentPosition = node;
    /* loop down to find the rightmost leaf */
    	while (currentPosition->rightChild != NULL)
        	currentPosition = currentPosition->rightChild;
 
    	return currentPosition;
	}

	Node* BST::removeRecursion(Node* currentPosition, int value){
    	if (currentPosition == NULL) { // base case
    		return currentPosition;
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
	            return temp;
	        }
	        else if (currentPosition->rightChild == NULL) {
	            Node* temp = currentPosition->leftChild;
	            delete currentPosition;
	            return temp;
	        }
	        // node with two children: Get the inorder predecessor (smallest
	        // in the left subtree)
	        Node* temp = maxValueNodeLeftTree(currentPosition->leftChild);
	        // Copy the inorder predecessor's content to this node
	        currentPosition->data = temp->data;
	        // Delete the inorder predecessor
	        currentPosition->leftChild = removeRecursion(currentPosition->leftChild, temp->data);
	    }
	    return currentPosition;
	}
	
	bool BST::remove(int data){
		if (BST::found(data)){
			root = BST::removeRecursion(root, data);
			return true;
		}
		else {
			return false;
		}
	}

	void BST::clear() {
		while (root != NULL) {
			remove(root->data);
		}
	}