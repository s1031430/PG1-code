#include<iostream>
using namespace std;
int gcd(int,int);
int main()
{
	int m,n;
	cout<<"";
	cin>>m>>n;
	cout<<"gcd:"<<gcd(m,n)<<endl;
	cout<<"lcm:"<<gcd(m,n)*(m/gcd(m,n))*(n/gcd(m,n));
	return 0;
}
int gcd(int m,int n)
{
	if(n==0)
	return m;
	else
	return gcd(n,m%n);
}
