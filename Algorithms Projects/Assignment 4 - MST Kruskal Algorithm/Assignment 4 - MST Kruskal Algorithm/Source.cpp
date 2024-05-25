#include<iostream>
#include"Kruskal.h"
using namespace std;


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

