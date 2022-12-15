#include <iostream>
#include <time.h>
#include <windows.h>
#include "IO.h"
#include "Checks.h"
#include "Time.h"
using namespace std; // пространство имен std

int main()
{  
	system ("color F0"); // цвет экрана белый
	do
	{
		int n;
		n=Input_n(); // ввод колличества элементов массива А
		int *a=new int [n]; // объявление массива А
		Input_array(a,n); // ввод массива A
		StartCounter(); // начало отсчета времени работы
		Check_array(a,n); // проверка элементов массива
		cout << GetCounter()<<" mks" <<endl; // подсчет времени работы
		Output_array(a,n); // вывод массива A
		delete [] a; // удаление массива
		double PCFreq = 0.0; 
		__int64 CounterStart = 0;
	}
	while (Continue("Done! ")); // повторное выполнение всей программы
	return 0;
}


