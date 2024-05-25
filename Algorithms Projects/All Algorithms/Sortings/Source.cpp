#include <iostream>
#include <vector>

using namespace std;

int numberOfChildren(vector<vector<int>>& MyTree) {

    int count = 0;

    int sizy = MyTree.size();



    for (int i = 0; i < sizy; ++i)

    {

        int numberOfChildren = 0;

        for (int j = 0; j < sizy; ++j) {

            if (MyTree[i][j] == 1)

            {

                numberOfChildren++;

            }

        }

        if (numberOfChildren >= 2) {

            count++;

        }

    }

    return count;

}

int main() {
    // Example usage:
    vector<vector<int>> tree = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };
    cout << "Number of nodes with 2 or more children: " << numberOfChildren(tree) << endl;
    return 0;
}