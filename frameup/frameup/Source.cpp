/*
ID:jinyimi1
TASK:frameup
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<string.h>

using namespace std;

string result[10000];
int myindex = -1;

int h, w;

int store[31][31];
int count_num = 0;
int isVis[30];

int my_paint[31][31];



int minX[30], minY[30], maxX[30], maxY[30];

int cmp(string s1, string s2)
{
	return s1 < s2;
}

bool myCheck()
{
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			
				if (my_paint[i][j] >=1 && my_paint[i][j] <= 26)
				{
					return false;
				}
			
		}
	}
	return true;
}



void myDfs(int index0 = 0,string tmp = "")
{
	//cout << tmp << endl;
	if (myCheck())
	{
		//result[++myindex] = tmp;
		result[++myindex] = "";
		//cout << 1 << endl;
		for (int i = tmp.size()-1; i >=0; i--)
		{
			result[myindex] += tmp[i];
		}
		//cout << 2 << endl;
		//cout << tmp << endl;
		//cout << myindex << endl;
		return;
	}

	bool isTrue = true;

	int old_map[31][31];
	for (int i1 = 1; i1 <= h; i1++)
	{
		for (int i2 = 1; i2 <= w; i2++)
		{
			old_map[i1][i2] = my_paint[i1][i2];
		}
	}

	for (int i = 1; i <= 26; i++)
	{
		if (isVis[i] == 0 && maxX[i] != -1)
		{
			isTrue = true;

			for (int i1 = 1; i1 <= h; i1++)
			{
				for (int i2 = 1; i2 <= w; i2++)
				{
					my_paint[i1][i2] = old_map[i1][i2];
				}
			}



			int y1 = minY[i], y2 = maxY[i];
			for (int k = minX[i]; k <= maxX[i]; k++)
			{
				if ((my_paint[k][y1] != -2 && i != my_paint[k][y1]) || (my_paint[k][y2] != -2 && i != my_paint[k][y2] ))
				{
					isTrue = false;
					break;
				}
				//my_paint[k][y1] = i ;
				//my_paint[k][y2] = i ;
			}
			int x1 = minX[i], x2 = maxX[i];
			for (int k = y1; k <= y2; k++)
			{
				if ((my_paint[x1][k] != -2 && my_paint[x1][k] != i) || (my_paint[x2][k] != -2 && my_paint[x2][k] != i))
				{
					isTrue = false;
					break;
				}
				//my_paint[x1][k] = i;
				//my_paint[x2][k] = i ;
			}

			if (isTrue == true)
			{
				isVis[i] = 1;
				for (int k = minX[i]; k <= maxX[i]; k++)
				{
					my_paint[k][y1] = -2 ;
					my_paint[k][y2] = -2 ;
				}
				x1 = minX[i], x2 = maxX[i];
				for (int k = y1; k <= y2; k++)
				{
					if ((my_paint[x1][k] != -2 && my_paint[x1][k] != i) || (my_paint[x2][k] != -2 && my_paint[x2][k] != i))
					{
						isTrue = false;
						break;
					}
					my_paint[x1][k] = -2;
					my_paint[x2][k] = -2 ;
				}
				myDfs(i, tmp + char(i + 'A' - 1));
				isVis[i] = 0;
			}


			//myDfs(i, tmp + char(i + 'A' - 1));
			//isVis[i] = 0;
		}
	}
}

void myQS(int low, int high)
{
	if (low >= high)
		return;
	string key = result[low];
	int left = low;
	int right = high;
	while (left < right)
	{
		while (left < right && result[right] >= key)
		{
			right--;
		}
		result[left] = result[right];
		while (left < right && result[left] <= key)
		{
			left++;
		}
		result[right] = result[left];
	}
	result[left] = key;
	myQS(low, left - 1);
	myQS(left + 1, high);
}


int main()
{
	ifstream input("frameup.in");
	ofstream output("frameup.out");

	input >> h >> w;
	char c;

	memset(minX, 100, sizeof(minX));
	memset(minY, 100, sizeof(minY) );
	memset(maxX, -1, sizeof(maxX));
	memset(maxY, -1, sizeof(maxY));
	
	c = ' ';
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			input >> c;
			//cout << c << endl;
			
			if (c - 'A' + 1 > count_num)
			{
				count_num = c - 'A' + 1;
			}
			
			if (c == '.')
			{
				store[i][j] = -1;
			}
			else
			{
				store[i][j] = c - 'A'+1;
				//cout << c - 'A' + 1 << endl;
				if (maxX[c - 'A' + 1]  < i)
				{
					maxX[c - 'A' + 1] = i;
				}
				if (maxY[c - 'A' + 1] < j)
				{
					maxY[c - 'A' + 1] = j;
				}

				if (minX[c - 'A' + 1]  > i)
				{
					minX[c - 'A' + 1] = i;
				}

				if (minY[c - 'A' + 1] > j)
				{
					minY[c - 'A' + 1] = j;
				}
			}
			my_paint[i][j] = store[i][j];

			//cout << c - 'A' + 1 << endl;
			
		}
	}

	
	
	myDfs();

	//cout << "here" << endl;

	myQS(0, myindex);
	//sort(result, result + myindex , cmp);

	for (int i = 0; i <= myindex; i++)
	{
		output << result[i] << endl;
	}
	
	
	
	return 0;
}