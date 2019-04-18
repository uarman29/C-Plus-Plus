#include <iostream>
using std:: cin;
using std:: cout;

int main()
{
  int n;
  int k;
  int upper;
  int lower;
  cout<<"Please enter two numbers \n";
  cin>>n>>k;
  if(n==k)
  {
    cout<<"The greatest common divisor is "<< k <<"\n";
    return 0;
  }
  else
  {
    if(n>k)
    {
      upper = n;
      lower = k;
    }
    else
    {
      if(n<k)
      {
        upper=k;
        lower=n;
      }
    }
  }
  for(int i=lower;i>0;i--)
  {
    if(lower%i==0&&upper%i==0)
    {
      cout<<"The greatest common divisor is "<< i <<"\n";
      return 0;
    }
  }
  return 0;
}