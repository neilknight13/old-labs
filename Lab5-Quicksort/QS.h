#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "QSInterface.h"
using namespace std;

class QS : public QSInterface
{
public:
	QS() {table = NULL; arrayCount = 0; maxSize = 0;}
	~QS() {
      delete table;
	}
	void sortAll();
	void quickSort(int first, int last);
	int medianOfThree(int left, int right);
	int partition(int left, int right, int pivotIndex);
	string getArray() const;
	int getSize() const;
	bool addToArray(int value);
	bool createArray(int capacity);
	void clear();
private:
   int* table;
   int arrayCount;
   int maxSize;
};
