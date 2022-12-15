// try2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;
void mas(int*a,int n)
	{
		/*cout << "Enter elements ";
		for (int i=0;i<n; i++)
			cin >>a[i];*/
		int i;
		scanf("%d", &n);
		a = malloc(n*sizeof(int));
		for (i=0; i <n; i++) 
		{
			 a[i]=0;
		}
		free(a);
	}
void ar(int*a,int n)
	{
		for (int i=0; i<n; i++)
			cout << a[i]<<" ";
	
    }
void insertionSort(int *a, int length) 
{
      int i, j, tmp;
      for (i = 1; i < length; i++) {
            j = i;
            while (j > 0 && a[j - 1] > a[j]) {
                  tmp = a[j];
                  a[j] = a[j - 1];
                  a[j - 1] = tmp;
                  j--;
            }
      }
}
int main(int argc, _TCHAR* argv[])
{
	int n;
	cout <<"Size ";
    cin>>n;
	int *a=new int (n);
	mas(a,n);
	insertionSort(a,n);
	ar(a,n);
	getchar(); getchar();
	return 0;
	
}

