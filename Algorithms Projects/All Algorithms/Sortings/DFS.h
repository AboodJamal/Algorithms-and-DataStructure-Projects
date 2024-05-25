#include <iostream>
#include <vector>
#include <stack>.
#include <algorithm> // for sorting

using namespace std;

void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);

}

void DFS(vector<vector<int>>& G, int start) {
    int n = G.size(); // Number of nodes
    vector<int> visit(n, 0); // Initialize all nodes as unvisited
    stack<int> s;

    s.push(start); // Push the starting node onto the stack

    while (!s.empty()) {
        int x = s.top();
        s.pop();
        if (visit[x] == 1) // Skip if already visited
            continue;

        // Process node x
        cout << x << " ";
        visit[x] = 1; // Mark current node as visited


        sort(G[x].begin(), G[x].end(), greater<int>()); 

        // Traverse neighbors of x
        for (int y : G[x]) {
            if (visit[y] == 0) {
                s.push(y);
            }
        }
    }
}



/*

int main() {
    // Example usage
    int no_of_nodes = 11;
    vector<vector<int>> adjList(no_of_nodes);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 8);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 2, 8);
    addEdge(adjList, 3, 4);
    addEdge(adjList, 4, 9);
    addEdge(adjList, 8, 7);
    addEdge(adjList, 7, 4);
    addEdge(adjList, 7, 5);
    addEdge(adjList, 5, 6);

    int start_node = 1; // Starting node for DFS traversal
    cout << "DFS traversal from node " << start_node << ": ";
    DFS(adjList, start_node);
    return 0;
}
*/



