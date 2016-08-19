/*
ID:jinyimi1
TASK:rockers
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int n, t, m;

int dp[21][21][21];



int main()
{
	ifstream input("rockers.in");
	ofstream output("rockers.out");

	input >> n >> t >> m;

	int num;

	int index = 0;

	int disk = 1;
	int compacity = 0;


	for (int i = 1; i <= n;i++)
	{
		input >> num;

		for (int j = 1; j <= m; j++)
		{
			for (int k = 0; k <= t; k++)
			{
				if (num > k)
				{
					dp[i][j][k] = max(dp[i - 1][j][k], dp[i-1][j-1][t]);
				}
				else
				{
					dp[i][j][k] = max(dp[i-1][j][k-num],dp[i-1][j-1][t])+1;
				}
			}
		}

	}

	output << dp[n][m][t] << endl;
	

	return 0;
}