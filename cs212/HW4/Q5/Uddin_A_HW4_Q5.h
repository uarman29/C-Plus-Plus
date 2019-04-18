#ifndef __UDDIN__A__HW4__Q5__H__
#define __UDDIN__A__HW4__Q5__H__
#include <iostream>
#include <cassert>
#include "Uddin_A_HW4_Q2.h"
using namespace std;

template <class Item>
class Stack
{
	private:
		Queue<Item> queue1;
		Queue<Item> queue2;
		size_t used;
		size_t capacity;

	public:
		static const size_t CAPACITY = 30;
		Stack(size_t initCap = CAPACITY);
		Stack(const Stack<Item>& source);
		~Stack();
		void operator=(const Stack<Item>& source);
		size_t getCapacity()const {return capacity;}
		void resize(size_t nCap);
		bool empty() const {return used == 0;}
		size_t size() const {return used;}
		void push(const Item& entry);
		Item pop();
		Item top();
		void swap(Stack<Item>& source);
		void print();
};

#endif