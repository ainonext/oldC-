#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int maxn=100;
int n,i,s,count,found;
int _min;
int m[maxn],minm[maxn];
int a[maxn][maxn];

void input();                    //���� ������
void output();                    //����� ������
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

void input()                    //���� ������
{
	ifstream fin("input.txt");     //������� ����
	fin >> n; 
	cout<< "Readed from file N is "<<n<<endl; //������� n
	cout <<"Readed from file matrix is "<< endl;
	for (int i=1;i<=n;i++)
	{	 
		for (int j=1;j<=n;j++)
		{ fin >> a[i][j];                //������� ������� ����������
		cout <<setw(2)<< a[i][j]; };
		cout << endl;
	}
}
void output()                    //����� ������
{

	ofstream fout("output.txt");   //������� ����
	if (found)                        //���� ������ �������...
	{
		fout << "Lenght of min path = " << _min << endl;
		cout<<"Lenght of min path = "<< _min << endl;
		fout << "Path : ";
		cout << "Path : "<<endl;
		int c=1;                    //����� � ������� ������ �������
		for (int i=1;i<=n;i++)      //��������� �� ���� �������
		{
			int j=1;
			while ((j<=n)&&                //���� ��������� ����� � ������� ������    
				(minm[j]!=c)) j++;
			fout << j <<"->";
			cout << j <<"->";
			c++;
		}
		fout << minm[1] << endl;    //����� ����������� ������ �������
		cout << minm[1] << endl;
	}
	else fout << "Path not found!";
}
void search(int x)
{
	if ((count==n)&&                //���� ����������� ��� ������
		(a[x][1]!=0)&&                //�� ���������� ������ ���� ���� � ������ �����
		(s+a[x][1]<_min))            //����� ����� ���������� ������ ����������� �����
	{
		found=1;                    //������� ������
		_min=s+a[x][1];                //��������: ����� ����������� ����� ����������
		for (int i=1;i<=n;i++)minm[i]=m[i];//��������: ����� ����������� ����
	}
	else
	{
		for (int i=1;i<=n;i++)     //�� �������� ������ ������������� ��� ������
			if ((i!=x)&&                //����� ����� �� ��������� � �������    
				(a[x][i]!=0)&&            //���� ������ ���� �� x � i
				(m[i]==0)&&            //����� ����� ��� �� ����������
				(s+a[x][i]<_min))    //������� ����� �� ��������� �����������
			{
				s+=a[x][i];                //���������� �����
				count++;                //���������� ������������� �������
				m[i]=count;                //�������� � ������ ������ ����� ����� � ������� ������
				search(i);                //����� ������ ������ ������� � ������ i
				m[i]=0;                    //���������� ��� �����
				count--;                //-"-
				s-=a[x][i];                //-"-
			}
	}
}
void run()
{                                //�������������                                
	s=0;
	found=0;
	_min=32767;
	for (int i=1;i<=n;i++) m[i]=0;
	count=1;
	m[1]=count;                        //������� ��� ����� ���������� � ������� ������
	search(1);                        //������� ��� ����� ���������� � ������� ������
}