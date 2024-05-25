#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function to perform Breadth First Search on a graph
// represented using adjacency list
void BFS(vector<vector<int> >& adjList, int startNode,
	vector<bool>& visited)
{
	// Create a queue for BFS
	queue<int> q;

	// Mark the current node as visited and enqueue it
	visited[startNode] = true;
	q.push(startNode);

	// Iterate over the queue
	while (!q.empty()) {
		// Dequeue a vertex from queue and print it
		int currentNode = q.front();
		q.pop();
		cout << currentNode << " ";

		// Get all adjacent vertices of the dequeued vertex
		// currentNode If an adjacent has not been visited,
		// then mark it visited and enqueue it
		for (int neighbor : adjList[currentNode]) {
			if (!visited[neighbor]) {
				visited[neighbor] = true;
				q.push(neighbor);
			}
		}
	}
}

// Function to add an edge to the graph
void addEdge(vector<vector<int> >& adjList, int u, int v)
{
	adjList[u].push_back(v);
	adjList[v].push_back(u);
}

/*
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	// Number of vertices in the graph
	int vertices = 11;

	// Adjacency list representation of the graph
	vector<vector<int> > adjList(vertices);

	// Add edges to the graph
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

	// Mark all the vertices as not visited
	vector<bool> visited(vertices, false);

	// Perform BFS traversal starting from vertex 0
	cout << "Breadth First Traversal starting from vertex "
		"1: ";
	BFS(adjList, 1, visited);

	return 0;
}
*/

