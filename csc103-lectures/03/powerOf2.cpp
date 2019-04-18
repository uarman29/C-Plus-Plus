#include <iostream>
using std::cin;
using std::cout;
//Finds exponent of max power of 2 that input is divisible by

int main()
{
  cout<<"Enter an integer \n";
  int input;
  int counter = 0;
  cin>>input;
  while(input%2==0)
  {
    input /= 2;
    counter++;
  }
  cout<< "The max exponent of 2 that can go into input is "<<counter<<"\n";
  return 0;

}