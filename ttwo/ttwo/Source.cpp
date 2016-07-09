/*
ID:jinyimi1
TASK:ttwo
LANG:C++
*/

#include<iostream>
#include<fstream>

using namespace std;

int store[11][11]; //-1 obstacle 1 cow 2 farmer
int c_i, c_j, f_i, f_j;
int minute = 0;

void show()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << store[i][j] << endl;
	}
}

void solve()
{
	int c_i_tmp=c_i, c_j_tmp=c_j, f_i_tmp=f_i, f_j_tmp=f_j;
	int c_d = 0, f_d = 0; //0 N 1 E 2 S 3 W
	int flag = 0;
	int i = 0;
	while (i<10000 )
	{
		if (flag == 1 && !(c_i_tmp != c_i || c_j_tmp != c_j || f_i_tmp != f_i || f_j_tmp != f_j))
		{
			minute = 0;
			break;
			
		}
		if (c_i_tmp == f_i_tmp && c_j_tmp == f_j_tmp)
		{
			break;
		}
		if ((c_i_tmp == 0 || store[c_i_tmp-1][c_j_tmp] == -1) && c_d == 0)
		{
			c_d++;
		}
		else if ((c_j_tmp == 9 || store[c_i_tmp][c_j_tmp + 1] == -1) && c_d == 1)
		{
			c_d++;
		}
		else if ((c_i_tmp == 9 || store[c_i_tmp + 1][c_j_tmp] == -1) && c_d == 2)
		{
			c_d++;
		}
		else if ((c_j_tmp == 0 || store[c_i_tmp][c_j_tmp-1] == -1) && c_d == 3)
		{
			c_d = 0;
		}
		else
		{
			switch (c_d)
			{
			case 0:
			{
				c_i_tmp = c_i_tmp - 1;
				break;
			}
			case 1:
			{
				c_j_tmp = c_j_tmp + 1;
				break;
			}
			case 2:
			{
				c_i_tmp++;
				break;
			}
			case 3:
			{
				c_j_tmp--;
				break;
			}
			}
			flag = 1;
		}


		if ((f_i_tmp == 0 || store[f_i_tmp - 1][f_j_tmp] == -1) && f_d == 0)
		{
			f_d++;
		}
		else if ((f_j_tmp == 9 || store[f_i_tmp][f_j_tmp + 1] == -1) && f_d == 1)
		{
			f_d++;
		}
		else if ((f_i_tmp == 9 || store[f_i_tmp + 1][f_j_tmp] == -1) && f_d == 2)
		{
			f_d++;
		}
		else if ((f_j_tmp == 0 || store[f_i_tmp][f_j_tmp - 1] == -1) && f_d == 3)
		{
			f_d = 0;
		}
		else
		{
			switch (f_d)
			{
			case 0:
			{
				f_i_tmp = f_i_tmp - 1;
				break;
			}
			case 1:
			{
				f_j_tmp = f_j_tmp + 1;
				break;
			}
			case 2:
			{
				f_i_tmp++;
				break;
			}
			case 3:
			{
				f_j_tmp--;
				break;
			}
			}
			flag = 1;
		}

		
		i++;
		minute++;
		
	}
	if (i == 10000)
		minute = 0;
}

int main()
{
	char c;
	ifstream input("ttwo.in");
	ofstream output("ttwo.out");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			input >> c;
			//cout << c << endl;
			if (c == '*')
			{
				store[i][j] = -1;
			}
			else if (c == 'C')
			{
				store[i][j] = 1;
				c_i = i;
				c_j = j;
				//cout << c_i << " " << c_j << endl;
			}
			else if (c == 'F')
			{
				store[i][j] = 2;
				f_i = i;
				f_j = j;
				
			}
		}
	}
	solve();
	output << minute << endl;

	return 0;
}