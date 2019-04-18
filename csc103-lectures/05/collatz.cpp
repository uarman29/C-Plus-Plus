/* More about loops.
 * See lectures 4,5,6 from Prof. Li.,
 * and chapters 3,4 in the book. */

// the usual stuff:
#include <iostream>
using std::cin;
using std::cout;

int main()
{
	/* Collatz conjecture: for all integers n, the following process
	 * will terminate in a finite number of steps:
	 *    if n == 1, stop;
	 *    if n is even, divide by 2;
	 *    if n is odd, multiply by 3 and add 1;
	 *    repeat using this new value of n.
	 * */
	/* TODO: write a program that tests the conjecture for arbitrarily
	 * many integers, provided on standard input.  (Just print the input
	 * and the number of steps it required before terminating.) */
	cout<<"Please input a positive integer \n";
	int n;
	int counter = 0;
	int max;
	cin>>n;
	while(n<1)
	{
		cout<<"Invalid Input \n";
		cout<<"Please input a positive integer \n";
		cin>>n;
	}
	max = n;
	while(n!=1)
	{
		if(n%2==0)
		{
			n /= 2;
		}
		else
		{
			n = n*3+1;
		}
		if(max<n)
		{
			max = n;
		}
		counter++;
	}
	cout<<"The max value reached is "<< max <<"\n";
	cout<<"The number of steps to termination is "<< counter << "\n";
	return 0;
}

/* TODO: keep track of the maximal intermediate value and print that out
 * along with the result. */

// vim:foldlevel=1
