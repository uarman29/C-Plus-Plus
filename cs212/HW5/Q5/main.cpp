#include "Uddin_A_HW5_Q5.h"
#include <iostream>
using namespace std;

int main()
{
	Heap<int> h;
	h.add(5);
	h.add(6);
	h.add(4);
	h.add(7);
	h.add(3);
	h.add(9);
	h.print();

	cout<<h.max()<<"\n";
	cout<<h.min()<<"\n";
	int* arr = h.heapSort();
	for(int i = 0;i<h.size();i++)
		cout<<arr[i]<<", ";

	cout<<"\n";

	h.print();
	cout<<h.remove()<<"\n";
	h.print();
	cout<<h.remove()<<"\n";
	h.print();
	cout<<h.remove()<<"\n";
	h.print();
	cout<<h.remove()<<"\n";
	h.print();
	cout<<h.max()<<"\n";
	h.add(100);
	h.add(2);
	h.add(50);
	h.print();
	int* arr2 = h.heapSort();
	for(int i = 0;i<h.size();i++)
		cout<<arr2[i]<<", ";
	return 0;
}