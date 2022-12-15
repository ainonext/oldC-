#include <iostream>
#include <iomanip>
#include "IO.h"
#include "Checks.h"
using namespace std; // ������������ ���� std

int Input_n() // ���� ����������� ���������� ������� �
{ 
	float f;
	int n;
	do
	{   
		Initialize(); // ������������� ���������� �� ������� ������
		try
		{  
			cout << "Enter n ";
			cin >> f;
			if ((error_float(f))||(f<=0) || (f>=127))
				cout <<  " Correct n must be 0<n<127! " << endl;
		}

		catch(...)
		{
			error(1); // ��������� ������ ����� ����������� ���������� �������
		}
	}
	while ((f<=0) || (f>=127)||(error_float(f)));
	return n=f;
}

void Input_array(int *a, int n) // ���� ������� A
{
	float f;
	int i=0;
	cout << "Elements of array "<< endl;
	while (i<n)
	{
		Initialize(); // ������������� ���������� �� ������� ������
		try
		{
			cin >> f;
			if (error_float(f) || f<=-128|| f>=127)
				cout <<  "In position "<<i+1<<" must be number -128<=a[i]<=127. Please enter correct number  " ;
			else {
				a[i] = (int) f;
				i++;
			}
		}
		catch (...)
		{
			error(2); // ��������� ������ ����� �������� ������ ����
		}
	}
}

void Output_array(int *a, int n) // ����� ������� A
{
	cout << "Resulted array is "<< endl;
	for (int i=0; i<n;i++){
		cout<< setw(4)<< a[i];
		if((i+1)%15==0) // ����� �� 15 ��������� � ������
			cout<< endl;
	}
	cout<< endl;

}
