#include<iostream>
using namespace std;
void sort_incres(int num[],int num1[]);
void sort_decres(int num[],int num2[]);
void Max_Min(int num1[],int num2[],int num3[]);
void print(int num4[]);
int main()
{
	int m,a=0;
	int num1[5],num2[5],num3[5],num[5];
	cout<<"Please enter the five digits numbers:\n";
	cin>>m;
	for(int k=1;k<m;k=k*10)
	{
		num[a]=(m/k)%10;
		a++;
		if(a>4)
		break;
	}
	sort_incres(num,num1);
	sort_decres(num,num2);
	Max_Min(num1,num2,num3);
	cout<<"The value of Max-Min is ";
	print(num3);
	cout<<"<";
	print(num1);
	cout<<"-";
	print(num2);
	cout<<">";
	system("pause");
	return 0;
}
void sort_incres(int num[],int num1[])
{
	int i;
	int j;
	int t;
	for(i=0;i<=4;i++)
		num1[i]=num[i];
	for(i=0;i<=4;i++)	
	{
		for(j=0;j<4-i;j++)
		{
			if(num1[j]<num1[j+1])  //�Y�e����᭱�p�h�洫
			{
				t=num1[j];     //�H�U�T��洫
				num1[j]=num1[j+1];
				num1[j+1]=t;
			}
		}
	}


}
void sort_decres(int num[],int num2[])
{
	int i;
	int j;
	int t;
	for(i=0;i<=4;i++)
		num2[i]=num[i];
	for(i=0;i<=4;i++)	
	{
		for(j=0;j<4-i;j++)
		{
			if(num2[j]>num2[j+1])  
			{
				t=num2[j];     
				num2[j]=num2[j+1];
				num2[j+1]=t;
			}
		}
	}

}
void Max_Min(int num1[],int num2[],int num3[])
{
	for(int i=4;i>=0;i--)
	{
		num3[i]=num1[i]-num2[i];
	}
	for ( int i = 4; i >=0; i-- ) 
	{	
		if ( num3[i] < 0 )        //�Y�t�����@��Ƥp��s
			{
				num3[i] += 10;    //�����h��U�@���10�b���۴�
				num3[i-1] -= 1;   //�U�@��]����10�ҥH���@
			}
	}
}
void print(int num4[])
{
  for( int i = 0; i <=4; i++ )
      cout << num4[i];
}

