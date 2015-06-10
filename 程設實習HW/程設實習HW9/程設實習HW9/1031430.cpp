#include<iostream>
using namespace std;
int main()
{
	int n,a;    //a為記數器
	cout<<"Enter the number of prime you would like:";
	cin>>n;
	int *arr=new int[n];
	
		int i,j,flag;
		a=0;
		
		for(i=2;a<n;i++)
		{
			flag=0;
			for(j=2;j<i;j++)
			{
				if(i%j==0)
				flag=1;
			}
			if(flag==0)
			{
				arr[a]=i;
				a++;
			}
		}
		for(int k=0;k<n;k++)
		{
			cout<<arr[k]<<" ";
		}

	cout<<endl;
	delete []arr;
	system("pause");
	return 0;
}
