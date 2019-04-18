#ifndef __UDDIN__A__HW2_H__
#define __UDDIN__A__HW2_H__
#include <iostream>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;

const int MAX_SIZE = 50;
void fillRay(char arr[],int &used);
char highestOccurence(const char arr[],int size);
void shift(char arr[],int size);
char* merge(char ar1[],int s1,char ar2[],int s2);
void fillMatrix(char** &arr,int &m,int &n);
void rotate(char** arr,int m,int n);
char** enlarge(char** arr,int &m,int &n);

void swap(char *arr,int x,int y);
void swap(char &v1,char &v2);
void printRay(const char *arr,int size);
void printRay(char **arr,int length,int width);
void printRay(const int *arr,int size);
#endif