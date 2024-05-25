#include<iostream>
#include<map>
#include<list>
#include <algorithm>
#include"Graph.h"

using namespace std;

int main()
{
	Graph<double> myGraph; 
	myGraph.insert(0,1);
	myGraph.insert(0,2);
	myGraph.insert(1,4);
	myGraph.insert(1,3);
	myGraph.insert(3, 4);
	myGraph.insert(2, 3);


	myGraph.print();
	cout << endl << "All topological sort possibilities :" << endl;
	myGraph.allTopologicalSort();
}
