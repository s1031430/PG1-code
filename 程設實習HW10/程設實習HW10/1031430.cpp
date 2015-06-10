#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstring>
using namespace std;


void task(int);
void insert();
void search();
void del();
void print();

struct book
{
		int NO;
		char name[20];
		char sex[20];
		int age;
		book *next,*pre;
};
book *head=new book;
book *stop=new book;

int main()
{
	head->pre=NULL;
	head->next=stop;
	stop->pre=head;
	stop->next=NULL;

	int input;
	cout<<"Enter your choice"<<endl;
	cout<<"<1>insert"<<endl;
	cout<<"<2>delete"<<endl;
	cout<<"<3>search"<<endl;
	cout<<"<4>print"<<endl;
	cout<<"<5>exit"<<endl;
	
	while(cin>>input)
	{
		task(input);
		cout<<"Enter your choice"<<endl;
		cout<<"<1>insert"<<endl;
		cout<<"<2>delete"<<endl;
		cout<<"<3>search"<<endl;
		cout<<"<4>print"<<endl;
		cout<<"<5>exit"<<endl;
	
	}
	system("pause");
	return 0;
}

void task(int num)
{
	switch(num)
		{
			case 1: insert();break;
			case 2: del();break;
			case 3: search();break;
			case 4: print();break;
			case 5: exit(0);
		}
}





void insert()
{
	book *ptr=new book;
	ptr->pre=stop->pre;
	ptr->pre->next=ptr;
	stop->pre=ptr;
	ptr->pre->next=ptr;
	cout<<"Enter the NO. :";
	cin>>ptr->NO;
	cout<<"Enter the name :";
	cin>>ptr->name;
	cout<<"Enter the sex :";
	cin>>ptr->sex;
	cout<<"Enter the age :";
	cin>>ptr->age;
}

void del()
{
	char arr[30];
	cout<<"Enter the name that you want to delete:";
	cin>>arr;
	for(book *ntr=head->next;ntr!=stop;ntr=ntr->next){
		if(!strcmp(arr,ntr->name)){
			ntr->next->pre=ntr->pre;
			ntr->pre->next=ntr->next;
			return;
		}
	}			
	cout<<"Your search data doesn't exist";
}
			
void search()
{
	
	char arr[30];

	cout<<"Enter the name that you want to search:";
	cin>>arr;
	for(book *ntr=head->next;ntr!=stop;ntr=ntr->next)
		if(!strcmp(arr,ntr->name)){
			cout<<setw(10)<<"No."<<setw(8)<<"Name"<<setw(8)<<"Sex"<<setw(8)<<"Age"<<endl;
			cout<<setw(10)<<ntr->NO<<setw(8)<<ntr->name<<setw(8)<<ntr->sex<<setw(8)<<ntr->age;
		}
		cout<<"Your search data doesn't exist";
			
		
}	


void print()
{
	cout<<setw(10)<<"No."<<setw(10)<<"Name"<<setw(8)<<"Sex"<<setw(8)<<"Age"<<endl;
	for(book *ntr=head->next;ntr!=stop;ntr=ntr->next)
		cout<<setw(10)<<ntr->NO<<setw(10)<<ntr->name<<setw(8)<<ntr->sex<<setw(8)<<ntr->age<<endl;
}