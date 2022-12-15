#include <iostream>
#include <conio.h>
 using namespace std;
 class myclass {
 public: 
	 int a;
 };
int main()
{
 myclass ob1 , ob2;
 ob1.a = 10;
 ob2.a = 99;

 cout << ob1.a << "\n";
 cout << ob2.a << "\n";
 getch();
 return 0;

}