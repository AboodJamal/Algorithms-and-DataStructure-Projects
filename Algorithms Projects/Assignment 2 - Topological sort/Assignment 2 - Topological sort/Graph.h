#include<iostream>
#include<map>
#include<vector>
#include<list>
#include<stack> 


using namespace std;

template<typename type>
class Graph {
private:
	map<type, list<type>> graph; // a map where the key represents a node in the graph and the value is a list of its adjacent nodes (children).
	map<type, int> indegree; // a map to store the indegree of each node
	int n; // number of nodes

	void allTopologicalSortRec(stack<type>& result, map<type, bool>visited)  
	{
		// to avoid unnecessary recursive calls
		// when it is false in the end it goes to the last if statement and prints the topological sort
		bool flaggy = false;

		// iterats the graph map from he begining to the end
		for (auto iterator = graph.begin(); iterator != graph.end(); iterator++)
		{
			// check the indegree of the current vertex (it->first) and has been visited or not
			//(it->first) represents the key of the current element in the  map
			if (this->indegree[iterator->first] == 0 && !visited[iterator->first])
			{
				//  iterating through each adjacent vertex (child) of the current vertex (it->first).
				//  (it->second) represents the adjacency list of the current vertex in the graph
				for (const auto& child : iterator->second)
				{
					this->indegree[child]--;
				}
				result.push(iterator->first);
				visited[iterator->first] = true;
				this->allTopologicalSortRec(result, visited); 

				// Backtracking (fixing the changes done in the loop )
				visited[iterator->first] = false;
				result.pop(); 
				for (const auto& child : iterator->second) {
					this->indegree[child]++;
				}
				flaggy = true;
			}
		}

		// This situation implies that the current path does lead to a topological order, 
		// and thus the function prints the topological order stored in the result stack.
		if (!flaggy)
		{
			vector<type> tempVector;
			stack<type> tempStack = result; 
			while (!tempStack.empty())
			{
				tempVector.insert(tempVector.begin(), tempStack.top());
				tempStack.pop();
			}
			for (int i = 0; i < tempVector.size(); i++) 
			{
				cout << tempVector[i] <<" "; 
			}
			cout << endl;
		}
	}

public:
	// constructor
	Graph() {
		this->n = 0;
	}

	// checks if the graph is empty
	bool empty() const {
		return graph.empty();  
	}

	// returns n
	int size() const {
		return n; 
	}

	// adding an edge
	void insert(type parent, type child) 
	{
		// find(child) iterator , it returns an iterator to the key-value pair. If it is not found, it returns an iterator equal to this->graph.end().
		if (this->graph.find(child) == this->graph.end()) 
		{
			this->graph[child] = list<type>();
		}
		this->graph[parent].push_back(child); // pushing the child into the adjacency list of the parent value .
		this->indegree[child]++; // the indegree of the child node is incremented by one, to indicate that a parent is poining to it
		this->n++;
	}  


	void allTopologicalSort() 
	{
		// map of the value and in fonr of it a bolean value , in which it indicates if that value is visited or not
		map<type, bool>visited;

		stack<type> result; // a stack to store the result
		this->allTopologicalSortRec(result, visited);
	}

	void print() const 
	{
		cout << "parent  "<< "children"<<endl;
		for (const auto& parent : this->graph) {
			cout << "(" << parent.first << "  -->  ";
			for (const auto& child : parent.second) {
				cout << child << " ";
			}
			cout << "\t)" << endl;
		}
	}
};