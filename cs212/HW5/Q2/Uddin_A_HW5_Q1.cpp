#ifndef __UDDIN__A__HW5__Q1__CPP__
#define __UDDIN__A__HW5__Q1__CPP__
#include "Uddin_A_HW5_Q1.h"

template <class Item>
btNode<Item>::btNode(const Item& initData,btNode<Item>* initLeft,btNode<Item>* initRight,btNode<Item>* initP)
{
	data = initData;
	leftPtr = initLeft;
	rightPtr = initRight;
	parentPtr = initP;
}

template <class Item>
btNode<Item>::~btNode()
{
	leftPtr = NULL;
	rightPtr = NULL;
	parentPtr = NULL;
}

template <class Item>
btNode<Item>::btNode(const btNode<Item>& source)
{
	data = source.data;
	leftPtr = source.leftPtr;
	rightPtr = source.leftPtr;
	parentPtr = source.parentPtr;
}

template <class Item>
void btNode<Item>::setData(const Item& nData)
{
	data = nData;
}

template <class Item>
void btNode<Item>::setLeft(btNode<Item>* nLeft)
{
	leftPtr = nLeft;
}

template <class Item>
void btNode<Item>::setRight(btNode<Item>* nRight)
{
	rightPtr = nRight;
}

template <class Item>
void btNode<Item>::setParent(btNode<Item>* nParent)
{
	parentPtr = nParent;
}

template <class Item>
Item btNode<Item>::getData() const
{
	return data;
}

template <class Item>
btNode<Item>* btNode<Item>::getLeft()
{
	return leftPtr;
}

template <class Item>
btNode<Item>* btNode<Item>::getRight()
{
	return rightPtr;
}

template <class Item>
btNode<Item>* btNode<Item>::getParent()
{
	return parentPtr;
}

template <class Item>
const btNode<Item>* btNode<Item>::getLeft() const
{
	return leftPtr;
}

template <class Item>
const btNode<Item>* btNode<Item>::getRight() const
{
	return rightPtr;
}

template <class Item>
const btNode<Item>* btNode<Item>::getParent() const
{
	return parentPtr;
}

template <class Item>
bool btNode<Item>::isLeaf() const
{
	return leftPtr == NULL && rightPtr == NULL;
}

template <class Process,class Item>
void inOrder(Process f,btNode<Item>* rootPtr)
{
	if(rootPtr != NULL)
	{
		inOrder(f,(*rootPtr).getLeft());
		f(rootPtr);
		inOrder(f,(*rootPtr).getRight());
	}
}

template <class Process,class Item>
void postOrder(Process f,btNode<Item>* rootPtr)
{
	if(rootPtr != NULL)
	{
		postOrder(f,(*rootPtr).getLeft());
		postOrder(f,(*rootPtr).getRight());
		f(rootPtr);
	}
}

template <class Process,class Item>
void preOrder(Process f,btNode<Item>* rootPtr)
{
	if(rootPtr != NULL)
	{
		f(rootPtr);
		preOrder(f,(*rootPtr).getLeft());
		preOrder(f,(*rootPtr).getRight());
	}
}

template <class Item>
void clearTree(btNode<Item>*& rootPtr)
{
	if(rootPtr == NULL)
		return;

	clearTree((*rootPtr).getLeft());
	clearTree((*rootPtr).getRight());
	delete rootPtr;
	rootPtr = NULL;
}

template <class Item>
btNode<Item> copyTree(btNode<Item>* rootPtr)
{
	if(rootPtr == NULL)
		return NULL;

	btNode<Item>* left = copyTree((*rootPtr).getLeft());
	btNode<Item>* right = copyTree((*rootPtr).getRight());
	return btNode<Item>((*rootPtr).getData(),left,right);
}

template <class Item>
void print(btNode<Item>* rootPtr)
{
	if(rootPtr != NULL)
	{
		print((*rootPtr).getLeft());
		cout<<(*rootPtr).getData()<<", ";
		print((*rootPtr).getRight());
	}
}

template <class Item>
size_t height(btNode<Item>* rootPtr)
{
	if(rootPtr == NULL)
		return 0;

	size_t left = height((*rootPtr).getLeft())+1;
	return left;
}

template <class Item>
size_t numNodes(btNode<Item>* rootPtr)
{
	if(rootPtr == NULL)
		return 0;

	size_t count = 1;
	if((*rootPtr).getLeft() != NULL)
	{
		count++;
		numNodes((*rootPtr).getLeft());
	}
	if((*rootPtr).getRight() != NULL)
	{
		count++;
		numNodes((*rootPtr).getRight());
	}

	return count;
}

template <class Item>
void printTree(btNode<Item>* rootPtr,int indent)
{
	if(rootPtr != NULL)
	{
		if((*rootPtr).getRight()!=NULL)
			printTree((*rootPtr).getRight(),indent+4);
		
		if((*rootPtr).getLeft()!=NULL)
			printTree((*rootPtr).getLeft(),indent+4);
		
		for(int i = 0;i<indent;i++)
			cout<<"  ";
		cout<<(*rootPtr).getData()<<"\n";
	}
}

/*template class btNode<int>;
template class btNode<double>;
template class btNode<float>;
template class btNode<char>;
template class btNode<string>;*/

#endif
