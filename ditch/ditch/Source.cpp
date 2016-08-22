/*
ID:jinyimi1
TASK:ditch
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;

int graph[201][201];
int pre[201];
int isVis[201];
int dis[201];
queue<int> myQueue;

void show()
{

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (graph[i][j] != 0)
			{
				cout << j << " " << i << " " << graph[j][i] << endl;
			}
		}
		
	}

}

int test = 0;
int myFlow;
bool isEnd = false;



bool bfs()
{
	test++;
	//cout << test << endl;
	while (!myQueue.empty())
	{
		isVis[myQueue.front()] = 0;
		myQueue.pop();
	}

	for (int i = 1; i <= m; i++)
	{
		isVis[i] = 0;
	}
	
	//cout << isVis[2] << endl;

	int tmp;
	myQueue.push(1);
	isVis[1] = 1;
	do
	{
		tmp = myQueue.front();


		myQueue.pop();
		//isVis[tmp] = 0;
		//cout << tmp << endl;
		for (int i = 1; i <= m; i++)
		{
			if (isVis[i] == 0 && graph[tmp][i] != 0)
			{
				if (dis[tmp] == 0)
				{
					dis[i] = graph[tmp][i];
				}
				else
				{
					dis[i] = min(graph[tmp][i], dis[tmp]);
				}
				pre[i] = tmp;
				myQueue.push(i);
				isVis[i] = 1;
				if (i == m)
				{
					return true;
				}
			}
		}
	} while (!myQueue.empty() && tmp != m);
	if (tmp == m)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void clear()
{
	for (int i = 1; i <= m; i++)
	{
		isVis[i] = 0;
	}
	isEnd = false;
}

bool dijkstra()
{
	test++;
	//cout << "here" << endl;
	for (int i = 1; i <= m; i++)
	{
		//dis[i] = 0;
		dis[i] = graph[1][i];
		isVis[i] = 0;
		if (graph[1][i] != 0)
		{
			pre[i] = 1;
		}
	}
	dis[1] = 0;
	isVis[1] = 1;
	int maxNum = 0;
	int maxIndex = 0;
	int tmp = 0;

	//cout << dis[2] << endl;
	for (int i = 2; i <= m; i++)
	{
		maxNum = 0;
		maxIndex = 0;
		for (int j = 2; j <= m; j++)
		{
			if (isVis[j] == 0 && dis[j] > maxNum)
			{
				maxIndex = j;
				maxNum = dis[j];
			}
		}


		isVis[maxIndex] = 1;

		

		for (int j = 2; j <= m; j++)
		{
			if (graph[maxIndex][j] != 0 && isVis[j] == 0)
			{
				tmp = min(dis[maxIndex], graph[maxIndex][j]);


				if (tmp >= dis[j])
				{
					dis[j] = tmp;
					pre[j] = maxIndex;
				}
			}
		}

		

	}
	//show();
	if (dis[m] == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int solve()
{
	int result = 0;
	int tmp;
	//cout << graph[3][4] << endl;
	while (bfs())
	{
		result += dis[m];
		tmp = m;
		while (tmp != 1)
		{
			graph[pre[tmp]][tmp] -= dis[m];
			//cout <<pre[tmp]<<" "<<tmp<<" "<< graph[pre[tmp]][tmp] << endl;
			graph[tmp][pre[tmp]] += dis[m];
			tmp = pre[tmp];
			//cout << tmp << endl;
		}
	}

	

	return result;
	//cout << result << endl;
}

int main()
{
	ifstream input("ditch.in");
	ofstream output("ditch.out");
	input >> n >> m;
	int a, b,tmp;
	for (int i = 0; i < n; i++)
	{
		input >> a >> b;
		input >> tmp;
		graph[a][b] += tmp;
		if (a == b)
		{
			graph[a][a] = 0;
		}
		//cout << graph[3][4] << endl
	}
	output<<solve()<<endl;

	//show();
	return 0;
}