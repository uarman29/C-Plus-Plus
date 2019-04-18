#ifndef _UDDIN_A_HW6_Q2_H_
#define _UDDIN_A_HW6_Q2_H_
#include <iostream>
#include <cstdlib>
#include "Uddin_A_HW3.h"
using namespace std;

template <class Item>
class Graph
{
	private:
		gNode<Item>** list;
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
		size_t numNeighbors(const Item& vertex);
		bool isEdge(const Item& vertex1,const Item& vertex2)const;
		Item* neighbors(const Item& vertex);
		size_t getIndex(const Item& vertex);
		void resize(size_t nCap);	
};

#include "Uddin_A_HW6_Q2.cpp"
#endif