// firsttry.cpp: определяет точку входа для консольного приложения.
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

int main(int argc, char* argv[])
{
  int n=0;
  cout << "What you want to do? 1 is area of a triangle, 2 is factorial =";
  cin >> n;
  switch (n)
  { 
  case 1:
   n=1;
  int z;
  z = area (5,3);
  cout << "The result is =" << z;
  char StopCh;
  cout <<endl <<"Press any key and enter ";
  cin >> StopCh;
  return 0;
  break;
  case 2:
	n=2;
	long number;
	cout <<"Please enter the number = ";
	cin >> number;
	cout << number << "!="<<factorial(number);
	cout <<endl <<"Press any key and enter ";
    cin >> StopCh;
	return 0;
	break;
  case 3:
	  n=3;
	  int g;
cout<<"Input g"<<endl;
cin>>g;
if (g==1 || g==2) 
cout<<"F(g)=1";
else
{
int m=1,p=1,temp;
for(int i=2;i<g;i++)
{
temp=p;
p=p+m;
m=temp;
}
cout<<"F(g)="<<p<<endl;
cout <<endl <<"Press any key and enter ";
cin >> StopCh;
return 0;
}
break;
}
}


