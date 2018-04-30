#include <vector>

#include <iostream>
using namespace std;


void calculateSum(int sum, vector<int> data, int lowIndex, int highIndex) {
   if (vector.at(lowIndex) + vector.at(highIndex) = sum) {
      return true;
   }
   else if (vector.at(lowIndex) + vector.at(highIndex) < sum) {
      calculateSum(sum, data, lowIndex + 1, highIndex);
   }
   else if (vector.at(lowIndex) + vector.at(highIndex) > sum) {
      calculateSum(sum, data, lowIndex, highIndex - 1);
   }
   else if (lowIndex >= highIndex) {
      return false;
   }
   
}
int main () {
   vector<int> data;
   int newNum = 0;
   while (cin >> newNum) {
      data.insert(newNum);
   }
   calculateSum(sum, data, 0, data.size());
   
   return 0;
}