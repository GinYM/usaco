/*
ID:jinyimi1
TASK:maze1
LANG:C++
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int w, h;
string str[100 * 2 + 2];
int start_i = 0, start_j = 0, end_i = 0, end_j = 0;
int isvisit[100 * 2 + 2][38 * 2 + 2];
int isvisit0[100 * 2 + 2][38 * 2 + 2];
int maxStep = 0;
int store_step[100 * 2 + 2][38 * 2 + 2];

void dfs(int i, int j,int step,int flag)     //flag = 0 to start 1 to end
{
	//cout << i << " " << j<<" "<<step << endl;
	if (store_step[i][j] == 0)
	{
		store_step[i][j] = step;
	}
	else
	{
		if (store_step[i][j] > step)
		{
			store_step[i][j] = step;
		}
	}
	/*
	if ((flag == 1 && i == end_i && (j == end_j - 1 || j == end_j + 1)) || (flag == 0 && i == start_i && (j == start_j - 1 || j == start_j + 1)))
	{
		
		
		
		
		//cout << "here1" << endl;
		return;
	}
	else if ((flag == 1 && j == end_j && (i == end_i - 1 || i == end_i + 1)) || ( flag == 0 && j == start_j && (i == start_i - 1 || i == start_i + 1)))
	{
		//step++;
		//cout << i << " " << j << endl;
		//cout << step << endl;
		return;
	}
	*/
	if (i > 1 && str[i - 1][j] == ' ' && str[i - 2][j] == ' ' && isvisit[i-2][j] == 0)
	{
		isvisit[i-2][j] = 1;
		isvisit0[i - 2][j] = 1;
		if (store_step[i - 2][j] != 0)
		{
			if (store_step[i][j] + 1 < store_step[i - 2][j])
			{
				dfs(i - 2, j, step + 1, flag);
			}
		}
		else
		{
			dfs(i - 2, j, step + 1, flag);
		}
		
		isvisit[i - 2][j] = 0;
	}
	if (j <= 2*w-3 && str[i ][j+1] == ' ' && str[i][j+2] == ' ' && isvisit[i ][j+2] == 0)
	{
		isvisit[i ][j+2] = 1;
		isvisit0[i][j + 2] = 1;
		if (store_step[i][j + 2] == 0 || store_step[i][j] + 1 < store_step[i][j+2])
			dfs(i, j + 2, step + 1, flag);
		isvisit[i ][j+2] = 0;
	}
	if (i <= 2*h-3 && str[i +1][j] == ' ' && str[i + 2][j] == ' ' && isvisit[i + 2][j] == 0)
	{
		isvisit[i + 2][j] = 1;
		isvisit0[i + 2][j] = 1;
		if (store_step[i + 2][j] == 0 || store_step[i][j] + 1 < store_step[i+2][j])
			dfs(i + 2, j, step + 1, flag);
		isvisit[i + 2][j] = 0;
	}
	if (j > 1 && str[i ][j-1] == ' ' && str[i ][j-2] == ' ' && isvisit[i ][j-2] == 0)
	{
		isvisit[i ][j-2] = 1;
		isvisit0[i][j - 2] = 1;
		if (store_step[i][j - 2] == 0 || store_step[i][j] + 1 < store_step[i][j-2])
			dfs(i, j - 2, step + 1, flag);
		isvisit[i ][j-2] = 0;
	}
	
}

void dp(int i, int j)
{

}

void solve()
{
	
	for (int j = 1; j < 2 * w + 1; j=j+2)
	{
		
		if (str[0][j] == ' ')
		{
			if (start_i == 0 && start_j == 0)
			{
				start_i = 0;
				start_j = j;
			}
			else
			{
				end_i = 0;
				end_j = j;
			}
			
		}
	}
	for (int j = 1; j < 2 * w + 1; j=j+2)
	{
		if (str[2*h][j] == ' ')
		{
			if (start_i == 0 && start_j == 0)
			{
				start_i = 2 * h;
				start_j = j;
			}
			else
			{
				end_i = 2 * h;
				end_j = j;
			}
			
		}
	}
	for (int i = 1; i < 2 * h + 1; i=i+2)
	{
		if (str[i][0] == ' ')
		{
			if (start_i == 0 && start_j == 0)
			{
				start_i = i;
				start_j = 0;
			}
			else
			{
				end_i = i;
				end_j = 0;
			}
		}
	}
	for (int i = 1; i < 2 * h + 1; i=i+2)
	{
		if (str[i][2*w] == ' ')
		{
			//cout << i<<" "<<2*h << endl;
			if (start_i == 0 && start_j == 0)
			{
				start_i = i;
				start_j = 2 * h;
			}
			else
			{
				end_i = i;
				end_j = 2 * w;
			}
		}
	}
	//cout<<"start: " << start_i << " " << start_j << endl;
	//cout <<"end: "<< end_i << " " << end_j << endl;

}

void show_step()
{
	for (int i = 1; i < 2 * h + 1; i = i + 2)
	{
		for (int j = 1; j < 2 * w + 1; j = j + 2)
		{
			//cout << store_step[i][j] << " ";
		}
		//cout << endl;
	}
}

int main()
{
	ifstream input("maze1.in");
	ofstream output("maze1.out");

	string a = "123";
	
	input >> w >> h;
	getline(input, str[0]);
	for (int i = 0; i < 2 * h + 1; i++)
	{
		getline(input,str[i]);
		if (str[i].size() < 2 * w + 1)
		{
			//cout << i << endl;
			//str[i][str[i].size() - 1] = ' ';
			str[i].resize(2 * w + 1, ' ');
		}
		//cout << str[i] << endl;
	}
	solve();


	if (start_i == 0)
	{
		dfs(start_i+1, start_j, 1,1);
	}
	else if (start_i == 2 * h)
	{
		dfs(start_i -1,start_j,1, 1);
	}
	else if (start_j == 0)
	{
		dfs(start_i , start_j+1, 1, 1);
	}
	else
	{
		dfs(start_i, start_j - 1, 1, 1);
	}
	

	if (end_i == 0)
	{
		dfs(end_i + 1, end_j, 1, 0);
	}
	else if (end_i == 2 * h)
	{
		dfs(end_i - 1, end_j, 1, 0);
	}
	else if (end_j == 0)
	{
		dfs(end_i, end_j + 1, 1, 0);
	}
	else
	{
		dfs(end_i, end_j - 1, 1, 0);
	}

	for (int i = 1; i < 2 * h; i = i + 2)
	{
		for (int j = 1; j < 2 * w; j = j + 2)
		{
			if (store_step[i][j] != 0 && store_step[i][j] > maxStep)
			{
				maxStep = store_step[i][j];
			}
		}
	}
	
	//dfs(start_i, start_j,0);
	output << maxStep << endl;
	show_step();
	
	return 0;
}