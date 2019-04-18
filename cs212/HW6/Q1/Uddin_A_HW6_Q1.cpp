#ifndef _UDDIN_A_HW6_Q1_CPP_
#define _UDDIN_A_HW6_Q1_CPP_
#include "Uddin_A_HW6_Q1.h"

template <class Item>
Graph<Item>::Graph(size_t initSize)
{
	numVertices = 0;
	capacity = initSize;
	vertices = new Item[initSize];
	edges = new unsigned int*[initSize];
	for(size_t i = 0;i<initSize;i++)
		edges[i] = new unsigned int[initSize];
}

template <class Item>
Graph<Item>::Graph(const Graph<Item>& source)
{
	numVertices = source.numVertices;
	vertices = source.vertices;
	edges = source.edges;
	capacity = source.capacity;
}

template <class Item>
Graph<Item>::~Graph()
{
	numVertices = 0;
	capacity = 0;
	delete[] vertices;
	for(size_t i = 0;i<numVertices;i++)
		delete[] edges[i];
	delete[] edges;
}

template <class Item>
void Graph<Item>::addVertex(const Item& vertex)
{
	if(numVertices == capacity)
		resize((capacity+1)*2);
	vertices[numVertices] = vertex;
	numVertices++;
}

template <class Item>
void Graph<Item>::addEdge(const Item& vertex1,const Item& vertex2,const unsigned int weight)
{
	size_t index1;
	size_t index2;
	for(size_t i = 0;i<size();i++)
	{
		if(vertices[i] == vertex1)
			index1 = i;

		if(vertices[i] == vertex2)
			index2 = i;
	}

	edges[index1][index2] = weight;
}

template <class Item>
void Graph<Item>::removeEdge(const Item& vertex1,const Item& vertex2)
{
	size_t index1;
	size_t index2;
	for(size_t i = 0;i<size();i++)
	{
		if(vertices[i] == vertex1)
			index1 = i;

		if(vertices[i] == vertex2)
			index2 = i;
	}

	edges[index1][index2] = 0;
}

template <class Item>
void Graph<Item>::printEdges() const
{
	cout<<" ";
	for(size_t i = 0;i<size();i++)
		cout<<" "<<vertices[i]<<" ";
	cout<<"\n";
	for(size_t r = 0;r<size();r++)
	{
		cout<<vertices[r]<<" ";
		for(size_t c = 0;c<size()-1;c++)
		{
			cout<<edges[r][c]<<", ";
		}
		cout<<edges[r][size()-1]<<"\n";
	}
	cout<<"---------------------------------------\n";
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
	for(size_t r = 0;r<size();r++)
	{
		for(size_t c = 0;c<size();c++)
		{
			if(edges[r][c])
				count++;
		}
	}
	return count;
}

template <class Item>
bool Graph<Item>::isEdge(const Item& vertex1, const Item& vertex2) const
{
	size_t index1;
	size_t index2;
	for(size_t i = 0;i<size();i++)
	{
		if(vertices[i] == vertex1)
			index1 = i;

		if(vertices[i] == vertex2)
			index2 = i;
	}

	return edges[index1][index2];
}

template <class Item>
size_t Graph<Item>::numNeighbors(const Item& vertex) const
{
	size_t count = 0;
	size_t r = getIndex(vertex);
	for(size_t c = 0;c<size();c++)
	{
		if(edges[r][c] != 0)
		{
			count++;
		}
	}
	return count;
}

template <class Item>
Item* Graph<Item>::neighbors(const Item& vertex) const
{
	Item* neighbors = new Item[numNeighbors(vertex)];
	size_t count = 0;
	size_t r = getIndex(vertex);
	for(size_t c = 0;c<size();c++)
	{
		if(edges[r][c] != 0)
		{
			neighbors[count] = vertices[c];
			count++;
		}
	}
	return neighbors;
}

template <class Item>
size_t Graph<Item>::getIndex(const Item& vertex) const
{
	for(size_t i = 0;i<size();i++)
	{
		if(vertices[i] == vertex)
			return i;
	}
	return 999;
}

template <class Item>
Item Graph<Item>::getVertex(size_t position) const
{
	return vertices[position];
}

template <class Item>
void Graph<Item>::resize(size_t nCap)
{
	if(nCap == capacity)
		return;

	if(nCap<numVertices)
		nCap = numVertices;

	Item* resizedV = new Item[nCap];
	unsigned int** resizedE = new unsigned int*[nCap];
	for(size_t i = 0;i<nCap;i++)
		resizedE[i] = new unsigned int[nCap];

	for(size_t r = 0;r<size();r++)
	{
		resizedV[r] = vertices[r];
		for(size_t c = 0;c<size();c++)
		{
			resizedE[r][c] = edges[r][c];
		}
	}
	delete[] vertices;
	for(size_t i = 0;i<size();i++)
		delete[] edges[i];
	delete[] edges;

	vertices = resizedV;
	edges = resizedE;
	capacity = nCap;
}

