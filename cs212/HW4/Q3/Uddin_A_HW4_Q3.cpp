#ifndef __UDDIN__A__HW4__Q3__CPP__
#define __UDDIN__A__HW4__Q3__CPP__
#include "Uddin_A_HW4_Q3.h"

template <class Item>
PriorityQ<Item>::PriorityQ(size_t initCap)
{
	capacity = initCap;
	used = 0 ;
	first = 0;
	last = capacity-1;
	data = new Item[capacity];
	priority = new int[capacity];
}

template <class Item>
PriorityQ<Item>::PriorityQ(const PriorityQ<Item>& source)
{
	used = source.used;
	capacity = source.capacity;
	first = source.first;
	last = source.last;
	copy(source);
}

template <class Item>
PriorityQ<Item>::~PriorityQ()
{
	used = 0;
	first = 0;
	last = 0;
	delete[] data;
	delete[] priority;
}

template <class Item>
void PriorityQ<Item>::operator=(PriorityQ<Item>& source)
{
	if(this == &source)
		return;
	if(capacity != source.capacity)
	{
		capacity = source.capacity;
		Item* reData = new Item[capacity];
		int* rePriority = new int[capacity];
		delete[] data;
		delete[] priority;
		data = reData;
		priority = rePriority;
	}
	used = source.used;
	first = source.first;
	last = source.last;
	copy(source);
}

template <class Item>
void PriorityQ<Item>::resize(size_t nCap)
{
	if(nCap == capacity)
		return;

	if(nCap<used)
		nCap = used;

	Item* reData = new Item[nCap];
	int* rePriority = new int[nCap];
	int offset = nCap-capacity;
	capacity = nCap;

	if(first>last)
	{
		for(size_t i = 0;i<=last;i++)
		{
			reData[i] = data[i];
			rePriority[i] = priority[i];
		}

		for(size_t i = first+offset;i<capacity;i++)
		{
			reData[i] = data[i-offset];
			rePriority[i] = priority[i-offset];
		}
		first+=offset;
	}
	else
	{
		for(size_t i = first;i<=last;i++)
		{
			reData[i] = data[i];
			rePriority[i] = priority[i];
		}
	}
	delete[] data;
	delete[] priority;
	data = reData;
	priority = rePriority;

}

template <class Item>
void PriorityQ<Item>::push(const Item& entry,const int entryP)
{
	if(used == capacity)
		resize(capacity*2);

	last = nextIndex(last);
	data[last] = entry;
	priority[last] = entryP;
	used++;
}

template <class Item>
Item PriorityQ<Item>::top() const
{
	return data[findMaxPriority()];
}

template <class Item>
Item PriorityQ<Item>::pop()
{
	int maxPriority = findMaxPriority();
	Item tmp = data[last];
	Item retValue = data[maxPriority];
	data[last] = data[maxPriority];
	data[maxPriority] = tmp;
	priority[maxPriority] = priority[last];
	used--;
	if(last == 0)
		last = capacity-1;
	else
		last--;
	return retValue;
}

template <class Item>
int PriorityQ<Item>::findMaxPriority() const
{
	assert(!empty());
	int maxPriority = first;
	if(first>last)
	{
		for(size_t i = 0;i<=last;i++)
			if(priority[maxPriority]<priority[i])
				maxPriority = i;

		for(size_t i = first;i<capacity;i++)
			if(priority[maxPriority]<priority[i])
				maxPriority = i;
	}
	else
	{
		for(size_t i = first;i<=last;i++)
			if(priority[maxPriority]<priority[i])
				maxPriority = i;
	}
	return maxPriority;
}

template <class Item>
void PriorityQ<Item>::copy(const PriorityQ<Item>& source)
{
	if(first>last)
	{
		for(size_t i = 0;i<=last;i++)
		{
			data[i] = source.data[i];
			priority[i] = source.priority[i];
		}

		for(size_t i = first;i<capacity;i++)
		{
			data[i] = source.data[i];
			priority[i] = source.priority[i];
		}
	}
	else
	{
		for(size_t i = first;i<=last;i++)
		{
			data[i] = source.data[i];
			priority[i] = source.priority[i];
		}
	}
}

template <class Item>
void PriorityQ<Item>::print()
{
	PriorityQ<Item> tmp(capacity);
	tmp = (*this);
	if(tmp.empty())
	{
		cout<<"EMPTY\n";
		return;
	}
	int tmpPriority = tmp.findMaxPriority();
	while(tmp.size()>1)
	{
		tmpPriority = tmp.priority[tmp.findMaxPriority()];
		cout<<"["<<tmp.pop()<<", "<<tmpPriority<<"], ";
	}
	tmpPriority = tmp.priority[tmp.findMaxPriority()];
	cout<<"["<<tmp.pop()<<", "<<tmpPriority<<"]\n";
}

template class PriorityQ<int>;
template class PriorityQ<float>;
template class PriorityQ<char>;
template class PriorityQ<std::string>;

#endif