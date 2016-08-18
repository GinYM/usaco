/*
ID:jinyimi1
TASK:range
LANG:C++
*/

#include<iostream>
#include<fstream>

using namespace std;

int n;
int store[251][251];
int dp[251][251];

void initial()
{
	int isTrue;
	for (int i = 0; i  < n; i++)
	{
		for (int j = 0; j  < n; j++)
		{

			isTrue = true;
			for (int a = 0; i+a<n && j+a < n; a++)
			{
				for (int b = 0; b <=a; b++)
				{
					if (store[i + a][j + b] == 0 || store[i+b][j+a] == 0)
					{
						isTrue = false;
						break;
					}
				}
				if (isTrue == false)
				{
					break;
				}
				else
				{
					dp[i][j] = a+1;
				}
			}
			
		}
	}
}

int get_num(int num)
{
	bool isTrue = false;
	int count_n = 0;
	//cout << 0 + num << endl;
	for (int i = 0; i + num <= n; i++)
	{
		for (int j = 0; j + num <= n; j++)
		{
			if (dp[i][j] >= num)
			{
				count_n++;
			}
		}
	}
	return count_n;
}

void show()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << store[i][j] << " ";
		}
		cout << endl;
	}
}

void show_dp()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	ifstream input("range.in");
	ofstream output("range.out");
	
	input >> n;
	char c;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			input >> c;
			store[i][j] = c - '0';
			
		}
	}

	int tmp = 0;
	initial();
	for (int i = 2; i <= n; i++)
	{
		tmp = get_num(i);
		if (tmp == 0)
		{
			break;
		}
		else
		{
			output << i << " " << tmp << endl;
		}
	}
	//show();
	//show_dp();

	return 0;
}