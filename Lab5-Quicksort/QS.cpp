#include "QS.h"
using namespace std;


	/*
	* sortAll()
	*
	* Sorts elements of the array.  After this function is called, every
	* element in the array is less than or equal its successor.
	*
	* Does nothing if the array is empty.
	*/
void QS::sortAll() {
   quickSort(0, arrayCount - 1);
}
void QS::quickSort(int first, int last) {
   if ((last - first) < 2) return;
   int pivot = medianOfThree(first, last);
   pivot = partition(first, last, pivot);
   quickSort(first,pivot);
   quickSort(pivot+1, last);
}
   

	/*
	* medianOfThree()
	*
	* The median of three pivot selection has two parts:
	*
	* 1) Calculates the middle index by averaging the given left and right indices:
	*
	* middle = (left + right)/2
	*
	* 2) Then bubble-sorts the values at the left, middle, and right indices.
	*
	* After this method is called, data[left] <= data[middle] <= data[right].
	* The middle index will be returned.
	*
	* Returns -1 if the array is empty, if either of the given integers
	* is out of bounds, or if the left index is not less than the right
	* index.
	*
	* @param left
	* 		the left boundary for the subarray from which to find a pivot
	* @param right
	* 		the right boundary for the subarray from which to find a pivot
	* @return
	*		the index of the pivot (middle index); -1 if provided with invalid input
	*/
int QS::medianOfThree(int left, int right) {
   int middle = (left+right) / 2;
   int temp;
   if (table == NULL || left < 0 || right > arrayCount || left >= right || arrayCount == 0 || right > arrayCount - 1) {
      return -1;
   }
   if (table[left] > table[middle]) {
      temp = table[left];
      table[left] = table[middle];
      table[middle] = temp;
   }
   if (table[right] < table[middle]) {
      temp = table[right];
      table[right] = table[middle];
      table[middle] = temp;
   }
   if (table[middle] < table[left]) {
      temp = table[middle];
      table[middle] = table[left];
      table[left] = temp;
   }
   return middle;
}

	/*
	* Partitions a subarray around a pivot value selected according to
	* median-of-three pivot selection.  Because there are multiple ways to partition a list,
	* we will follow the algorithm on page 611 of the course text when testing this function.
	*
	* The values which are smaller than the pivot should be placed to the left
	* of the pivot; the values which are larger than the pivot should be placed
	* to the right of the pivot.
	*
	* Returns -1 if the array is null, if either of the given integers is out of
	* bounds, or if the first integer is not less than the second integer, or if the
	* pivot is not within the sub-array designated by left and right.
	*
	* @param left
	* 		the left boundary for the subarray to partition
	* @param right
	* 		the right boundary for the subarray to partition
	* @param pivotIndex
	* 		the index of the pivot in the subarray
	* @return
	*		the pivot's ending index after the partition completes; -1 if
	* 		provided with bad input
	*/
int QS::partition(int left, int right, int pivotIndex) {
   int temp;
   if (table == NULL || left < 0 || right > arrayCount - 1 || left >= right || pivotIndex > right || pivotIndex < left 
      || pivotIndex > arrayCount - 1) {
      return -1;
   }
   else {
      temp = table[pivotIndex];  table[pivotIndex] = table[left];   table[left] = temp; //STEP 1
      int up = left + 1;   int down = right; //STEP 2
      do { //step 3
         while ((table[up]<=table[left]) && (up < right)) {up++;} //step 4
         while ((table[down]>=table[left]) && (down > left)) {down--;} //step 5
         if (up<down) {temp = table[up]; table[up] = table[down]; table[down] = temp;} //step 6
      } while (up < down); //step 7
      temp = table[left]; table[left] = table[down];  table[down] = temp; // step 8
      return down; // step 9
   }
}

	/*
	* Produces a comma delimited string representation of the array. For example: if my array
	* looked like {5,7,2,9,0}, then the string to be returned would look like "5,7,2,9,0"
	* with no trailing comma.  The number of cells included equals the number of values added.
	* Do not include the entire array if the array has yet to be filled.
	*
	* Returns an empty string, if the array is NULL or empty.
	*
	* @return
	*		the string representation of the current array
	*/
string QS::getArray() const {
   string entireArray;
   if (table == NULL) {
      return entireArray;;
   }
   else {
      for (int i = 0; i <= arrayCount - 1; ++i) {
         /*if (i == maxSize) {
            entireArray = entireArray + to_string(table[i]);
         }
         else {*/
            entireArray = entireArray + to_string(table[i]) + ",";   
         //}
      }
      entireArray = entireArray.substr(0, entireArray.length() - 1);
      return entireArray;
   }
}

	/*
	* Returns the number of elements which have been added to the array.
	*/
int QS::getSize() const {
   return arrayCount;
}

	/*
	* Adds the given value to the end of the array starting at index 0.
	* For example, the first time addToArray is called,
	* the give value should be found at index 0.
	* 2nd time, value should be found at index 1.
	* 3rd, index 2, etc up to its max capacity.
	*
	* If the array is filled, do nothing.
	* returns true if a value was added, false otherwise.
	*/
bool QS::addToArray(int value) {  ////DONE
   if (arrayCount <= maxSize) {
      table[arrayCount] = value;
      arrayCount = arrayCount + 1;
      return true;
   }
   else {
      return false;
   }
}

	/*
	* Dynamically allocates an array with the given capacity.
	* If a previous array had been allocated, delete the previous array.
	* Returns false if the given capacity is non-positive, true otherwise.
	*
	* @param
	*		size of array
	* @return
	*		true if the array was created, false otherwise
	*/
bool QS::createArray(int capacity) { 
   if (table!=0) {
      delete [] table;
      table = new int[capacity];
      arrayCount = 0;
      maxSize = capacity - 1;
   }
   else {
      table = new int[capacity];
      arrayCount = 0;
      maxSize = capacity - 1;
   }
   if (table == 0 || capacity < 0) {
      return false;
   }
   else {
      return true;
   }
}

	/*
	* Resets the array to an empty or NULL state.
	*/
void QS::clear() {
   arrayCount = 0;
   maxSize = 0;
   delete table;
   table = NULL;
}

