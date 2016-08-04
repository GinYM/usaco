/*
ID:jinyimi1
LANG:C++
TASK:fact4
*/

#include<iostream>
#include<fstream>

using namespace std;

int n;

int solve()
{
	int num = 1;
	int tmp = 10;
	int flag = 0;
	for (int i = 1; i <= n; i++)
	{
		num *= i;
		while (num % 10 == 0)
		{
			num /= 10;
		}
		
		num = num%1000;
	}
	
	return num%10;
}

int main()
{
	ifstream input("fact4.in");
	ofstream output("fact4.out");
	input >> n;
	output << solve() << endl;

	return 0;
}