#include <iostream>
using namespace std;
void initialize (void)
{
 cin.exceptions(cin.failbit);
}
float GetDividend(void)
{
 float dividend=0;
 cout << "dividend=";
 cin>> dividend;
 return dividend;
}
float GetDivisor(void)
{
 float divisor=1;
 cout << "Divisor =";
 cin >> divisor;
 return divisor;
}
float divide(const float theDividend, const float theDivisor)
{
 return (theDividend/theDivisor);
}
int VvedenoNeChislo(void)
{
  cerr << "vvedeno ne chislo"<< endl;
  cin.clear();
  char BadInput[5];
  cin >> BadInput;
  return 1;
}
void ActionForExit(void)
{
 char StopCharacter;
 cout << " Vvedite chtoto and Enter dlya vahoda";
 cin >> StopCharacter;
}
int main(int argc, char* argv[])
{
 initialize();
 int returnCode=0;
 try 
 {
  float Dividend=GetDividend();
  float Divisor=GetDivisor();
  cout << divide(Dividend,Divisor)<<endl;

 }
 catch(...)
 {
  returnCode=VvedenoNeChislo();
 };
ActionForExit();
return returnCode;
}