#include "Bag.h"
#include <iostream>
using namespace std;

int main()
{
	Bag b1;
	Bag b2;

	for(int i = 1;i<=10;i++)
	{
		b1.insert(i*i);
	}
	b1.print();

	for(int i = 1;i<=3;i++)
	{
		b2.insert(i);
	}
	b2.print();
	b2 += b2;
	b2.print();

	return 0;
}