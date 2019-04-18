#ifndef _UDDIN_A_HW5_Q4_CPP_
#define _UDDIN_A_HW5_Q4_CPP_
#include "Uddin_A_HW5_Q4.h"

template <class Item>
BST<Item>::BST()
{
	//tree = new binaryTree<Item>();
}

template <class Item>
BST<Item>::BST(const Item& entry)
{
	//tree = new binaryTree<Item>();
	tree.createFirstNode(entry);
}

template <class Item>
BST<Item>::BST(const BST<Item>& source)
{
	tree(source);
}

template <class Item>
BST<Item>::~BST()
{
	tree.~binaryTree();
}

template <class Item>
btNode<Item>* BST<Item>::min()
{
	while(tree.hasLeft())
		tree.shiftLeft();

	btNode<Item>* result = tree.getCurrent();
	tree.shiftToRoot();
	return result;
}

template <class Item>
btNode<Item>* BST<Item>::min(btNode<Item>* start)
{
	moveTo((*start).getData());
	while(tree.hasLeft())
		tree.shiftLeft();

	btNode<Item>* result = tree.getCurrent();
	tree.shiftToRoot();
	return result;
}

template <class Item>
btNode<Item>* BST<Item>::max()
{
	while(tree.hasRight())
		tree.shiftRight();

	btNode<Item>* result = tree.getCurrent();
	tree.shiftToRoot();
	return result;
}

template <class Item>
btNode<Item>* BST<Item>::max(btNode<Item>* start)
{
	moveTo(start);
	while(tree.hasRight())
		tree.shiftRight();

	btNode<Item>* result = tree.getCurrent();
	tree.shiftToRoot();
	return result;
}

template <class Item>
btNode<Item>* BST<Item>::search(const Item& target)
{
	while(tree.getCurrent() != NULL)
	{
		if(tree.retrieve() == target)
		{
			btNode<Item>* result = tree.getCurrent();
			tree.shiftToRoot();
			return result;
		}

		if(tree.retrieve() > target)
			tree.shiftLeft();
		else
			tree.shiftRight();
	}
	tree.shiftToRoot();
	return NULL;
}

template <class Item>
void BST<Item>::add(const Item& entry)
{
	tree.shiftToRoot();
	while(tree.getCurrent() != NULL)
	{
		if(tree.retrieve() > entry)
			if(tree.hasLeft())
				tree.shiftLeft();
			else
				break;
		else
		{
			if(tree.hasRight())
				tree.shiftRight();
			else
				break;
		}
	}
	if(tree.retrieve() > entry)
		tree.addLeft(entry);
	else
		tree.addRight(entry);
	tree.shiftToRoot();
}

template <class Item>
btNode<Item>* BST<Item>::moveTo(Item target)
{
	tree.shiftToRoot();
	while(tree.getCurrent() != NULL)
	{
		if(tree.retrieve() == target)
			return tree.getCurrent();

		if(tree.retrieve() > target)
			tree.shiftLeft();
		else
			tree.shiftRight();
	}
	return tree.getCurrent();
}

template <class Item>
void BST<Item>::remove(Item target)
{
	btNode<Item>* targetNode = moveTo(target);
	if(!tree.hasLeft())
		transplant(tree.getCurrent(),tree.getRight());
	else if(!tree.hasRight())
		transplant(tree.getCurrent(),tree.getLeft());
	else
	{
		btNode<Item>* swapped = min(tree.getRight());
		cout<<(*swapped).getData()<<"\n";
		if((*swapped).getParent() != targetNode)
		{
			transplant(swapped,(*swapped).getRight());
			(*swapped).setRight((*targetNode).getRight());
			(*(*swapped).getRight()).setParent(swapped);
		}
		transplant(targetNode,swapped);
		(*swapped).setLeft((*targetNode).getLeft());
		(*((*swapped).getLeft())).setParent(swapped);
	}

}

template <class Item>
void BST<Item>::remove(btNode<Item>* &target)
{
	moveTo(target);
	if(!tree.hasLeft())
		transplant(tree.getCurrent(),tree.getRight());
	else if(!tree.hasRight())
		transplant(tree.getCurrent(),tree.getLeft());
	else
	{
		btNode<Item>* swapped = min(tree.getRight());
		cout<<(*swapped).getData()<<"\n";
		if((*swapped).getParent() != target)
		{
			transplant(swapped,(*swapped).getRight());
			(*swapped).setRight((*target).getRight());
			(*(*swapped).getRight()).setParent(swapped);
		}
		transplant(target,swapped);
		(*swapped).setLeft((*target).getLeft());
		(*((*swapped).getLeft())).setParent(swapped);
	}
}

template <class Item>
void BST<Item>::transplant(btNode<Item>* u, btNode<Item>* v)
{
	tree.shiftToRoot();
	if((*u).getParent() == NULL)
		tree.change((*v).getData());

	else
	{
		btNode<Item>* parent = (*u).getParent();
		btNode<Item>* left = (*parent).getLeft();
		if(u == left)
			(*((*u).getParent())).setLeft(v);
		else
			(*((*u).getParent())).setRight(v);
	}

	if(v != NULL)
		(*v).setParent((*u).getParent());
}

template <class Item>
void BST<Item>::print()
{
	tree.print();
}


#endif