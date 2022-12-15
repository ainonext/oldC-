// sortBooble.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int array[100];

void Sort(int col)
{
int trash=0;
int sorted=true;
for (int i=1; i<=col ; i++)
{
	sorted=false;
for (int j=1; j<=col-i; j++)
{
if (array [j]>array [j+1])
{
trash=array[j];
array [j]=array [j+1];
array [j+1]=trash;
sorted=true;
}
}
}
}

void Out(int col)
{
for (int i=1; i<=col; i++)
cout << array [i] <<" ";
cout << endl;
}

int main()
{
int col_el;

cout << " Enter length of array"<< endl;
cin >> col_el;
cout << "Enter ekements "<< endl;
for (int n=1; n<=col_el ; n++)
cin >> array[n];

Sort(col_el);
cout << "Result is :"<<endl;
Out(col_el);
cin >> col_el;
getchar();
return 0;
}