#include <iostream>
#include <string>
#include "MV.h"
#include "MyVector.h"
#include "VectorInterface.h"
using namespace std;

int main()
{
   MyVector<int> myvecint;
    myvecint.push_back(5);
    myvecint.insertAt(0, 6);
    cout << "Size "<<myvecint.size()<<endl;
    myvecint.remove(0);
    cout << "Zero " << myvecint.at(0)<<endl;
    
}