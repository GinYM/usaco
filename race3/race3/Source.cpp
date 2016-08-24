/*
ID:jinyimi1
TASK:race3
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<queue>

using namespace std;

int myMap[55][55];
int result[55];
int index=-1;
int n = -1;
int isVis[55];
int result2[55];
int index2 = -1;
int isVis2[55];

void bfs()
{
	int tmp = 0;
	bool isEnd = false;
	for (int i = 1; i < n; i++)
	{
		queue<int> myQueue;
		isEnd = false;
		myQueue.push(0);
		for (int k = 0; k <= n; k++)
		{
			isVis[k] = 0;
			isVis2[k] = 0;
		}
		isVis[0] = 1;
		do
		{
			tmp = myQueue.front();
			myQueue.pop();
			//cout << tmp << endl;
			if (tmp == i)
			{
				continue;
			}
			if (tmp == n)
			{
				isEnd = true;
				break;
			}
			for (int j = 0; j <= n; j++)
			{
				if (j != i && myMap[tmp][j] == 1 && isVis[j] == 0)
				{
					myQueue.push(j);
					isVis[j] = 1;
				}
			}
		} while (!myQueue.empty());
		if (isEnd == false&& i!=0 && i!=n)
		{
			result[++index] = i;
			while (!myQueue.empty())
			{
				myQueue.pop();
			}
			myQueue.push(i);
			isEnd = false;
			do
			{
				tmp = myQueue.front();
				myQueue.pop();
				for (int kk = 0; kk <= n; kk++)
				{
					if (myMap[tmp][kk] == 1 && isVis2[kk] == 0)
					{
						if (isVis[kk] == 1)
						{
							isEnd = true;
							break;
						}
						else
						{
							myQueue.push(kk);
							isVis2[kk] = 1;
						}
					}
				}
				if (isEnd == true)
				{
					break;
				}
			} while (!myQueue.empty());
			if (isEnd == false)
			{
				result2[++index2] = i;
			}
		}
	}
}

void solve()
{
	int tmp;
	bool myresult = false;
	//int div_index = -1;
	//cout << n << endl;
	for (int i = 0; i <= index; i++)
	{
	//	cout << "here" << endl;

		for (int k = 0; k <= n; k++)
		{
			isVis[k] = 0;
		}
		isVis[0] = 1;
		//Mydiv[++div_index] = 0;
		queue<int>myQueue;
		myQueue.push(0);
		do
		{
			tmp = myQueue.front();
			myQueue.pop();
			for (int j = 0; j <= n; j++)
			{
				if (isVis[j] == 0 && myMap[tmp][j] == 1 && j != result[i])
				{
					myQueue.push(j);
					isVis[j] = 1;
					//Mydiv[++div_index] = j;
				}
			}
		} while (!myQueue.empty());

		myresult = true;
		for (int a = 0; a <= n; a++)
		{
			if (a == result[i])
				continue;
			for (int b = 0; b <= n; b++)
			{
				if (b == result[i])
					continue;

				if (isVis[a] + isVis[b] == 1)
				{
					//cout << a << " " << b << endl;
					if (myMap[a][b] == 1 || myMap[b][a] == 1)
					{
						//cout << a << " " << b << endl;
						myresult = false;
						break;
					}
				}
			}
			if (myresult == false)
				break;
		}

		if (myresult == true)
		{
			result2[++index2] = result[i];
		}
	}
}



void show()
{
	for (int i = 0; i <= index; i++)
	{
		cout << result[i] << endl;
	}
}

void show_store()
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cout << myMap[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	ifstream input("race3.in");
	ofstream output("race3.out");
	int num=0;

	
	n++;
	do
	{
		input >> num;
		//cout << num << endl;
		if (num == -1)
		{
			break;
		}
		//cout << num << endl;
		if (num == -2)
		{
			n++;
			continue;
		}
		myMap[n][num] = 1;
	} while (num != -1);
	//cout << n << endl;
	n--;
	//cout << n << endl;
	
	bfs();
	output << index+1;
	for (int i = 0; i <= index; i++)
	{
		output <<" "<< result[i];
	}
	output << endl;
	//solve();
	output << index2 + 1;
	for (int i = 0; i <= index2; i++)
	{
		output <<" "<< result2[i];
	}
	output << endl;
	
	//output << 0 << endl << 0 << endl;

	return 0;
}