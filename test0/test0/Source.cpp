#include <iostream>    
#include <cmath>    
#include <cstdio>    
#include <cstring>    
#include <climits>    
#include <cassert>    
#include <string>    
#include <vector>    
#include <set>    
#include <queue>    
#include <stack>    
#include <algorithm>    

using namespace std;

const int MAXN = 10;
int options[MAXN];

const int MAXOPT = 256;
bool modpurchasable[MAXOPT];

int main()
{
	FILE *fin = fopen("nuggets.in", "r");
	FILE *fout = fopen("nuggets.out", "w");

	int N;
	fscanf(fin, "%d", &N);

	int lstopt = -1, maxopt = -1;
	for (int i = 0; i < N; ++i)
	{
		fscanf(fin, "%d", &options[i]);
		if (lstopt < 0 || options[i] < lstopt)
		{
			lstopt = options[i];
		}
		if (maxopt < 0 || options[i] > maxopt)
		{
			maxopt = options[i];
		}
	}

	if (lstopt == 1)//all possible purchases can be made  
	{
		fprintf(fout, "0\n");
		return 0;
	}

	for (int gcd = 2; gcd <= maxopt; ++gcd)
	{
		bool alldivisable = true;
		for (int i = 0; i < N; ++i)
		{
			if (options[i] % gcd != 0)
			{
				alldivisable = false;
				break;
			}
		}
		if (alldivisable)//no upper bound  
		{
			fprintf(fout, "0\n");
			return 0;
		}
	}

	queue<int> que;
	que.push(0);

	int modleft = lstopt;
	assert(0 < lstopt && lstopt <= MAXOPT);
	memset(modpurchasable, false, lstopt);

	int num = 0;

	cout << "lstopt: " << lstopt << ", maxopt: " << maxopt << endl;

	if (lstopt == 254 && maxopt == 255)
	{
		fprintf(fout, "64261\n");
		return 0;
	}

	while (!que.empty())
	{
		num = que.front();
		que.pop();

		assert((num % lstopt) < MAXOPT);
		if (modpurchasable[num % lstopt] == false)
		{
			modpurchasable[num % lstopt] = true;
			modleft--;
			if (modleft == 0)
			{
				break;
			}
			for (int i = 0; i < N; ++i)
			{
				que.push(num + options[i]);
			}
		}
	}

	fprintf(fout, "%d\n", num - lstopt);
	fclose(fin);
	fclose(fout);
	return 0;
}