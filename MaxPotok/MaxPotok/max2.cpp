#include <iostream>
#include <stdlib.h>  //��� ������� abs().
#define TRUE 1
#define FALSE 0
#define MaxNodes 4   //���������� ������.
#define MaxInt 1000  //�������� ���������� �������������.
using namespace std;
int sum;
//�������� ���� ����.
struct Uzel
{
  int Element; //�������� ����� �������.
  int Propusk; //���������� �����������.
  int Metka;   //�������� ������� ��� ���.
};


class Spisok
{
  private:
      int C[MaxNodes][MaxNodes];    //������� ��������� ���������� ������������.
      int c[MaxNodes][MaxNodes];    //������� �������� ���������� ������������.
      int Put[MaxNodes][MaxNodes];  //������� �������� �����.
      int Potok [MaxNodes];         //������.
      int Est (Uzel*,int,int);
      int Tpk (int*,int,int);
  public:
      void Vvod_Ves();
      int Reshenie ();
      void Vyvod(int);

};

void main()
{
  Spisok A;

  A.Vvod_Ves();
  A.Vyvod(A.Reshenie());
  system ("Pause");
}

void Spisok::Vvod_Ves()
//���� ������� ���������� ������������.
{
  cout << "������� ���������� ����������� �����:\n";
  for (int i=0;i<MaxNodes;i++)
   for (int j=0;j<MaxNodes;j++)
     {
       cout << "������� C[" << (i+1) << "," << (j+1) << "]: "; 
       cin >> C[i][j];
       c[i][j] = C[i][j];
     }
}

void Spisok::Vyvod(int n)
//����� �����������.
{
  //���������� ������������� ������ ������.
  for (int i=0,sum=0;i<=n;sum+=Potok[i++]);
  cout << "\n������������ ����� ������ � ����: " << sum;
  cout << "\n�������� ������� �� ��������� ������:\n";
  for (int i=0;i<MaxNodes;i++)
   for (int j=i;j<MaxNodes;j++)
     if (C[i][j])
     {
         cout << "����� (" << (i+1) << "," << (j+1) <<"): ";
         cout << "(" << C[i][j]  << "," << C[j][i] << ")-(";
         cout << c[i][j]  << "," << c[j][i] << ")=(";
         cout << (C[i][j]-c[i][j]) << "," << (C[j][i]-c[j][i]) << ") ";
         cout << "�����: " << abs(C[i][j]-c[i][j]) << " ";
         if (C[i][j]-c[i][j]!=0)
         {
           cout << "�����������: ";
           if (C[i][j]-c[i][j]>0)
              cout << (i+1) << "->" << (j+1);
           else
              cout << (j+1) << "->" << (i+1);
         }
         cout << endl;
     }
}

int Spisok::Reshenie()
{
  Uzel SS[MaxNodes]; //��������� �����, � ������� ����� �������.
  Uzel S[MaxNodes]; //����.
  int i,j=0,k,el,mx,mn;
  int m; //������� ���������� ������ � ����.
  int nomer=-1; //������� ���������� �������� �������.
  int Tupik[MaxNodes]; //�������� "���������" ������.
  int N_Tupik; //���������� ��������� � �������.

  while (j!=-1)
  {
    i=m=0;
    S[i].Element=0;
    S[i].Propusk=MaxInt;
    S[i].Metka=TRUE;
    el=0;
    N_Tupik=-1;
    while (el!=MaxNodes-1)
    {
      j=-1;
      for (k=0;k<MaxNodes;k++)
       if (c[i][k]!=0) //���� ���� ��������� �����...
        if (i>0)   //� � ���� ��� �������� �������...
        {
          if (!Est(&S[0],m,k) && !Tpk(&Tupik[0],N_Tupik,k)) 
                            //�� �������� ������� �������,
                           //���� �� ��� � ���� � ���� ��� �� "���������".
          {  
             SS[++j].Element=k;
             SS[j].Propusk=c[i][k];
             SS[j].Metka=FALSE;
          }
        }
        else 
          if (!Tpk(&Tupik[0],N_Tupik,k)) //�� ��������� �� �����?
               //����� �� �������, � ��� ������ �������.
          {    //�������� ��� ������� � ����.
               SS[++j].Element=k;
               SS[j].Propusk=c[i][k];
               SS[j].Metka=FALSE;
          }
      if (j!=-1) //���� �����������.
      {
         mx=SS[0].Propusk;
         el=0;
         for (k=1;k<=j;k++)
          if (SS[k].Propusk>mx)
            { el=k; mx=SS[k].Propusk; }
         S[++m].Element=SS[el].Element;
         S[m].Propusk=mx;
         S[m].Metka=TRUE;
         if (SS[el].Element==MaxNodes-1) //������ �������� ����.
         {
           nomer++;
           //���������� �������� ����.
           for (k=0;k<=m;k++)
              Put[nomer][k]=S[k].Element;
           //���� ����������� �����.
           mn=S[0].Propusk;
           el=0;
           for (k=1;k<=m;k++)
            if (S[k].Propusk<mn)
              { el=k; mn=S[k].Propusk; }
           Potok[nomer]=mn; //���������� ���.
           //��������� ���������� ���������� �����������.
           for (k=0;k<m;k++)
           { 
             c[S[k].Element][S[k+1].Element] -= Potok[nomer];
             c[S[k+1].Element][S[k].Element] += Potok[nomer];
           }
           el=MaxNodes-1; //������� � ��������� ��������.
           j=0;
         }
         else i=S[m].Element;
      }
      else //����������� ���. ��� �������� �����, �����:
      {
         if (i==0)  //�) ��� ���������� ����������� �������.
                    //   � ���� ������ - �����
              el=MaxNodes-1;
         else       //�) �� ������ � �����. �������� ��������� �������
                    //   � ������� � �������� ����� �� ���� �������.
         {
           Tupik[++N_Tupik]=S[m].Element;
           m--;
           i=S[m].Element;
         }
      }
    }
  }
  return nomer; //���������� ���������� �������� �������.
}

int Spisok::Est(Uzel S[], int m, int k)
//������� ���������, ���� �� ������� k � ���� S.
//m - ������� ���������� ��������� � ����.
//���������� 1, ���� ������� ����, � 0 - � ��������� ������.
{
  for (int l=0;l<=m;l++)
    if (S[l].Element==k) return 1;
  return 0;
}

int Spisok::Tpk(int Tupik[],int N_Tupik, int k) 
//������� ���������, ���� �� ������� k � ������� "���������" ������.
//N_Tupik - ������� ���������� ������ � �������.
//���������� 1, ���� ������� ����, � 0 - � ��������� ������.
{
  if (N_Tupik==-1) return 0;
  for (int l=0;l<=N_Tupik;l++)
    if (Tupik[l]==k) return 1;
  return 0;
}
