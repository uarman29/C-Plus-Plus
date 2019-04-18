#include <iostream>
#include "Uddin_A_HW2.h"
using namespace std;

int main()
{
	/*char arr[MAX_SIZE] = "";
	int used = 0;
	fillRay(arr,used);
	printRay(arr,used);
	cout<<"The most common letter was: "<<highestOccurence(arr,used)<<"\n";*/
	

	/*char arr3[9] = {'0','1','2','3','4','5','6','7','8'};
	char arr2[9] = {'a','b','c','a','d','e','b','c','a'};
	shift(arr2,9);
	printRay(arr2,9);*/

	/*char sorted1[3] = {'1','2','4'};
	char sorted2[6] = {'0','0','3','5','7','8'};
	char* merged = merge(sorted1,3,sorted2,6);
	printRay(merged,9);
	delete[] merged;*/

	
	int rows = 3;
	int columns = 3;
	char** matrix;
	fillMatrix(matrix,rows,columns);
	printRay(matrix,rows,columns);
	
	/*rotate(matrix,rows,columns);
	printRay(matrix,rows,columns);*/
	char** bigger = enlarge(matrix,rows,columns);
	printRay(bigger,rows,columns);
	return 0;
}