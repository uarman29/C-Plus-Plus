#include "Uddin_A_HW4_Q2.h"
#include <iostream>
using namespace std;


int main()
{
	Queue<int> test(5);
	for(size_t i = 0;i<5;i++)
		test.push(i*i);
	test.print();

	cout<<test.pop()<<"\n";
	test.print();
	test.push(10000);
	test.print();
	test.pop();
	test.pop();
	test.print();
	test.push(-2);
	test.push(-7);
	test.print();
	test.push(944);
	test.print();
	test.push(1);
	test.pop();
	test.push(59);
	test.print();

	Queue<int> test2;
	for(int i =0;i<15;i++)
		test2.push(i);

	Queue<int> test3(6);
	for(int i=0;i<8;i++)
		test3.push(i*i);

	cout<<"LETS START BOIIIIIIIIISSSSSS\n";
	test2.print();
	test3.print(); 
	cout<<test2.getCapacity()<<"\n";
	cout<<test3.getCapacity()<<"\n";

	cout<<"SWAP IT CHEWIE\n";
	test2.swap(test3);
	test2.print();
	test3.print(); 
	cout<<test2.getCapacity()<<"\n";
	cout<<test3.getCapacity()<<"\n";

	cout<<"DO IT AGAIN\n";
	test2.swap(test3);
	test2.print();
	test3.print(); 
	cout<<test2.getCapacity()<<"\n";
	cout<<test3.getCapacity()<<"\n";

	Queue<int> test4(test3);
	test4.print();
	test4.pop();
	test4.pop();
	test4.pop();
	test4.pop();
	test4.pop();
	test4.pop();
	test4.pop();
	test4.pop();
	test4.print();

	test3.pop();
	test3.print();
	cout<<test3.getCapacity()<<"\n";
	for(int i=0;i<10;i++)
	{
		test3.push(i);
		test3.push(i);
	}
	test3.print();
	cout<<test3.getCapacity()<<"\n";
	return 0;
}