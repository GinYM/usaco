/*
ID:jzzlee1
PROB:kimbits
LANG:C++
*/
//#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
using namespace std;
ifstream cin("kimbits.in");
ofstream cout("kimbits.out");
int dp[33][33];
int dy(int n, int v)
{
	if (dp[n][v] != 0)
		return dp[n][v];
	else
		dp[n][v] = dy(n - 1, v) + dy(n - 1, v - 1);
	return dp[n][v];
}
int main()
{
	unsigned int n, l, i;
	int j, k;
	cin >> n >> l >> i;
	for (j = 0, k = 0; j != 33; j++)
		dp[j][k] = dp[k][j] = 1;
	
	for (k = n - 1; k >= 0; k--)
	{
		if (i&&dy(k, l) < i)
		{
			cout << 1;
			i -= dy(k, l);
			l--;
		}
		else
			cout << 0;
	}
	cout << endl;
	return 0;
}