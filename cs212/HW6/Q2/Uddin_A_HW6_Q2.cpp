#ifndef _UDDIN_A_HW6_Q2_CPP_
#define _UDDIN_A_HW6_Q2_CPP_
#include "Uddin_A_HW6_Q2.h"

template <class Item>
Graph<Item>::Graph(size_t initSize)
{
	numVertices = 0;
	capacity = initSize;
	list  = new gNode<Item>*[capacity];
}

template <class Item>
Graph<Item>::Graph(const Graph<Item>& source)
{
	numVertices = source.numVertices;
	capacity = source.capacity;
	list = source.list;
}

template <class Item>
Graph<Item>::~Graph()
{
	numVertices = 0;
	capacity = 0;
	delete[] list;
}

template <class Item>
void Graph<Item>::addVertex(const Item& vertex)
{
	if(numVertices == capacity)
		resize((capacity+1)*2);

	list[numVertices] = new gNode<Item>(vertex,0,NULL);
	numVertices++;
}

template <class Item>
void Graph<Item>::addEdge(const Item& vertex1, const Item& vertex2, const unsigned int weight)
{
	if(search(list[getIndex(vertex1)],vertex2) == NULL)
		insertTail(list[getIndex(vertex1)],vertex2,weight);
}

template <class Item>
void Graph<Item>::removeEdge(const Item& vertex1,const Item& vertex2)
{
	for(size_t i = 0;i<size();i++)
	{
		if(list[i]->getVertex() == vertex1)
		{
			if(search(list[i],vertex2) != NULL)
				remove(list[i],searchIndex(list[i],vertex2));
		}
	}
}


template <class Item>
void Graph<Item>::printEdges()const
{
	for(size_t i = 0;i<size();i++)
	{
		print(list[i]);
	}
}

template <class Item>
size_t Graph<Item>::size() const
{
	return numVertices;
}

template <class Item>
size_t Graph<Item>::numEdges() const
{
	size_t count = 0;
	for(size_t i = 0;i<size();i++)
	{
		count += length(list[i])-1;
	}
	return count;
}

template <class Item>
bool Graph<Item>::isEdge(const Item& vertex1, const Item& vertex2) const
{
	return (search(list[getIndex(vertex1)],vertex2) != NULL);
}

template <class Item>
size_t Graph<Item>::numNeighbors(const Item& vertex)
{
	
	return list[getIndex(vertex)]->size()-1;
}

template <class Item>
size_t Graph<Item>::getIndex(const Item& vertex)
{
	for(size_t i = 0;i<size();i++)
	{
		if((*list[i]).getVertex() == vertex)
		{
			return i;
		}
	}
}

template <class Item>
Item* Graph<Item>::neighbors(const Item& vertex)
{
	gNode<Item>* nbors = list[getIndex(vertex)];
	removeHead(nbors);
	return nbors;
}

template <class Item>
void Graph<Item>::resize(size_t nCap)
{
	if(nCap == capacity)
		return;

	if(nCap<numVertices)
		nCap = numVertices;

	gNode<Item>** resizedV = new gNode<Item>*[nCap];

	for(size_t i = 0;i<size();i++)
	{
		resizedV[i] = list[i];
	}
	delete[] list;

	list = resizedV;
	capacity = nCap;
}




#endif