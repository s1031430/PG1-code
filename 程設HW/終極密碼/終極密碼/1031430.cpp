#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
int main()
{
	int a,i;
	srand(time(NULL));
	cout<<"Please guess a number(1~1000):";
	cin>>a;
	i=(rand()%1000)+1;
	do
	{
		if(a<i)
		cout<<"Too low,try again:";
		else if(a>i)
		cout<<"Too high,try again:";
		else
		cout<<"You enter the right number\nWould you like to play again(y/n):";
	}while(cin>>a);
	system("pause");
	return 0;
}

	