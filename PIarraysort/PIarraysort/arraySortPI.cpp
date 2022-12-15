#include <iostream>
using namespace std;

void Initialize(void);
void error(int err_no);
bool error_float(float a);
int Input_n();
void Input_array(int *a, int n);
void Check_array(int *a, int n);
void Sort(int *a,int n);
void Output_array(int *a, int n);

int main()
{  
  int n;
  n=Input_n();
  int *a=new int [n];
  Input_array(a,n);
  Check_array(a,n);
  Output_array(a,n);
  delete [] a;
  system("Pause");
  return 0;
}
void Initialize(void)
{
  cin.exceptions(cin.failbit);
}
void error(int err_number)
{
  switch(err_number)
  {
  case 0:
    cin.clear(); 
    char binput[5];
    cin>> binput;
    break;
  case 1:
    cerr << "Wrong n! Please retry input n "<< endl; 
    error(0);
    break;
  case 2:
    cerr << "Wrong element! Please repeat input and then continue entry "<< endl; 
    error(0);
    break;

  }
}
bool error_float(float a)
{
  float b=a-(int)a;
  if (b==0)
    return false;
  else 
    return true;
}
int Input_n()
{ 
  float f;
  int n;
  do
  {   
    Initialize();
    try
    {  
      cout << "enter n ";
      cin >> f;
      if ((error_float(f))||(f<=0) || (f>=127))
        cout <<  "Wrong n! Please retry input n " << endl;
    }

    catch(...)
    {
      error(1);
    }
  }
  while ((f<=0) || (f>=127)||(error_float(f)));
  return n=f;
}

void Input_array(int *a, int n)
{
  float f;
  int i=0;
  cout << "Elements of array "<< endl;
  while (i<n)
  {
    Initialize();
    try
    {
      cin >> f;
      if (error_float(f) || f<=-128|| f>=127)
        cout <<  "Wrong number in position "<<i+1<<". Please retry and then continue entry " ;
      else {
        a[i] = (int) f;
        i++;
      }
    }
    catch (...)
    {
      error(2);
    }
  }
}

void Check_array(int *a, int n)
{
  int i = 0;
  while(a[i] <= a[i+1] && i < n-1)
  {
    i++;
  }
  if(i != n-1)
  {
    cout << "Array is not sorted! "<< endl;
    Sort(a,n);
  }
  else
    cout << "Array already sorted! "<< endl;

}
void Sort(int *a,int n)
{
  int temp;
  int sorted=true;
  while(sorted){
    sorted=false;
    for (int i=0; i<n-1; i++){
      if(a[i]>a[i+1]){
        temp=a[i+1];
        a[i+1]=a[i];
        a[i]=temp;
        sorted=true;
      }
    }
  }
}
void Output_array(int *a, int n)
{
  cout << "Resulted array is "<< endl;
  for (int i=0; i<n;i++){
    cout<< a[i]<<" ";
    if((i+1)%15==0)
      cout<< endl;
  }
  cout<< endl;
}