#include <iostream>
using std::cout;
using std::cin;
#include <vector>
using std::vector;

bool inVector(vector<int> v,int x)
{
  for(int i=0;i<v.size();i++)
  {
    if(v[i]==x)
    {
      return true;
    }
  }
  return false;
}

int binarySearch(vector<int> v,int target)
{
  int high = v.size()-1;
  int low = 0;
  int mid = (high+low)/2;
  while(high>=low)
  {
    if(v[mid]==target)
    {
      return mid;
    }
    else
    {
      if(v[mid]>target)
      {
        high = mid-1;
      }
      else
      {
        low = mid+1;
      }
      mid = (high+low)/2;
    }
  }
  return -1;
}

void printVector(vector<int> v)
{
  for(int i=0;i<v.size()-1;i++)
  {
    cout<<v[i]<<", ";
  }
  cout<<v[v.size()-1]<<"\n";
}

void vectorSwap(vector<int> &v,int a,int b)
{
  int temp = v[a];
  v[a] = v[b];
  v[b] = temp;
}

void sortVector(vector<int> &v)
{
  int min;
  int minIndex = 0;
  for(int j= 0;j<v.size()-1;j++)
  {
    min = v[j];
    minIndex = j;
    for(int i=j+1;i<v.size();i++)
    {
      if(min>v[i])
      {
        min = v[i];
        minIndex=i;
      }
    }
    vectorSwap(v,j,minIndex);
  }
}

int findIndexOfSmallest(vector<int> v,int start,int end)
{
  int min = v[start];
  int minIndex = start;
  for(int i=start+1;i<end;i++)
  {
    if(min>v[i])
    {
      min = v[i];
      minIndex=i;
    }
  }
  return minIndex;
}

int main()
{
  vector<int> v;
  int n;
  /*for(int i=0;i<20;i++)
  {
    v.push_back(i);
  }
  cout<<"Please enter a number \n";
  while(cin>>n)
  {
    cout<<"Which index is this element?: "<<binarySearch(v,n)<<    "\n";
    cout<<"Please enter a number \n";
  }
  while(cin>>n)
  {
    cout<<"Is element in vector?: "<<inVector(v,n)<<"\n";
    cout<<"Please enter a number \n";
  }
  for(int i=20;i>0;i--)
  {
    v.push_back(i);
  }
  printVector(v);
  sortVector(v);
  printVector(v);*/
  while(cin>>n)
  {
    v.push_back(n);
  }
  printVector(v);
  sortVector(v);
  printVector(v);
  return 0;
}

