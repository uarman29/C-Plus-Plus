#ifndef __UDDIN__A__HW3__H__
#define __UDDIN__A__HW3__H__
#include <cassert>
#include <iostream>
#include <cstdlib>
using namespace std;


typedef int nodeDataType;
class Node
{
	private:
		nodeDataType data;
		Node* link;

	public:
		Node(const nodeDataType &initData = nodeDataType(),Node* initLink = NULL);
		void setData(const nodeDataType &newData);
		void setLink(Node* newLink);
		nodeDataType getData() const;
		const Node* getLink()const;
		Node* getLink();
		void print();
};
void insertHead(Node* &headPtr,const nodeDataType &newData);
void removeHead(Node* &headPtr);
void insertTail(Node* &headPtr,const nodeDataType &newData);
void removeTail(Node* &headPtr);
size_t size(Node* headPtr);
void clearList(Node* &headPtr);
void print(Node* headPtr);
void insert(Node* &headPtr,const size_t &position,const nodeDataType &newData);
void insert(Node* &headPtr,const size_t &position,Node* &entryNode);
void remove(Node* &headPtr,const size_t &position);
Node* locate(Node* headPtr,const size_t &position);
Node* search(Node* headPtr,const nodeDataType &target);
bool cycleCheck(Node* headPtr);
void swapNext(Node* &headPtr,const size_t &position);
void swap(Node* &headPtr,const size_t &i,const size_t &j);
void reverse(Node* &headPtr);


#endif