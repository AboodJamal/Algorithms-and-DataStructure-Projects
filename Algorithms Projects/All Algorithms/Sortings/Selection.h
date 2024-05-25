#include<iostream>
using namespace std;


int selection(int L[], int n, int k)
{
    for (int i = 0; i < k; i++) // Outer loop for k iterations
    {
        int largest = L[0]; // Initialize largest with the first element
        int largestLocation = 0;
        for (int j = 1; j < n - i; j++) // Inner loop from 1 to n - i
        {
            if (L[j] > largest)
            {
                largest = L[j];
                largestLocation = j;
            }
        }
        // Swap the largest element found with L[n - 1 - i]
        int temp = L[n - 1 - i];
        L[n - 1 - i] = L[largestLocation];
        L[largestLocation] = temp;
    }
    return L[n - k]; // Return the kth largest element
}
