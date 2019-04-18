#ifndef _UDDIN_A_HW5_Q4_H_
#define _UDDIN_A_HW5_Q4_H_
#include <iostream>
#include "Uddin_A_HW5_Q2.h"

template <class Item>
class BST
{
	private:
		binaryTree<Item> tree;
	public:
		BST();
		BST(const Item& entry);
		BST(const BST<Item>& source);
		~BST();
		void add(const Item& entry);
		void remove(btNode<Item>* &target);
		void remove(Item target);
		btNode<Item>* moveTo(Item target);
		void transplant(btNode<Item>* u, btNode<Item>* v);
		btNode<Item>* min();
		btNode<Item>* min(btNode<Item>* start);
		btNode<Item>* max();
		btNode<Item>* max(btNode<Item>* start);
		btNode<Item>* search(const Item& target);
		void print();
};

#include "Uddin_A_HW5_Q4.cpp"

#endif
