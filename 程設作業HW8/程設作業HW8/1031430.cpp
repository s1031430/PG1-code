#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

void task(int);
void list();
void update();
void insert();
void del();


struct book
{
	int record;
	string name;
	int quantity;
	int price;
	book *next,*pre;
};

book *head=new book;
book *stop=new book;
book *atr=new book;
book *gtr=new book;
book *ktr=new book;
book *htr=new book;

int main()
{
	int input;
	head->pre=NULL;
	head->next=stop;
	stop->pre=head;
	stop->next=NULL;

	atr->next=ktr; ktr->next=gtr; gtr->next=htr;
	ktr->pre=atr; gtr->pre=ktr; htr->pre=gtr;

	htr->next=head->next;
	atr->pre=stop->pre;
	head->next=atr;
	htr->next=stop;
	
	atr->record=1;atr->name=" Tomato ";atr->quantity=20;atr->price=25.00;
	ktr->record=5;ktr->name=" Apple ";ktr->quantity=10;ktr->price=20.00;
	gtr->record=10;gtr->name=" Orange ";gtr->quantity=8;gtr->price=22.00;
	htr->record=60;htr->name=" Grape ";htr->quantity=5;htr->price=15.00;
	
	while(1)
	{
		cout<<"Enter a choice:"<<endl;
		cout<<"1.List all fruits."<<endl;
		cout<<"2.Update record."<<endl;
		cout<<"3.Insert record."<<endl;
		cout<<"4.Delete record."<<endl;
		cout<<"5.End program."<<endl;
		cin>>input;
		task(input);
	}
	
	system("pause");
	return 0;
}

void task(int num)
{
	switch(num)
	{
		case 1:list();break;
		case 2:update();break;
		case 3:insert();break;
		case 4:del();break;
		case 5:system("pause");exit(0);
	}
}

void list()
{
	cout<<setw(10)<<" Record "<<setw(10)<<" Fruit name "<<setw(10)<<" Quantity "<<setw(10)<<" Price "<<endl;
	for(book *ntr=head->next;ntr!=stop;ntr=ntr->next)
		cout<<setw(10)<<ntr->record<<setw(10)<<ntr->name<<setw(10)<<ntr->quantity<<setw(10)<<ntr->price<<endl;
}

void update()
{
	int arr;
	cout<<"Enter the fruit number for update :"; 
	cin>>arr;
	for(book *ntr=head->next;ntr!=stop;ntr=ntr->next)
	{
		if(arr==ntr->record)
		{
			cout<<setw(10)<<" Record "<<setw(10)<<" Fruit Name "<<setw(10)<<" Quantity "<<setw(10)<<" Price "<<endl;
			cout<<setw(10)<<ntr->record<<setw(10)<<ntr->name<<setw(10)<<ntr->quantity<<setw(10)<<ntr->price<<endl;
			cout<<"Enter the fruit name :";
			cin>>ntr->name;
			cout<<"Enter the quantity :";
			cin>>ntr->quantity;
			cout<<"Enter the price :";
			cin>>ntr->price;
			cout<<"Record update."<<endl;
			return ;
		}
	}
	cout<<"Cannot update. The record is empty."<<endl;
}

void insert()
{
	int arr;
	
	cout<<"Enter the fruit number for insertion :";
	cin>>arr;
	
	for(book *ntr=head->next;ntr!=stop;ntr=ntr->next)
	{
		if(arr==ntr->record)
		{
			cout<<"Cannot insert. The record contains information."<<endl;
			return;
		}
		
	}		
	
	book *ptr=new book;
	ptr->next=htr->next;
	ptr->pre=stop->pre;
	htr->next=ptr;
	stop->pre=ptr;
	ptr->record=arr;
	
	cout<<"Enter the fruit name :";
	cin>>ptr->name;
	cout<<"Enter the quantity :";
	cin>>ptr->quantity;
	cout<<"Enter the price :";
	cin>>ptr->price;
	cout<<"Record inserted."<<endl;	
	
}

void del()
{
	int arr;
	
	cout<<"Enter the fruit number for deletion :";
	cin>>arr;
	for(book *ntr=head->next;ntr!=stop;ntr=ntr->next)
	{
		if(arr==ntr->record)
		{
			ntr->next->pre=ntr->pre;
			ntr->pre->next=ntr->next;
			delete ntr;
			cout<<"Record deleted."<<endl;
			return;
		}
	}			
	cout<<"Cannot delete. The record is empty."<<endl;

}

