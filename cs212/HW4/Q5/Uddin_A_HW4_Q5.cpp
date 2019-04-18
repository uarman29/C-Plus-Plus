#ifndef __UDDIN__A__HW4__Q5__CPP__
#define __UDDIN__A__HW4__Q5__CPP__
#include "Uddin_A_HW4_Q5.h"

template <class Item>
Stack<Item>::Stack(size_t initCap)
{
	used = 0;
	capacity = initCap;
	queue1 = Queue<Item>(initCap);
	queue2 = Queue<Item>(initCap);
}

template <class Item>
Stack<Item>::Stack(const Stack<Item>& source)
{
	used = source.used;
	capacity = source.capacity;
	queue1 = source.queue1;
	queue2 = source.queue2;
}

template <class Item>
Stack<Item>::~Stack()
{
	used = 0;
	queue1.~Queue();
	queue2.~Queue();
}

template <class Item>
void Stack<Item>::operator=(const Stack<Item>& source)
{
	if(this == &source)
		return;

	used = source.used;
	capacity = source.capacity;
	queue1 = source.queue1;
	queue2 = source.queue2;
}

template <class Item>
void Stack<Item>::resize(size_t nCap)
{
	queue1.resize(nCap);
	queue2.resize(nCap);
	capacity = queue1.getCapacity();
}

template <class Item>
void Stack<Item>::push(const Item& entry)
{
	queue1.push(entry);
	used++;
	capacity = queue1.getCapacity();
}

template <class Item>
Item Stack<Item>::pop()
{
	assert(!queue1.empty());
	while(queue1.size()>1)
		queue2.push(queue1.pop());


	Item tmp = queue1.pop();

	while(!queue2.empty())
		queue1.push(queue2.pop());
	used--;
	return tmp;
}

template <class Item>
Item Stack<Item>::top()
{
	while(queue1.size()>1)
		queue2.push(queue1.pop());

	Item tmp = queue1.front();

	while(!queue2.empty())
		queue1.push(queue2.pop());
	return tmp;
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
	queue1.print();
}
template class Stack<int>;
template class Stack<float>;
template class Stack<char>;
template class Stack<std::string>;

#endif