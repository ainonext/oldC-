#include <iostream>
#include <string>
#include <math.h> 
#include "user_data.h"
using namespace std;
#define MAXIMUM_BYTE 128
void print(const char c);
void networks(char *net, char *enet, int *ipadr);

int user_data::get_data_from_user(int *ip)
{
	string str,str2;
	cout << "Enter adress given from provider "<< endl;
	getline(cin, str);
	cout << str<< endl;
	size_t found;
	found=str.find_first_of(".");
	str2 = str.substr (0,found);
	int a = atoi(str2.c_str());
	int *ip=new (nothrow) int[4];
	for(int i=0;i<3;i++)
	{
		found=str.find_first_of(".");
		str2 = str.substr (0,found);
		int a = atoi(str2.c_str());
		ip[i]=a;
		str = str.substr (found+1,str.length());
	}

	found=str.find_first_of("/");
	str2 = str.substr (0,found);
	a = atoi(str2.c_str());
	ip[3]=a;
	str = str.substr (found+1,str.length());
	ip[4]=atoi(str.c_str());
	ip[4]=atoi(str.c_str());
	/*for (int i=0; i<5; i++)
	cout<<ip[i]<<" ";
	cout<<endl;*/
	cout<< endl;
	cout<< "Binary code of IP is  ";
	for (int i=0; i<5; i++)
		print(ip[i]);
	cout << endl;
	char enet, net;
	int ipadr;
	networks(&net, &enet, &ipadr);
	return *ip;
}
void print(const char c)
{			
	for (int i=MAXIMUM_BYTE;i>0;i/=2)
		if (c&i) cout<<"1";
		else cout<<"0";
		cout<<" ";

}
void networks(char *net, char *enet, int *ipadr)
{
	char buf[4];
	cout<<"Total number of networks ";
	cin>>buf;
	*net=atoi(buf);
	cout << "Which network are you interested in? ";
	cin>>buf;
	*enet=atoi(buf);
	cout << "Which host are you interested in? ";
	cin>>*ipadr;
}
