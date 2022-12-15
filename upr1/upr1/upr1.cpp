#include <iostream>
#include <conio.h>
using namespace std;
int main ()
{
 double hours,zarplata;
 cout << "vvedite colichestvo chasov ";
 cin >> hours;
 cout << "vvedite pochasovuyu oplatu ";
 cin >> zarplata;
 cout << hours*zarplata << " itogovaya zarplata";
 getch();
 return 0;
}