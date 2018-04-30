#include "VectorInterface.h"
using namespace std;
template <class T>
class MyVector: public VectorInterface<T>
{

public:

	MyVector(void) {cout << "In constructor"<<endl;};
	~MyVector(void) {cout << "In destructor"<<endl;};

	void push_back(T value){cout << "In push_back"<<endl;};
	
	/* Insert value after given index */
	void insertAt(int index, T value){cout << "In insertAt"<<endl;};

	/* Remove the element at index */
	void remove(int index) {cout << "In remove"<<endl;};
	
	T at(int index){cout << "In at"<<endl;};

	int size(){cout << "In size"<<endl; return(0);};
};