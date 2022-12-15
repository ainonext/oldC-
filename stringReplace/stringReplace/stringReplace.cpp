// stringReplace.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string str;
	cout << "Enter string "<< endl;
	getline(cin, str);
	cout << str<< endl;
  string::iterator it;
  for ( it=str.begin() ; it < str.end(); it++ )
    cout << *it;
	system ("Pause");
	return 0;
}

