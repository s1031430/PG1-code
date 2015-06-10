#include<iostream>
#include<ctime>
using namespace std;
void Rand(int number[]);
void Sort(int number[]);
int Search(int number[],int b,int,int);
int main()
{
	int number[10],a,b,ans,i;     //a=一開始輸入的1或2;b=要搜尋的數字;c=判斷要搜尋的數字是否有在陣列內;d=陣列中數字位置
	do{
			
		srand(time(NULL));
		cout<<"<1>start\n";
		cout<<"<2>end\n";
		cin>>a;

		if(a==2)
			break;
		
		Rand(number);
		Sort(number);
		for(i=0;i<10;i++)
			cout<<number[i]<<" ";
		cout<<"\nPlease input a number that you want to search:";
		cin>>b;
		int low=0,high=(sizeof(number)/sizeof(int))-1;
		ans=Search(number,b,low,high);
		if(ans<0)
			cout<<b<<" is not in the array!\n";
		else
			cout<<b<<" is in the array, and the position is "<<ans+1<<endl;
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
				number[j]=(rand()%100+1);
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
int Search(int number[],int b,int low,int high)
{
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(number[mid]==b)
		{
			return mid;
		}
		else if(number[mid]>b)
		{
			high=mid-1;
			return Search(number,b,low,high);
		}
		else if(number[mid]<b)
		{
			low=mid+1;
			return Search(number,b,low,high);
		}
	}
	return -1;
}