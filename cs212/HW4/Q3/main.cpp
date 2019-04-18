#include "Uddin_A_HW4_Q3.h"
#include <iostream>
using namespace std;

int main()
{
	PriorityQ<int> test;
	for(int i = 0;i<10;i++)
	{
		test.push(i,i);
	}
	test.print();
	test.pop();
	test.print();
	test.push(50,100);
	test.print();
	test.pop();
	test.pop();
	test.pop();
	test.print();
	test.push(-10,5);
	test.print();
	cout<<"Line23: CAPACITY: "<<test.getCapacity()<<"\n";

	PriorityQ<int> test2(5);
	for(int i = 0;i<5;i++)
		test2.push(i,-1*(i-5));
	test2.print();
	cout<<"Line28: CAPACITY: "<<test2.getCapacity()<<"\n";
	test2.push(50,3);
	test2.print();
	cout<<"Line28: CAPACITY: "<<test2.getCapacity()<<"\n";
	test2.pop();
	test2.print();
	cout<<"Line28: CAPACITY: "<<test2.getCapacity()<<"\n";
	test2.push(20,-1);
	test2.print();
	cout<<"Line28: CAPACITY: "<<test2.getCapacity()<<"\n";
	test2.pop();
	test2.print();
	cout<<"Line28: CAPACITY: "<<test2.getCapacity()<<"\n";
	test2.pop();test2.pop();test2.pop();test2.pop();
	test2.print();
	test2.pop();
	test2.print();
	return 0;
}