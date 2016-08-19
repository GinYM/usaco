/*
ID:jinyimi1
TASK:fence9
LANG:C++
*/

#include<iostream>
#include<fstream>

using namespace std;

int n, m, p;

int solve()
{
	int result = 0;
	int tmp1, tmp2;
	for (int i = 1; i < m; i++)
	{
		tmp1 = n*i / m + 1;

		if (abs((n - p))*i%m == 0)
		{
			tmp2 = (n - p)*i / m + p - 1;
		}
		else
		{
			tmp2 = (double(n) - p)*i / m + p;
		}

		//cout << tmp1 << " " << tmp2 << endl;
		//cout << tmp2 - tmp1 + 1 << endl;
		result += tmp2 - tmp1 + 1;
	}
	return result;
	//cout << result << endl;
}

int main()
{
	ifstream input("fence9.in");
	ofstream output("fence9.out");

	input >> n >> m >> p;
	output<<solve()<<endl;

	return 0;
}