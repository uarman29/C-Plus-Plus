#ifndef _UDDIN_A_HW5_Q5_H_
#define _UDDIN_A_HW5_Q5_H_
#include <iostream>
#include "Uddin_A_HW5_Q3.h"


template <class Item>
class Heap
{
	private:
		binaryTree<Item> tree;
	public:
		Heap();
		Heap(const Item& entry);
		Heap(const Heap<Item>& source);
		void operator=(const Heap<Item>& source);
		~Heap();
		void heapify(size_t i);
		void buildHeap();
		void heapUp(size_t &i);
		void add(const Item& entry);
		Item remove();
		Item min();
		Item max();
		Item* heapSort();
		size_t size();
		void print();

};

#include "Uddin_A_HW5_Q5.cpp"

#endif