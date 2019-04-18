#ifndef _UDDIN_A_HW5_Q5_CPP_
#define _UDDIN_A_HW5_Q5_CPP_
#include "Uddin_A_HW5_Q5.h"

template <class Item>
Heap<Item>::Heap()
{

}

template <class Item>
Heap<Item>::Heap(const Item& entry)
{
	tree.createFirstNode(entry);
}

template <class Item>
Heap<Item>::Heap(const Heap<Item>& source)
{
	tree = source.tree;
}

template <class Item>
void Heap<Item>::operator=(const Heap<Item>& source)
{
	tree = source.tree;
}

template <class Item>
Heap<Item>::~Heap()
{
	tree.~binaryTree();
}

template <class Item>
void Heap<Item>::heapify(size_t i)
{
	tree.moveTo(i);
	size_t left = tree.getLeftIndex();
	size_t right = tree.getRightIndex();
	size_t largest = i;

	if(tree.retrieve(largest)<tree.retrieve(left))
		largest = left;
	
	if(tree.retrieve(largest)<tree.retrieve(right))
		largest = right;

	if(largest != i)
	{
		Item tmp = tree.retrieve(i);
		tree.change(tree.retrieve(largest));
		tree.moveTo(largest);
		tree.change(tmp);
		heapify(largest);
	}
}

template <class Item>
void Heap<Item>::buildHeap()
{
	size_t size = tree.size();
	for(int i = size/2;i>=0;i--)
	{
		heapify(i);
	}
}

template <class Item>
Item Heap<Item>::max()
{
	return tree.retrieve(0);
}

template <class Item>
Item Heap<Item>::min()
{
	size_t size = tree.size();
	tree.moveTo(size/2);
	Item min = tree.retrieve();
	for(size_t i = size/2;i<size;i++)
	{
		if(min > tree.retrieve(i))
			min = i;
	}
	return tree.retrieve(min);
}

template <class Item>
void Heap<Item>::add(const Item& entry)
{
	tree.addShift(entry);
	while(entry > tree.getParent() && tree.getCurrent() != 0)
	{
		tree.change(tree.getParent());
		tree.shiftUp();
		tree.change(entry);
	}
}

template <class Item>
Item Heap<Item>::remove()
{
	tree.shiftToRoot();
	Item tmp = tree.retrieve();
	tree.change(tree.retrieve(tree.size()-1));
	tree.removeLast();
	buildHeap();
	return tmp;
}

template <class Item>
Item* Heap<Item>::heapSort()
{
	size_t size = tree.size();
	Item* sorted = new Item[size];
	Heap<Item> copied;
	copied = *this;
	for(int i = 0;i<size;i++)
		sorted[i] = copied.remove();

	return sorted;
}

template <class Item>
void Heap<Item>::print()
{
	tree.printTree();
}

template <class Item>
size_t Heap<Item>::size()
{
	return tree.size();
}


#endif