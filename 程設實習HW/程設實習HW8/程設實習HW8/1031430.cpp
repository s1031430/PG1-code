#include<iostream>
#include<string.h>
using namespace std;
bool check(int head,char *id);
bool ask();
/* 判斷身分證是否正確*/
int main()
{
	char id[11];  //   10碼 + '/0'
	while(true){
	cout<<"Please input your ID number : "; 
	cin>>id;	
		if(strlen(id)!=10){
		cout<<"input error!!"<<endl;
		if(ask())
			continue;
			break;
		}
		int head=id[0];  //將英文字母強制轉型

		/* 判斷大寫 */
		if(head>=65&&head<=90){ //  A~Z ASCII範圍
			if(head==73) head=head-39;  // I
			else if (head==79) head=head-44; // O
			else if (head==87) head=head-55; //W
			else if (head==90) head=head-57; //Z
			else if(head>=65&&head<=72) head=head-55; //A~H
			else if(head>=74&&head<=78) head=head-56; //J~N
			else if(head>=80&&head<=86) head=head-57; //P~V
			else  head=head-58; //X~Y  
			/* 進入驗證函式 */
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
	/* 個位數*9 + 十位數 */
	int sum=head%10;
	head=head/10;
	sum=sum*9+head;
	/* 將數字字元轉成數字 */
	int data[10];
	for(int i=1;id[i]!='\0';i++)
		data[i]=id[i]-'0';
	/* 運算第二碼~第九碼 */
	for(int j=8;j>=1;j--)
		sum=sum+(data[9-j]*j);
	sum=sum%10;
	if( (data[9]==0 && sum==0) || ( (10-sum)==data[9] ) )
		return true;
	else
		return false;
}


/* 判斷要不要繼續 */
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






	




