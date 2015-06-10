#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	int H,M;   //H代表時針，M代表分針
	char semicolon;     //semicolon為分號
	cout<<"Please enter the clockhands:";

	while(cin>>H>>semicolon>>M)
	{
		if(H==0 && M==0)
		{
			break;
		}
		double H_angle=static_cast<double>(H)*30 + static_cast<double>(M)/60;
		double M_angle=static_cast<double>(M)*6;
		double angle=abs(H_angle-M_angle);
		if(angle > 180)
		{
			angle=abs(360-angle);
		}
		cout<<fixed<<setprecision(2)<<"The angle is: "<<angle<<endl;
		cout<<"Please enter the clockhands:";
	}	
	
	system("pause");
	return 0;
}