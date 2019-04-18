#include "Uddin_A_HW6_Q1.h"
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
	g.printEdges();
	g.addEdge("a","b");
	g.printEdges();
	g.addEdge("c","a",2);
	g.printEdges();
	g.addEdge("d","b",3);
	g.printEdges();
	cout<<"NumEdges: "<<g.numEdges()<<"\n";
	cout<<"Is a-b an edge: "<<g.isEdge("a","b")<<"\n";
	cout<<"Is b-a an edge: "<<g.isEdge("b","a")<<"\n";
	cout<<"Is a-d an edge: "<<g.isEdge("a","d")<<"\n";
	g.removeEdge("a","b");
	g.printEdges();
	cout<<"Is a-b an edge: "<<g.isEdge("a","b")<<"\n";
	g.addVertex("e");
	g.addVertex("f");
	g.addVertex("g");
	g.printEdges();
	g.addEdge("e","f");
	g.addEdge("e","g");
	g.printEdges();
	g.addEdge("a","b");
	g.addEdge("a","c");
	g.addEdge("c","d");
	g.addEdge("c","e");
	g.addEdge("d","f");
	//g.addEdge("a","a");
	g.printEdges();
	string* arr = g.neighbors("a");
		for(int i = 0;i<g.numNeighbors("a");i++)
		cout<<arr[i]<<", ";

	cout<<"\n";

	arr = g.neighbors("c");
	for(int i = 0;i<g.numNeighbors("c");i++)
		cout<<arr[i]<<", ";
	cout<<"\n";

	int* distance = g.BFS("a");
	for(int i = 0;i<g.size();i++)
		cout<<distance[i]<<", ";
	cout<<"\n";

	distance = g.BFS("c");
	for(int i = 0;i<g.size();i++)
		cout<<distance[i]<<", ";
	cout<<"\n";

	g.DFS("a");
	Graph<string> ex;
	ex.addVertex("s");
	ex.addVertex("t");
	ex.addVertex("x");
	ex.addVertex("y");
	ex.addVertex("z");
	ex.addEdge("s","t",10);
	ex.addEdge("s","y",5);
	ex.addEdge("t","x",1);
	ex.addEdge("t","y",2);
	ex.addEdge("y","t",3);
	ex.addEdge("y","z",2);
	ex.addEdge("y","x",9);
	ex.addEdge("x","z",4);
	ex.addEdge("z","s",7);
	ex.addEdge("z","x",6);
	ex.printEdges();
	
	distance = ex.dijkstra("s");
	for(int i = 0;i<ex.size();i++)
		cout<<distance[i]<<", ";
	cout<<"\n";

	ex.DFS("s");
	breadthFirst(ex,printout<string>);
	cout<<"\n";
	depthFirst(ex,printout<string>);
	cout<<"\n";


	return 0;
}