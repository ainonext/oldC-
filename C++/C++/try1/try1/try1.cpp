// try1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int area (int a, int b)
{
int r;
r=a*b/2;
return (r);
}
long factorial (long a)
{
if (a>1)
return (a*factorial(a-1));
else
return (1);
}
int fib(int f)
{
if (f==1||f==2) return 1;
else return (fib(f-1)+fib(f-2));
}
int addition (int n)
{
if (n>1)
	return (n+addition(n+1));
else
	return (1);
}

int main(int argc, char* argv[])
{
int n=0;
cout << "What you want to do? 1 is area of a triangle, 2 is factorial, 3 is feb =";
cin >> n;
switch (n)
{
case 0:
	int g;
	cout << "g =";
	cin >> g;
	cout>> addition(g);
	break;
case 1:
int z;
z = area (5,3);
cout << "The result is =" << z;

break;
case 2:
long number;
cout <<"Please enter the number = ";
cin >> number;
cout << number << "!="<<factorial(number);
break;
case 3:
	
	int f;
	cout <<"enter the number=";
	cin >> f;
	cout << endl << fib(f);
break;
}
char StopCh;
cout <<endl <<"Press any key and enter ";
cin >> StopCh;
return 0;
}