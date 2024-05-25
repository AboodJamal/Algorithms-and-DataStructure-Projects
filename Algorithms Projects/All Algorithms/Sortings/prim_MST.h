#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX

// Structure to represent an edge
struct Edge {
    int dest;
    int weight;
};

// Function to add an undirected edge to the graph
void addEdge(vector<vector<Edge>>& graph, int src, int dest, int weight) {
    graph[src].push_back({ dest, weight });
    graph[dest].push_back({ src, weight }); // Adding the reverse edge for undirected graph
}

// Function to find the vertex with minimum key value
int minKey(vector<int>& key, vector<bool>& flag, int V) {
    int min = INF, min_index;

    for (int v = 0; v < V; ++v) {
        if (flag[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to construct and print MST for a graph represented using adjacency list representation
void Prim(vector<vector<Edge>>& graph, int V, int start) {
    vector<int> parent(V, -1);  // Array to store parent of each vertex in MST
    vector<int> key(V, INF);     // Key values used to pick minimum weight edge in cut
    vector<bool> flag(V, false); // To represent set of vertices not yet included in MST

    // Initialize all keys as infinite and flag as 0 (not included in MST)
    for (int i = 0; i < V; ++i) {
        key[i] = INF;
        flag[i] = false;
    }

    // Always include the first vertex in MST
    key[start] = 0;

    // The MST will have V vertices
    for (int count = 0; count < V - 1; ++count) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, flag, V);

        // Mark the picked vertex as included in MST
        flag[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (const auto& edge : graph[u]) {
            int v = edge.dest;
            int weight = edge.weight;
            if (!flag[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    // Print the constructed MST
    cout << "Edge   Weight" << endl;
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << "    " << key[i] << endl;
    }
}

/*
int main() {
    // Example graph representation (adjacency list)
    int V = 9;  // Number of vertices
    vector<vector<Edge>> graph(V);

    // Adding edges to the graph using addEdge function
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 16);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 7, 8, 7);
    addEdge(graph, 7, 6, 1);
    addEdge(graph, 6, 5, 2);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 5, 3, 14);
    addEdge(graph, 5, 4, 10);
    addEdge(graph, 4, 3, 9);

    // Call Prim's algorithm with start vertex 0
    Prim(graph, V, 0);

    return 0;
}

*/

