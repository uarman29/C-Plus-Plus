#include <iostream>
using std::cout;
using std::cin;
#include <cmath>

int max(int a,int b,int c)
{
  if(a>b&&a>c)
  {
    return a;
  }
  if(b>a&&b>c)
  {
    return b;
  }
  if(c>a&&c>b)
  {
    return c;
  }
  return a;
}

double average(int a,int b,int c)
{
  return ((double)a+b+c)/3;
}

void swap(int &x,int &y)
{
  int temp = x;
  x = y;
  y = temp;
}

bool isPrime(int num)
{
  if(num%2==0&&num!=2||num<2)
   {
    return false;
   }
   else
   {
     if(num==2)
     {
      return true;
     }
     else
     {
       for(int i=3;i<=sqrt(num);i+=2)
       {
         if(num%i==0)
         {
           return false;
         }
       }
       return true;
     }
   }
}

int fibonacciSequence(int input)
{
  int term1=1;
  int term2=1;
  int placeholder=1;
  if(input<=0)
  {
    return 0;
  }
  else
  {
    if(input==1||input==2)
    {
      return 1;
    }
  }
  for(int i=2;i<input;i++)
  {
    placeholder=term2;
    term2 = term1 + term2;
    term1=placeholder;
  }
  return term2;
}

int main()
{
  int x = 2;
  int y = 5;
  int input;
  cout<<"Average: "<<average(5,10,7)<<"\n";
  cout<<"Max: "<<max(5,10,7)<<"\n";
  cout<<"x: "<<x<<" y: "<<y<<"\n";
  swap(x,y);
  cout<<"x: "<<x<<" y: "<<y<<"\n";
  while(cin>>input)
  {
    cout<<fibonacciSequence(input)<<"\n";
  }
  return 0;
}


