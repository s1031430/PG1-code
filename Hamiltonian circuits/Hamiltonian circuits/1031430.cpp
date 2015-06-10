#include <iostream>
using namespace std;
int V = 9; //總共有9個點
bool adj[9][9]; //相鄰的兩點
bool visit[9]; //經過的點
int solution[250]; //跑出來的路線
void HamiltonCircuit( int &count ); //跑路線
void backtrack( int n, int &count ); //帶點跑路線
int main()
{
	int count = 0; //計算有幾條路線
	adj[0][1] = true; adj[0][2] = true; adj[0][3] = true; adj[0][4] = true; adj[0][8] = true; 
	adj[1][0] = true; adj[1][2] = true; adj[1][6] = true; adj[1][7] = true; adj[1][8] = true;
	adj[2][0] = true; adj[2][1] = true; adj[2][4] = true; adj[2][5] = true; adj[2][6] = true;
	adj[3][0] = true; adj[3][4] = true; adj[3][5] = true; adj[3][7] = true; adj[3][8] = true;
	adj[4][0] = true; adj[4][2] = true; adj[4][3] = true; adj[4][5] = true;
	adj[5][2] = true; adj[5][3] = true; adj[5][4] = true; adj[5][6] = true; adj[5][7] = true;
	adj[6][1] = true; adj[6][2] = true; adj[6][5] = true; adj[6][7] = true;
	adj[7][1] = true; adj[7][3] = true; adj[7][5] = true; adj[7][6] = true; adj[7][8] = true;
	adj[8][0] = true; adj[8][1] = true; adj[8][3] = true; adj[8][7] = true; //全部相鄰的兩點都設為true
	HamiltonCircuit( count ); //跑HamiltonCircuit function
	cout << "總共有" << count << "條路線" << endl << endl; //印出有多少條路線
	system("pause"); //結束
	return 0; 
}
void HamiltonCircuit( int &count ) //HamiltonCircuit function
{
	solution[0] = 0; //先設solution[0]為0
	backtrack( 1, count ); //跑backtrack function (n先用1代入)
}
void backtrack( int n, int &count ) //backtrack function
{
	if ( n == V ) //當n等於9的時候執行
	{
		int x = solution[V - 1]; //x設為solution[9-1] = solution[8]
		int y = solution[0]; // y = solution[0] = 0
		if( adj[x][y] ) //當xy兩點相鄰的時候執行
		{
			for( int i = 0; i <= 9; i++ )
			{
				cout << solution[i] << " " ; //印出路線
			}
			count++; //路線數加1
			cout << endl << endl;
		}
		return;
	}

	int x = solution[n - 1]; //x = solution[0] = 0  
	
	for( int y = 1; y < V; ++y ) //跑for迴圈
	{
		if( adj[x][y] && !visit[y] ) //當"xy是相鄰的兩點"和"y那點還沒跑過"時執行(adj[0][1] = true && visit[1] = false)
		{  
			visit[y] = true; //設visit[y]為true 代表跑過了(visit[1] = true)
			solution[n] = y; //設solution[n]的值為y (soltion[1] = 1)
			backtrack( (n + 1), count ); //跑backtrack function (n用n+1代入 就是2)
			visit[y] = false; //設visit[y]為false(visit[1] = false)
		}
	}
}
