#ifndef __UDDIN__A__HW4__Q1__CPP__
#define __UDDIN__A__HW4__Q1__CPP__
#include "Uddin_A_HW4_Q1.h"

template <class Item>

Stack<Item>::Stack(size_t initCap)
{
	capacity = initCap;
	data = new Item[capacity];
	used = 0;
}

template <class Item>
Stack<Item>::~Stack()
{
	delete[] data;
	used = 0;
}

template <class Item>
Stack<Item>::Stack(const Stack<Item>& source)
{
	used = source.used;
	capacity = source.capacity;
	data = new Item[capacity];
	for(size_t i = 0;i<used;i++)
		data[i] = source.data[i];
}

template <class Item>
void Stack<Item>::operator=(const Stack<Item> &source)
{
	if(this==&source)
		return;


	if(capacity!=source.capacity)
	{
		Item* tmp = new Item[source.capacity];
		delete[] data;
		data = tmp;
		capacity = source.capacity;
	}
	used = source.used;
	for(size_t i=0;i<used;i++)
		data[i] = source.data[i];
}

template <class Item>
size_t Stack<Item>::getCapacity() const
{
	return capacity;
}

template <class Item>
void Stack<Item>::resize(size_t nCap)
{
	if(nCap == capacity)
		return;

	if(nCap<used)
		nCap = used;

	Item* resized = new Item[nCap];
	for(size_t i = 0;i<used;i++)
		resized[i] = data[i];

	delete[] data;
	data = resized;
	capacity = nCap;
}

template <class Item>
bool Stack<Item>::empty() const
{
	return used == 0;
}

template <class Item>
size_t Stack<Item>::size() const
{
	return used;
}

template <class Item>
void Stack<Item>::push(const Item& entry)
{
	if(used == capacity)
		resize(capacity*2);

	data[used] = entry;
	used++;

}

template <class Item>
Item Stack<Item>::pop()
{
	assert(!empty());
	used--;
	return data[used];
}

template <class Item>
Item Stack<Item>::top() const
{
	assert(!empty());
	return data[used-1];
}

template <class Item>
void Stack<Item>::swap(Item &a,Item&b)
{
	Item tmp = a;
	a = b;
	b = tmp;
}

template <class Item>
void Stack<Item>::swap(Stack<Item>& source)
{
	if(this == &source)
		return;

	Stack<Item> tmp(source);
	source = (*this);
	(*this) = tmp;
}

template <class Item>
void Stack<Item>::print()
{
	if(empty())
		return;

	for(size_t i=0;i<used-1;i++)
	{
		cout<<data[i]<<", ";
	}
	cout<<data[used-1];
}

//SWAP VERSION 2
/*void Stack<Item>::swap(Stack<Item>& source)
{
	if(this == &source)
		return;

	if(source.capacity<capacity)
		source.resize(capacity);

	if(source.capacity>capacity)
		resize(source.capacity);

	if(used>source.used)
	{
		size_t greaterUsed = used;
		size_t smallerUsed = source.used;
		for(int i=0;i<smallerUsed;i++)
			swap(data[i],source.data[i]);

		while(greaterUsed != smallerUsed)
		{
			source.data[smallerUsed] = data[smallerUsed];
			smallerUsed++;
		}
		used = source.used;
		source.used = greaterUsed;

	}
	else
	{
		size_t greaterUsed = source.used;
		size_t smallerUsed = used;
		for(int i=0;i<smallerUsed;i++)
			swap(data[i],source.data[i]);

		while(greaterUsed != smallerUsed)
		{
			data[smallerUsed] = source.data[smallerUsed];
			smallerUsed++;
		}
		source.used = used;
		used = greaterUsed;
	}

}*/

template class Stack<int>;
template class Stack<float>;
template class Stack<char>;
template class Stack<std::string>;
#endif