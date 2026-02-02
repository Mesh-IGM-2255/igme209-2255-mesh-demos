#include <iostream>
using namespace std;


void passByValue(int num)
{
	num += 20;
	cout << "by value + 20: " << num << endl;
}

// could call this with nullptr
void passByPtr(int* num)
{
	*num += 30; // dereference to the data, then add
	cout << "by ptr + 30: " << *num << endl;
}

void passByReference(int& num) // effectively a ptr to the passed in data,
							   // always deref'd when we use it
{
	num += 40;
	cout << "by ref + 40: " << num << endl;
}

