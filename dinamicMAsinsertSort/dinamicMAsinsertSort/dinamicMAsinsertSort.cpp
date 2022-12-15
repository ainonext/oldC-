// dinamicMAsinsertSort.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;
void mas(int *a,int n)
  {
    int i;
	cout << "Enter elements "<< endl;
    for (i=0; i <n; i++) 
    cin >> a[i];
   }

void ar(int*a,int n)
  {
    for (int i=0; i<n; i++)
      cout << a[i]<<" "<< endl;
  }
void insertionSort(int arr[], int length) 
{
      int i, j, tmp;
      for (i = 1; i < length; i++)
	  {
            j = i;
            while (j > 0 && arr[j - 1] > arr[j])
			{
                  tmp = arr[j];
                  arr[j] = arr[j - 1];
                  arr[j - 1] = tmp;
                  j--;
            }
      }
}
int main(int argc, _TCHAR* argv[])
{
  time_t start,end;
  char szInput [256];
  double dif;
  time (&start);
  int n;
  cout <<"Size ";
    cin>>n;
  int *a = new int[n];
  mas(a,n);
  insertionSort(a,n);
  ar(a,n);
  delete [] a;
  time (&end);
  dif = difftime (end,start);
  cout << "time is "<< dif<< endl;
  system("Pause");
   return 0;
  
}
