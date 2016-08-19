/*
ID:jinyimi1
TASK:game1
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int n;
int store[101];
int sum[101][101];
int point[101][101];

void initial()
{
	int tmp = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			tmp = 0;
			for (int a = i; a <= j; a++)
			{
				tmp += store[a];
			}
			sum[i][j] = tmp;
		}
	}
}

int dp(int a, int b)
{
	if (point[a][b] != 0)
	{
		return point[a][b];
	}

	point[a][b] =  sum[a][b] - min(dp(a+1,b), dp(a,b-1));
	return point[a][b];
}



void show()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			cout <<i<<" "<<j<<" "<< point[i][j] << "  ";
		}
		cout << endl;
	}
}

int main()
{
	ifstream input("game1.in");
	ofstream output("game1.out");
	input >> n;

	for (int i = 1; i <= n; i++)
	{
		input >> store[i];
		point[i][i] = store[i];
	}
	initial();
	dp(1, n);
	output << point[1][n]<<" "<<(sum[1][n]-point[1][n])<<endl;
	//show();

	return 0;
}