#include <iostream>
#include <time.h>
#include <windows.h>
#include "IO.h"
#include "Checks.h"
#include "Time.h"
using namespace std; // ������������ ���� std

int main()
{  
	system ("color F0"); // ���� ������ �����
	do
	{
		int n;
		n=Input_n(); // ���� ����������� ��������� ������� �
		int *a=new int [n]; // ���������� ������� �
		Input_array(a,n); // ���� ������� A
		StartCounter(); // ������ ������� ������� ������
		Check_array(a,n); // �������� ��������� �������
		cout << GetCounter()<<" mks" <<endl; // ������� ������� ������
		Output_array(a,n); // ����� ������� A
		delete [] a; // �������� �������
		double PCFreq = 0.0; 
		__int64 CounterStart = 0;
	}
	while (Continue("Done! ")); // ��������� ���������� ���� ���������
	return 0;
}


