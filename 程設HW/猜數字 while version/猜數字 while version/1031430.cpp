#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
int main()
{
	int a=0,i=0;
	srand(time(NULL));
	cout<<"Please guess a number(1~1000):";
	i=(rand()%1000)+1;
	while(cin>>a)
	{
		
		if(a<i)
		cout<<"Too low,try again:";
		else if(a>i)
		cout<<"Too high,try again:";
		else
		cout<<"You enter the right number\nWould you like to play again(y/n):";
	}	
	system("pause");
	return 0;
}

	