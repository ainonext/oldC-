#include <iostream>
#include <math.h>
#include <locale.h>
using namespace std;

float func(float x, float y)
{
  return y+4*sin(x*3)*exp(-x)+1;
}

void runge_kutta(float x, float y, int n, float h)
{
  const float eps=0.05;
  float step=h;
  bool first=true;
  float K1=0, K2=0, K3=0, K4=0;
  cout <<"  X         Y";
  for(int i=1; i<=n; i++)
  {
    do
    {
      if (first) first = false;
      else h=h/2;
      K1=func(x,y);
      K2=func(x+h/2,y+h*K1/2);
      K3=func(x+h/2,y+h*K2/2);
      K4=func(x+h,y+h*K3);
        }
    while (abs((K2-K3)/(K1-K2)) > eps);
    x=x+h;
    y=y+h*(K1+2*K2+2*K3+K4)/6;
    cout <<'\n' <<"    "<<x<<"    "<<y<<endl;
    h=step;
  }
    
}

void main()
{
  float X0=0, Y0=1, h=1;
  int n=10;
  system ("color F0");
  runge_kutta(X0,Y0,n,h);
  system("Pause");
}