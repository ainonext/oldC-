#include <iostream>
#include "Checks.h"
#include "Sort.h"

using namespace std;// ������������ ���� std

void Initialize(void)
{
	cin.exceptions(cin.failbit); // ������������� ���������� �� ������� ������
}
void error(int err_number) // ��������� ��������� ����������
{
	switch(err_number)
	{
	case 0: // ���������� ������ �� ������� ������ �� 5 ��������
		cin.clear(); 
		char binput[5];
		cin>> binput;
		break;
	case 1: // ��������� ������ ����� ����������� ���������� �������
		cerr << " Correct n must be -128<n<127! Please enter n<0 "<< endl; 
		error(0);
		break;
	case 2: // ��������� ������ ����� �������� ������ ����
		cerr << "You write letters. Element must be number -128<=a[i]<=127. Please enter number  " << endl; 
		error(0);
		break;
	}
}

bool error_float(float d) // �������� �������� �� ��������� �������� �������
{
	if (d-(int)d==0)
		return false;
	else 
		return true;
}

void Check_array(int *a, int n) // �������� ������� �� ��������������� � ������������
{

	int i = 0;
	while(a[i] <= a[i+1] && i < n-1)
	{
		i++;
	}
	if(i != n-1)
	{
		cout << "Array is not sorted! "<< endl;
		Sort <int> (a,n);
	}
	else
		cout << "Array already sorted! "<< endl;
}

bool Continue (const char *e) // ��������� ���������� ���� ���������
{
	char c;
	bool bcharentered=false;
	do
	{
		cout<<e<<"Repeat again? if not press - n ";
		cin>> c;
		bcharentered=!((c=='y')||(c=='n'));
		if(bcharentered)
		{
			cout<< "Please enter \"y\" or \"n\"."<< endl;
		};
	}
	while(bcharentered);
	return (c !='n'); 
}