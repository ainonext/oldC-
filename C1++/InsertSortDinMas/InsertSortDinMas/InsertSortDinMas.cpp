// InsertSortDinMas.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
void mas(int *a,int n)
  {
	srand(time(NULL));  
    int i;
	/* cout << "Enter elements "<< endl;*/
    for (i=0; i <n; i++) 
		a[i]=rand()%100;
   }

void ar(int*a,int n)
  {
	  cout << "result is "<< endl;
    for (int i=0; i<n; i++)
      cout << a[i] <<" ";
	cout<<endl;
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

void Sort(int a[],int col)
	{
		int temp;
		int sorted=true;
		while(sorted){
			sorted=false;
			for (int i=0; i<col-1; i++){
				if(a[i]>a[i+1]){
					temp=a[i+1];
					a[i+1]=a[i];
					a[i]=temp;
					sorted=true;
				}
			}
		}
      }
				
int main(int argc, _TCHAR* argv[])
{
	
  int n;
  cout <<"Size ";
    cin>>n;
  int *a = new int[n];
  int *b = new int[n];
  mas(a,n);
  mas(b,n);
  time_t start1, end1,start2,end2;
  char szInput [256];
  double dif;
  time (&start1);
  insertionSort(a,n);
  /*ar(a,n);*/
  time (&end1);
  //mas(a,n);
  time (&start2);
  Sort(b,n);
  //ar(a,n);
  time (&end2);
  delete [] a;
   dif = difftime (end1,start1);
   cout << "time1 is "<< dif<< endl;
   dif = difftime (end2,start2);
   cout << "time2 is "<< dif<< endl;
   system("Pause");
   return 0;
  
}