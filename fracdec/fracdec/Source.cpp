/*
ID:jinyimi1
TASK:fracdec
LANG:C++
*/

#include<iostream>
#include<fstream>

using namespace std;

int n, d;

struct Node
{
	int num;
	Node*left;
	Node*right;
};

int result[100000];
int result_int;
int index = -1;
int repeat = -1;

int store[100000];
int index_s = -1;

int map[100000];

Node * head = NULL;

int Minsert(int num)
{
	if (head == NULL)
	{
		head = new Node();
		head->num = num;
		return 0;
	}
	Node*tmp = head;
	while (true)
	{
		if (num == tmp->num)
		{
			return 1;
		}
		else if (num > tmp->num)
		{
			if (tmp->right == NULL)
			{
				tmp->right = new Node();
				tmp->right->num = num;
				return 0;
			}
			else
			{
				tmp = tmp->right;
			}
		}
		else
		{
			if (tmp->left == NULL)
			{
				tmp->left = new Node();
				tmp->left->num = num;
				return 0;
			}
			else
			{
				tmp = tmp->left;
			}
		}
	}
	//return 0;
}

void solve()
{
	result_int = n / d;
	int remainder, div;
	div = d;
	remainder = n;
	remainder = n - d*result_int;
	//remainder *= 10;
	while (remainder != 0)
	{
		remainder *= 10;
		//cout << remainder << endl;
		if (Minsert(remainder) == 1)
		{
			for (int i = 0; i <= index; i++)
			{
				if (map[i] == remainder)
				{
					repeat = i;
				}
			}
			//repeat = map[remainder];
			return;
		}
		result[++index] = remainder / div;
		//cout << remainder << endl;
		map[index] = remainder;
		store[++index_s] = remainder;
		remainder = remainder%div;
		
	}
}

int size_int(int num)
{
	if (num == 0)
	{
		return 1;
	}
	int s = 0;
	int tmp = 10;
	while (num != 0)
	{
		num /= 10;
		s++;
	}
	return s;
}

int main()
{
	ifstream input("fracdec.in");
	ofstream output("fracdec.out");

	input >> n >> d;
	solve();
	int s;
	s = size_int(result_int);

	if (n%d == 0)
		output << result_int<<".0" << endl;
	else
	{
		output << result_int << '.';
		s++;
		if (repeat != -1)
		{
			for (int i = 0; i < repeat; i++)
			{
				if (s % 76 == 0)
				{
					output << endl;
					s = 0;
				}
				output << result[i];
				s++;
			}
			output << "(";
			s++;
			for (int i = repeat; i <= index; i++)
			{
				if (s % 76 == 0)
				{
					output << endl;
					s = 0;
				}
				output << result[i];
				s++;
			}
			if (s % 76 == 0)
			{
				output << endl;
				s = 0;
			}
			output << ")" << endl;
			s++;
		}
		else
		{
			for (int i = 0; i <= index; i++)
			{
				if (s % 76 == 0)
				{
					output << endl;
					s = 0;
				}
				output << result[i];
				s++;
			}
			output << endl;
		}
	}


	return 0;
}