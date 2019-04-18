#include "Uddin_A_HW5_Q4.h"
#include <iostream>

int main()
{
	BST<int> b1(5);
	b1.add(6);
	//b1.print();
	b1.add(15);
	b1.add(20);
	b1.add(2);
	b1.add(3);
	b1.add(7);
	b1.add(1);
	b1.print();
	//cout<<(*b1.moveTo(15)).getData()<<"\n";
	//b1.transplant(b1.moveTo(1),b1.moveTo(2));
	/*b1.remove(1);
	b1.print();
	cout<<(*b1.min()).getData()<<"\n";
	cout<<(*b1.max()).getData()<<"\n";*/
	b1.remove(15);
	b1.print();
	b1.remove(1);
	b1.print();
	b1.remove(6);
	b1.print();
	//cout<<(*(b1.min())).getData()<<"\n";
	return 0;
}