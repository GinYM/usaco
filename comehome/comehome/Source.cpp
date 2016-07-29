/*
ID:jinyimi1
TASK:comehome
LANG:C++
*/

#include<iostream>
#include<fstream>

using namespace std;

#define INF 10000000

int p;

struct s
{
	char a;
	char b;
	int d;
}store[10000];

int map[100][100];

int isVis[10000];

char result_name;
int result_d = 1000000000;

void solve1()
{
	for (int k = 0; k <= 'z' - 'A'; k++)
	{
		for (int j = 0; j <= 'z' - 'A'; j++)
		{
			
			for (int i = 0; i <= 'z' - 'A'; i++)
			{
				if (i == j)
				{
					continue;
				}
				if (map[i][k]!=0 &&  map[k][j] !=0  && ( map[i][j] == 0 || map[i][k] + map[k][j] < map[i][j]))
				{
					//cout << map['R'-'A']['Z'-'A'] << endl;
					map[i][j] = map[i][k] + map[k][j];
					map[j][i] = map[i][j];
					//cout << char(i + 'A') << " " << char(j + 'A') <<" "<< map[i][j] << endl;
				}
			}
		}
	}

	for (int i = 0; i < 'Z'-'A'; i++)
	{
		if (map[i]['Z' - 'A'] != 0 && map[i]['Z' - 'A'] < result_d)
		{
			//cout << result << endl;
			result_d = map[i]['Z' - 'A'];
			result_name = char(i + 'A');
			//cout << result_d << endl;
		}
	}
}

int main()
{
	ifstream input("comehome.in");
	ofstream output("comehome.out");

	input >> p;
	char a, b;
	int d;
	for (int i = 0; i < p; i++)
	{
		input >> a >> b >> d;
		//input >> store[i].a >> store[i].b >> store[i].d;
		if (map[a - 'A'][b - 'A'] == 0 || ( map[a - 'A'][b - 'A'] != 0 && d < map[a - 'A'][b - 'A']))
		{
			map[a - 'A'][b - 'A'] = d;
			map[b - 'A'][a - 'A'] = d;
		}
	}

	solve1();
	output << result_name << " " << result_d << endl;

	return 0;
}