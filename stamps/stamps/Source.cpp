/*
ID:jinyimi1
TASK:stamps
LANG:C++
*/

#include<iostream>
#include<fstream>

using namespace std;

int k, n;

int store[51];
int map[2000000];

int solve()
{
	int num = 1;
	while (1)
	{
		for (int i = 0; i < n; i++)
		{
			if (num - store[i] > 0)
			{
				if (map[num] != 0 && map[num - store[i]] + 1 < map[num])
				{
					map[num] = map[num - store[i]] + 1;
				}
				else if (map[num] == 0)
				{
					map[num] = map[num - store[i]] + 1;
				}
			}
		}
		if (map[num] == 0 || map[num] > k)
		{
			break;
		}
		//cout << num << endl;
		num++;
	}
	return num - 1;
}

int main()
{
	ifstream input("stamps.in");
	ofstream output("stamps.out");
	input >> k >> n;

	for (int i = 0; i < n; i++)
	{
		input >> store[i];
		map[store[i]] = 1;
	}
	output<<solve()<<endl;

	return 0;
}