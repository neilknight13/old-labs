#include <vector>
#include <iostream>
using namespace std;
const int CONSIZE=10;

template <typename Name, typename Value>

class HashMap {
   	Name myname;
      Value myvalue;
   public:
      void putName(Name arg) {myname = arg;};
      void putValue(Value arg) {myvalue = arg;};
      Name get() {return myname;}
      
      int hashme(Name /* or name*/ key) {
         unsigned char *ptr = (unsigned char *)&key;
         int sum = 0;
         for(int i = 0; i < sizeof(key); i++) {
            sum += ptr[i];
         }
         int hashval = sum % CONSIZE;
         cout << "Size = " << sizeof(key) << " Sum = " << sum << " hash " << hashval << endl;
         return hashval;
      }
      
	private:
	   pair <Name,Value> context;
	   struct node {
		   pair<Name, Value> context;
		   node *next;
	   };
	   node *context_array[CONSIZE];
};

int main () {
   HashMap<string, string> wordmap;
   cout <<wordmap.hashme("blah") << endl;
   return 0;
}