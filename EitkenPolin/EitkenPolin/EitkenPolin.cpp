#include <iostream>
#include <math.h>
#include <locale.h>
using namespace std;


double interp(int n, double*x, double*y, double t, double eps)
{
	double *q, *P1, *P2;
	q = new double[n];
	P1 = new double[n];
	P2 = new double[n];

	for (int i = 0; i<n; i++)
	{
		q[i] = x[i] - t;
		P1[i] = y[i];
	}

	int k = 0;
	do 
	{
		k++;
		for (int i = 0; i<n; i++)
			P2[i] = (P1[i]*q[i+k] - P1[i+1]*q[i])/(x[i+k]-x[i]);
		if (abs(P2[0] - P1[0]) <= eps || !n)
			return P2[0];
		else
			for (int i=0; i<n; i++)
				P1[i] = P2[i];
		n--;
	}
	while(1);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 0;
	double t = 0, eps = 0;
	cout << "Введите количество контрольных точек: "; cin >> n; 
	double *x, *y;
	x = new double[n];
	y = new double[n];
	for (int i=0; i<n; i++)
	{
		cout <<'\n' << "Контрольная точка " << i+1;
		cout <<'\n' << "Введите абциссу: "; cin >> x[i];
		cout << "Введите ординату: "; cin >> y[i];
	}
	cout <<'\n' << "Введите значение, при котором будет совершаться поиск значения функции "; cin >> t;
	cout << "Введите допустимую погрешность eps: "; cin >> eps;
	cout << "Результат: y("<< t <<") = " << interp(n,x,y,t,eps)<<endl;
	system ("Pause");
}