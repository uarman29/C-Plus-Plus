//Prints out nth term of fibonacci sequence
#include <iostream>
using std::cout;
using std::cin;

int main()
{
  int term1=1;
  int term2=1;
  int placeholder=1;
  int input;
  cout<<"Please enter a positive Integer \n";
  cin>>input;
  if(input<=0)
  {
    cout<<"Invalid Input \n";
    return 0;
  }
  else
  {
    if(input==1||input==2)
    {
      cout<<"Your term is 1 \n";
      return 0;
    }
  }
  for(int i=2;i<input;i++)
  {
    placeholder=term2;
    term2 = term1 + term2;
    term1=placeholder;
  }
  cout<< "Your term is "<<term2<<"\n";
  return 0;
}