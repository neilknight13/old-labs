
#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include <vector>
using namespace std;
	

int main() {
   vector<int> list = {23, 14, 65, 3, 19, 2, 71, 12, 8, 61, 5, 25};
   
   for (int i = 0; i < list.size(); ++i) {
      int min = list.at(i);
      for (int j = i + 1; j < list.size() - 1; ++j) {
         if (list.at(j) < min) {
            min = list.at(j);
            int temp = list.at(i);
            list.at(i) = min;
            list.at(j) = temp;
         } 
      }
   }
   
   for (int i = 0; i < list.size(); ++i) {
      cout << list.at(i) << ",";
   }
   return 0;
}

