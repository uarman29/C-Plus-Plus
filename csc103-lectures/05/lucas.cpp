/* Lucas sequences. */

// the usual stuff:
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	/* Lucas sequences (of the first kind).  For numbers P,Q, set
	 * U_n = P*U_{n-1} - Q*U_{n-2}.
	 * The first two terms are defined as 0 and 1, respectively.
	 * NOTE: this is a generalization of the fibonacci sequence
	 * (fibonacci is the special case of P==1,Q==-1).
	 * */
	/* TODO: finish our fibonacci code from class, and generalize
	 * to lucas sequences (see above). */
	cout<<"Pleas input two numbers \n";
	int p;
	int q;
	int termNum;
	int term1 = 0;
	int term2 = 1;
	int nextTerm;
	cin>>p>>q;
	cout<<"Please input the term number you want \n";
	cin>>termNum;
	if(termNum<=0)
	{
		cout<<"Invalid Input \n";
		return 0;
	}
	else
	{
		if(termNum==1)
		{
			cout<<"Your term is 0 \n";
      return 0;
		}
		if(termNum==2)
		{
			cout<<"Your term is 1 \n";
      return 0;
		}
	}
	for(int i=2;i<termNum;i++)
	{
		nextTerm = p*term2-q*term1;
		term1 = term2;
		term2 = nextTerm;
	}
	cout<< "Your term is "<<nextTerm<<"\n";
	return 0;
}

// vim:foldlevel=1
