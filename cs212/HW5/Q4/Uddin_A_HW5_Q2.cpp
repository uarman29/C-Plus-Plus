#ifndef _UDDIN_A_HW5_Q2_CPP_
#define _UDDIN_A_HW5_Q2_CPP_
#include "Uddin_A_HW5_Q2.h"


template <class Item>
binaryTree<Item>::binaryTree()
{
	rootPtr = NULL;
	currentNode = NULL;
	numNodes = 0;
}

template <class Item>
binaryTree<Item>::binaryTree(const binaryTree<Item> &source)
{
	rootPtr = source.rootPtr;
	currentNode = source.currentNode;
	numNodes = source.numNodes;
}

template <class Item>
void binaryTree<Item>::operator=(const binaryTree<Item>& source)
{
	rootPtr = source.rootPtr;
	currentNode = source.currentNode;
	numNodes = source.numNodes;
}

template <class Item>
binaryTree<Item>::~binaryTree()
{
	rootPtr = NULL;
	currentNode = NULL;
	numNodes = 0;
}

template <class Item>
void binaryTree<Item>::createFirstNode(const Item& entry)
{
	if(size() == 0)
	{
		rootPtr = new btNode<Item>(entry);
		currentNode = rootPtr;
		numNodes++;
	}
}

template <class Item>
void binaryTree<Item>::shiftToRoot()
{
	if(size() > 0)
		currentNode = rootPtr;
}

template <class Item>
void binaryTree<Item>::shiftUp()
{
	if(hasParent())
		currentNode = (*currentNode).getParent();
}

template <class Item>
void binaryTree<Item>::shiftLeft()
{
	if(hasLeft())
		currentNode = (*currentNode).getLeft();
}

template <class Item>
void binaryTree<Item>::shiftRight()
{
	if(hasRight())
		currentNode = (*currentNode).getRight();
}

template <class Item>
void binaryTree<Item>::change(const Item& new_entry)
{
	if(size() > 0)
		(*currentNode).setData(new_entry);
}

template <class Item>
void binaryTree<Item>::addLeft(const Item& entry)
{
	if(size() > 0 && !hasLeft())
	{
		(*currentNode).setLeft(new btNode<Item>(entry,NULL,NULL,currentNode));
		numNodes++;
	}
}

template <class Item>
void binaryTree<Item>::addLeftShift(const Item& entry)
{
	if(size() > 0 && !hasLeft())
	{
		(*currentNode).setLeft(new btNode<Item>(entry,NULL,NULL,currentNode));
		shiftLeft();
		numNodes++;
	}
}

template <class Item>
void binaryTree<Item>::addRight(const Item& entry)
{
	if(size() > 0 && !hasRight())
	{
		(*currentNode).setRight(new btNode<Item>(entry,NULL,NULL,currentNode));
		numNodes++;
	}
}

template <class Item>
void binaryTree<Item>::addRightShift(const Item& entry)
{
	if(size() > 0 && !hasRight())
	{
		(*currentNode).setRight(new btNode<Item>(entry,NULL,NULL,currentNode));
		shiftRight();
		numNodes++;
	}
}

template <class Item>
size_t binaryTree<Item>::size() const
{
	return numNodes;
}

template <class Item>
Item binaryTree<Item>::retrieve() const
{
	return (*currentNode).getData();
}

template <class Item>
bool binaryTree<Item>::hasParent() const
{
	return ((*currentNode).getParent() != NULL) && size() > 0;
}

template <class Item>
bool binaryTree<Item>::hasLeft() const
{
	return ((*currentNode).getLeft() != NULL) && size() > 0;
}

template <class Item>
bool binaryTree<Item>::hasRight() const
{
	return ((*currentNode).getRight() != NULL) && size() > 0;
}

template <class Item>
btNode<Item>* binaryTree<Item>::getParent()
{
	return (*currentNode).getParent();
}

template <class Item>
const btNode<Item>* binaryTree<Item>::getParent() const
{
	return (*currentNode).getParent();
}

template <class Item>
btNode<Item>* binaryTree<Item>::getLeft()
{
	return (*currentNode).getLeft();
}

template <class Item>
const btNode<Item>* binaryTree<Item>::getLeft() const
{
	return (*currentNode).getLeft();
}

template <class Item>
btNode<Item>* binaryTree<Item>::getRight()
{
	return (*currentNode).getRight();
}

template <class Item>
const btNode<Item>* binaryTree<Item>::getRight() const
{
	return (*currentNode).getRight();
}

template <class Item>
btNode<Item>* binaryTree<Item>::getCurrent()
{
	return currentNode;
}

template <class Item>
const btNode<Item>* binaryTree<Item>::getCurrent() const
{
	return currentNode;
}

template <class Item>
btNode<Item>* binaryTree<Item>::getRoot()
{
	return rootPtr;
}

template <class Item>
const btNode<Item>* binaryTree<Item>::getRoot() const
{
	return rootPtr;
}

template <class Item>
void binaryTree<Item>::print()
{
	printTree(rootPtr);
}

#endif