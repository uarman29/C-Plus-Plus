#include "Uddin_A_HW5_Q3.h"
#include <iostream>

int main()
{
	binaryTree<int> b1;
	b1.add(5);
	b1.add(4);
	b1.add(6);
	b1.add(3);
	b1.add(2);
	b1.add(1);
	b1.add(0);
	b1.add(2);
	b1.printTree();
	b1.removeLast();
	b1.printTree();
	b1.removeLast();
	b1.printTree();
	b1.add(0);
	b1.printTree();
	b1.shiftToRoot();
	cout<<b1.retrieve()<<"\n";
	b1.shiftLeft();
	cout<<b1.retrieve()<<"\n";
	cout<<b1.getLeft()<<"\n";
	cout<<b1.getRight()<<"\n";
	b1.shiftRight();
	cout<<b1.retrieve()<<"\n";
	return 0;
}