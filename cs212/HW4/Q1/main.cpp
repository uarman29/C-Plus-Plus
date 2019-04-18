#include "Uddin_A_HW4_Q1.h"
using namespace std;

int main()
{
	Stack<int> test(5);
	test.print();

	for(int i=0;i<10;i++)
		test.push(i);

	test.print();
	cout<<test.top()<<"\n";
	test.pop();
	cout<<test.pop()<<"\n";
	test.print();
	cout<<test.size()<<"\n";

	Stack<int> test2;
	for(int i = 0;i<15;i++)
		test2.push(i*i);

	cout<<"SWAP PREPERATION"<<"\n";
	test.print();
	test2.print();
	cout<<test.getCapacity()<<"\n";
	cout<<test2.getCapacity()<<"\n";
	test.swap(test2);

	cout<<"SWAPPED\n";
	test.print();
	test2.print();
	cout<<test.getCapacity()<<"\n";
	cout<<test2.getCapacity()<<"\n";

	cout<<"SWAP BACK\n";
	test.swap(test2);
	test.print();
	test2.print();

	cout<<test.getCapacity()<<"\n";
	cout<<test2.getCapacity()<<"\n";

	test.pop();test.pop();test.pop();
	test.print();
	test.pop();
	test.print();
	test.push(100);
	test.print();
	test.pop();
	test.print();
	test.pop();test.pop();test.pop();
	test.print();
	test.pop();
	test.print();
	//test.pop();
	for(int i = 0;i<100;i++)
		test.push(i);
	test.print();
	cout<<"CAPACITY:"<<test.getCapacity()<<"\n";
	return 0;
}