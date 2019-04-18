/*
 * CSc103 Project 2: prime numbers.
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
<<<<<<< HEAD
 * References:readme.html
=======
 * References:
>>>>>>> 2b0f5acf05ef4bfc3c5b24a4064e476e34b0faa8
 *
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
<<<<<<< HEAD
#include <cmath>

int main()
{
  int input;
  bool printed;
  while(cin>>input)
  {
   if((input>2&&input%2==0)||input==0||input==1)
   {
    cout<<0<<endl;
   }
   else
   {
     if(input==2)
     {
      cout<<1<<endl;
     }
     else
     {
       printed=false;
       for(int i=3;i<=sqrt(input);i+=2)
       {
         if(input%i==0)
         {
          cout<<0<<endl;
          printed=true;
          break;
         }
       }
       if(!printed)
       {
         cout<<1<<endl;
       }
     }
   }
  }
  return 0;
=======

int main()
{
	return 0;
>>>>>>> 2b0f5acf05ef4bfc3c5b24a4064e476e34b0faa8
}
