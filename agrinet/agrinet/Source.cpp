/*
ID:jinyimi1
TASK:agrinet
LANG:C++
*/

#include<iostream>
#include<fstream>

using namespace std;

int n;

int store[101][101];
int inTree[101];
int index = 0;
int isVis[101];

int solve()
{
	isVis[0] = 1;
	int d = 0;
	int tmp = 0;
	int tmp_index = 0;
	for (int k = 0; k < n-1;k++)
	{
		tmp = 100004;
		for (int i0 = 0; i0 <= index; i0++)
		{
			int i = inTree[i0];
			for (int j = 0; j < n; j++)
			{
				if (isVis[j] == 1)
				{
					continue;
				}
				if (store[i][j] < tmp)
				{
					tmp = store[i][j];
					tmp_index = j;
				}
			}
		}
		isVis[tmp_index] = 1;
		d += tmp;
		inTree[++index] = tmp_index;
	}
	return d;
}

int main()
{
	ifstream input("agrinet.in");
	ofstream output("agrinet.out");

	input >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			input >> store[i][j];
		}
	}
	output << solve() << endl;
	return 0;
}