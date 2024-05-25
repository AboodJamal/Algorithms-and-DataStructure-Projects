
#define N 6 
#include <stdbool.h> 
#include <stdio.h> 
#include <iostream>
#include <iomanip> 

using namespace std;

//function to print the solution
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << setw(2) << board[i][j]<< " ";
        cout << endl<<endl;
    }
}

// function to check whether the position is safe or not 
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// The function that solves the problem using backtracking 
bool solveNQUtil(int board[N][N], int col)
{
    if (col >= N)
        return true;


    for (int i = 0; i < N; i++) {
        //if it is safe to place the queen at position i,col -> place it
        if (isSafe(board, i, col)) {

            board[i][col] = 1;


            if (solveNQUtil(board, col + 1))
                return true;

            //backtrack if the above condition is false
            board[i][col] = 0; // BACKTRACK 
        }
    }


    return false;
}

/*
// driver program to test above function 
int main()
{
    int board[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (solveNQUtil(board, 0) == false) {
        cout << "Solution does not exist";
        return 0;
    }

    printSolution(board);
    return true;
    return 0;
}

*/
