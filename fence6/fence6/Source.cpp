/*
ID:jinyimi1
TASK:fence6
LANG:C++
*/

#include<iostream>
#include<fstream>

using namespace std;

int n;

int myMap[101][101];
int result = 25500;

//int len[101];

struct ss
{
	int sub[9];
	int after[9];
	int n1, n2;
	int len;
}store[101];

//int result[101];



int isVis[101][101];

bool isFind(int ini, int index)
{
	

	for (int i = 0; i < store[ini].n2; i++)
	{
		if (index == store[ini].after[i])
		{
			//cout << "here" << endl;
			return true;
		}
	}

	return false;
}

int type(int last, int index)
{
	for (int i = 0; i < store[index].n1; i++)
	{
		if (last == store[index].sub[i])
		{
			return 1;
		}
	}

	return 0;
}



void dfs(int ini,int last,int index,int len)
{
	len += store[index].len;

	//cout << ini << " " << last << " " << index << " " << len << endl;
	//cout << ini << " " << index << endl;
	if (isFind(ini, index))
	{
		if (len < result)
		{
			//cout << ini<<" "<<len << endl;
			result = len;
		}
		return;
	}
	if (last == 0)
	{
		for (int i = 0; i < store[index].n1; i++)
		{
			if (isVis[index][store[index].sub[i]] == 0)
			{
				isVis[index][store[index].sub[i]] = 1;
				isVis[store[index].sub[i]][index] = 1;
				dfs(ini,index, store[index].sub[i],len);
				isVis[index][store[index].sub[i]] = 0;
				isVis[store[index].sub[i]][index] = 0;
			}
		}
	}
	else
	{
		if (type(last, index))
		{
			for (int i = 0; i < store[index].n2; i++)
			{
				if (isVis[index][store[index].after[i]] == 0)
				{
					isVis[index][store[index].after[i]] = 1;
					isVis[store[index].after[i]][index] = 1;
					dfs(ini, index, store[index].after[i], len);
					isVis[index][store[index].after[i]] = 0;
					isVis[store[index].after[i]][index] = 0;
				}
			}
		}
		else
		{
			for (int i = 0; i < store[index].n1; i++)
			{
				if (isVis[index][store[index].sub[i]] == 0)
				{
					isVis[index][store[index].sub[i]] = 1;
					isVis[store[index].sub[i]][index] = 1;
					dfs(ini, index, store[index].sub[i], len);
					isVis[index][store[index].sub[i]] = 0;
					isVis[store[index].sub[i]][index] = 0;
				}
			}
		}
	}
}

void show_isVis(int index)
{
	for (int i = 1; i <= n; i++)
	{
		cout << isVis[index][i];
	}
	cout << endl;
}

void solve()
{
	for (int i = 1; i <= n; i++)
	{
		dfs(i, 0, i, 0);
		//cout << i << " ";
		//show_isVis(i);
	}
}



int main(){
	ifstream input("fence6.in");
	ofstream output("fence6.out");
	input >> n;
	int s,l,n1,n2;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		input >> s;
		input >> store[s].len;
		//cout << s<<" "<<store[1].len << endl;
		
		input >> store[s].n1 >> store[s].n2;
		for (int j = 0; j < store[s].n1;j++)
		{
			input >> store[s].sub[j];
		}
		for (int j = 0; j < store[s].n2; j++)
		{
			input >> store[s].after[j];
		}
	}
	solve();
	output << result << endl;

	//cout << "here" << " " << store[1].len << endl;
	
	return 0;
}