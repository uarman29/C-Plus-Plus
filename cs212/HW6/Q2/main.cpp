#include "Uddin_A_HW6_Q2.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Graph<string> g;
	g.addVertex("a");
	g.addVertex("b");
	g.addVertex("c");
	g.addVertex("d");
	g.addEdge("a","b");
	g.addEdge("a","c",2);
	g.addEdge("a","b",3);
	g.addEdge("d","c",5);
	g.addEdge("d","b",6);
	g.addEdge("b","a");
	g.addEdge("b","b",999);
	g.printEdges();
	cout<<"NumEdges is: "<<g.numEdges()<<"\n";
	cout<<"Size is: "<<g.size()<<"\n";
	g.removeEdge("a","b");
	g.removeEdge("a","b");
	//g.removeEdge("b","b");
	g.printEdges();
	return 0;
}