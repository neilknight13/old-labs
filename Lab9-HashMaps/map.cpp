#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include "hashmap2.h"
//#include "VectorMap.h"
using namespace std;

list <string> lst;
int main(int argc, char **argv)
{
  ifstream file(argv[1]);

  // Read data
  while (!file.eof()) {
    string word, nopunct="";
    file >> word;
    
    for(auto &c : word) { // Remove Punctuation      
      if (isalpha(c)) {
        nopunct +=c;       
      }
    }
    lst.push_back(nopunct);
  }
  
  HashMap<string, vector<string>> wordmap;
  //VectorMap<string, vector<string>> wordmap;
  string state = "";
  for(list<string>::iterator it=lst.begin(); it !=lst.end(); it++) {
    wordmap[state].push_back(*it);
    state = *it;
  }
  
  srand(time(NULL)); // this line initializes the random number generated
                     // so you dont get the same thing every time
  state = "";
  for (int i = 0; i < 1000; i++) {
    //cout << "Wordmap state size is " << wordmap[state].size() << endl;
    int ind = rand() % wordmap[state].size();
    cout << wordmap[state][ind] << " "; //implement this and find a way to index into our map
    state = wordmap[state][ind];
  }
  cout << endl;
}