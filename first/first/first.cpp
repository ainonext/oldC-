
#include <iostream>
#include <conio.h>
 using namespace std;
  int main()
  {
  int i,j, k, p;
  double d;
  float m;
  char s[80];
  i=10;
  j=20;
  d=99.101;
  cout << "vot neskolko chisel: ";
  cout << i;
  cout << ' ';
  cout << j <<' ';
  cout << d << '  ';
  cout <<" vvedite chislo ";
   cin >> k;
   cout <<"vot vashe chislo: "<< k << "\n";
  cout << " Vvedite celoe chislo s plav tochkoi v stroku ";
   cin >> p >> m >> s;
   cout << "vot vashi dannie: ";
   cout << p << ' '<< m<<' ' << s;
  getch();
  return 0;
  }