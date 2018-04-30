# Search
This Searching Example will illustrate the benefits of using a binary search approach.  First initialize the array with values that we can search for.
```c++
#include <iostream>
#include <time.h>
using namespace std;

int main() 
{
 long start;
 long end;
 const int searchSize = 100000000;
 int *array=new int[searchSize];
 for(int i = 0; i < searchSize; i++) {
  array[i] = i*2; // Initialize the data with 2x the index
 }
 int searchval = (searchSize-1)*2; // Look for the last element
 cout << "Linear Search for "<<searchval<<endl;
 ```
 Now start the clock and use a linear search to find the value
 ```c++
 start = clock(); // Start Time

 for (int i = 0; i < searchSize; i++)
   if (searchval == array[i]) {
    cout << "Found "<<searchval<<" at "<<i<<endl;
   }
    
 end = clock();

 double etime = (end - start)/(double)CLOCKS_PER_SEC;
 cout << "time: " << etime << endl;
 ```
 Now lets try a binary search.  In this case we will assume the array is sorted and will break the array in half each iteration to look only in the half where the value could possibly be.
 ```c++
 start = clock();
 int low = 0;
 int high = searchSize-1;
 while(low<=high)  {
  int mid = (high-low)/2+low;
  // cout << "low "<<low<<" mid "<<mid<<" high "<<high<<endl;
  if(searchval < array[mid]) {
    high = mid - 1;
  } else {
    if(searchval > array[mid]) {
      low = mid + 1;
    } else {
      cout <<"found "<<searchval<<" at "<<mid<<endl;
      break;
    }
  }
 }
 ```
 Now lets look at the problem in detail on a problem that is small enough that we can do it by hand.
 ```c++
 end = clock();
 etime = (end - start)/(double)CLOCKS_PER_SEC;
 cout << "time: " << etime << endl << endl;

 int array2[]={16,	18,	24,	32,	36,	48,	55,	64,	72,	75,	77,	83,	90,	96,	99};
 low = 0;
 high = sizeof(array2)/sizeof(array2[0])-1;
 searchval=36;
 while(low<=high)  {
  int mid = (high-low)/2+low;
  cout << "low "<<low<<" mid "<<mid<<" high "<<high<<endl;
  if(searchval < array2[mid]) {
    high = mid - 1;
  } else {
    if(searchval > array2[mid]) {
      low = mid + 1;
    } else {
      cout <<"found "<<searchval<<" at "<<mid<<endl;
      break;
    }
  }
 }
}
```
