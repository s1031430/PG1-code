#include <iostream>
using namespace std;
int V = 9; //�`�@��9���I
bool adj[9][9]; //�۾F�����I
bool visit[9]; //�g�L���I
int solution[250]; //�]�X�Ӫ����u
void HamiltonCircuit( int &count ); //�]���u
void backtrack( int n, int &count ); //�a�I�]���u
int main()
{
	int count = 0; //�p�⦳�X�����u
	adj[0][1] = true; adj[0][2] = true; adj[0][3] = true; adj[0][4] = true; adj[0][8] = true; 
	adj[1][0] = true; adj[1][2] = true; adj[1][6] = true; adj[1][7] = true; adj[1][8] = true;
	adj[2][0] = true; adj[2][1] = true; adj[2][4] = true; adj[2][5] = true; adj[2][6] = true;
	adj[3][0] = true; adj[3][4] = true; adj[3][5] = true; adj[3][7] = true; adj[3][8] = true;
	adj[4][0] = true; adj[4][2] = true; adj[4][3] = true; adj[4][5] = true;
	adj[5][2] = true; adj[5][3] = true; adj[5][4] = true; adj[5][6] = true; adj[5][7] = true;
	adj[6][1] = true; adj[6][2] = true; adj[6][5] = true; adj[6][7] = true;
	adj[7][1] = true; adj[7][3] = true; adj[7][5] = true; adj[7][6] = true; adj[7][8] = true;
	adj[8][0] = true; adj[8][1] = true; adj[8][3] = true; adj[8][7] = true; //�����۾F�����I���]��true
	HamiltonCircuit( count ); //�]HamiltonCircuit function
	cout << "�`�@��" << count << "�����u" << endl << endl; //�L�X���h�ֱ����u
	system("pause"); //����
	return 0; 
}
void HamiltonCircuit( int &count ) //HamiltonCircuit function
{
	solution[0] = 0; //���]solution[0]��0
	backtrack( 1, count ); //�]backtrack function (n����1�N�J)
}
void backtrack( int n, int &count ) //backtrack function
{
	if ( n == V ) //��n����9���ɭ԰���
	{
		int x = solution[V - 1]; //x�]��solution[9-1] = solution[8]
		int y = solution[0]; // y = solution[0] = 0
		if( adj[x][y] ) //��xy���I�۾F���ɭ԰���
		{
			for( int i = 0; i <= 9; i++ )
			{
				cout << solution[i] << " " ; //�L�X���u
			}
			count++; //���u�ƥ[1
			cout << endl << endl;
		}
		return;
	}

	int x = solution[n - 1]; //x = solution[0] = 0  
	
	for( int y = 1; y < V; ++y ) //�]for�j��
	{
		if( adj[x][y] && !visit[y] ) //��"xy�O�۾F�����I"�M"y���I�٨S�]�L"�ɰ���(adj[0][1] = true && visit[1] = false)
		{  
			visit[y] = true; //�]visit[y]��true �N��]�L�F(visit[1] = true)
			solution[n] = y; //�]solution[n]���Ȭ�y (soltion[1] = 1)
			backtrack( (n + 1), count ); //�]backtrack function (n��n+1�N�J �N�O2)
			visit[y] = false; //�]visit[y]��false(visit[1] = false)
		}
	}
}
