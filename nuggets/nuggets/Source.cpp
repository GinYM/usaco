/*
ID:jinyimi1
TASK:nuggets
LANG:C++
*/

#include<iostream>
#include<fstream>

using namespace std;

int n;
int store[11];
int max_size = 0;

int dp[70000];

int modul = 70000;

int get_gcd(int a,int b)
{

	int tmp_a, tmp_b;
	if (a > b)
	{
		tmp_a = a;
		tmp_b = b;
	}
	else
	{
		tmp_a = b;
		tmp_b = a;
	}
	int tmp = 0;
	while (tmp_b != 0)
	{
		tmp = tmp_b;
		tmp_b = tmp_a%tmp_b;
		tmp_a = tmp;
	}
	return tmp_a;
}

int get_all_gcd()
{
	int last = store[0];
	for (int i = 1; i < n; i++)
	{
		last = get_gcd(last, store[i]);
		if (last == 1)
		{
			return 1;
		}
	}
	return last;
}

int solve()
{
	int index = 0;
	//bool flag = true;
	bool isFind = false;
	int result = 0;
	int count_n = 0;
	int myIndex = 0;

	if (get_all_gcd() != 1)
	{
		//cout << "here" << endl;
		return 0;
	}


	while (true)
	{
		
		isFind = false;
		index++;
		myIndex = index%modul;
		//cout << index << endl;
		//cout << myIndex << endl;
		for (int i = 0; i < n; i++)
		{
			if (myIndex >= store[i])
			{
				
				if (index == store[i] || dp[myIndex - store[i]] == 1)
				{
					
					dp[myIndex] = 1;
					isFind = true;
				}
			}
			else
			{
				//myIndex = myIndex - store[i] + modul;
				if (dp[myIndex - store[i] + modul] == 1)
				{
					dp[myIndex] = 1;
					isFind = true;
				}
			}
		}

		if (isFind == false)
		{
			//cout << "here" << endl;
			dp[myIndex] =0;
		}

		if (dp[myIndex] == 0)
		{
			count_n = 0;
			result = index;
		}
		else
		{
			//cout << index << endl;
			count_n++;
		}

		if (count_n == max_size+1)
		{
			break;
		}
		//cout << count_n << endl;
		//cout << index << endl;
	}

	//cout << result << endl;
	return result;
}

int main()
{
	ifstream input("nuggets.in");
	ofstream output("nuggets.out");

	input >> n;

	bool isEnd = false;

	for (int i = 0; i < n; i++)
	{
		input >> store[i];
		if (store[i] > max_size)
		{
			max_size = store[i];
		}
		dp[store[i]] = 1;
		//cout << store[i] << " " << dp[store[i]] << endl;
		if (store[i] == 1)
		{
			isEnd = true;
		}
	}

	

	if (isEnd == true)
	{
		output << 0 << endl;
	}
	else
	{
		output << solve() << endl;
	}


	return 0;
}