// subneting.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h> 
using namespace std;
#define IP_L 4
#define MAXIMUM_BYTE 128
#define MAXIMUM_OFFSET 7
#define SIZEOF_CHAR 8
void print(const char c)
{			
	for (int i=MAXIMUM_BYTE;i>0;i/=2)
		if (c&i) cout<<"1";
		else cout<<"0";
		cout<<" ";

}
unsigned char power_of_two (int net) 
{
	unsigned char j;
	for (j=0; net>1; net/=2, j++);
	return j;
}
int _tmain(int argc, _TCHAR* argv[])
{
	string str,str2;
	cout << "Enter adress "<< endl;
	getline(cin, str);
	cout << str<< endl;
	int net;
	cout<<"Networks= ";
	cin>>net;
	char enet;
	cout << "Wich network ";
	cin >> enet;
	char ipadr;
	cout << "Wich ip adress ";
	cin>> ipadr;
	size_t found;
	found=str.find_first_of(".");
	str2 = str.substr (0,found);
	int a = atoi(str2.c_str());
	/*cout << a<< endl;*/
	int ip[4];
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
	 cout<<str<<endl;
	cout<<str.c_str()<<endl;
	cout<<atoi(str.c_str())<<endl;
	 ip[4]=atoi(str.c_str());
	cout<<ip[4]<<endl;
	ip[4]=atoi(str.c_str());
	cout << "Test ip "<<ip[4]<< endl;
	cout << "Test ip "<< ip[4]/SIZEOF_CHAR<< endl;
	for (int i=0; i<5; i++)
		cout<<ip[i]<<" ";
	cout<<endl;
	cout<< endl;
	cout<< "Binary code of IP ";
	for (int i=0; i<5; i++)
		print(ip[i]);
	cout << endl;
	unsigned char sub_mask[4];
	for (int i=0;i<4;i++)
	{
		sub_mask[i]=0;
	}
	cout << "Subnet mask is ";
	for (int i=0;i<ip[4]/8;i++)
	{
		sub_mask[i]=255;
	}
	/* for (int i=0; i<IP_L; i++)
    cout<< sub_mask[i]<< endl;
 

  cout <<"Subnet mask is ";
  for (int i=0; i<IP_L; i++)
   cout<< "Sub "<< sub_mask[i]<< endl;*/
  
	unsigned char ip_sub_mask=ip[4]-(ip[4]/8)*8;
	for (int i=128; ip_sub_mask>0; ip_sub_mask--, i/=2)
	{ 
		sub_mask[ip[4]/8]=sub_mask[ip[4]/8] | i;

	}
	for (int i=0; i<4;i++)
	{
		cout<<int(sub_mask[i])<<".";
	}
	cout << endl;
	cout<<"Number of subnets is 2 in power of "<<int(power_of_two(net))<<endl;

	unsigned char building=enet;
	unsigned char mask_end=ip[IP_L]/SIZEOF_CHAR;
	/* if ((SIZEOF_CHAR-ip[IP_L]+ip[IP_L]/SIZEOF_CHAR*SIZEOF_CHAR-power_of_two(int(argv[2])))<0)
	int i=i+1;
	/*Разбитые октеты*/
	/*  else {*/
	/*Всё умещается в один октет*/
	cout << "Elsing!"<< endl;
	building=building<<(SIZEOF_CHAR-(ip[IP_L]-((ip[IP_L]/SIZEOF_CHAR)*SIZEOF_CHAR))-power_of_two(int(enet)));
	ip[mask_end]=ip[mask_end] | building;
	unsigned char mask_offset=ip[IP_L]-(ip[IP_L]/SIZEOF_CHAR)*SIZEOF_CHAR;
	unsigned char room=ipadr;
	cout<< "Room consumes bits"<< endl; power_of_two(int(ipadr));
	mask_end=(ip[IP_L]+power_of_two(int(enet)))/SIZEOF_CHAR;
	cout<<"Mask ends in ip["<<int(mask_end)<<"]"<<endl;
	room=room<<(SIZEOF_CHAR-mask_offset-power_of_two(int(enet))-power_of_two(int(ipadr)-1));
	ip[mask_end]=ip[mask_end] | room;

	for (int i=0; i<IP_L; i++)
		print(ip[i]);
	cout <<endl<<"Ip adress of given room is: ";
	for (int i=0; i<IP_L; i++)
		cout << int(ip[i]);


	system ("Pause");
	return 0;
}

