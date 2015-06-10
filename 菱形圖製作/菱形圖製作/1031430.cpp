#include <iostream>
#include<iomanip>
using namespace std;

int main(){
int number;

cout<<"Enter an odd number for the diamond size:";
cin>>number;


	for(int i=0; i<=number/2; i++){
		for(int j=1; j<=9-i; j++)
			cout<<" ";
		for(int j=1; j<=2*i+1; j++)
			cout<<"*";
		cout<<endl;
	}

	for(int i=number/2-1; i>=0; i--){
		for(int j=1; j<=9-i; j++)
			cout<<" ";
		for(int j=1; j<=2*i+1; j++)
			cout<<"*";
		cout<<endl;
	}
	system("pause");
	return 0;
}