#include "Uddin_A_HW4_Q4.h"
#include <iostream>
using namespace std;

int main()
{
	/*Queue<int> test;
	test.print();
	for(int i = 0;i<10;i++)
		test.push(i);
	test.print();
	test.pop();
	test.print();
	cout<<test.getCapacity()<<"\n\n";*/

	Queue<int> test2(10);
	cout<<test2.getCapacity()<<"\n";
	for(int i = 0;i<10;i++)
		test2.push(i*i);
	test2.print();
	cout<<test2.getCapacity()<<"\n";
	test2.pop();
	test2.pop();
	test2.print();
	test2.push(5);
	test2.push(99);
	test2.print();
	cout<<test2.getCapacity()<<"\n";
	test2.push(100);
	test2.print();
	test2.pop();
	test2.pop();
	test2.push(40);
	test2.push(50);
	test2.push(70);
	test2.print();
	cout<<test2.getCapacity()<<"\n";
	test2.pop();
	test2.pop();
	test2.pop();
	test2.pop();
	test2.pop();
	test2.pop();
	test2.pop();
	test2.pop();
	test2.pop();
	test2.pop();
	test2.pop();
	test2.pop();
	test2.print();
	for(int i=0;i<50;i++)
		test2.push(i*i);
	test2.pop();
	test2.print();
	cout<<test2.getCapacity()<<"\n";


	Queue<int> test3;
	for(int i=0;i<15;i++)
		test3.push(i);
	test3.print();
	Queue<int> test4(10);
	for(int i=0;i<10;i++)
		test4.push(i*i);
	test4.print();
	test3.swap(test4);
	test3.print();
	test4.print();
	/*
	Queue<int> test5(test3);
	test5.print();
	Queue<int> test6;
	test6 = test4;

	test6.print();

	test5.swap(test6);
	test5.print();
	test6.print();*/

	return 0;
}