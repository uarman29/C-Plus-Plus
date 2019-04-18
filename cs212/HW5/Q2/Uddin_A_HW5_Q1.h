#ifndef __UDDIN__A__HW5__Q1__H__
#define __UDDIN__A__HW5__Q1__H__
#include <iostream>
#include <cassert>
using namespace std;

template <class Item>
class btNode
{
	private:
		Item data;
		btNode* leftPtr;
		btNode* rightPtr;
		btNode* parentPtr;
	public:
		btNode(const Item& initData = Item(),btNode<Item>* initLeft = NULL,btNode<Item>* initRight = NULL,btNode<Item>* initP = NULL);
		~btNode();
		btNode(const btNode<Item>& source);
		void setData(const Item& nData);
		void setLeft(btNode<Item>* nLeft);
		void setRight(btNode<Item>* nRight);
		void setParent(btNode<Item>* nParent);
		Item getData() const;
		btNode<Item>* getLeft();
		btNode<Item>* getRight();
		btNode<Item>* getParent();
		const btNode<Item>* getLeft() const;
		const btNode<Item>* getRight() const;
		const btNode<Item>* getParent() const;
		bool isLeaf() const;
};
template <class Process,class Item>
void inOrder(Process f,btNode<Item>* rootPtr);
template <class Process,class Item>
void postOrder(Process f,btNode<Item>* rootPtr);
template <class Process,class Item>
void preOrder(Process f,btNode<Item>* rootPtr);

template <class Item>
void clearTree(btNode<Item>*& rootPtr);
template <class Item>
btNode<Item>* copyTree(btNode<Item>* rootPtr);
template <class Item>
void print(btNode<Item>* rootPtr);
template <class Item>
size_t height(btNode<Item>* rootPtr);
template <class Item>
size_t numNodes(btNode<Item>* rootPtr);
template <class Item>
void printTree(btNode<Item>* rootPtr,int indent = 0);

#include "Uddin_A_HW5_Q1.cpp"
#endif
