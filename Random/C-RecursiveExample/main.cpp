#include <iostream>
using namespace std;

void numberFunction(int i) {
   cout << "The number is: " << i << endl;
   if (i == 10) {
      return;
   }
   numberFunction(i + 1);
  // cout << "The number is: " << i << endl;
}

int F(int N) {
   int sum;
   if (N == 1) {
      return 1;
   }
   else {
      return (N * F(N-1));
   }
}

int main() {
   cout << F(10);
   
   
   /*for (int i = 0; i < 10; ++i) {
      numberFunction(i);
   }*/
   
   return 0;
}

/*
1. Base Case - Thing that ends the recursion (N == 0)
2. Recursive Step
3. Faith
4. Math by induction
*/