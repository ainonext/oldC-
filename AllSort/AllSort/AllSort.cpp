// AllSort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
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

void insertionSort(int a[], int n) 
{
	int i, j, tmp;
	for (i = 1; i < n; i++)
	{
		j = i;
		while (j > 0 && a[j - 1] > a[j])
		{
			tmp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = tmp;
			j--;
		}
	}
}

void Sort(int a[],int n)
{
	int temp;
	int sorted=true;
	while(sorted){
		sorted=false;
		for (int i=0; i<n-1; i++){
			if(a[i]>a[i+1]){
				temp=a[i+1];
				a[i+1]=a[i];
				a[i]=temp;
				sorted=true;
			}
		}
	}
}
void qSort (int *a, int n)
{
	int i=0;
	int j=n;
	int p =a[ n/2];
	do {
		while ( a[i] < p ) i++;
		while ( a[j] > p ) j--;

		if (i <= j) {
			int temp = a[i]; a[i] = a[j]; a[j] = temp;
			i++; j--;
		}
	} while ( i<=j );
	if ( j > 0 ) qSort(a, j);
	if ( n > i ) qSort(a+i, n-i); 
}
int linearSearch (int a[], int key, int n )
{	
	int i=1;
	for (int i=1;i<=n;i++)
	{
		if (a[i]==key)
			return i;
	}
	return -1;
}
void printHeader (int n)
{

    cout << endl << "Indexes: " << endl;
	for (int i = 0; i < n; i++)
    cout << setw(3) << i << ' ';
	cout << endl;
	for (int i = 0; i < n; i++)
    cout << "----";
    cout << endl;
}
void printRow (int b[], int low, int middle, int high, int n)
{

    for (int i = 0; i < n; i++)
    { 
		if (i < low || i > high)
	    cout << " ";
		else if (i == middle)
	    cout << setw(3) << b[i] << '*';
		    else
		        cout << setw(3) << b[i] << ' ';
	}
	cout<<endl;
}
int binarySearch (int a[], int key, int low, int high, int n)
{
	int middle;
	while (low <= high)
	{
	    middle = (low + high) / 2;
		printRow (a, low, middle, high, n);
			if (key == a[middle])
		    return middle;
			else 
				if (key < a[middle])
				high = middle - 1;
				    else
			        low = middle + 1;
	}

	return -1;
}

int main(int argc, _TCHAR* argv[])
{
	int n;
	cout <<"Size ";
	cin>>n;
	int *a = new int[n];
	mas(a,n);
	time_t start1,end1,start2,end2;
	char szInput [256];
	double dif;
	int numb =0;
	cout << "Which sort or search do you need to use? 1- InsertSort, 2- BubbleSort, 3 - qSort, 4 - linearSearch, 5 - binarySearch ";
	cin >> numb;
	switch(numb)
	{
	case 1:
		time (&start1);
		insertionSort(a,n);
		ar(a,n);
		time (&end1);
		dif = difftime (end1,start1);
		cout << "time1 is "<< dif<< endl;
		break;
		
	case 2:
		time (&start2);
		Sort(a,n);
		ar(a,n);
		time (&end2);
		dif = difftime (end2,start2);
		cout << "time2 is "<< dif<< endl;
		break;
	case 3:
		ar(a,n);
		qSort(a,n-1);
		ar(a,n);
		break;
	case 4:
		ar(a,n);
		int searchKey;
		cout << "Enter a key of search: " << endl;
        cin >> searchKey;
		ar(a,n);
		int element;
		element = linearSearch(a, searchKey, n);
		if (element != -1)
			cout << "Value is found in an element " << element << endl;
		else 
			cout << "Value is not found" << endl;
	break;
	case 5:
		qSort(a,n-1);
		ar(a,n);
		int key, result;
		cout << "enter key for search ";
		cin >> key;
		printHeader (n);
		result = binarySearch (a, key, 0, n, n);

	if (result != -1)

    cout << endl << key << " found in element of massiv " << result << endl;

		else

		cout << endl << key << " no found" << endl;

	break;
	}  
	delete [] a;
	system("Pause");
	return 0;
	}