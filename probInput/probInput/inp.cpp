#include <stdio.h>
#include <conio.h>
#include <iostream>
 
using namespace std;
 
int main()
{
    int a;
    int counter=1,num=0;
    while(!kbhit()){
        a=getch();
        if(a==' ' || a==13){ //пробел или ентер
            cout<<num<<" "; //здесь хорошее число с которым можно делать что угодно
            num=0;
        }else{
            if(a<'0' || a>'9')
                continue;
            num=num*10+(a-'0');
//            printf("%d %d %d\n",des,(a-'0'),num);
        }
        counter++;
        if(counter%15==0)
            cout<<endl;
        if(a==27) //нажали esc
            break;
    }
    return 0;
}