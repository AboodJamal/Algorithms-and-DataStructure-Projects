#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <limits> 
#include <iomanip> 
using namespace std;


// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) 
    {
        for (int val : row) 
        {
            cout << setw(3) << val << " "; // setw for column width
        }
        cout << endl;
    }
    cout << endl;
}


// Function to generate a strongly connected graph represented as an adjacency matrix with zeros on the diagonal
vector<vector<int>> generateStronglyConnectedGraph(int size) 
{
    vector<vector<int>> stronglyConnectedGraph(size, vector<int>(size, 0));
    srand(time(0));
    int cellValue;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) 
        {
            // Generate a random non-zero value between 1 and 100
            cellValue = rand() % 100 + 1;;
            stronglyConnectedGraph[i][j] = cellValue;
        }
    }

    // Fill diagonal with zeros
    for (int i = 0; i < size; i++)
    {
        stronglyConnectedGraph[i][i] = 0; 
    }


    return stronglyConnectedGraph;
}



// Function to compute the sum of differences for a given matrix after reduces each row and column of the matrix 
//by subtracting the minimum non-zero value from all non-zero elements in that row or column.
int computeSumOfDifferences(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int sumOfDifferences = 0; 
    // Reduce rows
    for (int i = 0; i < n; ++i) 
    {
        int minVal = numeric_limits<int>::max(); // Initialize to the maximum possible value  
        int numbersNotZeroInOneLine = 0; // (to count non-zero values in one line) if it is 1 or less it means that the only number on the line will not be added to the sumOfDifferences .

        for (int j = 0; j < n; ++j) 
        {
            // Check if the current cell is non-zero
            if (matrix[i][j] != 0)
            {
                minVal = min(minVal, matrix[i][j]); // updating the minimum value
                numbersNotZeroInOneLine++;
            }
        }
        // If there are more than one non-zero value in the row, do row reduction
        if (numbersNotZeroInOneLine > 1)
        {
            sumOfDifferences += minVal; 
            for (int j = 0; j < n; ++j) 
            {
                if (matrix[i][j] != 0)
                    matrix[i][j] -= minVal;
            }
        }
        
    }
    cout << "After subtracting the smallest element from each row" << endl;
    printMatrix(matrix);
    
    // Reduce columns
    for (int j = 0; j < n; ++j) {
        int minVal = numeric_limits<int>::max(); // Initialize to the maximum possible value 
        int numbersNotZeroInOneLine = 0;  // (to count non-zero values in one line) if it is 1 or less it means that the only number on the line will not be added to the sumOfDifferences .

        for (int i = 0; i < n; ++i) 
        {
            // Check if the current cell is non-zero
            if (matrix[i][j] != 0)
            {
                minVal = min(minVal, matrix[i][j]); // updating the minimum value
                numbersNotZeroInOneLine++;
            }
                
        }
        // If there are more than one non-zero value in the row, do column reduction
        if (numbersNotZeroInOneLine > 1)
        {
               sumOfDifferences += minVal;

                for (int i = 0; i < n; ++i) 
                {
                    if (matrix[i][j] != 0)
                        matrix[i][j] -= minVal;
                }
        }
       
    }
    cout << "After subtracting the smallest element from each column" << endl; 
    printMatrix(matrix);


    return sumOfDifferences;
}

int main() 
{
    cout << " In this program, the code makes a random Adjacency Matrix of a specific size chosen by the user, \n then the code computes the Sum of Differences" << endl << endl;
    int size;
    cout << "Choose the size of the matrix : ";
    cin >> size;
    while (size < 1)
    {
        cout << "Size can't be negative , choose agian : ";
        cin >> size;
    }

    vector<vector<int>> adjacencyMatrix = generateStronglyConnectedGraph(size);

    cout << "The Adjacency Matrix:"<<endl;
    printMatrix(adjacencyMatrix);

    // Compute sum of differences
    int sumOfDifferences = computeSumOfDifferences(adjacencyMatrix);
    cout << "\nSum of Differences: " << sumOfDifferences << endl;

}



// Done ÇáÍãÏááå




