// ploshad.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int a; cout << "Enter a-katet"; 
	cin >> a; 
	int b; 
	cout << "enter b"; 
	cin >> b;
	int c=a*b/2; 
	cout << "result is "<< c; 
	getchar(); getchar();
	return 0;
}

