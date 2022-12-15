#include <iostream>
using namespace std;
int main()
{
 char ch;
 cout << "vvodite simvoli, dlya okonchaniya vvoda vvedite x. \n";
 do
 {
	 cout << ":";
	 cin >> ch;
 }
 while (ch!='x');
 return 0;
}