/*
ID:jinyimi1
LANG:C++
TASK:concom
*/

#include<iostream>
#include<fstream>

using namespace std;

int Map[105][105];
int manage[105][105];
int total;
struct Node
{
	Node*next;
	int value;
	int own;
	Node(Node*Tnext = NULL, int Tvalue = 0) :next(Tnext), value(Tvalue){}
};

struct s
{
	Node *head;
	bool flag;
}store[100];

void show()
{
	for (int i = 1; i <= total; i++)
	{
		if (store[i].flag == false)
			continue;
		Node*tmp = store[i].head->next;
		while (tmp != NULL)
		{
			cout << tmp->value << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}
}

void solve()
{
	int tmp = 0;
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			tmp = 0;
			if (manage[i][j] == 0)
			{
				for (int k = 1; k <= 100; k++)
				{
					if (manage[i][k] == 1 )
					{
						tmp += Map[k][j];
					}
				}
				if (tmp > 50)
				{
					manage[i][j] = 1;
					
					i = 0; j = 0;
					break;
				}
			}
		}
	}
}

int main()
{
	ifstream input("concom.in");
	ofstream output("concom.out");
	input >> total;
	int x1, x2, p;
	for (int i = 0; i < total;i++)
	{
		input >> x1 >> x2 >> p;
		manage[x1][x1] = 1;
		manage[x2][x2] = 1;
		Map[x1][x2] = p;
		if (p > 50)
			manage[x1][x2] = 1;
	
		
	}
	solve();
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			if (i!=j && manage[i][j] == 1)
			{
				output << i<<" " << j << endl;;
			}
		}
	}
	return 0;
}