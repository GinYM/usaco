/*
ID:jinyimi1
TASK:spin
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int count_t = 0;
bool result = false;

int check_map[5];

struct we
{
	int start;
	int extend;
};

struct o
{
	we wedge[5];
}old[5];


struct s
{
	int speed;
	int w;
	we wedge[5];
}store[5];

void update()
{
	count_t++;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < store[i].w; j++)
		{
			store[i].wedge[j].start += store[i].speed;
			if (store[i].wedge[j].start >= 360)
			{
				store[i].wedge[j].start -= 360;
			}
		}
	}
}

void m_swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

bool check()
{
	int start = store[0].wedge[check_map[0]].start, extend = store[0].wedge[check_map[0]].extend;
	int tmp_s, tmp_e;
	int flag = true;
	int angle = start;
	for (int ii = 0; ii <= extend; ii ++)
	{
		angle++;
		angle %= 360;
		
		if (count_t == 357)
		{
			//cout <<ii<<" "<< angle << endl;
		}

		flag = true;
		for (int i = 0; i < 5; i++)
		{
			if (angle >= store[i].wedge[check_map[i]].start)
			{
				if (angle > store[i].wedge[check_map[i]].start + store[i].wedge[check_map[i]].extend)
				{
					flag =  false;
					break;
				}
			}
			else
			{
				if (store[i].wedge[check_map[i]].start + store[i].wedge[check_map[i]].extend < 360)
				{
					flag =  false;
					break;
				}
				else if (store[i].wedge[check_map[i]].start + store[i].wedge[check_map[i]].extend - 360 < angle)
				{
					flag = false;
					break;
				}
			}
		}
		if (flag == true)
		{
			
			return true;
		}
		
	}
	return false;


	
}

void get_check(int i,bool &tmp)
{
	for (int j = 0; j < store[i].w; j++)
	{
		check_map[i] = j;

		if (i == 4)
		{
			//cout <<count_t<< check_map[0] << check_map[1] << check_map[2] << check_map[3] << check_map[4] << endl;
			if (check() == true)
			{
				tmp = true;
				return;
			}	
			else
			{
				continue;
			}
		}

		get_check(i+1,tmp);
		if (tmp == true)
		{
			return;
		}
	}
}

bool isSame()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < store[i].w; j++)
		{
			if (old[i].wedge[j].start != store[i].wedge[j].start)
			{
				return false;
			}
		}
	}
	return true;
}

void show()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < store[i].w; j++)
		{
			cout << store[i].wedge[j].start << " " << store[i].wedge[j].extend << endl;
		}
	}
}

bool solve()
{
	bool tmp = false;

	get_check(0, tmp);
	if (tmp == true)
	{
		return true;
	}

	while (1)
	{
		tmp = false;
		update();
		get_check(0,tmp);
		if (tmp == true)
		{
			return true;
		}
		if (isSame() == true)
		{
			return false;
		}
		if (count_t == 357)
		{
			//show();
		}
		
	}
	return true;
}



int main()
{
	ifstream input("spin.in");
	ofstream output("spin.out");

	for (int i = 0; i < 5; i++)
	{
		input >> store[i].speed >> store[i].w;
		for (int j = 0; j < store[i].w; j++)
		{
			input >> store[i].wedge[j].start >> store[i].wedge[j].extend;
			old[i].wedge[j].start = store[i].wedge[j].start;
		}
	}
	if (solve())
	{
		output << count_t << endl;
	}
	else
	{
		output << "none" << endl;
	}
	
	//show();
	//cout << check() << endl;
	return 0;
}