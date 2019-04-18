#ifndef __UDDIN__A__HW4__Q4__CPP__
#define __UDDIN__A__HW4__Q4__CPP__
#include "Uddin_A_HW4_Q4.h"

template <class Item>

Queue<Item>::Queue(size_t initCap)
{
	capacity = initCap;
	used = 0;
	stack1 = Stack<Item>(initCap/2);
	stack2 = Stack<Item>(initCap/2);
}

template<class Item>
Queue<Item>::Queue(const Queue<Item>& source)
{
	capacity = source.capacity;
	used = source.used;
	stack1 = source.stack1;
	stack2 = source.stack2;
}

template <class Item>
Queue<Item>::~Queue()
{
	stack1.~Stack();
	stack2.~Stack();
	used = 0;
}

template <class Item>
void Queue<Item>::operator=(const Queue<Item>& source)
{
	if(this == &source)
		return;

	stack1 = source.stack1;
	stack2 = source.stack2;
	used = source.used;
	capacity = source.capacity;
}

template <class Item>
void Queue<Item>::resize(size_t nCap)
{
	stack1.resize(nCap);
	stack2.resize(nCap);
	capacity = stack1.getCapacity()*2;
}

template <class Item>
void Queue<Item>::push(const Item& entry)
{
	stack1.push(entry);
	capacity = stack1.getCapacity()+stack2.getCapacity();
	used++;
}

template <class Item>
Item Queue<Item>::pop()
{
	assert(!(stack1.empty()&&stack2.empty()));

	if(stack2.empty())
		while(!(stack1.empty()))
			stack2.push(stack1.pop());
	used--;
	return stack2.pop();
}

template <class Item>
Item Queue<Item>::front()
{
	if(stack2.empty())
		while(!(stack1.empty()))
			stack2.push(stack1.pop());

	return stack2.top();
}


template <class Item>
void Queue<Item>::swap(Queue<Item>& source)
{
	if(this == &source)
		return;

	Queue<Item> tmp(source);
	source = (*this);
	(*this) = tmp;
}

template <class Item>
void Queue<Item>::print()
{
	if(stack1.empty()&&stack2.empty())
	{
		cout<<"EMPTY\n";
		return;
	}
	Stack<Item> tmp(stack2);
	Stack<Item> tmp2;
	while(!(tmp.empty()))
	{
		tmp2.push(tmp.pop());
	}
	tmp2.print();

	if(!(stack1.empty())&&!(stack2.empty()))
	{
		cout<<", ";
		stack1.print();
	}
	else
	{
		stack1.print();
	}
	cout<<"\n";
}

template class Queue<int>;
template class Queue<float>;
template class Queue<char>;
template class Queue<std::string>;


#endif