// try2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void mas(int*a,int n)
	{
		cout << "Enter elements ";
		for (int i=0;i<n; i++)
			cin >>a[i];
	}
void ar(int*a,int n)
	{
		for (int i=0; i<n; i++)
			cout << a[i]<<" ";
	
    }
int main(int argc, _TCHAR* argv[])
{
	int n;
	cout <<"Size ";
    cin>>n;
	/*for (int i=0; i<100; i=i+5)
		cout << i << " ";*/
	/*int i=0;
	while (i<100) 
	{
    i=i+5;
	cout << i << " ";
	}
	getchar();
	return 0;*/
	/*int n=0;
	cout << "Enter number ";
	cin >>n;
	bool issimple=true;
	for (int i=2; i<n/2; i++)
		if (n%i==0) issimple=false;
	if (issimple) cout << "simple number";
	else cout << "not simple number";*/
	int *a=new int (n);
	/*for (int i=0; i<20;i++)
	{
		a[i]=i;
	
	
	}*/
	mas(a,n);
	ar(a,n);
	getchar(); getchar();
	return 0;
	
}

