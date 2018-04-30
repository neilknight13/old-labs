#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <sstream>
#include <map>
#include <list>
using namespace std;

int main (int argc, char *argv[]) {
   ofstream newFile;
   string fileName = argv[1];
   map<string, string> wordmap;
   for (int i = 0; i < fileName.size(); ++i) {
      if (fileName.find('.') == i) {
         fileName = fileName.substr(0, i);
      }
   }

   vector<string> tokens;
   set<string> unique;
   string next_line;  
   ifstream in(argv[1]);
   srand(time(NULL));
   while (getline(in, next_line)) {
      istringstream iss(next_line);
      string token;
         while (iss >> token) {
            string nopunct = "";
            for(auto &c : token) {      
               if (isalpha(c)) {
                  nopunct +=c;       
               }
            }
		      unique.insert(nopunct); //PART 1
		      tokens.push_back(nopunct); //PART 2
	   }
   }
   string last=""; //initialize map1 - PART 3
   for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
      wordmap[last]=*it;
      last = *it;
   }
   cout << "Number of words "<< tokens.size()<<endl;
   cout << "Number of unique words "<< unique.size()<<endl;
   
   //create set file for PART 1
   newFile.open(fileName + "_set.txt");
   for (set<string>::iterator it=unique.begin(); it!=unique.end(); ++it) {
      newFile << *it << endl;
   }
   newFile.close();
   
   //create vector file for PART 2
   newFile.open(fileName + "_vector.txt");
   for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); ++it) {
      newFile << *it << endl;
   }
   newFile.close();
   
   //create map1 file for PART 3
   newFile.open(fileName + "_1_1.txt");
   for (map<string, string>::iterator i=wordmap.begin(); i!=wordmap.end(); i++) {
      if (i != wordmap.begin()) {
         newFile << i->first << ", " << i->second << endl;
      }
   }
   newFile.close();
   
   //////////////////UNCOMMENT THIS PART TO RUN PART 4/////////////////
   
   
   
   //Creating another map for PART 4 and 5
   map<string, vector<string>> wordmap2;
   string newInput = "";
   for(vector<string>::iterator it=tokens.begin(); it !=tokens.end(); it++) {
      wordmap2[newInput].push_back(*it);
      newInput = *it;
   }
   
   string state = "";
   for(int i = 0; i < 100; i++){
      cout << wordmap[state] << " ";
      state = wordmap[state];
   }
   cout << endl << endl;
   
   //GENERATES 100 WORD SERMON FOR PART 4
   for (int i = 0; i < 100; i++) {
      int ind = rand() % wordmap2[state].size();
      cout << wordmap2[state][ind] << " ";
      state = wordmap2[state][ind];
   }
   cout << endl << endl;
   
   
   
   ///////////////////////////////////////////////////////////////////
   
   
   //////////This next part couts the words associated with Nephi - PART 5////////////////////
   
   
   
   for (map<string, vector<string>>::iterator i=wordmap2.begin(); i!=wordmap2.end(); i++) {
      if (i != wordmap2.begin() && i->first == "Nephi") {
         cout << i->first << ": ";
         for (auto it2 = i->second.begin(); it2 != i->second.end(); ++it2) {
            cout << *it2 << " ";
         }
      }
   }
   
   cout << endl << endl;
   
   
   
   /////////////////////////////////////////////////////
   
   
   //Generating another map using context of value M. - PART 6
   int contextValue=4; //changing M will change the amount of context the map uses.
   map<list<string>, vector<string>> wordmap3;
   list<string> newState;
   for (int i = 0; i < contextValue; i++) {
      newState.push_back("");
   }
                        
   for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
      wordmap3[newState].push_back(*it);
      newState.push_back(*it);
      newState.pop_front();
   }
   
   newState.clear();
   for (int i = 0; i < contextValue; i++) {
      newState.push_back("");
   }
   for (int i = 0; i < 100; i++) { //change the i < 100 to whatever length of text you want
      int ind = rand() % wordmap3[newState].size();
      cout << wordmap3[newState][ind]<<" ";
      newState.push_back(wordmap3[newState][ind]);
      newState.pop_front();
   }
   
   
   return 0;
}

///NOTE TO TA: Part 7 is creating a poem in the style of Walt Whitman and then creating a text similar
//to Harry Potter 3

