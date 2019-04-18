//Sum of first n odd cubes
#include <iostream>
using std::cout;
using std::cin;

int main()
{
  int counter;
  int sum=0;
  cout<<"Please input a positive integer \n";
  cin>>counter;
  if(counter<=0)
  {
    cout<<"Invalid input \n";
    return 0;
  }
  for(int i=1;counter>0;i++)
  {
    if(i%2==1)
    {
      sum += (i*i*i);
      counter--;
    }
  }
  cout<<"The sum is "<< sum <<"\n";
  return 0;
}