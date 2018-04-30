# OperatorOverloading
In order to use your HashMap class, we will need to be able to put things into the map and take things out. One version of the maps lab created a map from a string to a vector of strings.  This version used the following syntax to access the map:
```c++
  map<string, vector<string>> wordmap;
  string state = "";
  for(list<string>::iterator it=lst.begin(); it !=lst.end(); it++) {
    wordmap[state].push_back(*it);
    state = *it;
  }
  
  srand(time(NULL)); // this line initializes the random number generated
                     // so you dont get the same thing every time
  state = "";
  for (int i = 0; i < 100; i++) {
    int ind = rand() % wordmap[state].size();
    cout << wordmap[state][ind] << " ";
    state = wordmap[state][ind];
  }
  cout << endl;
```
So, we need a way of introducing the square bracket syntax into our HashMap class.  For this exercise, we are going to create a class that does not use a hash, but keeps the keys in one vector and the values in another vector.  We will show you how to perform operator overloading in this implementation in hopes that it will help you in your final implementation.

First, lets set up the basic class with the vectors to hold keys and values
```c++
#include <iostream>
#include <vector>
using namespace std;
template <class Name, class Value>
class VectorMap {
  private:
	vector<Name> name_vector;
	vector <Value> value_vector;
	
  public:

	Value &at(Name name) {
		for(int i = 0; i < name_vector.size(); i++) {
			if(name_vector[i]==name) {
				return value_vector[i];
			}
		}
		// If it doesnt exist, create it.
		name_vector.push_back(name);
		Value emptyval;
		value_vector.push_back(emptyval);
		return value_vector.back();
	}
};
```
Notice that the function at(Name name) is a function that will look up name and return a reference to the entry in the value_vector.  But we need to be able to use the square bracket syntax.  It turns out that the square brackets are just a function, so we can declare this function and use it.
```c++
	Value &operator[](Name opname) {
		return at(opname);
	}
```
The following statements are equivalent:
```c++
foo.operator[]("Hello")
foo["Hello"]
```
Now all you have to do it to write your own at() function that performs the hash in order to complete the assignment.
