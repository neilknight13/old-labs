#include <vector>
#include <iostream>
using namespace std;

template <typename Name, typename Value>

class VectorMap {
   private:
      vector<Name> nameVector;
      vector<Value> valueVector;
   public:
      Value &operator [](Name opname) {
         return at(opname);
      }
      
      Value &at(Name param) {
         // O(n) -
         for (int i = 0; i < nameVector.size(); i++) {
            if (param == nameVector.at(i)) {
               return valueVector[i];
            }
         }
         //if value not found, create a new vector assocaited witht he parameter
         nameVector.push_back(param);
         Value emptyval;
         valueVector.push_back(emptyval);
         return valueVector.back();
      }
};