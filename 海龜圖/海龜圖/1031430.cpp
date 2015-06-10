#include<iostream> 
#include<stdlib.h>
using namespace std;

bool map[20][20]={false};
bool pen=true; /* pen=1-> ¤£°O¿ý  pen=2 -> °O¿ý */
int direction=0; /* right=0 down=1 left=2 up=3*/
int x=0,y=0;

void task(int);
void forward();
void print();


int main()
{
	map[0][0]=true;
	int input;
	cout<<"Enter command(9 to end input)";
	while(cin>>input){
	 task(input);
	 cout<<"Enter command(9 to end input)";	
	}
	system("pause");
	return 0;
}

void task(int num)
{
	switch(num){
		case 1: pen=false; break;
		case 2: pen=true;  break;
		case 3: direction=(direction+1)%4; break;
		case 4: direction=(direction+3)%4; break;
		case 5: forward(); break;
		case 6: print();break;
		case 9: exit(0);
	}
}


void forward()
{
  int foot;
  cin>>foot;
  for(int i=0;i<foot;i++){
	  switch(direction){
	  case 0: x++; break;
	  case 1: y++; break;
	  case 2: x--;break;
	  case 3: y--; break;
	  }
	  if(pen)
		  map[x][y]=true;  
  }

}

void print()
{
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
		 if(map[j][i])
			cout<<"*";
		 else
			 cout<<" ";		 		
		}
		cout<<endl;	
	}
	system("PAUSE");
}