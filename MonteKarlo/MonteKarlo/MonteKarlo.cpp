#include <iostream>
#include <math.h>
#include <time.h>
#include <random>
#include <locale.h>
using  namespace std;

float f1(float x);
float f2 (float x);
float f3 (float x);
float **fsolve(float eps);
float leftBorder(float **arr);
float rightBorder(float **arr);
float topBorder(float**arr);
float bottomBorder(float**arr);
bool inArea(float x,float y);
float monteCarlo(float eps);

int main()
{
	setlocale(LC_ALL, "Russian");
	system ("color F0");
	cout << "Функции: "<< endl<<endl;
	cout << "y = 15*cos(x)-6 "<< endl;
	cout << "y = x+2"<<endl;
	cout << "y = 7*(x+1)^3"<<endl<<endl;

	cout << "Решение = "<<monteCarlo(0.001)<<endl;
	system("Pause");
}

float f1(float x)
{
	return 15*cos(x)-6;
}
float f2 (float x)
{
	return 7*(pow(x+1, 3));
}
float f3 (float x)
{
	return x+2;
}
float **fsolve(float eps)
{
	float **res=new float*[3];
	for (int i=0; i<3; i++)
		res[i]=new float[2];
	float fbuf1,fbuf2,fbuf3;
	for (int i=0; i<6;i+=eps/2)
	{
		fbuf1=f1(i);
		fbuf2=f2(i);
		fbuf3=f3(i);

		if (abs(fbuf1-fbuf2)<eps)
		{
			res[0][0]=i;
			res[0][1]=(fbuf1+fbuf2)/2;
		}
		else
		{
			if (abs(fbuf2-fbuf3)<eps)
			{
				res[1][0]=i;
				res[1][1]=(fbuf2+fbuf3)/2;
			}
			else 
			{
				if (abs(fbuf1-fbuf3)<eps)
				{
					res[2][0]=i;
					res[2][1]=(fbuf1+fbuf3)/2;
				}
			}
		}
	}
	return res;
}

float leftBorder(float **arr)
{
	float res=arr[0][0];
	for (int i=1; i<3;i++)
		if (arr[i][0]<res)
			res=arr[i][0];
	return res;
}
float rightBorder(float **arr)
{
	float res=arr[0][0];
	for (int i=1;i<3;i++)
		if (arr[i][0]>res)
			res=arr[i][0];
	return res;
}
float topBorder(float**arr)
{
	float res=arr[0][1];
	for (int i=1;i<3;i++)
		if (arr[i][0]>res)
			res=arr[i][1];
	return res;
}
float bottomBorder(float**arr)
{
	float res=arr[0][1];
	for (int i=1; i<3;i++)
		if (arr[i][0]<res)
			res=arr[i][1];
	return res;
}
bool inArea(float x,float y)
{
	if ((f1(x)>=y)&& (f3(x)>=y)&&(f2(x)<=y))
		return true;
	else
		return false;
}
float monteCarlo(float eps)
{
	float res=0;
	float x,y;
	float **dot=fsolve(eps);
	float l=leftBorder(dot);
	float r=rightBorder(dot);
	float t=topBorder(dot);
	float b=bottomBorder(dot);
	int m=0, n=0;
	srand(time(NULL));
	int con=0;
	for (con=0;con<10;con++)
	{
		m=0; n=0;
		for (int i=0;i<1000;i++)
		{
			x=(float)(rand()%(int)((r-l)/eps))*eps+l;
			y=(float)(rand()%(int)((t-b)/eps))*eps+b;
			if (inArea(x,y))
				m++;
			n++;
		}
		res +=(float)(((float)(m)/(float)n)*(r-l)*(t-b));
	}
	res/=con;
	return res;
}