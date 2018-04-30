#include <iostream>
#include <utility>

using namespace std;
template <class Name; class Value>

const int TABLESIZE = 10;

class HashMap {
   private:
      Name myname;
      Value myvalue;
      pair <Name, Value> context;
      context.first = myname;
      context.second = myvalue;
      struct node {
         pair<Name, Value> context;
         node *next;
      };
   public:
      int hash(Name geeber) {
         char *ptr = (char *)&geeber;
         int sum = 0;
         for (int i = 0; i < sizeof(geeber); i++) {
            sum += ptr[i];
         }
         return (sum % TABLESIZE);
      }
};


0 - vector at index 0
1 vector at index 1
2 vector at index 2
3
4
5


int main () {

   HashMap <string, vector<string>> foo;
      
   return 0;
}