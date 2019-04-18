#include <iostream>
using namespace std;

int main()
{
  /*int x;
  int y;
  double z;
  cout<< "Please type in an integer \n";
  cin>>x;
  cout<< "Please type in another integer \n";
  cin>>y;
  cout<< "Please type one more integer \n";
  cin>>z;
  cout<<"The average of the integers is "<<(x+y+z)/3<<endl;
  Finds average of three integers
  */
  int x = 0;
  int y;
  cout<< "Please type in 5 integers \n";
  for(int i=0;i<5;i++)
  {
    cin>>y;
    x += y;
  }
  cout<<"The average of the integers is "<<x/5.0<<endl;
  return 0;
}