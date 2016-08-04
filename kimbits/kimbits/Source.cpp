/*
ID:jinyimi1
TASK:kimbits
LANG:C++
*/

#include<iostream>
#include<fstream>

using namespace std;

long long n, l, i;
int dp[33][33];

int get(int len, int count)
{
	int ans = dp[len][count];
	if (ans != 0)
	{
		return ans;
	}
	else
	{
			dp[len][count] = get(len - 1, count) + get(len - 1, count - 1);
			return dp[len][count];
		
	}
}


int main()
{
	ifstream input("kimbits.in");
	ofstream output("kimbits.out");

	input >> n >> l >> i;

	for (int j = 0; j < 33; j++)
	{
		dp[j][0] = dp[0][j] = 1;
	}
	for (int j = n - 1; j >= 0; j--)
	{
		if (get(j, l) < i)
		{
			output << 1;
			i -= get(j, l);
			l--;
		}
		else
		{
			output << 0;
		}
	}
	output << endl;
	//cout << dp[2][3] << endl;

	return 0;
}