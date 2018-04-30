
#pragma once
#include <iostream>
#include <sstream>
#include "LinkedListInterface.h"

using namespace std;

template<class T>
class LinkedList : public LinkedListInterface<T>
{
private:
   struct Node {
   	 T data; // The data we are storing
   	 Node* next; // A pointer to the next Node 
   	 Node(const T& the_data, Node* next_val = NULL) :
   	   data(the_data) {next = next_val;}
   	};
   Node *head;
public:

	LinkedList(void) {
	   head = NULL;
	};
	~LinkedList(void) {
	   while (head != NULL) {
	      Node* current = head;
	      head = head->next;
	      delete current;
	   }
	};
	
	bool alreadyExists(T value) {
	   Node* verification = head;
	   while (verification != NULL) {
	      if (verification->data == value) {
	         return true;
	      }
	      verification = verification->next;
	   }
	   return false;
	}

	/*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
	void insertHead(T value) { 
	   if (alreadyExists(value)) {
	      return;
	   }
	   Node* temp = new Node(value);
		temp->next = head;
		head = temp;
	}

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	void insertTail(T value) {
	   if (head == NULL) {
			insertHead(value);
			return;
		}
		if (alreadyExists(value)) {
		   return;
		}
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		if (temp->next == NULL) {
			Node* newTail = new Node(value);
			temp->next = newTail;
			newTail->next = NULL;
		}
	}

	/*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	void insertAfter(T value, T insertionNode) {
	   if (alreadyExists(value)) {
	      return;
	   }
	   Node* currentPosition = head;
		while (currentPosition != NULL) {
			if (currentPosition->data == insertionNode) {
				Node* newInsert = new Node(value);
				newInsert->next = currentPosition->next;
				currentPosition->next = newInsert;
			}
			currentPosition = currentPosition->next;
		}
	}

	/*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	void remove(T value) {
	   if (!alreadyExists(value)) {
	   	return;
	   }
	   Node* temp1 = head;
	   if (head->data == value) {
	   	head = temp1->next;
	   	delete temp1;
	   	return;
	   }
	   while (temp1->next->data != value) {
	   	temp1 = temp1->next;
	   }
	   if (temp1->next->data == value) {
	   	Node* temp2 = temp1->next;
	   	temp1->next = temp2->next;
	   	delete temp2;
	   }
	}

	/*
	clear

	Remove all nodes from the list.
	*/
	void clear() {
	   while (head != NULL) {
	      remove(head->data);
	   }
	}

	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	T at(int index) {
	   if (index < 0 || index >= size()) {
	   	throw out_of_range("placeholder");
	   }
	   Node* position = head;
	   int currentPosition = 0;
	   while (position != NULL) {
	   	if (currentPosition == index) {
	      	return position->data;
	   	}
	      currentPosition++;
	      position = position->next;
	   }
	}

	/*
	size

	Returns the number of nodes in the list.
	*/
	int size() {
	   Node* position = head;
	   int count = 0;
	   while (position != NULL) {
	   	position = position->next;
	   	count++;
	   }
	   return count;
	}
	/*
	toString
	
	Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
	There should be no trailing space at the end of the string

	For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
	"1 2 3 4 5"
	*/
	string toString() {
		stringstream hello;
	   for(Node *ptr=head; ptr != NULL; ptr=ptr->next) {
	      if (ptr->next != NULL) {
	   	   hello << ptr->data << " ";
	      }
	      else if (ptr->next == NULL) {
	         hello << ptr->data;
	      }
	   }
	   return hello.str();
	}

};
