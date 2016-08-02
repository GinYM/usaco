/*
ID:jinyimi1
TASK:contact
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>

using namespace std;

int a, b, n;

char store[200001];
int index_s = -1;
map<string, int> myMap;

struct s
{
	string str;
	int num;
}result[10000];
int index = -1;

void show()
{
	for (int i = 0; i <= index; i++)
	{
		cout << store[i] ;
	}
}

void solve()
{
	string stmp;
	for (int i = 0; i <= index_s; i++)
	{
		stmp = "";
		for (int j = 0; j < b; j++)
		{
			if (i + j > index_s)
			{
				break;
			}
			stmp += store[i+j];
			if (j + 1 >= a && j + 1 <= b)
			{
				if (myMap.find(stmp) == myMap.end())
				{
					myMap.insert(pair<string, int>(stmp, 1));
				}
				else
				{
					myMap[stmp]++;
					//cout << myMap[stmp] << endl;
				}
			}
		}
	}
}


void mSort(int a,int b)
{
	if (a >= b)
	{
		return;
	}
	int key_num = result[a].num;
	string key_str = result[a].str;
	int low, high;
	low = a;
	high = b;
	while (low < high)
	{
		while (low<high && (result[high].num > key_num || (result[high].num == key_num && (result[high].str.size()<key_str.size() || (result[high].str.size()==key_str.size() && result[high].str < key_str)))))
		{
			high--;
		}
		result[low].str = result[high].str;
		result[low].num = result[high].num;
		while (low<high && (result[low].num < key_num || (result[low].num == key_num && (result[low].str.size()>key_str.size() || (result[low].str.size()==key_str.size() && result[low].str > key_str)))))
		{
			low++;
		}
		result[high].num = result[low].num;
		result[high].str = result[low].str;
	}
	result[low].num = key_num;
	result[low].str = key_str;
	mSort(a, low-1);
	mSort(low+1, b);
}

void show_result()
{
	for (map<string, int>::iterator miter = myMap.begin(); miter != myMap.end(); miter++)
	{
		cout << miter->first << " " << miter->second << endl;
	}
}

void move()
{
	for (map<string, int>::iterator miter = myMap.begin(); miter != myMap.end(); miter++)
	{
		result[++index].num = miter->second;
		result[index].str = miter->first;
		//cout << result[index].num << " " << result[index].str << endl;
	}
}

int main()
{
	ifstream input("contact.in");
	ofstream output("contact.out");

	input >> a >> b >> n;
	char c;
	while (input >> c)
	{
		if (c != '\n' && c != '\0')
		{
			store[++index_s] = c;
		}
	}
	
	solve();
	move();
	mSort(0, index);
	//cout << "hehe" << endl;

	int start = index;
	int record_size = 0;
	for (int i = 0; i < n; i++)
	{
		output << result[start].num << endl;
		int j;
		record_size = 0;
		for (j = start; j >= 0; j--)
		{
			if (result[j].num != result[start].num)
				break;

			if (record_size != 0)
				output << " ";
			output << result[j].str;
			record_size++;
			if (record_size == 6)
			{
				output << endl;
				record_size = 0;
			}
		}
		if (record_size != 0)
			output << endl;
		start = j;
		if (start <0)
			break;
	}

	return 0;
}