#include<iostream>
using namespace std;
void bubblesort(int num[])
{
	int i;
	int j;
	int t;
	for(i=0;i<=9;i++)	
	{
		for(j=0;j<9-i;j++)
		{
			if(num[j]<num[j+1])  //若前面比後面小則交換
			{
				t=num[j];     //以下三行交換
				num[j]=num[j+1];
				num[j+1]=t;
			}
		}
	}
	
}

void selectionsort(int num[])
{
	int i;
	int j;
	int t;
	for(j=9;j>=0;j--)
	{
		int max=0;
		for(int i=1;i<=j;i++)
		{
			if(num[i]>num[max])
			max=i;
		}
			t=num[max];
			num[max]=num[j];
			num[j]=t;
	}
}

int main()
{
	int num[10],m;
	cout<<"Please input ten numbers:\n";
	for(m=0;m<10;m++)
	cin>>num[m];
	cout<<"Your input numbers are:\n";
	for(m=0;m<10;m++)
	cout<<num[m]<<" ";
	cout<<endl;
	
	bubblesort(num);
	
	cout<<"sort from large to small:\n";
	for(m=0;m<=9;m++)
	cout<<num[m]<<" ";  
	cout<<endl;
	
	selectionsort(num);
	
	cout<<"sort from small to large:\n";
	for(m=0;m<=9;m++)
	cout<<num[m]<<" ";
	cout<<endl;
	
	system("pause");
	return 0;
}



	


	
	
	
	