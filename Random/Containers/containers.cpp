#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <list>
#include <queue>

using namespace std;

void Print(vector<int> intVector) { 
   for (vector<int>::iterator it = intVector.begin(); it != intVector.end(); it++) {
      cout << *it << " ";
   }
   cout << endl;
}

void Print(stack<int> intStack) {
   stack<int> temp;
   while (intStack.size()) {
      cout << intStack.top() << " ";
      temp.push(intStack.top());
      intStack.pop();
   }
   while (temp.size()) {
      intStack.push(temp.top());
      temp.pop();
   }
   cout << endl;
}

void print(list<int> mylist) {
      for (list<int>::iterator it = mylist.begin(); it != mylist.end(); it++) {
      cout << *it << " ";
      }
   cout << endl;
}

void print(queue<int> mydeque) {
      for (queue<int>::iterator it = mydeque.front(); it != mydeque.back(); it++) {
      cout << *it << " ";
      }
   cout << endl;
}

int main() {
   //vectors example
   vector <int> intVector;
   intVector.push_back(1);
   intVector.push_back(2);
   intVector[0] = 3;
   Print (intVector);
   
   //stacks
   stack<int> intStack;
   intStack.push(4);
   intStack.push(534);
   Print(intStack);
   
   //lists example
   list<int> intlist;
   intlist.push_back(7);
   intlist.push_back(8);
   intlist.push_back(9999);
   print(intlist);
   
   //queue example
   queue<int> intdeque;
   intdeque.push(10);
   intdeque.push(9);
   print(intdeque);
}