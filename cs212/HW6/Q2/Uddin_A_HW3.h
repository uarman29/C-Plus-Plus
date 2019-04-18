#ifndef __UDDIN__A__HW3__H__
#define __UDDIN__A__HW3__H__
#include <cassert>
#include <iostream>
#include <cstdlib>
using namespace std;


template <class Item>
class gNode
{
	private:
		Item vertex;
		unsigned int weight;
		gNode<Item>* link;

	public:
		gNode(const Item &initVertex = Item(),const unsigned int& initWeight = 0,gNode<Item>* initLink = NULL);
		void setVertex(const Item &newVertex);
		void setWeight(const unsigned int& newWeight);
		void setLink(gNode<Item>* newLink);
		Item getVertex() const;
		unsigned int getWeight() const;
		const gNode<Item>* getLink()const;
		gNode<Item>* getLink();
		void print();
};
template <class Item>
void insertHead(gNode<Item>* &headPtr,const Item &newVertex,const unsigned int& nWeight = 0);

template <class Item>
void removeHead(gNode<Item>* &headPtr);

template <class Item>
void insertTail(gNode<Item>* &headPtr,const Item &newVertex,const unsigned int& nWeight = 0);

template <class Item>
void removeTail(gNode<Item>* &headPtr);

template <class Item>
size_t length(gNode<Item>* headPtr);

template <class Item>
void clearList(gNode<Item>* &headPtr);

template <class Item>
void print(gNode<Item>* headPtr);

template <class Item>
void insert(gNode<Item>* &headPtr,const size_t &position,const Item &newVertex,const unsigned int& nWeight = 0);

template <class Item>
void insert(gNode<Item>* &headPtr,const size_t &position,gNode<Item>* &entrygNode);

template <class Item>
void remove(gNode<Item>* &headPtr,const size_t &position);

template <class Item>
gNode<Item>* locate(gNode<Item>* headPtr,const size_t &position);

template <class Item>
gNode<Item>* search(gNode<Item>* headPtr,const Item &target);

template <class Item>
int searchIndex(gNode<Item>* headPtr,const Item &target);

template <class Item>
bool cycleCheck(gNode<Item>* headPtr);

template <class Item>
void swapNext(gNode<Item>* &headPtr,const size_t &position);

template <class Item>
void swap(gNode<Item>* &headPtr,const size_t &i,const size_t &j);

template <class Item>
void reverse(gNode<Item>* &headPtr);

#include "Uddin_A_HW3.cpp"
#endif