template <class Item>
int* Graph<Item>::BFS(const Item& vertex)
{
	bool* visited = new bool[size()];
	int* distance = new int[size()];
	for(size_t i = 0;i<size();i++)
	{
		visited[i] = false;
		distance[i] = -1;
	}

	size_t target = getIndex(vertex);
	distance[target] = 0;
	visited[target] = true;
	Item* nbors;
	Queue<Item> adjacent;
	adjacent.push(vertex);
	Item previous;
	Item current;
	size_t currentIndex;
	size_t previousIndex;
	while(!adjacent.empty())
	{
		previous = adjacent.pop();
		previousIndex = getIndex(previous);
		nbors = neighbors(previous);
		for(size_t i = 0;i<numNeighbors(previous);i++)
		{
			current = nbors[i];
			currentIndex = getIndex(current);
			if(!visited[currentIndex])
			{
				visited[currentIndex] = true;
				distance[currentIndex] = distance[previousIndex] +1;
				adjacent.push(current);
			}
		}
	}
	return distance;	
}

template <class Item>
void Graph<Item>::DFS(const Item& vertex)
{
	bool* visited = new bool[size()];
	for(size_t i = 0;i<size();i++)
		visited[i] = false;

	DFSVisit(vertex,visited);
	for(size_t i = 0;i<size();i++)
	{
		if(!visited[i])
			DFSVisit(vertices[i],visited);
	}
	cout<<"\n";
}

template <class Item>
void Graph<Item>:: DFSVisit(const Item& vertex,bool* visited)
{
	cout<<vertex<<", ";
	Item* nbors = neighbors(vertex);
	size_t current = getIndex(vertex);
	visited[current] = true;
	for(size_t i = 0;i<numNeighbors(vertex);i++)
	{
		if(!visited[getIndex(nbors[i])])
		{
			DFSVisit(nbors[i],visited);
		}
	}
}


template <class Item>
size_t Graph<Item>::minWeightIndex(const Item& vertex)
{
	size_t row = getIndex(vertex);
	size_t minIndex = 0;
	for(size_t i = 0;i<size();i++)
		if(edges[row][minIndex]<edges[row][i])
			minIndex = i;

	return minIndex;
}

template <class Item>
int* Graph<Item>::dijkstra(const Item& vertex)
{
	int* distance = new int[size()];
	bool* visited = new bool[size()];
	for(int i = 0;i<size();i++)
	{
		visited[i] = false;
		distance[i] = -1;
	}

	size_t target = getIndex(vertex);
	visited[target] = true;
	distance[target] = 0;
	Item* nbors;
	Queue<Item> adjacent;
	adjacent.push(vertex);
	Item previous;
	size_t previousIndex;
	Item current;
	size_t currentIndex;
	while(!adjacent.empty())
	{
		previous = adjacent.pop();
		previousIndex = getIndex(previous);
		nbors = neighbors(previous);
		for(size_t i = 0;i<numNeighbors(previous);i++)
		{
			currentIndex = getIndex(nbors[i]);
			if(!visited[currentIndex])
			{
				visited[currentIndex] = true;
				distance[currentIndex] = distance[previousIndex] + edges[previousIndex][currentIndex];
				adjacent.push(vertices[currentIndex]);
			}
			else if(distance[currentIndex]>distance[previousIndex]+edges[previousIndex][currentIndex])
			{
				distance[currentIndex] = distance[previousIndex]+edges[previousIndex][currentIndex];
				adjacent.push(vertices[currentIndex]);
			}
		}

	}
	return distance;
}

template <class Process,class Item>
void breadthFirst(Graph<Item>& G,Process f)
{
	Item vertex = G.getVertex(0);
	bool* visited = new bool[G.size()];
	for(size_t i = 0;i<G.size();i++)
		visited[i] = false;

	size_t target = G.getIndex(vertex);
	visited[target] = true;
	Item* nbors;
	Queue<Item> adjacent;
	adjacent.push(vertex);
	Item previous;
	Item current;
	size_t currentIndex;
	size_t previousIndex;
	while(!adjacent.empty())
	{
		previous = adjacent.pop();
		f(previous);
		previousIndex = G.getIndex(previous);
		nbors = G.neighbors(previous);
		for(size_t i = 0;i<G.numNeighbors(previous);i++)
		{
			current = nbors[i];
			currentIndex = G.getIndex(current);
			if(!visited[currentIndex])
			{
				visited[currentIndex] = true;
				adjacent.push(current);
			}
		}
	}
}

template <class Process,class Item>
void depthFirstVisit(Graph<Item>& G, Process f,Item vertex,bool* visited)
{
	f(vertex);
	Item* nbors = G.neighbors(vertex);
	size_t current = G.getIndex(vertex);
	visited[current] = true;
	for(size_t i = 0;i<G.numNeighbors(vertex);i++)
	{
		if(!visited[G.getIndex(nbors[i])])
		{
			depthFirstVisit(G,f,nbors[i],visited);
		}
	}
}

template <class Process,class Item>
void depthFirst(Graph<Item>& G, Process f)
{
	bool* visited = new bool[G.size()];
	for(size_t i = 0;i<G.size();i++)
		visited[i] = false;

	Item vertex = G.getVertex(0);
	depthFirstVisit(G,f,vertex,visited);
	for(size_t i = 0;i<G.size();i++)
	{
		if(!visited[i])
			depthFirstVisit(G,f,G.getVertex(i),visited);
	}
	cout<<"\n";
}

template <class Item>
void printout(Item s)
{
	cout<<s<<", ";
}

#endif