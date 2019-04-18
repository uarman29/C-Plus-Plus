#ifndef _UDDIN_A_HW6_Q1_H_
#define _UDDIN_A_HW6_Q1_H_
#include <iostream>
#include <cstdlib>
#include "Uddin_A_HW4_Q2.h"
using namespace std;

template <class Item>
class Graph
{
	private:
		Item* vertices;
		unsigned int** edges;
		size_t numVertices;
		size_t capacity;
	public:
		static const size_t CAPACITY = 5;
		Graph(size_t initSize = CAPACITY);
		Graph(const Graph<Item>& source);
		~Graph();
		void addVertex(const Item& vertex);
		void addEdge(const Item& vertex1, const Item& vertex2, const unsigned int weight = 1);
		void removeEdge(const Item& vertex1, const Item& vertex2);
		void printEdges()const;
		size_t size()const;
		size_t numEdges()const;
		size_t numNeighbors(const Item& vertex)const;
		bool isEdge(const Item& vertex1,const Item& vertex2)const;
		Item* neighbors(const Item& vertex)const;
		size_t getIndex(const Item& vertex)const;
		Item getVertex(size_t position)const;
		void resize(size_t nCap);
		int* BFS(const Item& vertex);
		void DFS(const Item& vertex);
		void DFSVisit(const Item& vertex,bool* visited);
		int* dijkstra(const Item& vertex);
		size_t minWeightIndex(const Item& vertex);
};

template <class Item>
void printout(Item s);

template <class Process,class Item>
void breadthFirst(Graph<Item>& G,Process f);

template <class Process,class Item>
void depthFirstVisit(Graph<Item>& G, Process f, Item vertex,bool* visited);

template <class Process,class Item>
void depthFirst(Graph<Item>& G, Process f);

#include "Uddin_A_HW6_Q1.cpp"
#endif
