#include <iostream>
using namespace std;
int main()
{
 double fut;
 //eto stranii sposob /*delat komentarii*/
 do 
 {cout <<" Vvedite chislo futov ili 0 dlya vihoda";
  cout <<"= ";
  cin >> fut;
  cout << fut*12<<" dyuim\n";
 }
 while(fut !=0.0);
 return 0;
}