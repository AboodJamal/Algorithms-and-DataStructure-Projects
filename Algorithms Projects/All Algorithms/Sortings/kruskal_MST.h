#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int vertex1; // source vertex
    int vertex2; // destination vertex
    int weight; // weight of the edge
};
// compares two edges based on their weights. It's used later for sorting the edges
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

//undirected graph
class Graph
{
private:
    int n; // number of vertices
    vector<Edge> edges; // vector of edges (each cell represents v1,v2 and weight)

public:
    Graph(int V) : n(V) {}

    // Adds an edge to the graph
    void addEdge(int vertex1, int vertex2, int weight) {
        edges.push_back({ vertex1, vertex2, weight });
    }

    // It uses path compression to find the root of the set to which element 'i' belongs.
    // int 'i' wis the element whose root needs to be found.
    // so, if 'i' is not a root, it recursively calls the find function on its parent until it reaches a root
    int find(vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return parent[i] = find(parent, parent[i]);
    }

    // Perform union of two subsets
    // v1 is the element whose set needs to be merged.
    // v2 is the element whose set needs to be merged with the set containing x.
    void unionSet(vector<int>& parent, int v1, int v2) {
        int xroot = find(parent, v1); // finds the root of the set containing element v1
        int yroot = find(parent, v2); // finds the root of the set containing element v2
        parent[xroot] = yroot;
    }


    // Function to find MST using Kruskal's algorithm   
    void kruskalMST() {
        vector<Edge> result;

        // Sort edges by weight ascendingly
        sort(edges.begin(), edges.end(), compare);

        vector<int> vertexParent(n, -1); // indicating -1 initially, each vertex is a separate disjoint set. 

        int count = 0, i = 0;
        while (count < n - 1 && i < edges.size()) {
            Edge currentEdge = edges[i];
            int v1 = find(vertexParent, currentEdge.vertex1);
            int v2 = find(vertexParent, currentEdge.vertex2);

            if (v1 != v2) // Checks if adding the edge does not create a cycle in the MST.
            {
                result.push_back(currentEdge); //ading the edge to the MST
                unionSet(vertexParent, v1, v2); // merging the two sets
                count++;
            }
            i++;
        }

        int totalWeight = 0;
        // Print the MST edges and total weight
        cout << "Edges in the Minimum Spanning Tree ( MST ) :" << endl;
        for (const auto& edge : result) {
            cout << edge.vertex1 << " - " << edge.vertex2 << " : " << edge.weight << endl;
            totalWeight += edge.weight;

        }
        cout << "Total weight of Minimum Spanning Tree: " << totalWeight << endl;
    }
};


/*

int main()
{
    Graph MST_Graph(20);
    MST_Graph.addEdge(1, 2, 8);
    MST_Graph.addEdge(3, 1, 2);
    MST_Graph.addEdge(1, 4, 14);
    MST_Graph.addEdge(2, 4, 21);
    MST_Graph.addEdge(3, 4, 25);
    MST_Graph.addEdge(3, 5, 19);
    MST_Graph.addEdge(4, 5, 17);
    MST_Graph.addEdge(4, 6, 13);
    MST_Graph.addEdge(5, 6, 5);
    MST_Graph.addEdge(5, 7, 9);
    MST_Graph.addEdge(6, 7, 1);

    MST_Graph.kruskalMST();

}
*/