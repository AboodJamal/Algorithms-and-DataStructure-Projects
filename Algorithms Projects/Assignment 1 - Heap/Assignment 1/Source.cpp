#include<iostream>
#include<fstream>
#include"Heap.h"
using namespace std;

// 10, 5, 3, 2, 4 
// 6,5,3,2,4
// 9,5,6,7,1,3,10
// 10 9 8 3 4

int main()
{
	fstream valuesFile;
	valuesFile.open("C:\\Users\\Abdullah Jamal\\Desktop\\College\\Second year\\Second Term\\Algorithms\\Assignment 1 - Heap\\Values.txt", ios::in);
	if (!valuesFile.is_open()) {
		cout << "An Error occurred while opening the file." << endl;
		return 1;
	}
	Heap myHeap;
	double value;
	while (valuesFile >> value)
	{
		myHeap.insert(value);
	}
	cout << endl;
	cout << " The code segment reads some random values from a file and inserts them in the heap , and makes a Max-Heap as the default Heap " << endl << endl;
	cout << "The output after heapifyng the random values to Max-Heap : " << endl;
	myHeap.printHeap();
	cout << "The output after changing the heap type to Min-Heap  : " << endl;
	myHeap.typeChanger();
	myHeap.printHeap();




	// Done ÇáÍãÏááå

}// end of main function