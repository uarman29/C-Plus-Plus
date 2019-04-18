#ifndef __UDDIN__A__HW4__Q4__H__
#define __UDDIN__A__HW4__Q4__H__
#include <iostream>
#include <cassert>
#include "Uddin_A_HW4_Q1.h"
using namespace std;


template <class Item>
class Queue
{
	private:
		Stack<Item> stack1;
		Stack<Item> stack2;
		size_t used;
		size_t capacity;

	public:
		static const size_t CAPACITY = 30;
		Queue(size_t initCap = CAPACITY);
		Queue(const Queue<Item>& source);
		~Queue();
		void operator=(const Queue<Item>& source);
		void resize(size_t nCap);
		size_t getCapacity() const {return capacity;}
		size_t size() const {return used;}
		bool empty() const {return used == 0;}
		void push(const Item& entry);
		Item pop();
		Item front();
		void print();
		void swap(Queue<Item>& source);

};


#endif