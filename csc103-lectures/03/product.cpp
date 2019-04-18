#include <iostream>
using namespace std;

int main()
{
  cout<<"Please enter some integers to multiply \n";
  int product = 1;
  int input;
  while(cin>>input)
  {
    product*=input;
  }
  cout<< "The product is "<< product <<"\n";
  return 0;
}