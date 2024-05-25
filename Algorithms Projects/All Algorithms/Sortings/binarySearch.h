#include <iostream>
using namespace std;

int binarySearch(int L[], int i, int j, int key) {
    if (i <= j) 
    { // this means we have elements in the array
        int k = i + (j - i) / 2; // Calculate the middle index correctly
        if (L[k] == key) {
            return k;
        }
        else if (L[k] < key) {
            return binarySearch(L, k + 1, j, key);
        }
        else if (L[k] > key) {
            return binarySearch(L, i, k - 1, key);
        }
    }
    return -1;
}


/*
int main()
{
    int arr[] = { 19, 20, 77,100, 900 }; // array has to be sorted
    int wantedNumber = 100;
    int arraySize = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, arraySize - 1, wantedNumber);
    (result == -1) ? cout << "Element is not present in array":cout << "Element is present at index " << result;
}
*/