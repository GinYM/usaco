/*
ID:jinyimi1
TASK:inflate
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int m, n;

struct s
{
	int minutes;
	int points;
}store[10002];


int result[10002];



int solve()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (j - store[i].minutes >= 0)
				result[j] = max(result[j], result[j - store[i].minutes] + store[i].points);
		}
	}
	return result[m];
}

int main()
{
	ifstream input("inflate.in");
	ofstream output("inflate.out");

	input >> m >> n;
	for (int i = 1; i <= n; i++)
	{
		input >> store[i].points >> store[i].minutes;
	}

	//show();
	output << solve() << endl;

	return 0;
}