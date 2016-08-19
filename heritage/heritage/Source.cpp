/*
ID:jinyimi1
TASK:heritage
LANG:C++
*/

#include<iostream>
#include<fstream>

using namespace std;

char in_order[30];
char pre_order[30];
char post_order[30];

int size = 0;
int store_index = -1;
int index = -1;

int find_index(int the_index)
{
	for (int i = 0; i < size; i++)
	{
		if (in_order[i] == pre_order[the_index])
		{
			return i;
		}
	}
	return -1;
}

void get_root(int a, int b)
{
	if (a > b || a<0 || b<0 )
	{
		return;
	}
	
	int tmp = 0;
	
	tmp = find_index(++index);
	
	//cout << index << " " << a << " " << b << endl;
	
	//cout << tmp << endl;
	get_root(a, tmp - 1);
	get_root(tmp + 1, b );

	post_order[++store_index] = in_order[tmp];

}

int main()
{
	ifstream input("heritage.in");
	ofstream output("heritage.out");

	input.getline(in_order, 29);
	input.getline(pre_order, 29);

	for (int i = 0; in_order[i] != '\0'; i++)
	{
		size++;
	}
	//cout << size << endl;

	get_root(0, size - 1);

	for (int i = 0; i <= store_index; i++)
	{
		output << post_order[i];
	}
	output << endl;

	return 0;
}