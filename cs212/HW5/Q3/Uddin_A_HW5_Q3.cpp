#ifndef _UDDIN_A_HW5_Q3_CPP_
#define _UDDIN_A_HW5_Q3_CPP_
#include "Uddin_A_HW5_Q3.h"

template <class Item>
binaryTree<Item>::binaryTree(size_t initCap)
{
	data = new Item[initCap];
	numNodes = 0;
	capacity = initCap;
	currentIndex = 0;
}

template <class Item>
binaryTree<Item>::binaryTree(const binaryTree<Item>& source)
{
	data = source.data;
	numNodes = source.numNodes;
	capacity = source.capacity;
	currentIndex = source.currentIndex;
}

template <class Item>
void binaryTree<Item>::operator=(const binaryTree<Item>& source)
{
	delete[] data;
	for(size_t i = 0;i<source.numNodes;i++)
		data[i] = source.data[i];

	numNodes = source.numNodes;
	capacity = source.capacity;
	currentIndex = source.currentIndex;
}


template <class Item>
binaryTree<Item>::~binaryTree()
{
	delete[] data;
	numNodes = 0;
	capacity = 0;
	currentIndex = 0;
}

template <class Item>
void binaryTree<Item>::createFirstNode(const Item& entry)
{
	if(numNodes == capacity)
		resize((capacity+1)*2);

	data[0] = entry;
	numNodes++;
	currentIndex = 0;
}

template <class Item>
void binaryTree<Item>::shiftToRoot()
{
	currentIndex = 0;
}

template <class Item>
void binaryTree<Item>::shiftUp()
{
	currentIndex = (currentIndex-1)/2;
}

template <class Item>
void binaryTree<Item>::shiftLeft()
{
	currentIndex = currentIndex*2 + 1;
}

template <class Item>
void binaryTree<Item>::shiftRight()
{
	currentIndex = currentIndex*2 + 2;
}

template <class Item>
void binaryTree<Item>::change(const Item& entry)
{
	data[currentIndex] = entry;
}

template <class Item>
void binaryTree<Item>::removeLast()
{
	numNodes--;
}

template <class Item>
void binaryTree<Item>::add(const Item& entry)
{
	if(numNodes == capacity)
		resize((capacity+1)*2);

	data[numNodes] = entry;
	numNodes++;
}

template <class Item>
void binaryTree<Item>::addShift(const Item& entry)
{
	if(numNodes == capacity)
		resize((capacity+1)*2);

	currentIndex = numNodes;
	data[numNodes] = entry;
	numNodes++;
}

template <class Item>
void binaryTree<Item>::addLeft(const Item& entry)
{
	if(numNodes == capacity)
		resize((capacity+1)*2);

	data[currentIndex*2 + 1] = entry;
	numNodes++;
}

template <class Item>
void binaryTree<Item>::addLeftShift(const Item& entry)
{
	if(numNodes == capacity)
		resize((capacity+1)*2);

	shiftLeft();
	data[currentIndex] = entry;
	numNodes++;
}

template <class Item>
void binaryTree<Item>::addRight(const Item& entry)
{
	if(numNodes == capacity)
		resize((capacity+1)*2);

	data[currentIndex*2 + 2] = entry;
	numNodes++;
}

template <class Item>
void binaryTree<Item>::addRightShift(const Item& entry)
{
	if(numNodes == capacity)
		resize((capacity+1)*2);

	shiftRight();
	data[currentIndex] = entry;
	numNodes++;
}

template <class Item>
void binaryTree<Item>::resize(size_t nCap)
{
	if(nCap == capacity)
		return;

	if(nCap < numNodes)
		nCap = numNodes;

	Item* resized = new Item[nCap];
	for(size_t i = 0;i<numNodes;i++)
		resized[i] = data[i];

	delete[] data;
	data = resized;
	capacity = nCap;
}

template <class Item>
size_t binaryTree<Item>::size() const
{
	return numNodes;
}

template <class Item>
Item binaryTree<Item>::retrieve() const
{
	return data[currentIndex];
}

template <class Item>
Item binaryTree<Item>::retrieve(size_t i)
{
	return data[i];
}

template <class Item>
bool binaryTree<Item>::hasParent() const
{
	return size() > 0 && currentIndex != 0;
}

template <class Item>
bool binaryTree<Item>::hasLeft() const
{
	return size() > 0 && (currentIndex*2 + 1) < numNodes;
}

template <class Item>
bool binaryTree<Item>::hasRight() const
{
	return size() > 0 && (currentIndex*2 + 2) < numNodes;
}

template <class Item>
size_t binaryTree<Item>::getCurrent() const
{
	return currentIndex;
}

template <class Item>
void binaryTree<Item>::moveTo(size_t i)
{
	if(i<numNodes)
		currentIndex = i;
}

template <class Item>
Item binaryTree<Item>::getParent() const
{
	return data[(currentIndex-1)/2];
}

template <class Item>
size_t binaryTree<Item>::getParentIndex() const
{
	return (currentIndex-1)/2;
}

template <class Item>
Item binaryTree<Item>::getLeft() const
{
	return data[(currentIndex*2) + 1];
}

template <class Item>
size_t binaryTree<Item>::getLeftIndex() const
{
	return (currentIndex*2) + 1;
}

template <class Item>
Item binaryTree<Item>::getRight() const
{
	return data[(currentIndex*2) + 2];
}

template <class Item>
size_t binaryTree<Item>::getRightIndex() const
{
	return (currentIndex*2) + 2;
}

template <class Item>
void binaryTree<Item>::print()
{
	for(size_t i = 0;i<numNodes-1;i++)
		cout<<data[i]<<", ";
	cout<<data[numNodes-1]<<"\n";
}
template <class Item>
void binaryTree<Item>::printTree()
{
	size_t counter = 1;
	size_t offset = 0;
	size_t printed = 0;
	size_t spaced = sqrt(numNodes)+1;

	while(printed<numNodes)
	{
		for(size_t i = 0;i<spaced;i++)
			cout<<"\t";

		for(size_t i = 0;i<counter;i++)
		{
			if(offset+i>=numNodes)
			{
				cout<<"N/A";
				for(size_t i = 0;i<spaced+1;i++)
					cout<<"\t";
				printed++;
			}
			else
			{
				cout<< data[offset + i];
				for(size_t i = 0;i<spaced+1;i++)
					cout<<"\t";
				printed++;
			}
		}
		cout<<"\n";
		offset += counter;
		if(spaced!=0)
			spaced--;
		counter *= 2;
	}
	cout<<"\n---------------------------------------\n";

}


#endif