#include <iostream>

using namespace std;

int main (void)
{
	char s[256];
	/*cout<<"Please input string"<<endl;
	cin.getline(s,256);
	//cout<<s<<endl;
	for(int i=0;s[i]!='\0';i++)
		cout<<s[i];
	cout<<endl;*/
	for(unsigned char c=0;c<255;c++)
		printf("%c %d\n",c,c);
	system("Pause");
	return 0;

}