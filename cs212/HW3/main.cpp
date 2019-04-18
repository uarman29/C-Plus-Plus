#include "Uddin_A_HW3.h"
#include <iostream>
using namespace std;

int main()
{
	Node* headPtr = NULL;
	print(headPtr);
	cout<<size(headPtr)<<"\n";
	for(int i=0;i<10;i++)
	{
		print(headPtr);
		insertTail(headPtr,i*i);
	}
	print(headPtr);
	cout<<size(headPtr)<<"\n-----------------------------------------\n";

	Node* headPtr2 = NULL;
	for(int i=10;i>=0;i--)
	{
		insertHead(headPtr2,i*i);
	}
	print(headPtr2);
	cout<<size(headPtr2)<<"\n-----------------------------------------\n";
	//FUNCTIONS: insertHead(),insertTail(),size(),print() WORK

	Node* headPtr3 = NULL;
	insertHead(headPtr3,5);
	print(headPtr3);
	removeHead(headPtr3);
	print(headPtr3);
	removeHead(headPtr2);
	print(headPtr2);
	cout<<"removeHead()-----------------------------------------\n";
	//FUNCTION: removeHead() WORKS

	removeTail(headPtr3);
	print(headPtr3);
	insertTail(headPtr3,1000);
	print(headPtr3);
	removeTail(headPtr3);
	print(headPtr3);
	removeTail(headPtr2);
	print(headPtr2);
	cout<<"removeTail()-----------------------------------------\n";
	//FUNCTION: removeTail() WORKS

	clearList(headPtr);
	print(headPtr);
	cout<<"clearList()-----------------------------------------\n";
	//FUNCTION: clearList() WORKS

	insert(headPtr,0,57);
	print(headPtr);
	insert(headPtr2,0,92);
	print(headPtr2);
	insert(headPtr2,1,54);
	print(headPtr2);
	insert(headPtr2,5,206);
	print(headPtr2);
	insert(headPtr2,11,908);
	print(headPtr2);
	insert(headPtr2,13,500000);
	print(headPtr2);
	cout<<"size is:"<<size(headPtr2)<<"\n";
	insert(headPtr2,14,26);
	print(headPtr2);
	cout<<"insert()-----------------------------------------\n";
	//FUNCTION: insert() WORKS

	for(int i = 0 ;i<10;i++)
	{
		insertHead(headPtr3,i);
	}
	Node* testNode = new Node(712);
	print(headPtr3);
	insert(headPtr3,0,testNode);
	print(headPtr3);
	insert(headPtr3,5,testNode);
	print(headPtr3);
	cout<<"insert()-----------------------------------------\n";

	print(headPtr);
	remove(headPtr,0);
	print(headPtr);
	remove(headPtr2,0);
	print(headPtr2);
	remove(headPtr2,1);
	print(headPtr2);
	remove(headPtr2,5);
	print(headPtr2);
	remove(headPtr2,11);
	print(headPtr2);
	cout<<"size is:"<<size(headPtr2)<<"\n";
	remove(headPtr2,10);
	print(headPtr2);
	cout<<"remove()-----------------------------------------\n";
	//FUNCTION: remove() WORKS

	print(headPtr2);
	cout<<"Index 0:";
	(*locate(headPtr2,0)).print();
	cout<<"Index 1:";
	(*locate(headPtr2,1)).print();
	cout<<"Index 5:";
	(*locate(headPtr2,5)).print();
	cout<<"Index 9:";
	(*locate(headPtr2,9)).print();
	cout<<"locate()-----------------------------------------\n";
	//FUNCTION: locate() WORKS

	print(headPtr2);
	swapNext(headPtr2,0);
	print(headPtr2);
	swapNext(headPtr2,1);
	print(headPtr2);
	swapNext(headPtr2,8);
	print(headPtr2);
	swapNext(headPtr2,0);
	print(headPtr2);
	cout<<"swapNext()-----------------------------------------\n";
	//FUNCTION: swapNext() WORKS

	print(headPtr2);
	swap(headPtr2,2,3);
	print(headPtr2);
	swap(headPtr2,0,1);
	print(headPtr2);
	swap(headPtr2,2,4);
	print(headPtr2);
	swap(headPtr2,1,7);
	print(headPtr2);
	swap(headPtr2,0,6);
	print(headPtr2);
	swap(headPtr2,0,9);
	print(headPtr2);
	swap(headPtr2,5,9);
	print(headPtr2);
	cout<<"swap()-----------------------------------------\n";
	//FUNCTION: swap() WORKS

	print(headPtr2);
	reverse(headPtr2);
	print(headPtr2);

	return 0;
}