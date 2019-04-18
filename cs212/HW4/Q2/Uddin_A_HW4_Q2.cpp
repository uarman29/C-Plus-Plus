#ifndef __UDDIN__A__HW4__Q2__CPP__
#define __UDDIN__A__HW4__Q2__CPP__
#include "Uddin_A_HW4_Q2.h"

template <class Item>

Queue<Item>::Queue(size_t initCap)
{
	first = 0;
	capacity = initCap;
	data = new Item[capacity];
	used = 0;
	last = capacity-1;
}

template <class Item>
Queue<Item>::Queue(const Queue<Item>& source)
{
	used = source.used;
	capacity = source.capacity;
	first = source.first;
	last = source.last;
	data = new Item[capacity];
	copy(source);
}

template <class Item>
Queue<Item>::~Queue()
{
	delete[] data;
	used = 0;
	first = 0;
	last = 0;
}

template <class Item>
void Queue<Item>::operator=(const Queue<Item>&source)
{
	if(this == &source)
		return;

	if(capacity!=source.capacity)
	{
		Item* resized = new Item[source.capacity];
		delete[] data;
		data = resized;
		capacity = source.capacity;
	}

	used = source.used;
	first = source.first;
	last = source.last;
	copy(source);
}

template <class Item>
void Queue<Item>::resize(size_t nCap)
{
	if(capacity == nCap)
		return;

	if(nCap < used)
		nCap = used;

	Item* resized = new Item[nCap];
	int offset = nCap-capacity;
	capacity = nCap;
	if(first>last)
	{
		for(size_t i = 0;i<=last;i++)
			resized[i] = data[i];

		for(size_t i = first+offset;i<nCap;i++)
			resized[i] = data[i-offset];

		first += offset;
	}
	else
	{
		for(size_t i = first;i<=last;i++)
			resized[i] = data[i];
	}

	delete[] data;
	data = resized;
}

template <class Item>
void Queue<Item>::push(const Item& entry)
{
	if(used == capacity)
		resize(capacity*2);

	last = nextIndex(last);
	data[last] = entry;
	used++;
}

template <class Item>
Item Queue<Item>::pop()
{
	assert(!empty());
	Item tmp = data[first];
	first = nextIndex(first);
	used--;
	return tmp;
}

template <class Item>
Item Queue<Item>::front()
{
	assert(!empty());
	return data[first];
}

template <class Item>
void Queue<Item>::swap(Queue<Item>& source)
{
	if(this == &source)
		return;

	Queue tmp(source);
	source = (*this);
	(*this) = tmp;
}

template <class Item>
void Queue<Item>::print() const
{
	if(empty())
	{
		cout<<"EMPTY\n";
		return;
	}

	if(first>last)
	{
		for(size_t i = first;i<capacity;i++)
			cout<<data[i]<<", ";

		for(size_t i = 0;i<last;i++)
			cout<<data[i]<<", ";

		cout<<data[last]<<"\n";
	}
	else
	{
		for(size_t i = first;i<last;i++)
			cout<<data[i]<<", ";

		cout<<data[last]<<"\n";
	}
}

template <class Item>
void Queue<Item>::copy(const Queue<Item>& source)
{
	if(first>last)
	{
		for(size_t i = 0;i<=last;i++)
			data[i] = source.data[i];

		for(size_t i = first;i<capacity;i++)
			data[i] = source.data[i];
	}
	else
	{
		for(size_t i = first;i<=last;i++)
			data[i] = source.data[i];
	}
}


template class Queue<int>;
template class Queue<float>;
template class Queue<char>;
template class Queue<std::string>;
#endif
