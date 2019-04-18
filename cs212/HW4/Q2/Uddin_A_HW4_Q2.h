#ifndef __UDDIN__A__HW4__Q2__H__
#define __UDDIN__A__HW4__Q2__H__
#include <iostream>
#include <cassert>
using namespace std;


template <class Item>
class Queue
{
	private:
		size_t first;
		size_t last;
		size_t used;
		size_t capacity;
		Item* data;
		size_t nextIndex(size_t index) const
		{
			return (index+1)%capacity;
		}

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
		void print()const;
		void swap(Queue<Item>& source);
		void copy(const Queue<Item>& source);
};
#endif