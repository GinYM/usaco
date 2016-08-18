/*
ID:jinyimi1
TASK:camelot
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<queue>
#include<algorithm>

using namespace std;

int r, c;
int my_map[27][31];
int k_x, k_y;

int dis[27][31][27][31];
int vis [27][31];
//point m_set[35][35][40];
int my_index = -1;
int d_knight = 100000;

void initial()
{
	for (int a = 1; a < 27; a++)
	{
		for (int b = 1; b < 31; b++)
		{
			for (int c = 1; c < 27; c++)
			{
				for (int d = 1; d < 31; d++)
				{
					dis[a][b][c][d] = 1000000;
				}
			}
		}
	}
}

struct point
{
	int x, y;
	point(int t_x = 0, int t_y = 0) :x(t_x), y(t_y){}
}store[781];



queue<point> m_queue;

bool change(int x,int y,int new_x,int new_y,point tmp)
{

	int old_dis = dis[x][y][tmp.x][tmp.y];
	point new_tmp;
	if (new_x >= 1 && new_x<=c && new_y <= r && new_y>=1)
	{
		if ( old_dis + 1 <= dis[x][y][new_x][new_y])
		{
			dis[x][y][new_x][new_y] = old_dis + 1;

			
			
			if (vis[new_x][new_y] == 0)
			{
				vis[new_x][new_y] = 1;
				return true;
			}
			else
			{
				return false;
			}
			
		}
	}
	return false;
}

void bfs(int x,int y)
{
	vis[x][y] = 1;
	m_queue.push(point(x, y));
	point tmp;
	//int new_x, new_y;
	while (!m_queue.empty())
	{
		tmp = m_queue.front();
		m_queue.pop();
		vis[tmp.x][tmp.y] = 0;

		if (change(x,y, tmp.x - 2, tmp.y + 1, tmp) )
		{
			m_queue.push(point(tmp.x - 2, tmp.y + 1));
		}
		if (change(x,y, tmp.x - 1, tmp.y + 2, tmp))
		{
			m_queue.push(point(tmp.x - 1, tmp.y + 2));
		}
		if (change(x,y, tmp.x + 1, tmp.y + 2, tmp))
		{
			m_queue.push(point(tmp.x + 1, tmp.y + 2));
		}
		if (change(x,y, tmp.x + 2, tmp.y + 1, tmp))
		{
			m_queue.push(point(tmp.x + 2, tmp.y + 1));
		}
		if (change(x,y, tmp.x + 2, tmp.y - 1, tmp))
		{
			m_queue.push(point(tmp.x + 2, tmp.y - 1));
		}
		if (change(x,y, tmp.x + 1, tmp.y - 2, tmp))
		{
			m_queue.push(point(tmp.x + 1, tmp.y - 2));
		}
		if (change(x,y, tmp.x - 1, tmp.y - 2, tmp))
		{
			m_queue.push(point(tmp.x - 1, tmp.y - 2));
		}
		if (change(x,y, tmp.x - 2, tmp.y - 1, tmp))
		{
			m_queue.push(point(tmp.x - 2, tmp.y - 1));
		}
	}
}

void spfa()
{
	for (int x = 1; x <= c; x++)
	{
		for (int y = 1; y <= r; y++)
		{
			
				//cout << char(x + 'A' - 1) << " " << y << endl << endl;
				for (int xx = 1; xx <= c; xx++)
				{
					for (int yy = 1; yy <= r; yy++)
					{
						vis[xx][yy] = 0;
					}
				}
				dis[x][y][x][y] = 0;
				bfs(x, y);
				//cout << x << " " << y << endl;
				dis[x][y][x][y] = 0;
			
		}
	}
}

void show()
{
	for (int i = 0; i <= my_index; i++)
	{
		for (int y = r; y >= 1; y--)
		{
			for (int x = 1; x <= c; x++)
			{
				cout << dis[i][x][y]<<" ";
			}
			cout << endl;
		}
		cout << endl;
	}
}

void get_knight(int index,int x, int y)
{
	//cout << x<<" "<<y << endl;
	
}

int calculate(int x,int y)
{
	int total = 0;
	for (int i = 0; i <= my_index; i++)
	{
		if (dis[store[i].x][store[i].y][x][y] == 0 && (store[i].x != x || store[i].y != y))
		{
			return 10000000;
		}

		total += dis[store[i].x][store[i].y][x][y];
	}
	int knight = 0;
	knight= max((abs(k_x - x)), abs(k_y - y));
	int result_m = 1000000;
	result_m = total + knight;
	//cout << result_m << endl;
	int tmp_total = 0;

	for (int i = 0; i <= my_index; i++)
	{
		total -= dis[store[i].x][store[i].y][x][y];
		for (int xx = k_x - 2; xx <= k_x + 2; xx++)
		{
			for (int yy = k_y - 2; yy <= k_y+2; yy++)
			{
				if (xx < 1 || yy<1 || xx>c || yy>r )
				{
					continue;
				}
				tmp_total = dis[store[i].x][store[i].y][xx][yy] + dis[xx][yy][x][y] + total + max(abs(xx-k_x),abs(yy-k_y));
				//cout << tmp_total << endl;

				if (tmp_total < result_m)
				{
					result_m = tmp_total;
					
					//cout << result_m << endl;
				}

			}
		}
		total += dis[store[i].x][store[i].y][x][y];
	}

	
	
	return result_m;
}

int solve()
{
	int minD = 1000000;
	int tmp = 0;
	for (int x = 1; x <= c; x++)
	{
		for (int y = 1; y <= r; y++)
		{
			//cout << x << " " << y << endl;
			tmp = calculate(x, y);
			if (tmp < minD)
			{
				minD = tmp;
			}
		}
	}

	if (my_index == -1)
	{
		return 0;
	}

	return minD;
}

void show_set()
{
	for (int y = r; y >= 1; y--)
	{
		for (int x = 1; x <= c; x++)
		{
			cout << dis[store[0].x][store[0].y][x][y] << " ";
		}
		cout << endl;
	}

	
}

void test_show()
{
	int x = 1;
	int y = 8;

	show_set();

	
	
}



int main()
{
	ifstream input("camelot.in");
	ofstream output("camelot.out");

	input >> r >> c;

	char tmp_x;
	int tmp_y;
	input >> tmp_x >> tmp_y;
	k_x = tmp_x - 'A'+1;
	k_y = tmp_y;
	while (input >> tmp_x >> tmp_y)
	{
		my_map[tmp_x - 'A'+1][tmp_y] = 1;
		store[++my_index].x = tmp_x - 'A' + 1;
		store[my_index].y = tmp_y;
	}
	initial();
	spfa();
	//show();
	//test_show();
	//show_set();
	output<<solve()<<endl;

	return 0;
}