#include <iostream>
#include <string>

using namespace std;

void quick_struct(struct Stud items[], int count);
void qs_struct(struct Stud items[], int left, int right);
bool Continue (const char *e);
int compareByName(struct Stud st1, struct Stud st2);
int compareBySName(struct Stud st1, struct Stud st2);
void inputStruct(struct Stud* st1);
void outputStruct(struct Stud* st1);

int s;

struct Stud
{
	string Name;
	string SecName;
	double average_ball;
};

int main()
{
	struct Stud students[5]; // Массив структур
	int i,n; 
	cout <<"Number of students "<<endl;
	cin>>n;
	for (i=0;i<n;i++)
	{
		inputStruct(&students[i]);
	}
	do {
		cout<< "Sort field Name -1, Sname -2, A ball -3 = "; cin>>s;
		quick_struct(students,n);
		cout << "You input several students: "<<endl;
		for (i=0;i<n;i++)
		{
			outputStruct(&students[i]);
		}
	}
	while (Continue("Done! "));
	return 0;
}

void quick_struct(struct Stud items[], int count)
{
	qs_struct(items,0,count-1);
}

void qs_struct(struct Stud items[], int left, int right)
{
	register int i, j;
	/*char *x;*/
	struct Stud temp, x;
	i = left; j = right;
	switch(s){
	case 1: 
		do {
			x = items[(left+right)/2];
			while((compareByName(items[i],x) < 0) && (i < right)) i++;
			while((compareByName(items[j],x) > 0) && (j > left)) j--;
			if(i <= j) {
				temp = items[i];
				items[i] = items[j];
				items[j] = temp;
				i++; j--;
			}
		} while(i <= j);
		break;
	case 2:
do {
			x = items[(left+right)/2];
			while((compareBySName(items[i],x) < 0) && (i < right)) i++;
			while((compareBySName(items[j],x) > 0) && (j > left)) j--;
			if(i <= j) {
				temp = items[i];
				items[i] = items[j];
				items[j] = temp;
				i++; j--;
			}
		} while(i <= j);
		break;
	}  
	if(left < j) qs_struct(items, left, j);
	if(i < right) qs_struct(items, i, right);
}

bool Continue (const char *e) // повторное выполнение всей программы
{
	char c;
	bool bcharentered=false;
	do
	{    
		cout<<e<<"Sort with different field? if not press - n ";
		cin>> c;
		bcharentered=!((c=='y')||(c=='n'));
		if(bcharentered)
		{
			cout<< "Please enter \"y\" or \"n\"."<< endl;
		};
	}
	while(bcharentered);
	return (c !='n'); 
}

int compareByName(struct Stud st1, struct Stud st2)
{
	if (st1.Name>st2.Name) return 1;
	if (st1.Name<st2.Name) return -1;
	if (st1.Name==st2.Name) return 0;
}

int compareBySName(struct Stud st1, struct Stud st2)
{
	if (st1.SecName>st2.SecName) return 1;
	if (st1.SecName<st2.SecName) return -1;
	if (st1.SecName==st2.SecName) return 0;
}
void inputStruct(struct Stud* st1)
{
	fflush(stdin);
	cout << "Input name "<<endl;
	getline(cin, st1->Name, '\n');
	cout << "Input Sname "<< endl;
	getline(cin, st1->SecName);
	cout << "Average ball "<< endl;
	cin>>st1->average_ball;
}

void outputStruct(struct Stud* st1)
{
	cout << "Student "<<st1->Name;
	cout <<" Sname "<<st1->SecName<<endl;
	cout <<"Average ball "<<st1->average_ball<<endl;
}
