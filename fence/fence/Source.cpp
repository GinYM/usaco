/*
ID:jinyimi1
TASK:fence
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<stack>

using namespace std;

int f;

int mStack[502];
int index = -1;

int degree[502];

int max_num = 0;
int min_num = 100000;

int fence[501][501];

void dfs(int n)
{
	for (int i = min_num; i <= max_num; i++)
	{
		if (fence[n][i])
		{
			fence[n][i] --;
			fence[i][n] --;
			dfs(i);
		}
	}
	mStack[++index] = n;
}

void solve()
{
	for (int i = min_num; i <= max_num; i++)
	{
		if (degree[i] % 2 == 1)
		{
			dfs(i);
			return;
		}
	}
	dfs(min_num);
}

int main()
{
	ifstream input("fence.in");
	ofstream output("fence.out");

	input >> f;
	int x, y;
	for (int i = 0; i < f; i++)
	{
		input >> x >> y;
		degree[x]++;
		degree[y]++;
		fence[x][y] ++;
		fence[y][x] ++;
		if (x > max_num)
		{
			max_num = x;
		}
		if (y > max_num)
		{
			max_num = y;
		}
		if (x < min_num)
		{
			min_num = x;
		}
		if (y < min_num)
		{
			min_num = y;
		}
	}
	//cout << max_num << endl;

	solve();

	for (int i = index; i >= 0; i--)
	{
		output << mStack[i] << endl;
	}

	return 0;
}