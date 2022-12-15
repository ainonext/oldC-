#include <iostream>
#include <locale.h>
using namespace std;



void Gauss (int n, double** A, double* B)
{
  int l = 0;
  double* x;
  x = new double[n]; // Массив исходных значений
  bool f1 = false;
  bool f2 = true;
  double* str_save;
  str_save = new double[n];
  double b_save;

  while (l<n-1)
  {
    if (A[l][l]!=0)
    {
      for (int j = l+1; j < n; j++)
      {
        B[j] = B[j] - (B[l]* A[j][l])/A[l][l];
        for (int k = n-1; k>=1; k--)
          A[j][k] = A[j][k] - (A[l][k]*A[j][l])/A[l][l];
      }
      l++;
    }
    else
    {
      for (int j = l+1; j < n; j++)
        if (A[j][l]!=0 && (f1==false))
        {
          str_save = A[j]; 
          b_save = B[j];
          A[j] = A[l]; 
          B[j] = B[l];
          A[l] = str_save;
          B[l] = b_save;
          f1 = true;
        }
        if (f1 == true)
        { 
          for (int j = l+1; j < n; j++)
          {
            B[j] = B[j] - (B[l]*A[j][l])/A[l][l];
            for (int k = n-1; k>=1; k--)
              A[j][k] = A[j][k] - (A[l][k]*A[j][l])/A[l][l];
          }
          l++;
          f1 = false;
        }
        else
        {
          cout <<'\n' <<'\n' <<" Решения нет!";
          f2 = false;
          break;
        }
    }
  }
  if (A[n-1][n-1] == 0)
  { 
    cout <<'\n' <<'\n' <<" Решения нет!";
    f2 = false;
  }
  double S = 0;
  if (f2 == true)
  {
    x[n-1] = B[n-1]/A[n-1][n-1];
    for (int i=n-2; i>=0; i--)
    {
      for (int j = i+1; j<n; j++)
        S = S + A[i][j]*x[j];
      x[i] = (B[i] - S)/A[i][i];
      S = 0;
    }
  }
  if (f2 == true)
  {
    cout <<'\n' <<'\n' <<" Искомые значения: " <<'\n';
    for (int i = 0; i<n; i++)
      cout <<'\n' << " x[" << i+1 << "] = " << x[i];
  }
}



int main()
{
  setlocale(LC_ALL, "Russian");
  int n = 0;
  cout << "Введите количество наизвестных (количество уравнений): "; cin >> n;
  double **A = new double*[n];
  for (int i = 0; i < n; i++)
    A[i] = new double[i];
  double* B;
  B = new double[n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      cout << " A[" << i+1 <<"][" << j+1 <<"]: "; cin >> A[i][j];
    }
    for (int i = 0; i < n; i++)
    {
      cout << " B[" << i+1 <<"]: "; cin >> B[i];
    }
    cout <<'\n' <<"Принятые данные: " <<'\n'<<'\n'<<" Матрица А:" <<'\n';
    for (int i = 0; i < n; i++)
    {
      cout << '\n';
      for (int j = 0; j<n; j++)
        cout << " " << A[i][j];
    }
    cout <<'\n'<<'\n'<<" Матрица B: "<<'\n';
    for (int i = 0; i < n; i++)
      cout<<'\n' << " " <<B[i];
    Gauss(n,A,B);
	cout<< endl;
    system("Pause");
    return 0;
}