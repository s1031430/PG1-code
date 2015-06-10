#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int  sale[4][5]={0}; 
	int person,product,money;  
	cout<<"Enter the salesperson(1~4),product number(1~5),and total sales.\n";
	cout<<"Enter -1 for the salesperson and end input.\n";
	for(int i=1 ; i>0 ; )
	{  
		cin>>person;
		if (person== -1)
			break;
		else
		{
			cin>>product>>money;
			sale[person-1][product-1]=money;
		}
	}
	int stotal[4]={0};
	
	for(int i=0; i<4 ;i++)
	{
		for(int j=0;j<5;j++)
		{
			stotal[i] =stotal[i]+ sale[i][j];
		}
	}
	int ptotal[5]={0};
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<4;j++)
		{
			ptotal[i]=ptotal[i]+sale[j][i];
		}
	}
	cout<<"The total sales for each salesperson are displayed at the end of each rows,\n";
	cout<<"and the total sales for each products are displayed at the buttom of each columns.\n";
	for(int i=1;i<6;i++)
		cout<<setw(10)<<i;
		cout<<setw(10)<<"Total"<<endl;
	
	for(int i=0;i<4;i++){
		cout<<i+1;
		for(int j=0;j<5;j++)
		cout<<setw(10)<<sale[i][j];
		cout<<setw(10)<<stotal[i]<<endl;
	}
	cout<<"Total";
	
	for(int i=0;i<5;i++)
	cout<<setw(9)<<ptotal[i];	
	cout<<endl;
	
	system("pause");
	return 0;
}