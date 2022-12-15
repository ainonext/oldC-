#include <iostream>
using namespace std;
int main()
{
 {
     int a, b, d, min;
     cout <<"Vvedite dva chisla=";
     cin >> a >> b;
     min=a > b ? b: a;
 for (d=2; d<min; d++)
	 if ((a%d)==0)&&((b%d)==0)) break;
 if (d==min)
  
   cout<<"net obshego kratnogo\n";
   return 0;
   
 }
 cout << "Naimenshee obsh kratnoe ="<<d;
 return 0;
}