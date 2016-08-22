/*
ID:jinyimi1
LANG:C++
TASK:stall4
*/

#include<iostream>
#include<fstream>
#include<queue>

using namespace std;

int n, m;

int store[404][404];
int isVis[404];
int pre[404];

queue<int>myQueue;

bool bfs()
{
	while (!myQueue.empty())
	{
		myQueue.pop();
	}
	for (int i = 0; i <= n + m + 1;i++)
	{
		isVis[i] = 0;
	}
	isVis[0] = 1;

	myQueue.push(0);
	int tmp;
	do
	{
		tmp = myQueue.front();
		myQueue.pop();
		for (int i = 0; i <= n + m + 1; i++)
		{
			if (isVis[i] == 0 && store[tmp][i] != 0)
			{
				pre[i] = tmp;
				if (i == m + n + 1)
				{
					return true;
				}
				myQueue.push(i);
				
				isVis[i] = 1;
			}
		}
	} while (!myQueue.empty());
	return false;

}

int solve()
{
	bool isEnd = false;
	int tmp;
	int result = 0;
	while (bfs())
	{
		result++;

		tmp = n + m + 1;
		while (tmp != 0)
		{
			store[pre[tmp]][tmp] = 0;
			store[tmp][pre[tmp]] = 1;
			tmp = pre[tmp];
			//cout << tmp << endl;
		}
		//cout << result << endl;
		
	}
	return result;
}

int main()
{
	ifstream input("stall4.in");
	ofstream output("stall4.out");

	input >> n >> m;
	int tmp;
	int index = 0;
	for (int i = 1; i <= n; i++)
	{
		input >> tmp;
		while (tmp--)
		{
			input >> index;
			store[i][n+index] = 1;
			store[n + index][n+m+1] = 1;
		}
		store[0][i] = 1;
	}

	output<<solve()<<endl;

	return 0;
}