#include<iostream>
#include <vector>
#include <limits>
using namespace std;

// Function to find the maximum of three integers
int max(int a, int b, int c) {
    return max(a, max(b, c));
}

// Function to find the maximum contiguous subarray that crosses the midpoint
int findCrossingMaxSubarray(vector<int>& A, int l, int m, int r) {
    int leftSum = numeric_limits<int>::min();
    int sum = 0;
    for (int i = m; i >= l; i--) {
        sum += A[i];
        if (sum > leftSum)
            leftSum = sum;
    }

    int rightSum = numeric_limits<int>::min();
    sum = 0;
    for (int i = m + 1; i <= r; i++) {
        sum += A[i];
        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

// Function to find the Maximum Contiguous Sub-array
int MCS(vector<int>& A, int l, int r) {
    if (l == r)
        return A[r];
    else {
        int m = (l + r) / 2;
        int crossingSum = findCrossingMaxSubarray(A, l, m, r);
        int leftSum = MCS(A, l, m);
        int rightSum = MCS(A, m + 1, r);
        return max(crossingSum, max(leftSum, rightSum));
    }
}



/*

int main() {
    vector<int> A = { -3,2,1,-4,5,2,-1,3,-1 }; // Example input array
    int n = A.size();
    int maxSubarraySum = MCS(A, 0, n - 1);
    cout << "Maximum Contiguous Subarray Sum: " << maxSubarraySum << endl;
    return 0;
}
*/