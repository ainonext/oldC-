#include <iostream>
#include <string>
#include <math.h> 
#include "user_data.h"
using namespace std;
#define IP_L 4
#define MAXIMUM_BYTE 128
#define MAXIMUM_OFFSET 7
#define SIZEOF_CHAR 8
#define is_int(x) (x>='0' && x<='9')

void print(const char c);
unsigned char power_of_two (int net); 
int* address();
void networks(char *net, char *enet, int *ipadr);


int main()
{	
	int *ip=address();
	char enet, net;
	int ipadr;
	networks(&net, &enet, &ipadr);
	unsigned char sub_mask[4];
	for (int i=0;i<4;i++)
	{
		sub_mask[i]=0;
	}

	for (int i=0;i<ip[4]/8;i++)
	{
		sub_mask[i]=255;
	}


	unsigned char ip_sub_mask=ip[4]-(ip[4]/8)*8;
	for (int i=128; ip_sub_mask>0; ip_sub_mask--, i/=2)
	{ 
		sub_mask[ip[4]/8]=sub_mask[ip[4]/8] | i;

	}
	cout << "Binary subnet mask is ";
	for (int i=0;i<4;i++)
	{
		print (char(sub_mask[i]));
	}
	cout << endl;
	cout << "Subnet mask is ";
	for (int i=0; i<4;i++)
	{
		cout<<int(sub_mask[i])<<"."; 

	}
	cout << endl;

	cout<<"Number of subnets is 2 in power of "<<int(power_of_two(net))<<endl;

	unsigned char building=enet;
	cout<< "Subnet consumes bits "<< int(power_of_two(int(net))) << endl;

	unsigned char mask_end=ip[IP_L]/SIZEOF_CHAR;
	unsigned char mask_offset=ip[IP_L]-(ip[IP_L]/SIZEOF_CHAR)*SIZEOF_CHAR;
	unsigned char subnet_bytes=power_of_two(net);
	if (SIZEOF_CHAR-mask_offset < subnet_bytes)
	{
		/* Подсеть не влезает, кладем в разные октеты */
		unsigned char subnet_l=0, subnet_r=0;
		subnet_l=ip_sub_mask>>(subnet_bytes-(SIZEOF_CHAR-mask_offset));
		subnet_r=ip_sub_mask<<(SIZEOF_CHAR-(subnet_bytes-(SIZEOF_CHAR-mask_offset)));
		ip[mask_end]=ip[mask_end] | subnet_l;
		ip[mask_end+1]=ip[mask_end+1] | subnet_r;
	}
	/*Разбитые октеты*/
	else {
		/*Всё умещается в один октет*/
		building=building<<(SIZEOF_CHAR-mask_offset-subnet_bytes);
		ip[mask_end]=ip[mask_end] | building;
	}

	int room=ipadr;
	unsigned char room_bytes=power_of_two(ipadr)+1;
	cout<< "Host consumes bits "<< int(room_bytes) << endl;
	mask_end = (ip[IP_L]+subnet_bytes)/SIZEOF_CHAR;
	cout << "Bits masked " <<  mask_end*SIZEOF_CHAR+mask_offset+subnet_bytes<< endl;
	cout << "Mask ends in ip[" << int(mask_end) <<"]"<<endl;
	cout << "Free address space is " <<(SIZEOF_CHAR*IP_L-subnet_bytes-ip[4])<<" bits" <<endl;
	if (room_bytes>((IP_L-mask_end)*SIZEOF_CHAR+(SIZEOF_CHAR-mask_offset-subnet_bytes)))
	{
		cout<< "Something wrong! Check your input! "<< endl;
		return 1;
	}
	if (room_bytes>SIZEOF_CHAR) 
	{
		/* Разбитые октеты */
		unsigned char room_l=0, room_r=0;
		room_l=room>>(SIZEOF_CHAR-(room_bytes-SIZEOF_CHAR)+1);
		room_r=room;
		ip[mask_end]=ip[mask_end]|room_l;
		ip[mask_end+1]=ip[mask_end+1]|room_r;
	}
	else 
	{
		/* Всё умещается в один октет */
		ip[IP_L-1]=ip[IP_L-1] | room;	
	}
	for (int i=0; i<IP_L; i++)
		print(ip[i]);
	cout <<endl<<"Ip adress of given room is: ";
	for (int i=0; i<IP_L; i++)
	{cout << int(ip[i])<<".";}
	cout<<endl;

	system ("Pause");
	return 0;
}

/*void print(const char c)
{			
	for (int i=MAXIMUM_BYTE;i>0;i/=2)
		if (c&i) cout<<"1";
		else cout<<"0";
		cout<<" ";

}
*/
unsigned char power_of_two (int net) 
{
	unsigned char j;
	for (j=0; net>1; net/=2, j++);
	return j;
}

/*int* address()
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
	/*cout<< endl;
	cout<< "Binary code of IP is  ";
	for (int i=0; i<5; i++)
		print(ip[i]);
	cout << endl;
	return ip;
}*/
/*void networks(char *net, char *enet, int *ipadr)
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
}*/