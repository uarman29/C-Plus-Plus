#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
  int current_min = INT_MAX;
  int current_number;
  int second_min;
  cin>>current_min;
  second_min = current_min;
  cin>>second_min;
  if(current_min>second_min)
  {
    current_number = second_min;
    second_min = current_min;
    current_min = current_number;
  }
  while(cin>>current_number)
  {
    if(current_number<current_min)
    {
      second_min = current_min;
      current_min = current_number;
    }
    else
    {
      if(current_number<second_min)
      {
        second_min = current_number;
      }
    }
  }
  cout<<"The second smallest value was "<< second_min << "\n";
  return 0;
}