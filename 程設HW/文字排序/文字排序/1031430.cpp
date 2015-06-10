#include<iostream>
#include<cstdio>
#include<cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std ;

int n = 0 ;    // how many words
char input[100][30], str[200], *ptr ;
void SortAndPrint();

int main(){
    cout << "Enter a line of text : " << endl ;
    gets(str) ;
    ptr = strtok(str," ") ;    
    while(ptr != NULL)
	{
        strcpy(input[n++], ptr) ;
        ptr = strtok(NULL," ") ;
    }
    SortAndPrint() ;
    system("pause");
	return 0 ;
}
void SortAndPrint(){
    for(int i=0 ; i<n ; i++)       
        for(int j=i+1 ; j<n ; j++)
            if(strcmp(input[i], input[j]) > 0){
                strcpy(str, input[i]) ;
                strcpy(input[i], input[j]) ;
                strcpy(input[j], str) ;
            }
    for(int i=0 ; i<n ; i++)        
        cout << input[i] << " ";
		cout<<endl;
}
