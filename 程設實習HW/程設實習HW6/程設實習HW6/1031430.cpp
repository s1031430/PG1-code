#include<iostream>
#include<ctime>
using namespace std;
void Rand(int number[]);
void Sort(int number[]);
void Search(int number[],int b,int &c,int &d);
int main()
{
	int number[10],a,b,c=0,d=0,i;					
	do
	{
		c=0,
		d=0;
		srand(time(NULL));
		cout<<"<1> Start\n";
		cout<<"<2> End\n";
		cin>>a;
		
		if(a==2)
			break;
		
		Rand(number);
		Sort(number);
		for(i=0;i<10;i++)
			cout<<number[i]<<" ";
		cout<<"\nPlease input a number that you want to search:";
		cin>>b;
		Search(number,b,c,d);
		if(c==true)
			cout<<b<<" is in the array, and the position is "<<d<<endl;
		if(c==false)
			cout<<b<<" is not in the array!\n";
	}while(a == 1);
	system("pause");
	return 0;
		
	
}
void Rand(int number[]) 
{
	int i,j;
	
		
	for(i=0;i<10;i++)
	{
		number[i]=(rand()%100+1);
		for(j=0;j<i;j++)
		{
			if(number[i]==number[j])
			{
				//number[j]=(rand()%100+1);
				i--;
			}
		}
	}
}
void Sort(int number[])
{
	int i;
	int j;
	int t;
	for(i=0;i<=9;i++)
		number[i]=number[i];
	for(i=0;i<=9;i++)	
	{
		for(j=0;j<9-i;j++)
		{
			if(number[j]>number[j+1])  
			{
				t=number[j];     
				number[j]=number[j+1];
				number[j+1]=t;
			}
		}
	}
}
void Search(int number[],int b,int &c,int &d)
{
	int i;
	
	
	for(i=0;i<10;i++)
	{
		if(b==number[i])
		{
			d=i+1;
			c=true;
			
		}
		
	}
}
