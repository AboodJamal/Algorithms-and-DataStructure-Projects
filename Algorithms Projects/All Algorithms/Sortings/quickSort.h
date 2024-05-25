// C++ Implementation of the Quick Sort Algorithm.
#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{

	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

	// base case
	if (start >= end)
		return;

	// partitioning the array
	int p = partition(arr, start, end);

	// Sorting the left part
	quickSort(arr, start, p - 1);

	// Sorting the right part
	quickSort(arr, p + 1, end);
}

void printArray2(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
}
/*

int main()
{

	int arr[] = { 200 , 90 , 60 , 44 , 43 , 101 , 100 , 99 , -5 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is" << endl;
	printArray2(arr, arr_size);

	quickSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is" << endl;
	printArray2(arr, arr_size);

}

*/