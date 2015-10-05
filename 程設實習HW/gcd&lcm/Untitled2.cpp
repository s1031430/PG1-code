#include<iostream>
using namespace std;
int gcd(int,int);
int main()
{
	int a,b,c;
	cout<<"";
	cin>>a>>b>>c;
	cout<<"gcd:"<<gcd(gcd(a,b),c)<<endl;
	int num=gcd(gcd(a,b),c);
	cout<<"lcm:"<<num*(a/num)*(b/num)*(c/num)<<endl;
	return 0;
}
int gcd(int a,int b)
{
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}

