#include <iostream>
using namespace std;
int main (int argc, char* argv[])
{
	int returnCode=0;
 try 
 {
 float Dividend=0;
 cout << "dividend =";
 cin >> Dividend;

 float Divisor=1;
 cout << "delitel=";
 cin >> Divisor;

 float Result =(Dividend/Divisor);
 cout << Result << endl;
 }
 catch (...)
 {
 cerr << "vvedeno ne chislo";
 cin.clear();
 char BadInput[5];
 cin >>BadInput;
 returnCode=1;
 }
 char StopSymbol;
 cout << "Vvedite chto-to i Enter";
 cin >> StopSymbol;
 return returnCode;
}