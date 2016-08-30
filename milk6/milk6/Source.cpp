/*
ID:jinyimi1
TASK:milk6
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<queue>
#include<algorithm>

using namespace std;

#define size 33

int n, m;



int isVis[1002];
int pre[1002];
int flow[33][33];
int store[33][33];



struct ss
{
	int s, e, c,num;
}node[1002];
int node_index = 0;

int cmp(ss index1,ss index2)
{
	return index1.c > index2.c;
}


bool bfs()
{
	for (int i = 0; i <= n; i++)
	{
		isVis[i] = 0;
		pre[i] = 0;
	}

	
	queue<int> myqueue;
	
	myqueue.push(1);
	isVis[1] = 1;
	//cout << "here" << endl;
	int tmp;
	while (!myqueue.empty())
	{
		//cout << "here" << endl;
		tmp = myqueue.front();
		myqueue.pop();
		//cout << tmp << endl;
		for (int i = 1; i <= n; i++)
		{

			if (i != tmp && store[tmp][i] != 0 && isVis[i] == 0)
			{
				isVis[i] = 1;
				myqueue.push(i);
				pre[i]=tmp;
				if (i == n)
				{
					return true;
				}
			}
		}
	}
	return false;
}



int ek()
{
	//cout << "here" << endl;
	//cout << "here" << endl;
	int tmp;
	int minNum = 200000001;
	int count_cap = 0;
	//cout << "here\n";
	while (bfs())
	{
		//cout << "hre" << endl;
		tmp = n;
		//cout << pre[n] << endl;
		minNum = 10000000;
		while (pre[tmp] != 0)
		{
			if (store[pre[tmp]][tmp] < minNum)
			{
				minNum = store[pre[tmp]][tmp];
			}
			tmp = pre[tmp];
			//cout << pre[1]<< endl;
		}
		tmp = n;
		while (pre[tmp] != 0)
		{
			store[pre[tmp]][tmp] -= minNum;
			store[tmp][pre[tmp]] += minNum;
			tmp = pre[tmp];
		}
		count_cap += minNum;
		//cout << count_cap << endl;
	}
	return count_cap;
}

int main()
{
	ifstream input("milk6.in");
	ofstream output("milk6.out");

	input >> n >> m;
	int tmp1, tmp2, c;
	for (int i = 1; i <= m; i++)
	{
		input >> tmp1 >> tmp2 >> c;
		node[++node_index].s = tmp1;
		node[node_index].e = tmp2;
		node[node_index].c = c;
		node[node_index].num = i;

		store[tmp1][tmp2] += c;
		flow[tmp1][tmp2] += c;

		
		
		
	}
	sort(node+1, node + node_index,cmp);
	int total = ek();
	output<<total<<" ";
	int tmp_r;

	//cout << total << endl;

	//cout << total << endl;

	int count_num = 0;
	int store_result[10000];
	int index0 = -1;

	int index_re = -1;

	for (int i = 1; i <= node_index; i++)
	{
		for (int j1 = 1; j1 <= n; j1++)
		{
			for (int j2 = 1; j2 <= n; j2++)
			{
				store[j1][j2] = flow[j1][j2];
			}
		}
		store[node[i].s][node[i].e] -= node[i].c;
		tmp_r = ek();
		//cout << tmp_r << endl;
		if (tmp_r + node[i].c == total)
		{
			count_num++;
			//store_result[++index0] = i;
			flow[node[i].s][node[i].e] -= node[i].c;
			store_result[++index_re] = node[i].num;
			total = tmp_r;
			//cout << i << endl;
			//cout << node[i].num << endl;
		}
	}
	output << count_num << endl;
	if (index_re != -1)
		sort(store_result, store_result + index_re+1);
	for (int i = 0; i <= index_re; i++)
	{
		output << store_result[i] << endl;
	}
	
	return 0;
}