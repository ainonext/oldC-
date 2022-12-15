#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int maxn=100;
int n,i,s,count,found;
int _min;
int m[maxn],minm[maxn];
int a[maxn][maxn];

void input();                    //ввод данных
void output();                    //вывод данных
void search(int x);
void run();

int main ()
{
	system ("color F0");
	input();
	run();
	output();
	system ("Pause");
	return 0;
}

void input()                    //ввод данных
{
	ifstream fin("input.txt");     //открыли файл
	fin >> n; 
	cout<< "Readed from file N is "<<n<<endl; //считали n
	cout <<"Readed from file matrix is "<< endl;
	for (int i=1;i<=n;i++)
	{	 
		for (int j=1;j<=n;j++)
		{ fin >> a[i][j];                //считали матрицу расстояний
		cout <<setw(2)<< a[i][j]; };
		cout << endl;
	}
}
void output()                    //вывод данных
{

	ofstream fout("output.txt");   //открыли файл
	if (found)                        //если найден маршрут...
	{
		fout << "Lenght of min path = " << _min << endl;
		cout<<"Lenght of min path = "<< _min << endl;
		fout << "Path : ";
		cout << "Path : "<<endl;
		int c=1;                    //номер в порядке обхода городов
		for (int i=1;i<=n;i++)      //пробегаем по всем городам
		{
			int j=1;
			while ((j<=n)&&                //ищем следующий город в порядке обхода    
				(minm[j]!=c)) j++;
			fout << j <<"->";
			cout << j <<"->";
			c++;
		}
		fout << minm[1] << endl;    //обход завершается первым городом
		cout << minm[1] << endl;
	}
	else fout << "Path not found!";
}
void search(int x)
{
	if ((count==n)&&                //если просмотрели все города
		(a[x][1]!=0)&&                //из последнего города есть путь в первый город
		(s+a[x][1]<_min))            //новая сумма расстояний меньше минимальной суммы
	{
		found=1;                    //маршрут найден
		_min=s+a[x][1];                //изменяем: новая минимальная сумма расстояний
		for (int i=1;i<=n;i++)minm[i]=m[i];//изменяем: новый минимальный путь
	}
	else
	{
		for (int i=1;i<=n;i++)     //из текущего города просматриваем все города
			if ((i!=x)&&                //новый город не совпадает с текущим    
				(a[x][i]!=0)&&            //есть прямой путь из x в i
				(m[i]==0)&&            //новый город еще не простотрен
				(s+a[x][i]<_min))    //текущая сумма не превышает минимальной
			{
				s+=a[x][i];                //наращиваем сумму
				count++;                //количество просмотренных городав
				m[i]=count;                //отмечаем у нового города новый номер в порядке обхода
				search(i);                //поиск нового города начиная с города i
				m[i]=0;                    //возвращаем все назад
				count--;                //-"-
				s-=a[x][i];                //-"-
			}
	}
}
void run()
{                                //инициализация                                
	s=0;
	found=0;
	_min=32767;
	for (int i=1;i<=n;i++) m[i]=0;
	count=1;
	m[1]=count;                        //считаем что поиск начинается с первого города
	search(1);                        //считаем что поиск начинается с первого города
}