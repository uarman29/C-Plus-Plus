#ifndef __UDDIN__A__HW4__Q1__H__
#define __UDDIN__A__HW4__Q1__H__
#include <iostream>
#include <cassert>
using namespace std;


template <class Item>
class Stack
{
	private:
		size_t used;
		size_t capacity;
		Item* data;

	public:
		static const size_t CAPACITY = 30;
		Stack(size_t initCap = CAPACITY);
		Stack(const Stack<Item>& source);
		~Stack();
		void operator=(const Stack<Item>& source);
		size_t getCapacity()const;
		void resize(size_t nCap);
		bool empty() const;
		size_t size() const;
		void push(const Item& entry);
		Item pop();
		Item top() const;
		void swap(Stack<Item>& source);
		void swap(Item& a,Item& b);
		void print();
};

#endif