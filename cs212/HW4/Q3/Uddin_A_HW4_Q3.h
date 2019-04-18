#ifndef __UDDIN__A__HW4__Q3__H__
#define __UDDIN__A__HW4__Q3__H__
#include <iostream>
#include <cassert>
using namespace std;

template <class Item>
class PriorityQ
{
	private:
		size_t first;
		size_t last;
		size_t used;
		size_t capacity;
		Item* data;
		int* priority;
		size_t nextIndex(size_t index)
		{
			return (index+1)%capacity;
		}

	public:
		static const size_t CAPACITY = 30;
		PriorityQ(size_t initCap = CAPACITY);
		PriorityQ(const PriorityQ<Item>& source);
		~PriorityQ();
		void operator=(PriorityQ<Item>& source);
		size_t getCapacity() const {return capacity;}
		bool empty() const {return used == 0;}
		size_t size() const {return used;}
		void resize(size_t nCap);
		void push(const Item& entry,const int entryP);
		Item pop();
		Item top() const;
		void print();
		void copy(const PriorityQ<Item>& source);
		int findMaxPriority() const;
};

#endif