#include<iostream>
#include<string.h>
using namespace std;
bool check(int head,char *id);
bool ask();
/* �P�_�����ҬO�_���T*/
int main()
{
	char id[11];  //   10�X + '/0'
	while(true){
	cout<<"Please input your ID number : "; 
	cin>>id;	
		if(strlen(id)!=10){
		cout<<"input error!!"<<endl;
		if(ask())
			continue;
			break;
		}
		int head=id[0];  //�N�^��r���j���૬

		/* �P�_�j�g */
		if(head>=65&&head<=90){ //  A~Z ASCII�d��
			if(head==73) head=head-39;  // I
			else if (head==79) head=head-44; // O
			else if (head==87) head=head-55; //W
			else if (head==90) head=head-57; //Z
			else if(head>=65&&head<=72) head=head-55; //A~H
			else if(head>=74&&head<=78) head=head-56; //J~N
			else if(head>=80&&head<=86) head=head-57; //P~V
			else  head=head-58; //X~Y  
			/* �i�J���Ҩ禡 */
			check(head,id);
			if(check(head,id)){
				cout<<"The id is right!"<<endl;
				if(ask())
					continue;
				break;
			}
			else{
			cout<<"input error!!"<<endl;
			if(ask())
			continue;
			break;
		  }
		}

		else{
			cout<<"input error!!"<<endl;
			if(ask())
			continue;
			break;
		}
	}
	

	system("pause");
	return 0;
}
bool check(int head,char *id)
{
	/* �Ӧ��*9 + �Q��� */
	int sum=head%10;
	head=head/10;
	sum=sum*9+head;
	/* �N�Ʀr�r���ন�Ʀr */
	int data[10];
	for(int i=1;id[i]!='\0';i++)
		data[i]=id[i]-'0';
	/* �B��ĤG�X~�ĤE�X */
	for(int j=8;j>=1;j--)
		sum=sum+(data[9-j]*j);
	sum=sum%10;
	if( (data[9]==0 && sum==0) || ( (10-sum)==data[9] ) )
		return true;
	else
		return false;
}


/* �P�_�n���n�~�� */
bool ask()
{
	char answer;
	cout<<"again? <y/n>";
	cin>>answer;
	if(answer=='Y'||answer=='y'){
		cout<<endl<<endl;
		return true;
	}
	else
		return false;
}






	




