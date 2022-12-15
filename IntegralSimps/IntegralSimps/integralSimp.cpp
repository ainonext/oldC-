#include <iostream>
#include <math.h>
using namespace std;

double function(double x);
double simpson(double (*Fx)(double), double a, double b, int m);

int main()
{
	double I;
	double a,b;
	int m;
	cout << "Enter integration parameters "<< endl;
	cout <<endl<< "Enter coordinate of the beginning for integration ";
	cin>> a;
	cout << "Enter coordinate of the ending for integration ";
	cin >> b;
	cout << "Enter number of splittings ";
	cin>> m;
	I=simpson(&function,a,b,m);
	cout << endl<< "Result: I= "<< I<< endl;
	system ("Pause");
	return 0;
}
double function(double x)
{
	double r=x*x-2*x+4;
	return r;
}
double simpson(double (*Fx)(double), double a, double b, int m)
{
	double h;
	h=(b-a)/m;
	double I, I2=0, I4=0;
	I4=Fx(a+h);
	for (int k=2; k<m; k+=2)
	{
		I4+=Fx(a+(k+1)*h);
		I2+=Fx(a+k*h);
	}
	I= Fx(a)+Fx(b)+4*I4+2*I2;
	I*=h/3;
	return I;
}
