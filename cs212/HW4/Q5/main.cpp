#include "Uddin_A_HW4_Q5.h"
#include <iostream>
using namespace std;

int main()
{
	Stack<int> test;
	for(int i = 0;i<10;i++)
		test.push(i);
	test.print();
	cout<<"CAPACITY: "<<test.getCapacity()<<"\n";
	test.push(10);
	test.print();
	cout<<"CAPACITY: "<<test.getCapacity()<<"\n";
	test.pop();
	test.print();
	test.pop();
	test.print();
	test.pop();
	test.print();
	test.push(0);
	test.print();
	test.push(1);
	test.print();
	test.pop();
	test.print();

	Stack<int> test2(10);
	for(int i = 0;i<10;i++)
		test2.push(i*i);
	test2.print();
	cout<<"CAPACITY: "<<test2.getCapacity()<<"\n";
	cout<<"USED: "<<test2.size()<<"\n";
	test2.push(100);
	test2.print();
	cout<<"CAPACITY: "<<test2.getCapacity()<<"\n";
	cout<<"USED: "<<test2.size()<<"\n";
	test2.push(-10);
	test2.print();
	cout<<"CAPACITY: "<<test2.getCapacity()<<"\n";
	cout<<"USED: "<<test2.size()<<"\n";
	test2.pop();
	test2.print();
	cout<<"CAPACITY: "<<test2.getCapacity()<<"\n";
	cout<<"USED: "<<test2.size()<<"\n";

	Stack<int> test3;
	for(int i = 0;i<5;i++)
		test3.push(i);

	test2.print();
	test3.print();
	cout<<"SWAPPING:\n";
	test2.swap(test3);
	test2.print();
	test3.print();
	cout<<"SWAPPING:\n";
	test2.swap(test3);
	test2.print();
	test3.print();

	return 0;
}