// char.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;

void mas(char *a,int n)
{
	srand(time(NULL));  
	int i;
	/* cout << "Enter elements "<< endl;*/
	for (i=0; i <n; i++) 
		a[i]=rand()%100;
}
void ar(char*a,int n)
{
	cout << "result is "<< endl;
	for (int i=0; i<n; i++)
		cout << a[i] <<" ";
	cout<<endl;
}
int _tmain(int argc, _TCHAR* argv[])
{   int n;
	cout << "enter number of elements ";
	cin >> n;
	char *a = new char[n];
	mas(a,n);
	ar(a,n);
	delete [] a;
	system("Pause");
	return 0;
}

