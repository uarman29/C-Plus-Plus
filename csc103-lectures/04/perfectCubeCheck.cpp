//Check if input is a perfect cube
#include <iostream>
using std::cout;
using std::cin;

int main()
{
  int input;
  cout<<"Please input a number \n";
  cin>>input;
  if(input==0)
  {
    cout<<"It is a perfect cube \n";
    return 0;
  }
  else
  {
    if(input>0)
    {
      for(int i=1;i<input;i++)
      {
        if((i*i*i)==input)
        {
          cout<<"It is a perfect cube \n";
          return 0;
        }
      }
    }
    else
    {
      if(input<0)
      {
        for(int i=-1;i>input;i--)
        {
          if((i*i*i)==input)
          {
            cout<<"It is a perfect cube \n";
            return 0;
          }
        }
      }
    }
  }
  cout<<"It is not a perfect cube \n";
  return 0;
}