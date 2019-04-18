#include "Uddin_A_HW5_Q2.h"
#include <iostream>


int main()
{
	binaryTree<int> b1;
	b1.createFirstNode(5);
	b1.addLeftShift(4);
	b1.addLeftShift(3);
	b1.addLeftShift(2);
	b1.addLeftShift(1);
	b1.shiftToRoot();
	b1.addRightShift(6);
	b1.addRightShift(7);
	b1.addRightShift(8);
	b1.addRightShift(9);
	b1.shiftToRoot();
	print(b1.getRoot());
	cout<<"\n"<<b1.size()<<"\n";
	cout<<b1.hasParent()<<"\n";
	b1.shiftLeft();
	cout<<b1.hasParent()<<"\n";
	b1.print();
	return 0;
}

