/*
ID:jinyimi1
TASK:butter
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<queue>	

#define max_num 180006

using namespace std;

int n, p, c;

int cow[500];
int pastures[801][801];
int store[801][801];
int isIn[801];

queue<int> mq;

void initial()
{
	for (int i = 1; i <= p; i++)
	{
		for (int j = 1; j <= p; j++)
		{
			pastures[i][j] = max_num;
		}
		pastures[i][i] = 0;
	}
}

void show()
{
	for (int i = 1; i <= p; i++)
	{
		for (int j = 1; j <= p; j++)
		{
			cout << pastures[i][j] << " ";
		}
		cout << endl;
	}
}


int solve()
{
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		//cout << "he" << endl;
		mq.push(cow[i]);
		for (int j = 1; j <= p; j++)
		{
			store[i][j] = max_num;
			isIn[j] = 0;
		}
		store[i][cow[i]] = 0;
		
		while (!mq.empty())
		{
			//cout << "hehe" << endl;
			tmp = mq.front();
			isIn[tmp] = 0;
			mq.pop();
			for (int j = 1; j <= p; j++)
			{
				if (store[i][tmp] + pastures[tmp][j] < store[i][j])
				{
					store[i][j] = store[i][tmp] + pastures[tmp][j];
					if (isIn[j] == 0)
					{
						mq.push(j);
						isIn[j] = 1;
					}
				}
			}
		}


		

	}
	int result = max_num;
	int result_index = 0;
	for (int i = 1; i <= p; i++)
	{
		tmp = 0;
		for (int j = 0; j < n; j++)
		{
			tmp += store[j][i];
		}
		if (tmp < result)
		{
			result = tmp;
			result_index = i;
		}
	}
	//cout << result << endl;
	return result;
}



int main()
{
	ifstream input("butter.in");
	ofstream output("butter.out");

	input >> n >> p >> c;
	initial();
	for (int i = 0; i < n; i++)
	{
		input >> cow[i];
	}

	int x,y,l;
	for (int i = 0; i < c; i++)
	{
		input >> x >> y >> l;
		pastures[x][y] = l;
		pastures[y][x] = l;
	}
	//show();
	//solve();
	output << solve() << endl;

	return 0;
}