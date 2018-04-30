#include <vector>
#include <iostream>
using namespace std;
const int CONSIZE=10;

template <typename Name, typename Value>

class HashMap {
   private:
      vector<Name> nameVector; // was in vector.h
      vector<Value> valueVector; //was in vector.
      struct Node {
         Name data; // The data we are storing
   	   Node* next; // A pointer to the next Node 
   	   Node(const Name& the_data, Node* next_val = NULL) :
   	      data(the_data) {next = next_val;}
      };
      vector<Node*> nodeVector;
      //Node *context_array[CONSIZE];
   public:
      HashMap() {
         //cout << "creating the hashmap" << endl;
         for (int i = 0; i < CONSIZE; i++) {
            Node* temp = new Node("Clement");
            nodeVector.push_back(temp);
         }
         //cout << "finished creating the hashmap" << endl;
      }
      
      int hashme(string param) {
         unsigned char *ptr = (unsigned char *)param.c_str();
         int sum = 0;
         for(int i = 0; i < param.size(); i++) {
            sum += ptr[i];
         }
         int hashval = sum % CONSIZE;
         //cout << "Size = "<<sizeof(param)<<" Sum = "<<sum<<" hash "<<hashval<<endl;
         return hashval;
         } 

      
      Value &operator [](Name opname) {
         return at(opname);
      }
      
      Value &at(Name param) {
         // O(n) -
         int hashval = hashme(param);
         Node* temp = nodeVector.at(hashval);
         while (temp->next != NULL) {
            if (temp->data == param) {
               //cout << "debug statement 3" << endl;
               return valueVector[hashval]; //what does this do??
            }
            temp = temp->next;
         }

         	   if (nodeVector.at(hashval) == NULL) {
         			Node* temp2 = new Node(param);
		            temp2->next = nodeVector.at(hashval);
		            nodeVector.at(hashval) = temp2;
		            Value emptyval;
		            valueVector.push_back(emptyval);
         			return valueVector.back();
         		}
         		Node* temp2 = nodeVector.at(hashval);
         		while (temp2->next != NULL) {
         			temp2 = temp2->next;
         		}
         		if (temp2->next == NULL) {
         			Node* newTail = new Node(param);
         			temp2->next = newTail;
         			newTail->next = NULL;
         		}
               Value emptyval;
               valueVector.push_back(emptyval);
               return valueVector.back();
         }
};