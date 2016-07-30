/*
ID:jinyimi1
TASK:humble
LANG:C++
*/

#include<iostream>
#include<fstream>

using namespace std;

int k, n;

int s[101];

int humble[100002];

int store_index[101];

#define MAX_INT 0x7fffffff

void solve()
{
	humble[0] = 1;
	int minNum, minIndex;
	for (int i = 1; i <= n; i++)
	{
		minNum = MAX_INT; 
		for (int j = 1; j <= k; j++)
		{
			while (s[j] * humble[store_index[j]] <= humble[i - 1])
			{
				store_index[j]++;
			}

			if (s[j] * humble[store_index[j]]>humble[i-1] && s[j] * humble[store_index[j]] < minNum)
			{
				minNum = s[j] * humble[store_index[j]];
				minIndex = j;
			}
			
		}
		//cout << minIndex << " " << store_index[minIndex] << " "<<store_index[2]<< endl;
		store_index[minIndex]++;
		humble[i] = minNum;
	}
	
}

void show()
{
	for (int i = 0; i <= n; i++)
	{
		cout << humble[i] << endl;
	}
}

int main()
{

	ifstream input("humble.in");
	ofstream output("humble.out");

	input >> k >> n;

	for (int i = 1; i <= k; i++)
	{
		input >> s[i];
	}

	solve();

	//show();

	

	output << humble[n] << endl;

	return 0;
}