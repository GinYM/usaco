/*
ID:jinyimi1
TASK:ratios
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;
int store[4][3];
int D[3][4];

void show()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << D[i][j] << " ";
		}
		cout << endl;
	}
}


int M_calc(int d[3][3])
{
	int ans = 0;
	ans = d[0][0] * (d[1][1] * d[2][2] - d[1][2] * d[2][1]) - d[0][1] * (d[1][0] * d[2][2] - d[2][0] * d[1][2]) + d[0][2] * (d[1][0] * d[2][1] - d[1][1] * d[2][0]);
	return ans;
}

void m_show(int tmp[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << tmp[i][j] << " ";
		}
		cout << endl;
	}
}

int d0;
int d[3];
int r[5];

int gcd(int a, int b)
{
	
	if (a == 0)
	{
		return b;
	}
	else if (b == 0)
	{
		return a;
	}

	int tmp = a;
	if (a < b)
	{
		a = b;
		b = tmp;
	}
	int r1, r2;
	r1 = a;
	r2 = b;
	//cout << r1 << " " << r2 << endl;
	int tmp_s = 0;
	while (r1 % r2 != 0)
	{
		tmp_s = r2;
		r2 = r1%r2;
		r1 = tmp_s;
		//cout << r1 << " " << r2 << endl;
	}
	//cout << r1 <<" "<< r2 << endl;
	//cout << a << " " << b << " " << r2 << endl;

	return r2;
}

void solve()
{
	int tmp[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tmp[i][j] = D[i][j];
		}
	}

	d0 = M_calc(tmp);

	
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					tmp[j][i] = store[0][j] ;
				}
				d[i] = M_calc(tmp);
				for (int j = 0; j < 3; j++)
				{
					tmp[j][i] = D[j][i];
				}
			}
			
			if (d[0] <= 0 && d[1] <= 0 && d[2] <= 0 && d0 <= 0)
			{
				d[0] = -d[0];
				d[1] = -d[1];
				d[2] = -d[2];
				d0 = -d0;
			}
			//cout << d[0] << " " << d[1] << " " << d[2] << " " << d0 << endl;
			int max_tmp = gcd(d[0], gcd(d[1], gcd(d[2], d0)));
			//cout << max_tmp << endl;
			r[0] = d[0] / max_tmp;
			r[1] = d[1] / max_tmp;
			r[2] = d[2] / max_tmp;
			r[3] = d0 / max_tmp;
		
	
}



int main()
{
	ifstream input("ratios.in");
	ofstream output("ratios.out");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			input >> store[i][j];
		}
	}

	

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			D[i][j] = store[j + 1][i];
			
		}
	}
	
	//show();
	solve();
	if (d0 != 0 && d[0] >= 0 && d[1]>=0 && d[2]>=0 && d0>=0)
	{
		for (int i = 0; i <=3; i++)
		{
			if (i != 0)
			{
				output << " ";
			}
			output << r[i];
		}
		output << endl;
	}
	else
	{
		output << "NONE\n";
	}
	
	return 0;
}