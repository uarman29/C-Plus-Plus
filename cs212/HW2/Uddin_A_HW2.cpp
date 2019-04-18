#ifndef __UDDIN__A__HW2__CPP__
#define __UDDIN__A__HW2__CPP__
#include "Uddin_A_HW2.h"


void fillRay(char arr[],int &used)
{
	cout<<"Please enter letters to fill an array of size "<<MAX_SIZE<<"\n";
	used = 0;
	char input;
	while(used<MAX_SIZE && cin>>input && isalpha(input))
	{
		arr[used] = input;
		used++;
	}
}

char highestOccurence(const char arr[],int size)
{
	int count[26] = {0};
	for(int i = 0;i<size;i++)
	{
		count[arr[i]-'a']++;
	}
	int maxIndex = 0;
	for(int i=1;i<26;i++)
	{
		if(count[i]>count[maxIndex])
		{
			maxIndex = i;
		}

	}
	return maxIndex+'a';
}
void shift(char arr[],int size)
{
	int shift;
	cout<<"Please enter shift amount: ";
	cin>>shift;
	while(shift<0)
		shift = shift+size;

	int start = 0;
	int count = 0;
	int storedIndex = shift%size;
	while(count<size)
	{
		swap(arr,start,storedIndex);
		if(storedIndex==start)
		{
			start++;
			storedIndex++;
		}
		storedIndex = (storedIndex+shift)%size;
		count++;
	}
}

void swap(char *arr,int x,int y)
{
	char tmp = arr[x];
	arr[x] = arr[y];
	arr[y] = tmp;
}

void swap(char &v1,char &v2)
{
	char tmp = v1;
	v1 = v2;
	v2 = tmp;
}

char * merge(char ar1[],int s1,char ar2[],int s2)
{
	char* result = new char[s1+s2];
	int resultIndex = 0;
	int leftIndex = 0;
	int rightIndex = 0;
	while(leftIndex != s1 && rightIndex != s2)
	{
		if(ar1[leftIndex]<ar2[rightIndex])
		{
			result[resultIndex] = ar1[leftIndex];
			resultIndex++;
			leftIndex++;
		}
		else
		{
			result[resultIndex] = ar2[rightIndex];
			resultIndex++;
			rightIndex++;
		}
	}
	while(leftIndex<s1)
	{
		result[resultIndex] = ar1[leftIndex];
		resultIndex++;
		leftIndex++;
	}
	while(rightIndex<s2)
	{
		result[resultIndex] = ar2[rightIndex];
		resultIndex++;
		rightIndex++;
	}
	return result;
}

void fillMatrix(char** &arr,int &m,int &n)
{
	cout<<"Please enter the height of the matrix:";
	cin>>m;
	cout<<"Please enter the length of the matrix:";
	cin>>n;
	cout<<"Please enter letters to fill a "<<m<<" x "<<n<<" matrix\n";
	char** matrix = new char*[m];
	for(int i=0;i<m;i++)
	{
		matrix[i] = new char[n];
	}
	char input;
	for(int i = 0;i<m;i++)
	{
		for(int j = 0;j<n;j++)
		{
			cin>>input;
			matrix[i][j] = input;
		}
	}
	arr = matrix;
}

void rotate(char** arr,int m,int n)
{
	cout<<"Please enter the number of rotations: ";
	int rotations;
	cin>>rotations;
	for(int i = 0;i<abs(rotations);i++)
	{
		for(int r = 0;r<m;r++)
		{
			for(int c = r+1;c<n;c++)
			{
				swap(arr[r][c],arr[c][r]);
			}
		}
		if(rotations<0)
		{
			for(int r = 0;r<m;r++)
			{
				for(int c = 0;c<n/2;c++)
				{
					swap(arr[r][c],arr[r][n-1-c]);
				}
			}
		}
		else
		{
			for(int r = 0;r<m/2;r++)
			{
				for(int c = 0;c<n;c++)
				{
					swap(arr[r][c],arr[m-1-r][c]);
				}
			}
		}
	}
}

char** enlarge(char** arr,int &m,int &n)
{
	cout<<"How much do you wish to enlarge the matrix by?\n";
	int factor;
	cin>> factor;
	assert(factor>0);
	m*=factor;
	n*=factor;
	char** scaled  = new char*[m];
	for(int i = 0;i<m;i++)
	{
		scaled[i] = new char[n];
	}
	for(int r = 0;r<m;r++)
	{
		for(int c = 0;c<n;c++)
		{
			scaled[r][c] = arr[r/factor][c/factor];
		}
	}
	return scaled;
}

void printRay(const char *arr,int size)
{
	for(int i = 0;i<size-1;i++)
	{
		cout<<arr[i]<<", ";
	}
	cout<<arr[size-1]<<"\n";
}

void printRay(const int *arr,int size)
{
	for(int i = 0;i<size-1;i++)
	{
		cout<<arr[i]<<", ";
	}
	cout<<arr[size-1]<<"\n";
}

void printRay(char **arr,int length,int width)
{
	for(int i = 0;i<length;i++)
	{
		for(int j = 0;j<width-1;j++)
		{
			cout<<arr[i][j]<<", ";
		}
		cout<<arr[i][width-1]<<"\n";
	}
}
#endif