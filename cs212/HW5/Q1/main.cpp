#include "Uddin_A_HW5_Q1.h"
#include <iostream>
using namespace std;

void printAdd(btNode<int>* i)
{
	cout<<((*i).getData()+5)<<",";
}

int main()
{
	btNode<int> n1(5,NULL,NULL);
	btNode<int> n2(30);
	btNode<int> n3(10,&n1,&n2);
	cout<<n1.isLeaf()<<"\n";
	cout<<n2.isLeaf()<<"\n";
	btNode<int>* root = &n3;
	print(root);
	cout<<"\n"<<height(root)<<"\n";
	cout<<numNodes(root)<<"\n";
	inOrder(printAdd,root);
	cout<<"\n";
	preOrder(printAdd,root);
	cout<<"\n";
	postOrder(printAdd,root);
	cout<<"\n";
	printTree(root);
	return 0;
}
