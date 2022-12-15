#include <iostream>
using namespace std;
int Input_n();
void Input_array(int *a, int n);

int main()
{
	int n;
	int eps;
	n=Input_n();
	cout << "enter eps ";
	cin>> eps;
	int *x=new int [n];
	Input_array(x,n);
	int *y=new int [n];
	Input_array(y,n);
	int *a=new int [n];
	Input_array(a,n);
	int *b=new int [n];
	Input_array(b,n);
	int *c=new int [n];
	Input_array(c,n);
	int t;
	for (int i=0; i<n;i++)
	{
		b[i]=y[i];
		a[i]=x[i]-t;
	}
	bool flag=true;
	int k=0;
	while (flag)
	{
		k++; n--;
		for (int i=0; i<n; i++)
			c[i]=((b[i]*a[i+k]-b[i+1]*a[i])/(x[i+k]-x[i]));
	}
	if((c[0]-b[0])<=eps)
		flag=false;
	else 
		for (int j=0; j<n; j++)
			b[j]=c[j];

delete []a; 
system ("Pause");
return c[0];
}

int Input_n()
{ int n;
cout << "enter n ";
cin >>n;
return n;
}
void Input_array(int *a, int n)
{
	cout << "Elements of array "<< endl;
	for (int i=0; i<n;i++)
	{
		cin>> a[i];
	}

}