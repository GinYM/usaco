/*
ID:jinyimi1
TASK:shuttle
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<stack>
#include<map>
using namespace std;

int n;
bool isFind = false;
map<string, int> s2i;
map<int, string> i2s;
int pre[1000000];
stack<string> result;
string Myend;
string start;
stack<string> get_result;

void dfs(string s)
{
	if (s == Myend)
	{
		isFind = true;
		return;
	}
	//string initial = s;
	int tmp_n;
	string tmp = s;
	tmp_n = tmp.find(" ");
	if (tmp_n >= 2)
	{
		if (tmp[tmp_n - 2] != tmp[tmp_n - 1] && tmp[tmp_n - 2] == 'W')
		{
			tmp[tmp_n] = tmp[tmp_n - 2];
			tmp[tmp_n - 2] = ' ';
			result.push(tmp);
			dfs(tmp);
			if (isFind == false)
				result.pop();
			else
				return;
			
		}
	}
	tmp = s;
	if (tmp_n >= 1 && tmp[tmp_n - 1] == 'W')
	{
		tmp[tmp_n] = tmp[tmp_n - 1];
		tmp[tmp_n - 1] = ' ';
		result.push(tmp);
		dfs(tmp);
		if (isFind == false)
			result.pop();
		else
			return;
	}
	tmp = s;
	if (tmp_n <= s.size() - 2 && tmp[tmp_n + 1] == 'B')
	{
		tmp[tmp_n] = tmp[tmp_n + 1];
		tmp[tmp_n + 1] = ' ';
		result.push(tmp);
		dfs(tmp);
		if (isFind == false)
			result.pop();
		else
			return;
	}
	tmp = s;
	if (tmp_n <= s.size() - 3 && tmp[tmp_n + 2] == 'B')
	{
		if (tmp[tmp_n + 1] != tmp[tmp_n + 2])
		{
			tmp[tmp_n] = tmp[tmp_n + 2];
			tmp[tmp_n + 2] = ' ';
			result.push(tmp);
			dfs(tmp);
			if (isFind == false)
				result.pop();
			else
				return;
		}
	}
}

void bfs()
{
	string initial;
	initial.append(n, 'W');
	initial += " ";
	initial.append(n, 'B');
	queue<string>myQueue;
	myQueue.push(initial);
	string tmp;
	int count_n = 0;
	int tmp_n = 0;
	string end;
	end = end.append(n, 'B');
	end += " ";
	end.append(n, 'W');
	
	do
	{
		initial = myQueue.front();
		tmp = initial;
		//tmp = myQueue.front();
		myQueue.pop();
		tmp_n = tmp.find(" ");
		if (tmp_n >= 2)
		{
			if (tmp[tmp_n - 2] != tmp[tmp_n - 1] && tmp[tmp_n-2] == 'W')
			{
				tmp[tmp_n] = tmp[tmp_n - 2];
				tmp[tmp_n - 2] = ' ';
				if (s2i[tmp] == 0)
				{
					s2i[tmp] = ++count_n;
					i2s[count_n] = tmp;
					pre[count_n] = s2i[initial];
					myQueue.push(tmp);
				}
			}
		}
		if (tmp == end)
		{
			break;
		}
		tmp = initial;
		if (tmp_n >= 1 && tmp[tmp_n-1] == 'W')
		{
			tmp[tmp_n] = tmp[tmp_n - 1];
			tmp[tmp_n - 1] = ' ';
			if (s2i[tmp] == 0)
			{
				s2i[tmp] = ++count_n;
				i2s[count_n] = tmp;
				pre[count_n] = s2i[initial];
				myQueue.push(tmp);
			}
		}
		if (tmp == end)
		{
			break;
		}
		tmp = initial;
		if (tmp_n <= initial.size() - 2 && tmp[tmp_n+1]=='B')
		{
			tmp[tmp_n] = tmp[tmp_n + 1];
			tmp[tmp_n + 1] = ' ';
			if (s2i[tmp] == 0)
			{
				s2i[tmp] = ++count_n;
				i2s[count_n] = tmp;
				pre[count_n] = s2i[initial];
				myQueue.push(tmp);
			}
		}
		if (tmp == end)
		{
			break;
		}
		tmp = initial;
		if (tmp_n <= initial.size() - 3 && tmp[tmp_n+2] == 'B')
		{
			if (tmp[tmp_n + 1] != tmp[tmp_n + 2])
			{
				tmp[tmp_n] = tmp[tmp_n + 2];
				tmp[tmp_n + 2] = ' ';
				if (s2i[tmp] == 0)
				{
					s2i[tmp] = ++count_n;
					i2s[count_n] = tmp;
					pre[count_n] = s2i[initial];
					myQueue.push(tmp);
				}
			}
		}
		if (tmp == end)
		{
			break;
		}
	} while (!myQueue.empty());

	int result_index;
	result_index = s2i[tmp];
	do
	{
		tmp = i2s[result_index];
		result.push(tmp);
		result_index = pre[result_index];
		//cout << tmp << endl;
	} while (result_index != 0);

}

void solve()
{
	while (!result.empty())
	{
		get_result.push(result.top());
		result.pop();
	}
}

int main()
{
	ifstream input("shuttle.in");
	ofstream output("shuttle.out");

	input >> n;
	string initial;
	initial.append(n, 'W');
	initial += " ";
	initial.append(n, 'B');
	//bfs();

	start.append(n, 'W');
	start += " ";
	start.append(n, 'B');

	Myend.append(n, 'B');
	Myend += " ";
	Myend.append(n, 'W');

	dfs(start);

	bool isStart = true;
	int count_number = 0;
	solve();
	//get_result.pop();
	while (!get_result.empty())
	{
		if (count_number == 20)
		{
			count_number = 0;
			isStart = true;
			output << endl;
		}
		if (isStart == false)
		{
			output << " ";
		}
		else
		{
			isStart = false;
		}
		output << get_result.top().find(" ") + 1;
		count_number++;
		get_result.pop();
	}
	output << endl;

	return 0;
}