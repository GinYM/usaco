/*
ID:jinyimi1
TASK:cowtour
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdio>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip>

using namespace std;

int N;

#define MAX_NUM 10000000.0

struct s
{
	int x;
	int y;
}store[160];

int matrix[160][160];
double minD = 10000000;

int sset[160];

double d[160][160];
double my_d[160];

double Mydistance(int i, int j)
{
	//cout << ((store[i].x - store[j].x) ^ 2 )<< endl;
	return  sqrt((store[i].x - store[j].x)*(store[i].x - store[j].x) + (store[i].y - store[j].y) * (store[i].y - store[j].y));
}

void initial_my_d()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (sset[i] == sset[j])
			{
				if (d[i][j] > my_d[i])
				{
					my_d[i] = d[i][j];
				}
			}
		}
	}
}

int set_root0(int i)
{
	if (sset[i] == i) return i;
	else
	{
		sset[i] = set_root0(sset[i]);
		return sset[i];
	}
}


void show_sset()
{
	for (int i = 0; i < N; i++)
	{
		cout << sset[i] << endl;
		
	}
}


void show_my_d()
{
	for (int i = 0; i < N; i++)
	{
		cout << my_d[i] << endl;
	}
}

double solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (sset[i] != sset[j])
			{
				//cout << i << j << endl;
				if (Mydistance(i, j) + my_d[i] + my_d[j] < minD)
				{
					//cout << "here" << endl;
					//cout << my_d[i] << " " << my_d[j] <<" "<<Mydistance(i,j) << endl;
					minD = Mydistance(i, j) + my_d[i] + my_d[j];
				}
			}
		}
	}
	//show_my_d();
	return minD;
}

void show_Mydistance()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%.6f ", d[i][j]);
			//cout << d[i][j] << " ";
		}
		cout << endl;
	}
}





void show_d()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
}

void initial_d()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)
			{
				continue;
			}
			if (sset[i] == sset[j])
			{
				for (int k = 0; k < N; k++)
				{
					if (sset[k] == sset[i])
					{
						if (d[i][k] != 0 && d[k][j] != 0)
						{
							if (d[i][j] == 0 || d[i][k] + d[k][j] < d[i][j])
							{
								//if (i == j)
								d[i][j] = d[i][k] + d[k][j];
								d[j][i] = d[i][j];
							}
						}
					}
				}
			}
		}
	}

	//show_d();

}

void show_myD()
{
	for (int i = 0; i < N; i++)
	{
		cout << my_d[i] << endl;
	}
}


int main()
{
	ifstream input("cowtour.in");
	//ofstream output("cowtour.out");
	FILE* stream = fopen("cowtour.out", "w");

	input >> N;
	//cout << N << endl;
	for (int i = 0; i < N; i++)
	{
		input >> store[i].x >> store[i].y;
		sset[i] = i;
		//cout << store[i].x << " " << store[i].y << endl;
	}
	int type = 0;
	char c;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			input >> c;
			//cout << c;
			if (c == '1')
			{
				matrix[i][j] = 1;
			}
			else
			{
				matrix[i][j] = 0;
			}
			//matrix[i][j] = c - '0';
			
			//input >> matrix[i][j];
			//cout << matrix[i][j] ;
			if (matrix[i][j] == 1)
			{
				int tmp1 = set_root0(i);
				int tmp2 = set_root0(j);
				if (tmp1 != tmp2)
				{
					//cout << tmp1 << " " << tmp2 << endl;
					sset[tmp1] = tmp2;
				}
				d[i][j] = Mydistance(i, j);
				d[j][i] = d[i][j];
			}
			
		}
		//cout << endl;
	}
	//show_sset();

	//cout<<Mydistance(1, 2)<<endl;
	//show_sset();

	for (int i = 0; i < N; i++)
	{
		set_root0(i);
	}

	initial_d();
	initial_my_d();
	double result;
	result = solve();
	
	//show_Mydistance();
	//show_sset();
	for (int i = 0; i < N; i++)
	{
		if (my_d[i] > result)
		{
			result = my_d[i];
		}
	}

	//show_d();
	fprintf(stream, "%.6f\n", result);
	return 0;
}