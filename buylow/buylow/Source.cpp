/*
ID:jinyimi1
TASK:buylow
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<stack>
#include<string>
#include<vector>
#include<set>
#include<map>

using namespace std;

int n;
int store[5001];
int dp[5001];

//int check[5001][5002];
int index = -1;
//string check[1900000];
int num[5001][63];

int size = 63;



void show()
{
	for (int i = 0; i < n; i++)
	{
		cout << dp[i] << " ";
	}
	cout << endl;

	int index = size;
	for (int i = 0; i < n; i++)
	{
		index = size;
		while (num[i][index] == 0)
		{
			index--;
		}
		for (int k = index; k >= 0; k--)
		{
			cout << num[i][k];
		}
		cout <<  " ";
	}
	cout << endl;
}

void Myadd(int index1, int index2)
{
	int carry = 0;
	for (int i = 0; i <= size-1; i++)
	{
		num[index1][i] += num[index2][i] + carry;
		carry = num[index1][i] / 10;
		num[index1][i] %= 10;
	}
}

bool isZero(int index0)
{
	for (int i = 0; i <= size-1; i++)
	{
		if (num[index0][i] != 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ifstream input("buylow.in");
	ofstream output("buylow.out");
	int maxNum = 0;
	input >> n;
	int maxIndex = 0;
	map<int, int>myMap;
	//cout << n << endl;
	for (int i = 0; i < n; i++)
	{
		input >> store[i];
		myMap[store[i]] = i;
		dp[i] = 1;
		set<int> mySet;
		for (int j = 0; j < i; j++)
		{
			if (store[i] < store[j])
			{
				if (1 + dp[j] > dp[i])
				{
					dp[i] = dp[j] + 1;
				}
			}

		}

		for (int k = 0; k < i; k++)
		{
			if (dp[k] + 1 == dp[i] && store[k]>store[i])
			{
				mySet.insert(store[k]);
				
			}
		}
		for (set<int>::iterator iter = mySet.begin(); iter != mySet.end(); iter++)
		{
			Myadd(i, myMap[*iter]);
			//num[i] += num[myMap[*iter]];
		}



		if (isZero(i))
		{
			num[i][0] = 1;

			//num[i] = 1;
		}

		//cout << dp[i] << endl;
		if (dp[i] > maxNum)
		{
			maxNum = dp[i];
			maxIndex = i;
		}
		else if (dp[i] == maxNum)
		{
			maxIndex = i;
		}

	}

	set<int> mySet;
	for (int i = 0; i < n; i++)
	{
		if (dp[i] == maxNum)
		{
			mySet.insert(store[i]);
		}
	}
	int result=0;
	for (set<int>::iterator ivec = mySet.begin(); ivec != mySet.end(); ivec++)
	{
		//cout << myMap[*ivec] << endl;
		//result += num[myMap[*ivec]];
		Myadd(n, myMap[*ivec]);
		//cout << num[myMap[*ivec]];
	}

	//dfs(5001,"");
	//show_check();
	//cout << maxIndex << endl;
	output << maxNum << " ";
	int result_i = size-1;
	while (num[n][result_i] == 0)
	{
		result_i--;
	}
	for (int i = result_i; i >= 0; i--)
	{
		output << num[n][i];
	}
	output << endl;

	//show();

	return 0;
}