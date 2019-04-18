#include <iostream>
using std::cin;
using std::cout;
//Finds exponent of max power of 2 that input is divisible by

int main()
{
  cout<<"Enter an integer \n";
  int input;
  int k;
  int counter = 0;
  cin>>input;
  cout<<"Please enter a factor \n";
  cin>>k;
  while(input%k==0)
  {
    input /= k;
    counter++;
  }
  cout<< "The max exponent of k that can go into input is "<<counter<<"\n";
  return 0;

}