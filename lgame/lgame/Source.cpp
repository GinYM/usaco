/*
ID:jinyimi1
LANG:C++
TASK:lgame
*/

#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<queue>
#include<set>

using namespace std;
string store[40000];
int size = -1;
string str;
map<string, int> myMap;
queue<string> myQueue[50];
int grade[40] = { 2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};
set<string> mySet;

bool isContain(string s1, string s2,string&tmp)
{
	if (s1.size() > s2.size())
	{
		return false;
	}
	tmp = s2;
	int index = 0;
	string ss = s2;
	for (int i = 0; i < s1.size(); i++)
	{
		index = ss.find(s1[i]);
		if (index == string::npos)
		{
			tmp = ss;
			return false;
		}
		ss.erase(index,1);
	}
	tmp = ss;


	return true;
}

int getPoint(string tmp)
{
	int result = 0;
	for (int i = 0; i < tmp.size(); i++)
	{
		result += grade[tmp[i] - 'a'];
	}
	return result;
}

int main()
{
	ifstream input("lgame.in");
	ofstream output("lgame.out");
	ifstream dict("lgame.dict");
	string tmp;
	string tmp2 = "";
	while (dict >> tmp && tmp != ".")
	{
		store[++size] = tmp;
		//cout << store[size] << endl;
	}
	input >> str;

	int maxG = 0;
	int tmpG = 0;
	
	for (int i = 0; i <= size; i++)
	{
		if (isContain(store[i], str, tmp))
		{
			
				//cout << str << " " << store[i] << endl;
				//output << store[i] << endl;
				tmpG = getPoint(store[i]);
				if (tmpG > maxG)
				{
					maxG = tmpG;
				}
				
				myQueue[tmpG].push(store[i]);
			

			for (int j = 0; j <= size; j++)
			{
				if (isContain(store[j], tmp, tmp2))
				{
					tmpG = getPoint(store[i]) + getPoint(store[j]);
					if (store[i] < store[j])
					{
						myQueue[tmpG].push(store[i] + " " + store[j]);
					}
					else if (store[i] == store[j])
					{
						if (myMap[store[i]] == 0)
						{
							myQueue[tmpG].push(store[i] + " " + store[j]);
							myMap[store[i]] = 1;
						}
					}
					
					if (tmpG > maxG)
					{
						maxG = tmpG;
					}
				}
			}
		}
	}

	output << maxG << endl;
	while (!myQueue[maxG].empty())
	{
		output << myQueue[maxG].front()<<endl;
		myQueue[maxG].pop();
	}
	

	return 0;
}