#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std; // пространство имен std
double PCFreq=0.0;
__int64 CounterStart = 0;
void StartCounter() // начало отсчета
{
	LARGE_INTEGER li;
	if(!QueryPerformanceFrequency(&li))
		cout << "QueryPerformanceFrequency failed!\n"; // ошибка подсчета 
	PCFreq = double(li.QuadPart)/1000.0; //вычисление процессорного времени высокой точности
	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}
double GetCounter() // подсчет времени работы
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart-CounterStart)/PCFreq;  
}