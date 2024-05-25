#include <iostream>
#include <vector>
using namespace std;



// Structure to represent an item
struct Item {
    int weight;
    int value;
};

// Function to find the actual items included in the knapsack
vector<Item> findItemsIncluded(int W, int wt[], int val[], int n, vector<vector<int>>& V) 
{
    vector<Item> itemsIncluded;
    int i = n, k = W;

    while (i > 0 && k > 0) {
        if (V[i][k] != V[i - 1][k]) {
            itemsIncluded.push_back({ wt[i - 1], val[i - 1] });
            k -= wt[i - 1];
        }
        i--;
    }

    return itemsIncluded;
}

// Function to solve the 0/1 Knapsack Problem
int knapsack(int W, int wt[], int val[], int n) {
    vector<vector<int>> V(n + 1, vector<int>(W + 1, 0));

    // Initialize first row and first column to 0
    for (int w = 0; w <= W; w++) {
        V[0][w] = 0;
    }
    for (int i = 1; i <= n; i++) {
        V[i][0] = 0;
    }

    // Fill the matrix
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w) {
                if (val[i - 1] + V[i - 1][w - wt[i - 1]] > V[i - 1][w]) {
                    V[i][w] = val[i - 1] + V[i - 1][w - wt[i - 1]];
                }
                else {
                    V[i][w] = V[i - 1][w];
                }
            }
            else {
                V[i][w] = V[i - 1][w];
            }
        }
    }

    // Find the actual items included in the knapsack
    vector<Item> itemsIncluded = findItemsIncluded(W, wt, val, n, V);
    cout << "Items included in the knapsack:" << endl;
    for (auto item : itemsIncluded) {
        cout << "Weight: " << item.weight << ", Value: " << item.value << endl;
    }

    // The maximum value will be at V[n][W]
    return V[n][W];
}

/*
int main() 
{
    int wt[] = { 2, 3, 4 , 5 };
    int val[] = { 3, 4, 5 ,6 };
  
    int W = 5;
    int n = sizeof(val) / sizeof(val[0]);

    cout << "Maximum value that can be obtained: " << knapsack(W, wt, val, n) << endl;

    return 0;
}
*/
